/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/



#ifndef CPACSCREATORLIBANDTESTS_AIRCRAFTTREE_H
#define CPACSCREATORLIBANDTESTS_AIRCRAFTTREE_H


#include "CPACSTree.h"
#include "tigl.h"
#include <map>


namespace cpcr{


    enum PLANE {XY_PLANE, XZ_PLANE, YZ_PLANE, NO_PLANE, INVALID};


    /**
     * @brief Process and modify an aircraft stored in a CPACS file.
     *
     * This class first build a tree structure based on the geometric data of a aircraft described in a CPACS file.
     * Then, different functions can be call on this representation of the aircraft. For example, the wing sweep of
     * can be changed,the area of a wing can be retrieve, the transformation element of a fuselage can be changed.
     * It is also possible to rewrite the CPACS file such that this tree respect the Creator Standard for this particular
     * aircraft. The result of these functions can be saved back into the input file or into another file.
     *
     */
    class AircraftTree: public CPACSTree {


    public:


        /*
         * FUNCTIONS FOR THE CREATION OF AIRCRAFT TREE AND ITS MANAGEMENT
         */


        /***
         * Create a empty aircraft tree.
         */
        AircraftTree();

        /**
         * Destroy the aircraft tree.
         * The memory of the TreeItem instances are free. Thus, if some other function tries to access the aircraft
         * tree after is destruction, it can result in a segmentation fault error.
         */
        ~AircraftTree();

        /**
         * Construct the aircraft tree.
         * The aircraft tree structure is build from the file starting at the XPath given as the root.
         * The CPACSTreeItem are create and some memory is allocate for them.
         * This function use the parent function build.
         *
         * @param file : the cpacs file used to build the tree
         * @param root : the root node of the tree expressed as XPath
         */
        void build(std::string file, UniqueXPath root) override ;

        /***
         * Rebuild the aircraft tree with the same file and root.
         * Can be needed after some functions that modify the tree or if the file data has changed.
         *
         * @remark The root and TreeItem item would be modified
         *
         */
        void reBuild();

        /**
         * Destroy the aircraft tree and free memory but keeps this object.
         */
        void close();

        void writeToFile() override ;

        /**
         * Write the aircraft tree to the CPACS file.
         * @remark It's the same function as in CPACSTree class, but take care of TIGL handler
         * @param fileName
         */
        void writeToFile(std::string fileName) override ;


        /*
         * HIGH LEVEL FUNCITONS FOR GEOMETRY OF THE AIRCRAFT
         */


        /*
         * FUSELAGE FUNCTIONS
         */

        /**
         * Get the fuselage length in fuselage coordinate system.
         * The length is define as the distance from the center of the noise to the center of the tail.
         * The center is retrieve from Tigl function "tiglFuselageGetSectionCenter".
         *
         * @param fuselage
         * @return
         */
        double getFuselageLength(UID fuselage);


        /**
         * Get the length between the two fuselage elements in fuselage coordinate system.
         * The length is distance between the center of the first element given by "startElementUID"
         * and the center of the second element given by "endElementUID"
         *
         * @param fuselage
         * @return
         */
        double getFuselageLengthBetween(UID startElementUID, UID endElementUID);



        /**
         * Set the length of the fuselage.
         * The fuselage is stretched in the noise-tail direction.
         * The noise will stay at the same place.
         * Every profiles will remain with the same dimension.
         * @param fuselage
         * @param length
         */
        void setFuselageLength(UID fuselage, double length);

        /**
         * Set the length between these two element.
         * The element between start and end are stretched in the direction of the fuselage
         * The elements before are untouched.
         * The elements after are shifted such that the element does not overlap.
         *
         *
         * @param startElementUID
         * @param endElementUID
         * @param length
         */
        void setFuselageLengthBetween(UID startElementUID, UID endElementUID, double length);



        /**
         * Shift the the given element by the shift.
         * The shift is expressed in world coordinate system.
         *
         * @param elementToShift
         * @param shift
         */
        void shiftElements(std::vector<UID> elementToShift , Eigen::Vector3d shift);



        double getFuselageMaximalDiameter(UID fuselageUID);



        /*
         * WING FUNCTIONS
         */



        /***
         * Represent the wing or the fuselage as a graph.
         * This mean that each element used in the wing (or fuselage) is a vertex and each connection between two elements is a edge.
         * Element that does have any connection are not in the graph.
         * This represent basically the connection described in segments section of the cpacs.
         * @param wing
         * @return A map where the first item is a element of the wing, and the second item is the element connected to the first element
         * @remark There is not guarantee on the order of the map
         */
        std::map<CPACSTreeItem*, std::vector<CPACSTreeItem*> > getWingOrFuselageGraph(CPACSTreeItem *wingOrFuselage);


