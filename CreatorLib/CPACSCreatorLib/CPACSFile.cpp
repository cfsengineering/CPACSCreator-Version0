//
// Created by makem on 07/04/18.
//

#include "CPACSFile.h"
#include "CreatorException.h"


#include "easylogging++.h"



#include <iostream>



namespace cpcr {


    CPACSFile::CPACSFile() {
        fileName = "";
        tixiHandle = -1;
    }



    void CPACSFile::open(std::string inFileName) {

        // TODO Important: check if no meorz leak if we open mutltiple time the same file
        // TODO Plan the  xsd validation procedure

        // case where the cpacsfilewas allready open
        if( isValid() ){
            close();
        }

        tixiHandle = -1;
        fileName = inFileName;

        // Open document
        try {
            tixiHandle = tixi::TixiOpenDocument(fileName);
        } catch (tixi::TixiError error) {
            LOG(WARNING) << error.what();
            tixiHandle = -1;
            return;
        }


        return;
    }

    bool CPACSFile::isValidWithWarning() {
        if (isValid()) {
            return true;
        } else {
            std::string msg = "The file is not valid or not open!";
            LOG(WARNING) << msg;
            return false;
        };
    }

    Point CPACSFile::getPoint(UniqueXPath xpathObj) {

        std::string xpath = xpathObj.toString();

        Point point(-1, -1, -1);

        if (!isValidWithWarning()) return point;

        if (!isValidWithWarning()) {
            return point;
        }

        if (!tixi::TixiCheckElement(tixiHandle, xpath)) {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }


        std::string tempXpath = xpath + "/x";

        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            point.x = tixi::TixiGetElement<double>(tixiHandle, tempXpath);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }
        tempXpath = xpath + "/y";
        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            point.y = tixi::TixiGetElement<double>(tixiHandle, tempXpath);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }
        tempXpath = xpath + "/z";
        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            point.z = tixi::TixiGetElement<double>(tixiHandle, tempXpath);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }
        return point;
    }



    void CPACSFile::setPoint(UniqueXPath xpathObj, const Point& point) {

        std::string xpath = xpathObj.toString();


        if (!isValidWithWarning()) return;

        if (!tixi::TixiCheckElement(tixiHandle, xpath)) {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
            return;
        }

        std::string tempXpath = xpath + "/x";

        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            tixi::TixiSaveElement(tixiHandle, tempXpath, point.x);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }
        tempXpath = xpath + "/y";
        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            tixi::TixiSaveElement(tixiHandle, tempXpath, point.y);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }
        tempXpath = xpath + "/z";
        if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
            tixi::TixiSaveElement(tixiHandle, tempXpath, point.z);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }

        return;
    }


    void CPACSFile::createPoint(UniqueXPath target, const Point &point) {

        // create structure
        std::string last = target.popLast(); // target becomes parent

        if( ! tixi::TixiCheckElement(tixiHandle, target.toString()) ){
            throw CreatorException("Invalid target given impossible to create the point");
        }

        target.addParticleAtEnd(last);
        tixi::TixiCreateElement(tixiHandle, target.toString() ) ; // create the scaling rotation or translation element
        tixi::TixiCreateElement(tixiHandle, target.toString() + "/x" );
        tixi::TixiCreateElement(tixiHandle, target.toString() + "/y" );
        tixi::TixiCreateElement(tixiHandle, target.toString() + "/z" );

        this->setPoint(target, point);

    }




    void CPACSFile::save(std::string savingFileName) {


        if (!isValidWithWarning()) return;

        int ret = tixiSaveDocument(tixiHandle, savingFileName.c_str());
        if( ret > 0){
            throw CreatorException("Impossible to save file with the name: " + savingFileName );
        }

        // TODO: optimization avoid close-open?
        // we close and open again because tixi is not able to rewrite on saved document
        close();
        open(savingFileName);
    }



    void CPACSFile::save() {
        save(fileName);
    }



    void CPACSFile::close() {

        if( ! isValid() ){
            fileName = "";
            tixiHandle = -1;

        }
        if( isValid() ){
            tixiCloseDocument(tixiHandle);
            fileName = "";
            tixiHandle = -1;
        }


    }

    CPACSTransformation CPACSFile::getTransformation(UniqueXPath xpathObj) {

        std::string xpath = xpathObj.toString();

        CPACSTransformation value;

        if( ! isValidWithWarning() ){
            return value;
        }

        if (! tixi::TixiCheckElement(tixiHandle, xpath)) {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  +  " The default Transformation will be retruned." ;
            return  value;

        }

        std::string tempXpath = xpath + "/scaling";
        Point s = getPoint(tempXpath);

        tempXpath = xpath + "/rotation";
        Point r = getPoint(tempXpath);

        tempXpath = xpath + "/translation";
        Point t = getPoint(tempXpath);

        value = CPACSTransformation(s,r,t);
        return value;
    }




    void CPACSFile::setTransformation(UniqueXPath xpathObj, const CPACSTransformation& transform) {

        std::string xpath = xpathObj.toString();

        if( ! isValidWithWarning() ){
            return;
        }

        if( xpathObj.getLastElementType() != "transformation"){
            throw CreatorException("setTransformation: The target is not a transformation");
        }

        if (! tixi::TixiCheckElement(tixiHandle, xpath)) {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  +  " The default Transformation will be retruned." ;
            return ;
        }

        std::string tempXpath = xpath + "/scaling";
        setPoint(tempXpath, transform.getScaling());

        tempXpath = xpath + "/rotation";
        setPoint(tempXpath, transform.getRotation());

        tempXpath = xpath + "/translation";
        setPoint(tempXpath, transform.getTranslation());

    }



    void CPACSFile::createTransformation(UniqueXPath target, const CPACSTransformation &transform) {


        if( ! isValidWithWarning() ){
            return;
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("CreateTransformation: parent element not found!");
        }
        if ( tixi::TixiCheckElement(tixiHandle, target.toString() )) {
            throw CreatorException("CreateTransformation: similar element already exist!");
        }

        tixi::TixiCreateElement(tixiHandle, target.toString());

        std::string tempXpath = target.toString() + "/scaling";
        createPoint(tempXpath, transform.getScaling());

        tempXpath = target.toString() + "/rotation";
        createPoint(tempXpath, transform.getRotation());

        tempXpath = target.toString() + "/translation";
        createPoint(tempXpath, transform.getTranslation());




    }




    CPACSPositioning CPACSFile::getPositioning(UniqueXPath xpathObj) {

        std::string xpath = xpathObj.toString();

        CPACSPositioning pos ;

        std::string tempXpath = xpath + "/dihedralAngle";
        pos.setDihedralAngle( retrieve<double>(tempXpath, 0));

        tempXpath = xpath + "/fromSectionUID";
        // since is completely legal to have no value for this variable we not enable warning
        pos.setFromSectionUID( retrieve<std::string>(tempXpath, "", false) );

        tempXpath = xpath + "/length";
        pos.setLength( retrieve<double>(tempXpath, 0));

        tempXpath = xpath + "/sweepAngle";
        pos.setSweepAngle( retrieve<double>(tempXpath, 0));

        tempXpath = xpath + "/toSectionUID";
        pos.setToSectionUID( retrieve<std::string>(tempXpath, "") );

        return pos;
    }


    void CPACSFile::setPositioning(UniqueXPath xpathObj, const CPACSPositioning &positioning) {

        std::string xpath  = xpathObj.toString();

        std::string tempXpath = xpath + "/dihedralAngle";
        setValue(tempXpath, positioning.getDihedralAngle());

        tempXpath = xpath + "/fromSectionUID";
        // Special case if the optional elment is empty we do nothing if not present and delete them if present
        if(positioning.getFromSectionUID() == "" ){
            if (tixi::TixiCheckElement(tixiHandle, tempXpath)) {
                tixi::TixiRemoveElement(tixiHandle, tempXpath);
            }
        }else{
            if( tixi::TixiCheckElement(tixiHandle, tempXpath)){
                tixi::TixiSaveElement(tixiHandle, tempXpath, positioning.getFromSectionUID());
            } else{
                tixiAddTextElement(tixiHandle, xpath.c_str(), "fromSectionUID", positioning.getFromSectionUID().c_str() );
            }
        }


        tempXpath = xpath + "/length";
        setValue(tempXpath, positioning.getLength());

        tempXpath = xpath + "/sweepAngle";
        setValue(tempXpath, positioning.getSweepAngle());

        tempXpath = xpath + "/toSectionUID";
        setValue(tempXpath, positioning.getToSectionUID());


    }


    UniqueXPath CPACSFile::createPositioning(UniqueXPath target, const CPACSPositioning &positioning) {


        if( ! isValidWithWarning() ){
            return UniqueXPath();
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("CreatePositioning: parent element not found!");
        }
        if ( parent.getLastElementType() != "positionings" ) {
            throw CreatorException("CreatePositioning: parent is not a positionings");
        }

        int positioningCount = tixi::TixiGetNamedChildrenCount(tixiHandle, parent.toString() + "/positioning") ;
        int idx = positioningCount + 1;

        UniqueXPath newPositioningX(parent.toString() + "/positioning[" + std::to_string(idx) + "]" );

        tixi::TixiCreateElement(tixiHandle, parent.toString() + "/positioning");

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/dihedralAngle" );

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/fromSectionUID" );

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/length" );

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/name" );

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/sweepAngle" );

        tixi::TixiCreateElement(tixiHandle, newPositioningX.toString() + "/toSectionUID" );

        this->setPositioning(newPositioningX, positioning);

        return  newPositioningX;

    }









    template<typename T>
    T CPACSFile::retrieve(UniqueXPath xpathObj, T defaultValue, bool warningEnable){

        std::string xpath  = xpathObj.toString();

        T r = defaultValue;

        if( ! isValidWithWarning() ){
            return r;
        }

        if (tixi::TixiCheckElement(tixiHandle, xpath)) {
            r =  tixi::TixiGetElement<T>(tixiHandle, xpath) ;
        } else {
            if(warningEnable) LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }

        return r;
    }


    template<typename T>
    void CPACSFile::setValue(UniqueXPath xpathObj, T value) {

        std::string xpath  = xpathObj.toString();


        if( ! isValidWithWarning() ){
            return;
        }

        if (tixi::TixiCheckElement(tixiHandle, xpath)) {
            tixi::TixiSaveElement(tixiHandle, xpath, (T) value);
        } else {
            LOG(WARNING) << " Element not found! ( xpath: " + xpath + ")"  ;
        }

        return;
    }


    int CPACSFile::getNumberOfChildren(UniqueXPath xpathObj) {

        std::string xpath  = xpathObj.toString();


        int childrenCount = -1;
        int tixiRet = -1;
        tixiRet = tixiGetNumberOfChilds(tixiHandle,xpath.c_str(),&childrenCount);
        return childrenCount;
    }

    std::string CPACSFile::getUid(UniqueXPath targetObj, std::string defaultRetrunedValue) {

        std::string target  = targetObj.toString();

        std::string r = defaultRetrunedValue;
        if( ! isValidWithWarning() ){
            return r;
        }

        try {
            r = tixi::TixiGetTextAttribute(tixiHandle, target, "uID");
        } catch (tixi::TixiError error) {
            // we expect that some times this function is call on element that have no UID
            if( error.returnCode() != ATTRIBUTE_NOT_FOUND ){
                throw error;
            }
        }

        return r;
    }





    bool CPACSFile::wingAirfoilExist(std::string uid) {

        bool r = false;

        if( ! isValid() ){
            return r;
        }

        std::string airfoilXPath = "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil";
        int airfoilCount = tixi::TixiGetNamedChildrenCount(tixiHandle, airfoilXPath) ;

        for(int i =1; i < airfoilCount+1; i++ ){
            if (uid == getUid(airfoilXPath + "[" + std::to_string(i)  +"]")){
                r=true;
            }
        }
        return r;
    }

    CPACSPointsProfile CPACSFile::getAirfoil(std::string uid) {
        if(!wingAirfoilExist(uid)){
            throw CreatorException("Airfoil does not seem to exist");
        }


        std::string airfoilXPathGeneric = "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil";
        std::string airfoilXPathPrecise = "not found";
        int airfoilCount = tixi::TixiGetNamedChildrenCount(tixiHandle, airfoilXPathGeneric) ;

        for(int i =1; i < airfoilCount+1; i++ ){
            if (uid == getUid(airfoilXPathGeneric + "[" + std::to_string(i)  +"]")){
               airfoilXPathPrecise = airfoilXPathGeneric + "[" + std::to_string(i)  +"]";
            }
        }

        if( ! tixi::TixiCheckElement(tixiHandle, airfoilXPathPrecise + "/pointList")){
            throw CreatorException("PointList not found, only point list airfoil are supported for the moment", 3);
        }

        std::string xs = retrieve<std::string>(airfoilXPathPrecise + "/pointList/x", "" );
        std::string ys = retrieve<std::string>(airfoilXPathPrecise + "/pointList/y", "" );
        std::string zs = retrieve<std::string>(airfoilXPathPrecise + "/pointList/z", "" );
        std::string name = retrieve<std::string>(airfoilXPathPrecise + "/name", "" );
        return CPACSPointsProfile(uid,name, xs,ys,zs);
    }



    std::vector<std::string> CPACSFile::getAirfoilsUid() {

        std::vector<std::string> uids;

        if( !isValid())
            return uids;

        std::string airfoilXPath = "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil";
        int airfoilCount = tixi::TixiGetNamedChildrenCount(tixiHandle, airfoilXPath) ;

        for(int i =1; i < airfoilCount+1; i++ ){
            uids.push_back( getUid(airfoilXPath + "[" + std::to_string(i)  +"]"));
        }

        return uids;
    }



    CPACSPointsProfile CPACSFile::addWingAirfoil(CPACSPointsProfile &profile) {

        std::string airfoilXPath = "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil";

        while (  tixiUIDCheckExists(tixiHandle ,profile.getUID().c_str()) != UID_DONT_EXISTS ){
            LOG(WARNING) << "Profile with the same UID already exist -> we add a suffix to UID";
            profile.tryToMakeUidUnique();
        } ;

        int airfoilCount = tixi::TixiGetNamedChildrenCount(tixiHandle, airfoilXPath) ;
        int newIdx = airfoilCount + 1;

        // create the airfoil element
        std::string newAirfoilXPath = airfoilXPath + "[" + std::to_string(newIdx) + "]";
        tixi::TixiCreateElement(tixiHandle, airfoilXPath );
        tixi::TixiSaveAttribute(tixiHandle, newAirfoilXPath, "uID", profile.getUID());

        // create the name element
        tixi::TixiCreateElement(tixiHandle, newAirfoilXPath + "/name");
        setValue(newAirfoilXPath + "/name", profile.getName() );

        // create the pointlist
        tixi::TixiCreateElement(tixiHandle, newAirfoilXPath + "/pointList");
        tixi::TixiCreateElement(tixiHandle, newAirfoilXPath + "/pointList/x");
        tixi::TixiSaveAttribute(tixiHandle, newAirfoilXPath  + "/pointList/x", "mapType", "vector");
        setValue( newAirfoilXPath  + "/pointList/x", profile.getXsAsString() );
        tixi::TixiCreateElement(tixiHandle, newAirfoilXPath + "/pointList/y");
        tixi::TixiSaveAttribute(tixiHandle, newAirfoilXPath  + "/pointList/y", "mapType", "vector");
        setValue( newAirfoilXPath  + "/pointList/y", profile.getYsAsString() );
        tixi::TixiCreateElement(tixiHandle, newAirfoilXPath + "/pointList/z");
        tixi::TixiSaveAttribute(tixiHandle, newAirfoilXPath  + "/pointList/z", "mapType", "vector");
        setValue( newAirfoilXPath  + "/pointList/z", profile.getZsAsString() );

        return profile;
    }


    CPACSPointsProfile CPACSFile::addWingAirfoil(std::string filename) {

        CPACSPointsProfile profile(filename);
        addWingAirfoil(profile); // uid of the profile can change during this call
        return profile;
    }

    CPACSSegment CPACSFile::getSegment(UniqueXPath target) {

        CPACSSegment r;

        if( ! isValidWithWarning()){
            return r;
        }

        if (! tixi::TixiCheckElement(tixiHandle, target.toString())) {
            LOG(WARNING) << " Element not found! ( xpath: " + target.toString() + ")"  +  " The default Transformation will be retruned." ;return  r;

        }

        std::string tempXPath = target.toString() + "/fromElementUID";
        r.setFromElementUID( retrieve<std::string>( tempXPath, "", true ));

        tempXPath = target.toString() + "/toElementUID";
        r.setToElementUID( retrieve<std::string>( tempXPath, "", true ));

        tempXPath = target.toString() + "/name";
        r.setName( retrieve<std::string>( tempXPath, "", true ));

        return r;
    }



    void CPACSFile::setSegment(UniqueXPath target, const CPACSSegment &segment) {


        if( ! isValidWithWarning()){
            return ;
        }

        std::string tempXPath = target.toString() + "/name";
        setValue<std::string>(tempXPath, segment.getName());

        tempXPath = target.toString() + "/fromElementUID";
        setValue<std::string>(tempXPath, segment.getFromElementUID() );

        tempXPath = target.toString() + "/toElementUID";
        setValue<std::string>(tempXPath, segment.getToElementUID() );

    }


    void CPACSFile::createSegment(UniqueXPath target, std::string uid, const CPACSSegment &segment) {


        if( ! isValidWithWarning() ){
            return;
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("CreateSegment: parent element not found!");
        }
        if ( parent.getLastElementType() != "segments" ) {
            throw CreatorException("CreateSegment: parent is not a segments");
        }

        int positioningCount = tixi::TixiGetNamedChildrenCount(tixiHandle, parent.toString() + "/segment") ;
        int idx = positioningCount + 1;

        UniqueXPath newSegmentX(parent.toString() + "/segment[" + std::to_string(idx) + "]" );

        tixi::TixiCreateElement(tixiHandle, parent.toString() + "/segment");

        tixi::TixiSaveAttribute(tixiHandle, newSegmentX.toString(), "uID", uid );

        tixi::TixiCreateElement(tixiHandle, newSegmentX.toString() + "/fromElementUID" );

        tixi::TixiCreateElement(tixiHandle, newSegmentX.toString() + "/toElementUID" );

        tixi::TixiCreateElement(tixiHandle, newSegmentX.toString() + "/name" );

        this->setSegment(newSegmentX, segment);

    }

    void CPACSFile::createEmptyWing(UniqueXPath target, std::string wingUID) {

        if( ! isValidWithWarning()){
            return ;
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("CreateWing: parent element not found!");
        }
        if ( parent.getLastElementType() != "wings" ) {
            throw CreatorException("CreateWing: parent is not a model");
        }

        int positioningCount = tixi::TixiGetNamedChildrenCount(tixiHandle, parent.toString() + "/wing") ;
        int idx = positioningCount + 1;

        UniqueXPath newWingX(parent.toString() + "/wing[" + std::to_string(idx) + "]" );
        tixi::TixiCreateElement(tixiHandle, parent.toString() + "/wing");
        tixi::TixiSaveAttribute(tixiHandle, newWingX.toString(), "uID", wingUID );

        tixi::TixiCreateElement(tixiHandle, newWingX.toString() + "/name" );
        tixi::TixiCreateElement(tixiHandle, newWingX.toString() + "/description" );
        tixi::TixiCreateElement(tixiHandle, newWingX.toString() + "/positionings" );
        tixi::TixiCreateElement(tixiHandle, newWingX.toString() + "/sections" );
        tixi::TixiCreateElement(tixiHandle, newWingX.toString() + "/segments" );
        this->createTransformation( newWingX.toString() + "/transformation", CPACSTransformation() );
        tixi::TixiSaveAttribute(tixiHandle, newWingX.toString() + "/transformation", "uID", wingUID + "_transformation1" );


    }

    bool CPACSFile::isWingAirfoilPointList(std::string uid) {
        if(!wingAirfoilExist(uid)){
            return false;
        }

        std::string airfoilXPathPrecise =  "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil[@uID=\"" + uid  +"\"]";

        if( ! tixi::TixiCheckElement(tixiHandle, airfoilXPathPrecise + "/pointList")){
           return false;
        }

        return true;
    }

    CPACSPointsProfile CPACSFile::addWingAirfoilOverwriteIfExist(CPACSPointsProfile &profile) {

        std::string airfoilXPathPrecise =  "/cpacs/vehicles/profiles/wingAirfoils/wingAirfoil[@uID=\"" + profile.getUID()  +"\"]";

        if(wingAirfoilExist(profile.getUID())){
            tixi::TixiRemoveElement(tixiHandle, airfoilXPathPrecise);
        }
        return this->addWingAirfoil(profile);
    }

    void CPACSFile::clearPositionings(UniqueXPath target) {
        if( ! isValidWithWarning()){
            return ;
        }

        UniqueXPath parent = target;
        parent.popLast();

        if ( target.getLastElementType() != "positionings" ) {
            throw CreatorException("clearPositionings: the target is not a positionings element ");
        }

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("clearPositionings: parent of positionings element not found!");
        }

        if( tixi::TixiCheckElement(tixiHandle, target.toString()) ){ // cover the case when no positionings is present
            tixi::TixiRemoveElement(tixiHandle, target.toString() );    // implicit remove all positionings
        }

        tixi::TixiCreateElement(tixiHandle, target.toString() );



    }

    UniqueXPath CPACSFile::createEmptySection(UniqueXPath target, std::string newUid) {

        if( ! isValidWithWarning() ){
            return UniqueXPath();
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("createEmptySection: parent element not found!");
        }
        if ( parent.getLastElementType() != "sections" ) {
            throw CreatorException("createEmptySection: parent is not a sections");
        }

        int positioningCount = tixi::TixiGetNamedChildrenCount(tixiHandle, parent.toString() + "/section") ;
        int idx = positioningCount + 1;

        UniqueXPath newSectionX(parent.toString() + "/section[" + std::to_string(idx) + "]" );

        tixi::TixiCreateElement(tixiHandle, parent.toString() + "/section");

        tixi::TixiSaveAttribute(tixiHandle, newSectionX.toString(), "uID", newUid );

        tixi::TixiCreateElement(tixiHandle, newSectionX.toString() + "/description" );

        tixi::TixiCreateElement(tixiHandle, newSectionX.toString() + "/elements" );

        this->createEmptyElement(newSectionX.toString() + "/elements/element", newUid + "_element1" );

        tixi::TixiCreateElement(tixiHandle, newSectionX.toString() + "/name" );

        this->createTransformation( newSectionX.toString() + "/transformation", CPACSTransformation());

        return newSectionX;
    }




    void CPACSFile::createEmptyElement(UniqueXPath target, std::string newUid) {
        if( ! isValidWithWarning() ){
            return;
        }

        UniqueXPath parent = target;
        parent.popLast();

        if (! tixi::TixiCheckElement(tixiHandle, parent.toString() )) {
            throw CreatorException("createEmptyElement: parent element not found!");
        }
        if ( parent.getLastElementType() != "elements" ) {
            throw CreatorException("createEmptyElement: parent is not a elements");
        }

        int positioningCount = tixi::TixiGetNamedChildrenCount(tixiHandle, parent.toString() + "/element") ;
        int idx = positioningCount + 1;

        UniqueXPath newSegmentX(parent.toString() + "/element[" + std::to_string(idx) + "]" );

        tixi::TixiCreateElement(tixiHandle, parent.toString() + "/element");

        tixi::TixiSaveAttribute(tixiHandle, newSegmentX.toString(), "uID", newUid );

        tixi::TixiCreateElement(tixiHandle, newSegmentX.toString() + "/airfoilUID" );

        tixi::TixiCreateElement(tixiHandle, newSegmentX.toString() + "/name" );

        this->createTransformation( newSegmentX.toString() + "/transformation", CPACSTransformation());

    }

    std::string CPACSFile::makeUIDUnique(std::string uid) {

        if(!isValidWithWarning()){
            return uid;
        }

        ReturnCode rCode = tixiUIDCheckExists(tixiHandle, uid.c_str());
        if( rCode == FAILED ){
            DLOG(ERROR) << "makeUIDUnique: something go wrong when accessing tixi";
            return uid;
        }

        while ( rCode != UID_DONT_EXISTS) {
            uid = uid + "_v";
            rCode = tixiUIDCheckExists(tixiHandle, uid.c_str());
        } ;

        return uid;
    }

    void CPACSFile::setUid(UniqueXPath target, std::string newUid) {

        if( ! isValidWithWarning() ){
            return;
        }

        if (! tixi::TixiCheckElement(tixiHandle, target.toString() )) {
            throw CreatorException("setUid: target element not found!");
        }

        tixi::TixiSaveAttribute(tixiHandle, target.toString(), "uID", newUid );

    }


    bool CPACSFile::isAValidTiglSymmetry(std::string symmetry) {
        if(symmetry == "x-y-plane" ||symmetry == "x-z-plane" || symmetry == "y-z-plane"  ){
            return true;
        }
        return false;
    }

    void CPACSFile::setSymmetry(UniqueXPath target, std::string symmetry) {

        if( ! isValidWithWarning() ){
            return;
        }

        if(symmetry == "no-symmetry" || symmetry == ""){
            tixi::TixiRemoveAttribute( tixiHandle, target.toString(), "symmetry");
        }else {
            if(! isAValidTiglSymmetry(symmetry)){
                CreatorException("Unexpected symmetry");
            }
            tixi::TixiSaveAttribute(tixiHandle, target.toString(), "symmetry", symmetry);
        }
    }


    std::string CPACSFile::getSymmetry(UniqueXPath target) {

        std::string symmetry;

        if (tixi::TixiCheckAttribute(tixiHandle, target.toString() , "symmetry") ){
            symmetry = tixi::TixiGetAttribute<std::string>(tixiHandle, target.toString() , "symmetry");
        }
        else {
            symmetry = "no-symmetry";
        }

        return symmetry;
    }


}