        /***
         * Return a graph from root element to tip element, going through all elements in "wing order".
         * If the wing graph can not be expressed in a such way a Exception is throw.
         *
         * @param wingGraph
         * @return
         */
        std::vector<CPACSTreeItem* > formatWingOrFuselageGraph(
                std::map<CPACSTreeItem *, std::vector<CPACSTreeItem *> > wingGraph);


        void completeStandardizationForWing(UID wingUID);


        bool isWingStandardized(UID wingUID);


        bool checkIfAirfoilsAreStandardizedForWing( UID wingUID);


        void airfoilsStandardizationForWing(UID wingUID);

        /***
         * Check if the positionings used by the wing is standard.
         *
         * This mean that the translation of each elements is only given by positioning
         * and that the positioning are define incrementally from root to tip.
         * This implies that all positionings depend on the previous one.
         *
         *
         * @param wing
         * @return
         */
        bool checkIfPositioningsAreStandardizedForWing(UID wingUID);

        void positioningsStandardizationForWing(UID wingUID);




        bool checkIfOneSectionOneElementForWing(UID wingUID);

        /**
         * Create one section for each element.
         *
         * @remark The aircraft tree will be save in file and rebuild, all the CPACSTreeItem will change !!!!!!!!!
         * @param wing
         */
        void oneSectionOneElementStandardizationForWing(UID wingUID);




        bool checkIfWingTransformationIsStandardizedForWing(UID wingUID);




        void wingTransformationStandardization(UID wingUID);



        /***
         * Set the wing transformation without any remarkable changes on the output.
         * @param wing
         * @param newTransformation
         */
        void setWingTransformation(UID wingUID, const CPACSTransformation& newTransformation );





        /**
         * Evaluate which transform is more adapted for the wing.
         * 1) The origin of the transform is postionned (by translation) to the leading edge of the root element.
         * 2) If the wing seems to be on the XZ plane (global dihedral higher than 45 degree),
         * a transformation of 90 degree around X seems appropriate. Otherwise no rotation is perform on the wing.
         *
         *
         * @param wing
         * @return The new standardized transformation
         */
        CPACSTransformation determineWingTransformation(UID wingUID);




        /*
         * Add the profile defined in the the file in the airfoils profiles of CPACS file.
         * If a profile with a similar UID (filename) already exist, the function add a suffix.
         * Then all elements in the wing have there airfoilUID changed to this new airfoil UID.
         *
         * @param  wingUid : the wing that will use this airfoil
         * @param filename : the file that contains the list of point to define the profile
         * @param keepChord : if true the element transformation will be modified such that the TE and LE
         * are at the same position, otherwise only the airfoilUID of element are updated.
         */
        void setWingAirfoilsFromExternalFile(UID wingUID, std::string filename, bool keepChord = true);



        /**
         *
         * Change all the airfoil used by this wing.
         * The airfoil must already by present in the CPACS file, if not a error is throw.
         *
         *
         * @param wingUID : the wing that will use this airfoil
         * @param airfoilUID : the airfoil UID to be used
         * @param keepChord :  if true the element transformation will be modified such that the TE and LE
         * are at the same position, otherwise only the airfoilUID of element are updated.
         */
        void setWingAirfoilsByUID(UID wingUID, UID airfoilUID, bool keepChord = true);




        /**
         * Return the wing airfoil uid used by the wing given as parameter.
         * If the same airfoil is used by multiples elements, the vector will contains this uid only once;
         * If a airfoil uid is in a element but this element is not used in any segment, the airfoil uid will not be present
         * @param wingUID: the analyzed wing
         * @return the list of used uid
         *
         */
        std::vector<UID> getAllAirfoilsUIDInThisWing(UID wingUID);


        double getWingDihedral(UID wingUID, double chordPercent = 0);

        double getWingWorldDihedral(UID wingUID, double chordPercent = 0);



        void setWingDihedral(UID wingUID, double dihedral,  double chordPercent = 0);


        /**
         * Set symmetry attribute of the wing.
         * If a invalid symmetry is given an error is throw.
         * @param wingUID
         */
        void setWingSymmetry(UID wingUID, std::string);



        /**
         * Retrieve the symmetry attribute of the wing.
         * @param wingUID
         */
        std::string getWingSymmetry(UID wingUID);


        /**
         * Get the sweep angle of the wing using the given chord percent or the the leading (chord percent = 0) by default.
         *
         * @param wingUID
         * @param chordPercent the percentage of the chord to use for computing the sweep angle. A percentage of 0 means
         * taht we take the leading edge and a percent of 1 means that we take the trailing edge
         * @return sweep angle
         * @remark This method use tigl3 to get the position of the point on the chord.
         *
         */
        double getWingSweep(UID wingUID, double chordPercent = 0);






        /**
         * Set the sweep angle of the wing using the leading edge or the cgiven chord percentage.
         * This method conserve the direction and the scaling of every airfoils. But, if the some airfoils are not
         * on the XZ-plane, the area may not be preserve.
         *
         *
         * @param wingUID
         * @param sweepAngle
         * @param chordPercent
         */
        void setWingSweepByTranslation(UID wingUID, double sweepAngle, double chordPercent = 0);





        /**
         * Set the sweep angle of the wing using the leading edge or the cord percentage.
         * Shearing -> constante area
         * @param wingUID
         * @param sweepAngle
         */
        void setWingSweepByShearing(UID wingUID, double sweepAngle, double chordPercent = 0);







        /*
         *  FUNCTIONS TO RETRIEVE 3D INFORMATIONS
         */


        /**
         * @brief return the a matrix that represent all the affine transforms that is apply on the element
         * @param elementUID
         * @param wingItem
         * @return an Affine 4D matrix
         */
        Eigen::Matrix4d getGlobalTransformMatrixOfElement( UID elementUID);



        /**
         * Get all the treeItems that can influence the position of the CPACSElement given as parameter.
         * This means that all the Transformation and Positioning that influence this particular element are returned
         * as a vector composed of pair of the form <TreeItemTransformation*, Matrix4d>. The Matrix4d represent the transformation
         * in the world coordinate. The first pair of the vector is the first transformation apply on the CPACSElement
         * and the last pair is the last transformation apply on the CPACSElement. So we get the 4 matrices:
         * This method support element in Wing and Fuselage.
         *
         * The return vector contains the item in the following order:
         * [0] Element matrix
         * [1] Section matrix
         * [2] Positioning matrix
         * [3] Wing matrix
         *
         *
         * @param elementTreeItem
         * @return vector of transformation
         * @remark If element has no postionning attached to if the positioning pair is <nullptr,Identiy>
         */
        std::vector<std::pair<CPACSTreeItem*,Eigen::Matrix4d>> getTransformationChainForOneElement(CPACSTreeItem *elementItem) ;



        /**
         * Get the global translation that the section get from Positionings elements.
         * This means basically, that all the implicit references of the "fromSectionUID" of positionings are elucidate
         * and added in the global translation.
         * This method works for element in wing or fuselage
         *
         * @param section element
         * @return main positioning tree item element  and global translation matrix in world coordinate
         */
        std::pair<CPACSTreeItem*,Eigen::Matrix4d> getGlobalPositioningTranslationForSection(UID sectionUID);




        /**
        * @brief Return once all the elements UID used in this wing
        *
        * @param wingUID
        * @return a vector of UID
        *
        * All UID contained in "fromElementUID" and "toElementUID" in the "segments" of this wing are extracted.
        * Then a vector that contains exactly each UID once is returned.
        *
        */
        std::vector<UID> getAllElementUIDsUsedInAWing( UID wingUID);




        /**
         * Retrieve form TIGL the chord position of every element in a wing
         * @param wingUID
         * @param ChordPercent (0: Leading edge, 1: trailing edge)
         * @return
         */
        std::map< UID, Eigen::Vector4d> getChordPointsOfElementsInWing(UID wingUID, double ChordPercent);



        /**
         * Retrieve form TIGL the center position of every element in a fuselage
         * @param fuselageUID
         * @return
         */
        std::map< UID, Eigen::Vector4d> getCenterPointsOfElementsInFuselage(UID fuselageUID);


        /***
         * Retrieve from TIGL (tiglFuselageGetCircumference) the circumference create by each elements in fuselage
         * If a uid is not in the map, this means that is not connect by any segments
         * @param fuselageUID
         * @return
         *
         */
        std::map< UID, double> getCircumferenceOfElementsInFuselage(UID fuselageUID);





        /*
         *  HELPER FUNCTIONS TO MODIFIY THE GEOMETRY
         */


        /**
         * @brief Get the transform that the element UID needed to have to be at the wanted position.
         * This transform conserve the rotation and the scaling of the original one and change only
         * the translation component.
         *
         * @param elementUid uid of the element to place
         * @param wantedOriginP the wanted origin position for the element in the world coordinate system
         * @return CPACSTransform that the element should have to be at the wanted position
         */
        CPACSTransformation getTransformToPlaceElementByTranslationAt(const UID &elementUid,
                                                                      const Eigen::Vector4d &wantedOriginP);



        /**
         * Return a new vector that has a angle of "sweepAngle" with the given origin vector.
         * This mean that the new vector as the same y and z coordinate as the "toPlaceP" vector,
         * but the x coordinate is such that the angle on the XY-plan is equal to "sweepAngle"
         *
         * @param originP
         * @param toPlaceP
         * @param sweep
         * @return the new vector
         */
        Eigen::Vector4d computePositionToHaveSweepAngle(Eigen::Vector4d originP, Eigen::Vector4d toPlaceP,
                                                        double sweep);






        //
        // Accessing tigl function
        //

        double getWingPlanformAreaByTigl(UID wingUid, TiglSymmetryAxis symmetryAxis);


        Eigen::Vector4d computePositionToHaveDihedralAngle(Eigen::Vector4d originP, Eigen::Vector4d toPlaceP, double sweep);



        /***
         * Return the half span of the wing.
         * The half span is the distance in Y in the wing coordinate system from the root to the wing extremity.
         * @param wingUid
         * @return
         */
        double getWingSpan(UID wingUid, double chordPercent = 0.0);


        /**
         * Get the area of the segment in the wing coordinate system.
         *
         * @param segment
         * @return
         */
        double getSegmentArea(CPACSTreeItem* segment, PLANE );

        /**
         * Get the planforme area in the wing coordinate system'.
         * @param wingUID
         * @return
         */
        double getWingPlanformArea(UID wingUID,PLANE );


        double getWingAR(UID wingUID);

        void setWingSpanKeepArea(UID wingUID, double newSpan);

        void setWingSpanKeepAR(UID wingUID, double newSpan);

        void setWingAreaKeepSpan(UID wingUID, double newArea );

        void setWingAreaKeepAR(UID wingUID, double newArea);

        void setWingARKeepSpan(UID wingUID, double AR);

        void setWingARKeepArea(UID wingUID, double AR);


        /**
         * Set the wing area while keeping each leading edges to the same position.
         * This is done by scaling each chord in XY by the same factor.
         *
         * @param wing
         * @param area
         */
        void setWingAreaKeepLeadingEdges(CPACSTreeItem* wing, double area);


        /**
         * Find out the scale factor in XY to apply on the chord to obtain the target area
         * using quatric equation.
         */
        double findChordXYScaleFactor(CPACSTreeItem *wing, double targetArea);


        /**
         * Scale the wing in the wing coordinate system by the scale factor
         * @param wingUID
         * @param scaleFactor
         */
        void scaleWingUniformly(UID wingUID, double scaleFactor);






    protected:


        void setWingAirfoilsByUIDKeepChord(CPACSTreeItem* wing, UID airfoilUID);

        void setWingAirfoilsByUIDBasic(CPACSTreeItem* wing, UID airfoilUID);

        // Return the root of the wing
        // In the normal case the root is the end of the wing that is the most close of the X axis of the sing coordinate system.
        // If the wing as a special shape with more that two ends or detached element,
        // The root is simply the most closest element of the wing, without any care of its a end or not.
        UID getRootOfWing( CPACSTreeItem* wing );

        // The element that is more distant of the root in the Y direction
        // The root must be contained in the second list
        UID getExtremityInY( cpcr::UID rootUID, std::map<cpcr::UID, Eigen::Vector4d> );

        // Given a the global transformation matrix of a element,
        // this function set only the element transformation to get the correct global transformation
        void placeElementMinimalChanges(CPACSTreeItem* element, Eigen::Matrix4d globalM);


        // Given a the global transformation matrix of a element,
        // this function set the global element transformation to get the correct global transformation
        // trying to keep the creator standard.
        // This mean that the element transformation, the section transformation and the positioning can change.
        void placeElementRespectStd(CPACSTreeItem* element, Eigen::Matrix4d globalM);


        /**
         * This function set the cpacs tree such that the given element ended with a the given global matrix.
         * If the wing seems to respect the creator standard the function will try to keep the creator standard.
         * Otherwise it will chang has less as possible the file. This mean that the only element transformation
         * will be changed.
         *
         * @remark The element becomes dependent of other element though positioning. Thus if this function is used
         * to place multiples elements the order of the call is important.
         *
         * @param element
         * @param globalM
         */
        void placeElement(CPACSTreeItem* element, Eigen::Matrix4d globalM);


        void openTiglHandle(std::string modelUid);
        void closeTiglHandle();



    private:
        // to access tigl api
        TiglCPACSConfigurationHandle* tiglHandle;    // each time tixi (modifer) change some function this should be updated



        inline TiglCPACSConfigurationHandle* getTiglHandle() { return  tiglHandle;};

    };

}   // end namespace cpcr



#endif //CPACSCREATORLIBANDTESTS_AIRCRAFTTREE_H
