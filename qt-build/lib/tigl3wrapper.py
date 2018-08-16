# -*- coding: utf-8 -*-
#############################################################################
# Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
#
# Created: 2013-05-01 Martin Siggel <Martin.Siggel@dlr.de>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#############################################################################

# This file is automatically created from tigl.h on 2018-08-14.
# If you experience any bugs please contact the authors

import sys, ctypes

class TiglLoftSide(object):
    UPPER_SIDE = 0
    LOWER_SIDE = 1
    _names = {}
    _names[0] = 'UPPER_SIDE'
    _names[1] = 'LOWER_SIDE'


class TiglContinuity(object):
    C0 = 0
    C1 = 1
    C2 = 2
    _names = {}
    _names[0] = 'C0'
    _names[1] = 'C1'
    _names[2] = 'C2'


class TiglBoolean(object):
    TIGL_FALSE = 0
    TIGL_TRUE = 1
    _names = {}
    _names[0] = 'TIGL_FALSE'
    _names[1] = 'TIGL_TRUE'


class TiglImportExportFormat(object):
    TIGL_IMPORTEXPORT_IGES = 0
    TIGL_IMPORTEXPORT_STEP = 1
    TIGL_IMPORTEXPORT_STL = 2
    TIGL_IMPORTEXPORT_VTK = 3
    _names = {}
    _names[0] = 'TIGL_IMPORTEXPORT_IGES'
    _names[1] = 'TIGL_IMPORTEXPORT_STEP'
    _names[2] = 'TIGL_IMPORTEXPORT_STL'
    _names[3] = 'TIGL_IMPORTEXPORT_VTK'


class TiglCoordinateSystem(object):
    GLOBAL_COORDINATE_SYSTEM = 0
    WING_COORDINATE_SYSTEM = 1
    FUSELAGE_COORDINATE_SYSTEM = 2
    _names = {}
    _names[0] = 'GLOBAL_COORDINATE_SYSTEM'
    _names[1] = 'WING_COORDINATE_SYSTEM'
    _names[2] = 'FUSELAGE_COORDINATE_SYSTEM'


class TiglAlgorithmCode(object):
    TIGL_INTERPOLATE_LINEAR_WIRE = 0
    TIGL_INTERPOLATE_BSPLINE_WIRE = 1
    TIGL_APPROXIMATE_BSPLINE_WIRE = 2
    _names = {}
    _names[0] = 'TIGL_INTERPOLATE_LINEAR_WIRE'
    _names[1] = 'TIGL_INTERPOLATE_BSPLINE_WIRE'
    _names[2] = 'TIGL_APPROXIMATE_BSPLINE_WIRE'


class TiglStructureType(object):
    UPPER_SHELL = 0
    LOWER_SHELL = 1
    INNER_STRUCTURE = 2
    _names = {}
    _names[0] = 'UPPER_SHELL'
    _names[1] = 'LOWER_SHELL'
    _names[2] = 'INNER_STRUCTURE'


class TiglLogLevel(object):
    TILOG_SILENT = 0
    TILOG_ERROR = 1
    TILOG_WARNING = 2
    TILOG_INFO = 3
    TILOG_DEBUG = 4
    TILOG_DEBUG1 = 5
    TILOG_DEBUG2 = 6
    TILOG_DEBUG3 = 7
    TILOG_DEBUG4 = 8
    _names = {}
    _names[0] = 'TILOG_SILENT'
    _names[1] = 'TILOG_ERROR'
    _names[2] = 'TILOG_WARNING'
    _names[3] = 'TILOG_INFO'
    _names[4] = 'TILOG_DEBUG'
    _names[5] = 'TILOG_DEBUG1'
    _names[6] = 'TILOG_DEBUG2'
    _names[7] = 'TILOG_DEBUG3'
    _names[8] = 'TILOG_DEBUG4'


class TiglSymmetryAxis(object):
    TIGL_NO_SYMMETRY = 0
    TIGL_X_Y_PLANE = 1
    TIGL_X_Z_PLANE = 2
    TIGL_Y_Z_PLANE = 3
    _names = {}
    _names[0] = 'TIGL_NO_SYMMETRY'
    _names[1] = 'TIGL_X_Y_PLANE'
    _names[2] = 'TIGL_X_Z_PLANE'
    _names[3] = 'TIGL_Y_Z_PLANE'


class TiglReturnCode(object):
    TIGL_SUCCESS = 0
    TIGL_ERROR = 1
    TIGL_NULL_POINTER = 2
    TIGL_NOT_FOUND = 3
    TIGL_XML_ERROR = 4
    TIGL_OPEN_FAILED = 5
    TIGL_CLOSE_FAILED = 6
    TIGL_INDEX_ERROR = 7
    TIGL_STRING_TRUNCATED = 8
    TIGL_WRONG_TIXI_VERSION = 9
    TIGL_UID_ERROR = 10
    TIGL_WRONG_CPACS_VERSION = 11
    TIGL_UNINITIALIZED = 12
    TIGL_MATH_ERROR = 13
    TIGL_WRITE_FAILED = 14
    _names = {}
    _names[0] = 'TIGL_SUCCESS'
    _names[1] = 'TIGL_ERROR'
    _names[2] = 'TIGL_NULL_POINTER'
    _names[3] = 'TIGL_NOT_FOUND'
    _names[4] = 'TIGL_XML_ERROR'
    _names[5] = 'TIGL_OPEN_FAILED'
    _names[6] = 'TIGL_CLOSE_FAILED'
    _names[7] = 'TIGL_INDEX_ERROR'
    _names[8] = 'TIGL_STRING_TRUNCATED'
    _names[9] = 'TIGL_WRONG_TIXI_VERSION'
    _names[10] = 'TIGL_UID_ERROR'
    _names[11] = 'TIGL_WRONG_CPACS_VERSION'
    _names[12] = 'TIGL_UNINITIALIZED'
    _names[13] = 'TIGL_MATH_ERROR'
    _names[14] = 'TIGL_WRITE_FAILED'


class Tigl3Exception(Exception):
    ''' The exception encapsulates the error return code of the library and arguments that were provided for the function. '''
    def __init__(self, code, *args, **kwargs):
        Exception.__init__(self)
        self.code = code
        if "error" in kwargs:
            self.error = str(kwargs["error"])
        elif code in TiglReturnCode._names:
            self.error = TiglReturnCode._names[code]
        else:
            self.error = "UNDEFINED"
        self.args = tuple(args)
        self.kwargs = dict(kwargs)
    def __str__(self):
        return self.error + " (" + str(self.code) + ") " + str(list(self.args)) + " " + str(self.kwargs)


def catch_error(returncode, *args, **kwargs):
    if returncode != TiglReturnCode.TIGL_SUCCESS:
        raise Tigl3Exception(returncode, args, kwargs)



def encode_for_c(thestring):
    if type(thestring) is str:
        return str.encode(thestring)
    else:
        return thestring
        
def decode_for_py(thestring):
    if sys.version_info[0] >= 3:
        return thestring.decode("utf-8")
    else:
        return thestring


class Tigl3(object):

    # load the tigl3 library
    # We only support python2.5 and newer
    if sys.version_info<(2,5,0):
        print("At least python 2.5 is needed from tiglWrapper.")

    try:
        if sys.platform == 'win32':
            lib = ctypes.cdll.tigl3
        elif sys.platform == 'darwin':
            lib = ctypes.CDLL("libtigl3.dylib")
        else:
            lib = ctypes.CDLL("libtigl3.so")
    except:
        raise Exception("Could not load the tigl3 library. Please check if:\n" +
        "  1) The PATH (Windows) / LD_LIBRARY_PATH (Linux) environment variable points to the library\n" +
        "  2) The architecture of the library matches the architecture of python (a 32 bit python needs a 32 bit shared library)\n")

    def __init__(self):
        self._handle = ctypes.c_int(-1)

        
        self.version = self.getVersion()


    def __del__(self):
        if hasattr(self, "lib"):
            if self.lib != None:
                self.close()
                self.lib = None


    
    def open(self, tixi, uid):
        if tixi._handle.value < 0:
            catch_error(TiglReturnCode.TIGL_OPEN_FAILED, 'open')
        self.openCPACSConfiguration(tixi._handle.value, uid)
    
    def close(self):
        if self._handle.value >= 0:
            # call to native function
            errorCode = self.lib.tiglCloseCPACSConfiguration(self._handle)
            catch_error(errorCode, 'tiglCloseCPACSConfiguration')
            self._handle.value = -1
    
    def openCPACSConfiguration(self, tixiHandle, configurationUID):
        # input arg conversion
        _c_tixiHandle = ctypes.c_int(tixiHandle)
        _c_configurationUID = ctypes.c_char_p(encode_for_c(configurationUID))

        # call to native function
        errorCode = self.lib.tiglOpenCPACSConfiguration(_c_tixiHandle, _c_configurationUID, ctypes.byref(self._handle))
        catch_error(errorCode, 'tiglOpenCPACSConfiguration', tixiHandle, configurationUID)




    def saveCPACSConfiguration(self, configurationUID):
        # input arg conversion
        _c_configurationUID = ctypes.c_char_p(encode_for_c(configurationUID))

        # call to native function
        errorCode = self.lib.tiglSaveCPACSConfiguration(_c_configurationUID, self._handle)
        catch_error(errorCode, 'tiglSaveCPACSConfiguration', configurationUID)



    def getCPACSTixiHandle(self):

        # output arg preparation
        _c_tixiHandlePtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglGetCPACSTixiHandle(self._handle, ctypes.byref(_c_tixiHandlePtr))
        catch_error(errorCode, 'tiglGetCPACSTixiHandle')

        _py_tixiHandlePtr = _c_tixiHandlePtr.value

        return _py_tixiHandlePtr



    def isCPACSConfigurationHandleValid(self):

        # output arg preparation
        _c_isValidPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglIsCPACSConfigurationHandleValid(self._handle, ctypes.byref(_c_isValidPtr))
        catch_error(errorCode, 'tiglIsCPACSConfigurationHandleValid')

        _py_isValidPtr = _c_isValidPtr.value

        return _py_isValidPtr



    def getVersion(self):

        # call to native function
        self.lib.tiglGetVersion.restype = ctypes.c_char_p
        _c_ret = self.lib.tiglGetVersion()

        _py_ret = decode_for_py(_c_ret)

        return _py_ret



    def getWingCount(self):

        # output arg preparation
        _c_wingCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglGetWingCount(self._handle, ctypes.byref(_c_wingCountPtr))
        catch_error(errorCode, 'tiglGetWingCount')

        _py_wingCountPtr = _c_wingCountPtr.value

        return _py_wingCountPtr



    def wingGetSegmentCount(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentCount(self._handle, _c_wingIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglWingGetSegmentCount', wingIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def wingGetComponentSegmentCount(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_compSegmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetComponentSegmentCount(self._handle, _c_wingIndex, ctypes.byref(_c_compSegmentCountPtr))
        catch_error(errorCode, 'tiglWingGetComponentSegmentCount', wingIndex)

        _py_compSegmentCountPtr = _c_compSegmentCountPtr.value

        return _py_compSegmentCountPtr



    def wingGetComponentSegmentUID(self, wingIndex, compSegmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_compSegmentIndex = ctypes.c_int(compSegmentIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetComponentSegmentUID(self._handle, _c_wingIndex, _c_compSegmentIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglWingGetComponentSegmentUID', wingIndex, compSegmentIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def wingGetComponentSegmentIndex(self, wingIndex, compSegmentUID):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_compSegmentUID = ctypes.c_char_p(encode_for_c(compSegmentUID))

        # output arg preparation
        _c_segmentIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetComponentSegmentIndex(self._handle, _c_wingIndex, _c_compSegmentUID, ctypes.byref(_c_segmentIndexPtr))
        catch_error(errorCode, 'tiglWingGetComponentSegmentIndex', wingIndex, compSegmentUID)

        _py_segmentIndexPtr = _c_segmentIndexPtr.value

        return _py_segmentIndexPtr



    def wingGetUpperPoint(self, wingIndex, segmentIndex, eta, xsi):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetUpperPoint(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglWingGetUpperPoint', wingIndex, segmentIndex, eta, xsi)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def wingGetLowerPoint(self, wingIndex, segmentIndex, eta, xsi):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetLowerPoint(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglWingGetLowerPoint', wingIndex, segmentIndex, eta, xsi)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def wingGetChordPoint(self, wingIndex, segmentIndex, eta, xsi):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetChordPoint(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglWingGetChordPoint', wingIndex, segmentIndex, eta, xsi)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def wingGetChordNormal(self, wingIndex, segmentIndex, eta, xsi):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_normalXPtr = ctypes.c_double()
        _c_normalYPtr = ctypes.c_double()
        _c_normalZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetChordNormal(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, ctypes.byref(_c_normalXPtr), ctypes.byref(_c_normalYPtr), ctypes.byref(_c_normalZPtr))
        catch_error(errorCode, 'tiglWingGetChordNormal', wingIndex, segmentIndex, eta, xsi)

        _py_normalXPtr = _c_normalXPtr.value
        _py_normalYPtr = _c_normalYPtr.value
        _py_normalZPtr = _c_normalZPtr.value

        return (_py_normalXPtr, _py_normalYPtr, _py_normalZPtr)



    def wingGetUpperPointAtDirection(self, wingIndex, segmentIndex, eta, xsi, dirx, diry, dirz):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)
        _c_dirx = ctypes.c_double(dirx)
        _c_diry = ctypes.c_double(diry)
        _c_dirz = ctypes.c_double(dirz)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()
        _c_errorDistance = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetUpperPointAtDirection(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, _c_dirx, _c_diry, _c_dirz, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr), ctypes.byref(_c_errorDistance))
        catch_error(errorCode, 'tiglWingGetUpperPointAtDirection', wingIndex, segmentIndex, eta, xsi, dirx, diry, dirz)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value
        _py_errorDistance = _c_errorDistance.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr, _py_errorDistance)



    def wingGetLowerPointAtDirection(self, wingIndex, segmentIndex, eta, xsi, dirx, diry, dirz):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)
        _c_dirx = ctypes.c_double(dirx)
        _c_diry = ctypes.c_double(diry)
        _c_dirz = ctypes.c_double(dirz)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()
        _c_errorDistance = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetLowerPointAtDirection(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta, _c_xsi, _c_dirx, _c_diry, _c_dirz, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr), ctypes.byref(_c_errorDistance))
        catch_error(errorCode, 'tiglWingGetLowerPointAtDirection', wingIndex, segmentIndex, eta, xsi, dirx, diry, dirz)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value
        _py_errorDistance = _c_errorDistance.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr, _py_errorDistance)



    def wingGetSegmentEtaXsi(self, wingIndex, pointX, pointY, pointZ):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_pointX = ctypes.c_double(pointX)
        _c_pointY = ctypes.c_double(pointY)
        _c_pointZ = ctypes.c_double(pointZ)

        # output arg preparation
        _c_segmentIndex = ctypes.c_int()
        _c_eta = ctypes.c_double()
        _c_xsi = ctypes.c_double()
        _c_isOnTop = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentEtaXsi(self._handle, _c_wingIndex, _c_pointX, _c_pointY, _c_pointZ, ctypes.byref(_c_segmentIndex), ctypes.byref(_c_eta), ctypes.byref(_c_xsi), ctypes.byref(_c_isOnTop))
        catch_error(errorCode, 'tiglWingGetSegmentEtaXsi', wingIndex, pointX, pointY, pointZ)

        _py_segmentIndex = _c_segmentIndex.value
        _py_eta = _c_eta.value
        _py_xsi = _c_xsi.value
        _py_isOnTop = _c_isOnTop.value

        return (_py_segmentIndex, _py_eta, _py_xsi, _py_isOnTop)



    def wingGetInnerConnectedSegmentCount(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetInnerConnectedSegmentCount(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglWingGetInnerConnectedSegmentCount', wingIndex, segmentIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def wingGetOuterConnectedSegmentCount(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetOuterConnectedSegmentCount(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglWingGetOuterConnectedSegmentCount', wingIndex, segmentIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def wingGetInnerConnectedSegmentIndex(self, wingIndex, segmentIndex, n):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_n = ctypes.c_int(n)

        # output arg preparation
        _c_connectedIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetInnerConnectedSegmentIndex(self._handle, _c_wingIndex, _c_segmentIndex, _c_n, ctypes.byref(_c_connectedIndexPtr))
        catch_error(errorCode, 'tiglWingGetInnerConnectedSegmentIndex', wingIndex, segmentIndex, n)

        _py_connectedIndexPtr = _c_connectedIndexPtr.value

        return _py_connectedIndexPtr



    def wingGetOuterConnectedSegmentIndex(self, wingIndex, segmentIndex, n):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_n = ctypes.c_int(n)

        # output arg preparation
        _c_connectedIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetOuterConnectedSegmentIndex(self._handle, _c_wingIndex, _c_segmentIndex, _c_n, ctypes.byref(_c_connectedIndexPtr))
        catch_error(errorCode, 'tiglWingGetOuterConnectedSegmentIndex', wingIndex, segmentIndex, n)

        _py_connectedIndexPtr = _c_connectedIndexPtr.value

        return _py_connectedIndexPtr



    def wingGetInnerSectionAndElementIndex(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionIndexPtr = ctypes.c_int()
        _c_elementIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetInnerSectionAndElementIndex(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_sectionIndexPtr), ctypes.byref(_c_elementIndexPtr))
        catch_error(errorCode, 'tiglWingGetInnerSectionAndElementIndex', wingIndex, segmentIndex)

        _py_sectionIndexPtr = _c_sectionIndexPtr.value
        _py_elementIndexPtr = _c_elementIndexPtr.value

        return (_py_sectionIndexPtr, _py_elementIndexPtr)



    def wingGetOuterSectionAndElementIndex(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionIndexPtr = ctypes.c_int()
        _c_elementIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetOuterSectionAndElementIndex(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_sectionIndexPtr), ctypes.byref(_c_elementIndexPtr))
        catch_error(errorCode, 'tiglWingGetOuterSectionAndElementIndex', wingIndex, segmentIndex)

        _py_sectionIndexPtr = _c_sectionIndexPtr.value
        _py_elementIndexPtr = _c_elementIndexPtr.value

        return (_py_sectionIndexPtr, _py_elementIndexPtr)



    def wingGetInnerSectionAndElementUID(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionUIDPtr = ctypes.c_char_p()
        _c_elementUIDPtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetInnerSectionAndElementUID(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_sectionUIDPtr), ctypes.byref(_c_elementUIDPtr))
        catch_error(errorCode, 'tiglWingGetInnerSectionAndElementUID', wingIndex, segmentIndex)

        _py_sectionUIDPtr = decode_for_py(_c_sectionUIDPtr.value)
        _py_elementUIDPtr = decode_for_py(_c_elementUIDPtr.value)

        return (_py_sectionUIDPtr, _py_elementUIDPtr)



    def wingGetOuterSectionAndElementUID(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionUIDPtr = ctypes.c_char_p()
        _c_elementUIDPtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetOuterSectionAndElementUID(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_sectionUIDPtr), ctypes.byref(_c_elementUIDPtr))
        catch_error(errorCode, 'tiglWingGetOuterSectionAndElementUID', wingIndex, segmentIndex)

        _py_sectionUIDPtr = decode_for_py(_c_sectionUIDPtr.value)
        _py_elementUIDPtr = decode_for_py(_c_elementUIDPtr.value)

        return (_py_sectionUIDPtr, _py_elementUIDPtr)



    def wingGetProfileName(self, wingIndex, sectionIndex, elementIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_sectionIndex = ctypes.c_int(sectionIndex)
        _c_elementIndex = ctypes.c_int(elementIndex)

        # output arg preparation
        _c_profileNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetProfileName(self._handle, _c_wingIndex, _c_sectionIndex, _c_elementIndex, ctypes.byref(_c_profileNamePtr))
        catch_error(errorCode, 'tiglWingGetProfileName', wingIndex, sectionIndex, elementIndex)

        _py_profileNamePtr = decode_for_py(_c_profileNamePtr.value)

        return _py_profileNamePtr



    def wingGetUID(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetUID(self._handle, _c_wingIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglWingGetUID', wingIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def wingGetIndex(self, wingUID):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))

        # output arg preparation
        _c_wingIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetIndex(self._handle, _c_wingUID, ctypes.byref(_c_wingIndexPtr))
        catch_error(errorCode, 'tiglWingGetIndex', wingUID)

        _py_wingIndexPtr = _c_wingIndexPtr.value

        return _py_wingIndexPtr



    def wingGetSegmentUID(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentUID(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglWingGetSegmentUID', wingIndex, segmentIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def wingGetSegmentIndex(self, segmentUID):
        # input arg conversion
        _c_segmentUID = ctypes.c_char_p(encode_for_c(segmentUID))

        # output arg preparation
        _c_segmentIndexPtr = ctypes.c_int()
        _c_wingIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentIndex(self._handle, _c_segmentUID, ctypes.byref(_c_segmentIndexPtr), ctypes.byref(_c_wingIndexPtr))
        catch_error(errorCode, 'tiglWingGetSegmentIndex', segmentUID)

        _py_segmentIndexPtr = _c_segmentIndexPtr.value
        _py_wingIndexPtr = _c_wingIndexPtr.value

        return (_py_segmentIndexPtr, _py_wingIndexPtr)



    def wingGetSectionCount(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_sectionCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetSectionCount(self._handle, _c_wingIndex, ctypes.byref(_c_sectionCount))
        catch_error(errorCode, 'tiglWingGetSectionCount', wingIndex)

        _py_sectionCount = _c_sectionCount.value

        return _py_sectionCount



    def wingGetSectionUID(self, wingIndex, sectionIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_sectionIndex = ctypes.c_int(sectionIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingGetSectionUID(self._handle, _c_wingIndex, _c_sectionIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglWingGetSectionUID', wingIndex, sectionIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def wingGetSymmetry(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_symmetryAxisPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingGetSymmetry(self._handle, _c_wingIndex, ctypes.byref(_c_symmetryAxisPtr))
        catch_error(errorCode, 'tiglWingGetSymmetry', wingIndex)

        _py_symmetryAxisPtr = _c_symmetryAxisPtr.value

        return _py_symmetryAxisPtr



    def wingComponentSegmentFindSegment(self, componentSegmentUID, x, y, z):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_x = ctypes.c_double(x)
        _c_y = ctypes.c_double(y)
        _c_z = ctypes.c_double(z)

        # output arg preparation
        _c_segmentUID = ctypes.c_char_p()
        _c_wingUID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentFindSegment(self._handle, _c_componentSegmentUID, _c_x, _c_y, _c_z, ctypes.byref(_c_segmentUID), ctypes.byref(_c_wingUID))
        catch_error(errorCode, 'tiglWingComponentSegmentFindSegment', componentSegmentUID, x, y, z)

        _py_segmentUID = decode_for_py(_c_segmentUID.value)
        _py_wingUID = decode_for_py(_c_wingUID.value)

        return (_py_segmentUID, _py_wingUID)



    def wingComponentSegmentGetPoint(self, componentSegmentUID, eta, xsi):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_x = ctypes.c_double()
        _c_y = ctypes.c_double()
        _c_z = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetPoint(self._handle, _c_componentSegmentUID, _c_eta, _c_xsi, ctypes.byref(_c_x), ctypes.byref(_c_y), ctypes.byref(_c_z))
        catch_error(errorCode, 'tiglWingComponentSegmentGetPoint', componentSegmentUID, eta, xsi)

        _py_x = _c_x.value
        _py_y = _c_y.value
        _py_z = _c_z.value

        return (_py_x, _py_y, _py_z)



    def wingComponentSegmentPointGetEtaXsi(self, componentSegmentUID, pX, pY, pZ):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_pX = ctypes.c_double(pX)
        _c_pY = ctypes.c_double(pY)
        _c_pZ = ctypes.c_double(pZ)

        # output arg preparation
        _c_eta = ctypes.c_double()
        _c_xsi = ctypes.c_double()
        _c_errorDistance = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentPointGetEtaXsi(self._handle, _c_componentSegmentUID, _c_pX, _c_pY, _c_pZ, ctypes.byref(_c_eta), ctypes.byref(_c_xsi), ctypes.byref(_c_errorDistance))
        catch_error(errorCode, 'tiglWingComponentSegmentPointGetEtaXsi', componentSegmentUID, pX, pY, pZ)

        _py_eta = _c_eta.value
        _py_xsi = _c_xsi.value
        _py_errorDistance = _c_errorDistance.value

        return (_py_eta, _py_xsi, _py_errorDistance)



    def wingComponentSegmentPointGetSegmentEtaXsi(self, componentSegmentUID, eta, xsi):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_wingUID = ctypes.c_char_p()
        _c_segmentUID = ctypes.c_char_p()
        _c_segmentEta = ctypes.c_double()
        _c_segmentXsi = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentPointGetSegmentEtaXsi(self._handle, _c_componentSegmentUID, _c_eta, _c_xsi, ctypes.byref(_c_wingUID), ctypes.byref(_c_segmentUID), ctypes.byref(_c_segmentEta), ctypes.byref(_c_segmentXsi))
        catch_error(errorCode, 'tiglWingComponentSegmentPointGetSegmentEtaXsi', componentSegmentUID, eta, xsi)

        _py_wingUID = decode_for_py(_c_wingUID.value)
        _py_segmentUID = decode_for_py(_c_segmentUID.value)
        _py_segmentEta = _c_segmentEta.value
        _py_segmentXsi = _c_segmentXsi.value

        return (_py_wingUID, _py_segmentUID, _py_segmentEta, _py_segmentXsi)



    def wingSegmentPointGetComponentSegmentEtaXsi(self, segmentUID, componentSegmentUID, segmentEta, segmentXsi):
        # input arg conversion
        _c_segmentUID = ctypes.c_char_p(encode_for_c(segmentUID))
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_segmentEta = ctypes.c_double(segmentEta)
        _c_segmentXsi = ctypes.c_double(segmentXsi)

        # output arg preparation
        _c_eta = ctypes.c_double()
        _c_xsi = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingSegmentPointGetComponentSegmentEtaXsi(self._handle, _c_segmentUID, _c_componentSegmentUID, _c_segmentEta, _c_segmentXsi, ctypes.byref(_c_eta), ctypes.byref(_c_xsi))
        catch_error(errorCode, 'tiglWingSegmentPointGetComponentSegmentEtaXsi', segmentUID, componentSegmentUID, segmentEta, segmentXsi)

        _py_eta = _c_eta.value
        _py_xsi = _c_xsi.value

        return (_py_eta, _py_xsi)



    def wingComponentSegmentGetSegmentIntersection(self, componentSegmentUID, segmentUID, csEta1, csXsi1, csEta2, csXsi2, segmentEta):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_segmentUID = ctypes.c_char_p(encode_for_c(segmentUID))
        _c_csEta1 = ctypes.c_double(csEta1)
        _c_csXsi1 = ctypes.c_double(csXsi1)
        _c_csEta2 = ctypes.c_double(csEta2)
        _c_csXsi2 = ctypes.c_double(csXsi2)
        _c_segmentEta = ctypes.c_double(segmentEta)

        # output arg preparation
        _c_segmentXsi = ctypes.c_double()
        _c_hasWarning = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetSegmentIntersection(self._handle, _c_componentSegmentUID, _c_segmentUID, _c_csEta1, _c_csXsi1, _c_csEta2, _c_csXsi2, _c_segmentEta, ctypes.byref(_c_segmentXsi), ctypes.byref(_c_hasWarning))
        catch_error(errorCode, 'tiglWingComponentSegmentGetSegmentIntersection', componentSegmentUID, segmentUID, csEta1, csXsi1, csEta2, csXsi2, segmentEta)

        _py_segmentXsi = _c_segmentXsi.value
        _py_hasWarning = _c_hasWarning.value

        return (_py_segmentXsi, _py_hasWarning)



    def wingComponentSegmentComputeEtaIntersection(self, componentSegmentUID, csEta1, csXsi1, csEta2, csXsi2, eta):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_csEta1 = ctypes.c_double(csEta1)
        _c_csXsi1 = ctypes.c_double(csXsi1)
        _c_csEta2 = ctypes.c_double(csEta2)
        _c_csXsi2 = ctypes.c_double(csXsi2)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_xsi = ctypes.c_double()
        _c_hasWarning = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentComputeEtaIntersection(self._handle, _c_componentSegmentUID, _c_csEta1, _c_csXsi1, _c_csEta2, _c_csXsi2, _c_eta, ctypes.byref(_c_xsi), ctypes.byref(_c_hasWarning))
        catch_error(errorCode, 'tiglWingComponentSegmentComputeEtaIntersection', componentSegmentUID, csEta1, csXsi1, csEta2, csXsi2, eta)

        _py_xsi = _c_xsi.value
        _py_hasWarning = _c_hasWarning.value

        return (_py_xsi, _py_hasWarning)



    def wingComponentSegmentGetNumberOfSegments(self, componentSegmentUID):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))

        # output arg preparation
        _c_nsegments = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetNumberOfSegments(self._handle, _c_componentSegmentUID, ctypes.byref(_c_nsegments))
        catch_error(errorCode, 'tiglWingComponentSegmentGetNumberOfSegments', componentSegmentUID)

        _py_nsegments = _c_nsegments.value

        return _py_nsegments



    def wingComponentSegmentGetSegmentUID(self, componentSegmentUID, segmentIndex):
        # input arg conversion
        _c_componentSegmentUID = ctypes.c_char_p(encode_for_c(componentSegmentUID))
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_segmentUID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetSegmentUID(self._handle, _c_componentSegmentUID, _c_segmentIndex, ctypes.byref(_c_segmentUID))
        catch_error(errorCode, 'tiglWingComponentSegmentGetSegmentUID', componentSegmentUID, segmentIndex)

        _py_segmentUID = decode_for_py(_c_segmentUID.value)

        return _py_segmentUID



    def getFuselageCount(self):

        # output arg preparation
        _c_fuselageCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglGetFuselageCount(self._handle, ctypes.byref(_c_fuselageCountPtr))
        catch_error(errorCode, 'tiglGetFuselageCount')

        _py_fuselageCountPtr = _c_fuselageCountPtr.value

        return _py_fuselageCountPtr



    def fuselageGetSegmentCount(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSegmentCount(self._handle, _c_fuselageIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglFuselageGetSegmentCount', fuselageIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def fuselageGetSectionCenter(self, fuselageSegmentUID, eta):
        # input arg conversion
        _c_fuselageSegmentUID = ctypes.c_char_p(encode_for_c(fuselageSegmentUID))
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_pointX = ctypes.c_double()
        _c_pointY = ctypes.c_double()
        _c_pointZ = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSectionCenter(self._handle, _c_fuselageSegmentUID, _c_eta, ctypes.byref(_c_pointX), ctypes.byref(_c_pointY), ctypes.byref(_c_pointZ))
        catch_error(errorCode, 'tiglFuselageGetSectionCenter', fuselageSegmentUID, eta)

        _py_pointX = _c_pointX.value
        _py_pointY = _c_pointY.value
        _py_pointZ = _c_pointZ.value

        return (_py_pointX, _py_pointY, _py_pointZ)



    def fuselageGetCrossSectionArea(self, fuselageSegmentUID, eta):
        # input arg conversion
        _c_fuselageSegmentUID = ctypes.c_char_p(encode_for_c(fuselageSegmentUID))
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_area = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetCrossSectionArea(self._handle, _c_fuselageSegmentUID, _c_eta, ctypes.byref(_c_area))
        catch_error(errorCode, 'tiglFuselageGetCrossSectionArea', fuselageSegmentUID, eta)

        _py_area = _c_area.value

        return _py_area



    def fuselageGetCenterLineLength(self, fuselageUID):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))

        # output arg preparation
        _c_length = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetCenterLineLength(self._handle, _c_fuselageUID, ctypes.byref(_c_length))
        catch_error(errorCode, 'tiglFuselageGetCenterLineLength', fuselageUID)

        _py_length = _c_length.value

        return _py_length



    def fuselageGetPoint(self, fuselageIndex, segmentIndex, eta, zeta):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_zeta = ctypes.c_double(zeta)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetPoint(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_zeta, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetPoint', fuselageIndex, segmentIndex, eta, zeta)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def fuselageGetPointAngle(self, fuselageIndex, segmentIndex, eta, alpha):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_alpha = ctypes.c_double(alpha)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetPointAngle(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_alpha, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetPointAngle', fuselageIndex, segmentIndex, eta, alpha)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def fuselageGetPointAngleTranslated(self, fuselageIndex, segmentIndex, eta, alpha, y_cs, z_cs):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_alpha = ctypes.c_double(alpha)
        _c_y_cs = ctypes.c_double(y_cs)
        _c_z_cs = ctypes.c_double(z_cs)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetPointAngleTranslated(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_alpha, _c_y_cs, _c_z_cs, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetPointAngleTranslated', fuselageIndex, segmentIndex, eta, alpha, y_cs, z_cs)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def fuselageGetPointOnXPlane(self, fuselageIndex, segmentIndex, eta, xpos, pointIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xpos = ctypes.c_double(xpos)
        _c_pointIndex = ctypes.c_int(pointIndex)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetPointOnXPlane(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_xpos, _c_pointIndex, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetPointOnXPlane', fuselageIndex, segmentIndex, eta, xpos, pointIndex)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def fuselageGetPointOnYPlane(self, fuselageIndex, segmentIndex, eta, ypos, pointIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_ypos = ctypes.c_double(ypos)
        _c_pointIndex = ctypes.c_int(pointIndex)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetPointOnYPlane(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_ypos, _c_pointIndex, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetPointOnYPlane', fuselageIndex, segmentIndex, eta, ypos, pointIndex)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def fuselageGetNumPointsOnXPlane(self, fuselageIndex, segmentIndex, eta, xpos):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_xpos = ctypes.c_double(xpos)

        # output arg preparation
        _c_numPointsPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetNumPointsOnXPlane(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_xpos, ctypes.byref(_c_numPointsPtr))
        catch_error(errorCode, 'tiglFuselageGetNumPointsOnXPlane', fuselageIndex, segmentIndex, eta, xpos)

        _py_numPointsPtr = _c_numPointsPtr.value

        return _py_numPointsPtr



    def fuselageGetNumPointsOnYPlane(self, fuselageIndex, segmentIndex, eta, ypos):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)
        _c_ypos = ctypes.c_double(ypos)

        # output arg preparation
        _c_numPointsPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetNumPointsOnYPlane(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, _c_ypos, ctypes.byref(_c_numPointsPtr))
        catch_error(errorCode, 'tiglFuselageGetNumPointsOnYPlane', fuselageIndex, segmentIndex, eta, ypos)

        _py_numPointsPtr = _c_numPointsPtr.value

        return _py_numPointsPtr



    def fuselageGetCircumference(self, fuselageIndex, segmentIndex, eta):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_circumferencePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetCircumference(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_eta, ctypes.byref(_c_circumferencePtr))
        catch_error(errorCode, 'tiglFuselageGetCircumference', fuselageIndex, segmentIndex, eta)

        _py_circumferencePtr = _c_circumferencePtr.value

        return _py_circumferencePtr



    def fuselageGetStartConnectedSegmentCount(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetStartConnectedSegmentCount(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglFuselageGetStartConnectedSegmentCount', fuselageIndex, segmentIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def fuselageGetEndConnectedSegmentCount(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_segmentCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetEndConnectedSegmentCount(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_segmentCountPtr))
        catch_error(errorCode, 'tiglFuselageGetEndConnectedSegmentCount', fuselageIndex, segmentIndex)

        _py_segmentCountPtr = _c_segmentCountPtr.value

        return _py_segmentCountPtr



    def fuselageGetStartConnectedSegmentIndex(self, fuselageIndex, segmentIndex, n):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_n = ctypes.c_int(n)

        # output arg preparation
        _c_connectedIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetStartConnectedSegmentIndex(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_n, ctypes.byref(_c_connectedIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetStartConnectedSegmentIndex', fuselageIndex, segmentIndex, n)

        _py_connectedIndexPtr = _c_connectedIndexPtr.value

        return _py_connectedIndexPtr



    def fuselageGetEndConnectedSegmentIndex(self, fuselageIndex, segmentIndex, n):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_n = ctypes.c_int(n)

        # output arg preparation
        _c_connectedIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetEndConnectedSegmentIndex(self._handle, _c_fuselageIndex, _c_segmentIndex, _c_n, ctypes.byref(_c_connectedIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetEndConnectedSegmentIndex', fuselageIndex, segmentIndex, n)

        _py_connectedIndexPtr = _c_connectedIndexPtr.value

        return _py_connectedIndexPtr



    def fuselageGetStartSectionAndElementUID(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionUIDPtr = ctypes.c_char_p()
        _c_elementUIDPtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetStartSectionAndElementUID(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_sectionUIDPtr), ctypes.byref(_c_elementUIDPtr))
        catch_error(errorCode, 'tiglFuselageGetStartSectionAndElementUID', fuselageIndex, segmentIndex)

        _py_sectionUIDPtr = decode_for_py(_c_sectionUIDPtr.value)
        _py_elementUIDPtr = decode_for_py(_c_elementUIDPtr.value)

        return (_py_sectionUIDPtr, _py_elementUIDPtr)



    def fuselageGetEndSectionAndElementUID(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionUIDPtr = ctypes.c_char_p()
        _c_elementUIDPtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetEndSectionAndElementUID(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_sectionUIDPtr), ctypes.byref(_c_elementUIDPtr))
        catch_error(errorCode, 'tiglFuselageGetEndSectionAndElementUID', fuselageIndex, segmentIndex)

        _py_sectionUIDPtr = decode_for_py(_c_sectionUIDPtr.value)
        _py_elementUIDPtr = decode_for_py(_c_elementUIDPtr.value)

        return (_py_sectionUIDPtr, _py_elementUIDPtr)



    def fuselageGetStartSectionAndElementIndex(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionIndexPtr = ctypes.c_int()
        _c_elementIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetStartSectionAndElementIndex(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_sectionIndexPtr), ctypes.byref(_c_elementIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetStartSectionAndElementIndex', fuselageIndex, segmentIndex)

        _py_sectionIndexPtr = _c_sectionIndexPtr.value
        _py_elementIndexPtr = _c_elementIndexPtr.value

        return (_py_sectionIndexPtr, _py_elementIndexPtr)



    def fuselageGetEndSectionAndElementIndex(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_sectionIndexPtr = ctypes.c_int()
        _c_elementIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetEndSectionAndElementIndex(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_sectionIndexPtr), ctypes.byref(_c_elementIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetEndSectionAndElementIndex', fuselageIndex, segmentIndex)

        _py_sectionIndexPtr = _c_sectionIndexPtr.value
        _py_elementIndexPtr = _c_elementIndexPtr.value

        return (_py_sectionIndexPtr, _py_elementIndexPtr)



    def fuselageGetProfileName(self, fuselageIndex, sectionIndex, elementIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_sectionIndex = ctypes.c_int(sectionIndex)
        _c_elementIndex = ctypes.c_int(elementIndex)

        # output arg preparation
        _c_profileNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetProfileName(self._handle, _c_fuselageIndex, _c_sectionIndex, _c_elementIndex, ctypes.byref(_c_profileNamePtr))
        catch_error(errorCode, 'tiglFuselageGetProfileName', fuselageIndex, sectionIndex, elementIndex)

        _py_profileNamePtr = decode_for_py(_c_profileNamePtr.value)

        return _py_profileNamePtr



    def fuselageGetUID(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetUID(self._handle, _c_fuselageIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglFuselageGetUID', fuselageIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def fuselageGetIndex(self, fuselageUID):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))

        # output arg preparation
        _c_fuselageIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetIndex(self._handle, _c_fuselageUID, ctypes.byref(_c_fuselageIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetIndex', fuselageUID)

        _py_fuselageIndexPtr = _c_fuselageIndexPtr.value

        return _py_fuselageIndexPtr



    def fuselageGetSegmentUID(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSegmentUID(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglFuselageGetSegmentUID', fuselageIndex, segmentIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def fuselageGetSegmentIndex(self, segmentUID):
        # input arg conversion
        _c_segmentUID = ctypes.c_char_p(encode_for_c(segmentUID))

        # output arg preparation
        _c_segmentIndexPtr = ctypes.c_int()
        _c_fuselageIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSegmentIndex(self._handle, _c_segmentUID, ctypes.byref(_c_segmentIndexPtr), ctypes.byref(_c_fuselageIndexPtr))
        catch_error(errorCode, 'tiglFuselageGetSegmentIndex', segmentUID)

        _py_segmentIndexPtr = _c_segmentIndexPtr.value
        _py_fuselageIndexPtr = _c_fuselageIndexPtr.value

        return (_py_segmentIndexPtr, _py_fuselageIndexPtr)



    def fuselageGetSectionCount(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_sectionCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSectionCount(self._handle, _c_fuselageIndex, ctypes.byref(_c_sectionCount))
        catch_error(errorCode, 'tiglFuselageGetSectionCount', fuselageIndex)

        _py_sectionCount = _c_sectionCount.value

        return _py_sectionCount



    def fuselageGetSectionUID(self, fuselageIndex, sectionIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_sectionIndex = ctypes.c_int(sectionIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSectionUID(self._handle, _c_fuselageIndex, _c_sectionIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglFuselageGetSectionUID', fuselageIndex, sectionIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def fuselageGetSymmetry(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_symmetryAxisPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSymmetry(self._handle, _c_fuselageIndex, ctypes.byref(_c_symmetryAxisPtr))
        catch_error(errorCode, 'tiglFuselageGetSymmetry', fuselageIndex)

        _py_symmetryAxisPtr = _c_symmetryAxisPtr.value

        return _py_symmetryAxisPtr



    def fuselageGetMinumumDistanceToGround(self, fuselageUID, axisPntX, axisPntY, axisPntZ, axisDirX, axisDirY, axisDirZ, angle):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))
        _c_axisPntX = ctypes.c_double(axisPntX)
        _c_axisPntY = ctypes.c_double(axisPntY)
        _c_axisPntZ = ctypes.c_double(axisPntZ)
        _c_axisDirX = ctypes.c_double(axisDirX)
        _c_axisDirY = ctypes.c_double(axisDirY)
        _c_axisDirZ = ctypes.c_double(axisDirZ)
        _c_angle = ctypes.c_double(angle)

        # output arg preparation
        _c_pointXPtr = ctypes.c_double()
        _c_pointYPtr = ctypes.c_double()
        _c_pointZPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetMinumumDistanceToGround(self._handle, _c_fuselageUID, _c_axisPntX, _c_axisPntY, _c_axisPntZ, _c_axisDirX, _c_axisDirY, _c_axisDirZ, _c_angle, ctypes.byref(_c_pointXPtr), ctypes.byref(_c_pointYPtr), ctypes.byref(_c_pointZPtr))
        catch_error(errorCode, 'tiglFuselageGetMinumumDistanceToGround', fuselageUID, axisPntX, axisPntY, axisPntZ, axisDirX, axisDirY, axisDirZ, angle)

        _py_pointXPtr = _c_pointXPtr.value
        _py_pointYPtr = _c_pointYPtr.value
        _py_pointZPtr = _c_pointZPtr.value

        return (_py_pointXPtr, _py_pointYPtr, _py_pointZPtr)



    def getRotorCount(self):

        # output arg preparation
        _c_rotorCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglGetRotorCount(self._handle, ctypes.byref(_c_rotorCountPtr))
        catch_error(errorCode, 'tiglGetRotorCount')

        _py_rotorCountPtr = _c_rotorCountPtr.value

        return _py_rotorCountPtr



    def rotorGetUID(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_uidNamePtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglRotorGetUID(self._handle, _c_rotorIndex, ctypes.byref(_c_uidNamePtr))
        catch_error(errorCode, 'tiglRotorGetUID', rotorIndex)

        _py_uidNamePtr = decode_for_py(_c_uidNamePtr.value)

        return _py_uidNamePtr



    def rotorGetIndex(self, rotorUID):
        # input arg conversion
        _c_rotorUID = ctypes.c_char_p(encode_for_c(rotorUID))

        # output arg preparation
        _c_rotorIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglRotorGetIndex(self._handle, _c_rotorUID, ctypes.byref(_c_rotorIndexPtr))
        catch_error(errorCode, 'tiglRotorGetIndex', rotorUID)

        _py_rotorIndexPtr = _c_rotorIndexPtr.value

        return _py_rotorIndexPtr



    def rotorGetRadius(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_radiusPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetRadius(self._handle, _c_rotorIndex, ctypes.byref(_c_radiusPtr))
        catch_error(errorCode, 'tiglRotorGetRadius', rotorIndex)

        _py_radiusPtr = _c_radiusPtr.value

        return _py_radiusPtr



    def rotorGetReferenceArea(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_referenceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetReferenceArea(self._handle, _c_rotorIndex, ctypes.byref(_c_referenceAreaPtr))
        catch_error(errorCode, 'tiglRotorGetReferenceArea', rotorIndex)

        _py_referenceAreaPtr = _c_referenceAreaPtr.value

        return _py_referenceAreaPtr



    def rotorGetTotalBladePlanformArea(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_totalBladePlanformAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetTotalBladePlanformArea(self._handle, _c_rotorIndex, ctypes.byref(_c_totalBladePlanformAreaPtr))
        catch_error(errorCode, 'tiglRotorGetTotalBladePlanformArea', rotorIndex)

        _py_totalBladePlanformAreaPtr = _c_totalBladePlanformAreaPtr.value

        return _py_totalBladePlanformAreaPtr



    def rotorGetSolidity(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_solidityPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetSolidity(self._handle, _c_rotorIndex, ctypes.byref(_c_solidityPtr))
        catch_error(errorCode, 'tiglRotorGetSolidity', rotorIndex)

        _py_solidityPtr = _c_solidityPtr.value

        return _py_solidityPtr



    def rotorGetSurfaceArea(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetSurfaceArea(self._handle, _c_rotorIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglRotorGetSurfaceArea', rotorIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def rotorGetVolume(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetVolume(self._handle, _c_rotorIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglRotorGetVolume', rotorIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def rotorGetTipSpeed(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_tipSpeedPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorGetTipSpeed(self._handle, _c_rotorIndex, ctypes.byref(_c_tipSpeedPtr))
        catch_error(errorCode, 'tiglRotorGetTipSpeed', rotorIndex)

        _py_tipSpeedPtr = _c_tipSpeedPtr.value

        return _py_tipSpeedPtr



    def rotorGetRotorBladeCount(self, rotorIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)

        # output arg preparation
        _c_rotorBladeCountPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglRotorGetRotorBladeCount(self._handle, _c_rotorIndex, ctypes.byref(_c_rotorBladeCountPtr))
        catch_error(errorCode, 'tiglRotorGetRotorBladeCount', rotorIndex)

        _py_rotorBladeCountPtr = _c_rotorBladeCountPtr.value

        return _py_rotorBladeCountPtr



    def rotorBladeGetWingIndex(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_wingIndexPtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetWingIndex(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_wingIndexPtr))
        catch_error(errorCode, 'tiglRotorBladeGetWingIndex', rotorIndex, rotorBladeIndex)

        _py_wingIndexPtr = _c_wingIndexPtr.value

        return _py_wingIndexPtr



    def rotorBladeGetWingUID(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_wingUIDPtr = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetWingUID(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_wingUIDPtr))
        catch_error(errorCode, 'tiglRotorBladeGetWingUID', rotorIndex, rotorBladeIndex)

        _py_wingUIDPtr = decode_for_py(_c_wingUIDPtr.value)

        return _py_wingUIDPtr



    def rotorBladeGetAzimuthAngle(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_azimuthAnglePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetAzimuthAngle(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_azimuthAnglePtr))
        catch_error(errorCode, 'tiglRotorBladeGetAzimuthAngle', rotorIndex, rotorBladeIndex)

        _py_azimuthAnglePtr = _c_azimuthAnglePtr.value

        return _py_azimuthAnglePtr



    def rotorBladeGetRadius(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_radiusPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetRadius(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_radiusPtr))
        catch_error(errorCode, 'tiglRotorBladeGetRadius', rotorIndex, rotorBladeIndex)

        _py_radiusPtr = _c_radiusPtr.value

        return _py_radiusPtr



    def rotorBladeGetPlanformArea(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_planformAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetPlanformArea(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_planformAreaPtr))
        catch_error(errorCode, 'tiglRotorBladeGetPlanformArea', rotorIndex, rotorBladeIndex)

        _py_planformAreaPtr = _c_planformAreaPtr.value

        return _py_planformAreaPtr



    def rotorBladeGetSurfaceArea(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetSurfaceArea(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglRotorBladeGetSurfaceArea', rotorIndex, rotorBladeIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def rotorBladeGetVolume(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetVolume(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglRotorBladeGetVolume', rotorIndex, rotorBladeIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def rotorBladeGetTipSpeed(self, rotorIndex, rotorBladeIndex):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)

        # output arg preparation
        _c_tipSpeedPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetTipSpeed(self._handle, _c_rotorIndex, _c_rotorBladeIndex, ctypes.byref(_c_tipSpeedPtr))
        catch_error(errorCode, 'tiglRotorBladeGetTipSpeed', rotorIndex, rotorBladeIndex)

        _py_tipSpeedPtr = _c_tipSpeedPtr.value

        return _py_tipSpeedPtr



    def rotorBladeGetLocalRadius(self, rotorIndex, rotorBladeIndex, segmentIndex, eta):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_radiusPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetLocalRadius(self._handle, _c_rotorIndex, _c_rotorBladeIndex, _c_segmentIndex, _c_eta, ctypes.byref(_c_radiusPtr))
        catch_error(errorCode, 'tiglRotorBladeGetLocalRadius', rotorIndex, rotorBladeIndex, segmentIndex, eta)

        _py_radiusPtr = _c_radiusPtr.value

        return _py_radiusPtr



    def rotorBladeGetLocalChord(self, rotorIndex, rotorBladeIndex, segmentIndex, eta):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_chordPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetLocalChord(self._handle, _c_rotorIndex, _c_rotorBladeIndex, _c_segmentIndex, _c_eta, ctypes.byref(_c_chordPtr))
        catch_error(errorCode, 'tiglRotorBladeGetLocalChord', rotorIndex, rotorBladeIndex, segmentIndex, eta)

        _py_chordPtr = _c_chordPtr.value

        return _py_chordPtr



    def rotorBladeGetLocalTwistAngle(self, rotorIndex, rotorBladeIndex, segmentIndex, eta):
        # input arg conversion
        _c_rotorIndex = ctypes.c_int(rotorIndex)
        _c_rotorBladeIndex = ctypes.c_int(rotorBladeIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_twistAnglePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglRotorBladeGetLocalTwistAngle(self._handle, _c_rotorIndex, _c_rotorBladeIndex, _c_segmentIndex, _c_eta, ctypes.byref(_c_twistAnglePtr))
        catch_error(errorCode, 'tiglRotorBladeGetLocalTwistAngle', rotorIndex, rotorBladeIndex, segmentIndex, eta)

        _py_twistAnglePtr = _c_twistAnglePtr.value

        return _py_twistAnglePtr



    def intersectComponents(self, componentUidOne, componentUidTwo):
        # input arg conversion
        _c_componentUidOne = ctypes.c_char_p(encode_for_c(componentUidOne))
        _c_componentUidTwo = ctypes.c_char_p(encode_for_c(componentUidTwo))

        # output arg preparation
        _c_intersectionID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglIntersectComponents(self._handle, _c_componentUidOne, _c_componentUidTwo, ctypes.byref(_c_intersectionID))
        catch_error(errorCode, 'tiglIntersectComponents', componentUidOne, componentUidTwo)

        _py_intersectionID = decode_for_py(_c_intersectionID.value)

        return _py_intersectionID



    def intersectWithPlane(self, componentUid, px, py, pz, nx, ny, nz):
        # input arg conversion
        _c_componentUid = ctypes.c_char_p(encode_for_c(componentUid))
        _c_px = ctypes.c_double(px)
        _c_py = ctypes.c_double(py)
        _c_pz = ctypes.c_double(pz)
        _c_nx = ctypes.c_double(nx)
        _c_ny = ctypes.c_double(ny)
        _c_nz = ctypes.c_double(nz)

        # output arg preparation
        _c_intersectionID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglIntersectWithPlane(self._handle, _c_componentUid, _c_px, _c_py, _c_pz, _c_nx, _c_ny, _c_nz, ctypes.byref(_c_intersectionID))
        catch_error(errorCode, 'tiglIntersectWithPlane', componentUid, px, py, pz, nx, ny, nz)

        _py_intersectionID = decode_for_py(_c_intersectionID.value)

        return _py_intersectionID



    def intersectWithPlaneSegment(self, componentUid, p1x, p1y, p1z, p2x, p2y, p2z, wx, wy, wz):
        # input arg conversion
        _c_componentUid = ctypes.c_char_p(encode_for_c(componentUid))
        _c_p1x = ctypes.c_double(p1x)
        _c_p1y = ctypes.c_double(p1y)
        _c_p1z = ctypes.c_double(p1z)
        _c_p2x = ctypes.c_double(p2x)
        _c_p2y = ctypes.c_double(p2y)
        _c_p2z = ctypes.c_double(p2z)
        _c_wx = ctypes.c_double(wx)
        _c_wy = ctypes.c_double(wy)
        _c_wz = ctypes.c_double(wz)

        # output arg preparation
        _c_intersectionID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglIntersectWithPlaneSegment(self._handle, _c_componentUid, _c_p1x, _c_p1y, _c_p1z, _c_p2x, _c_p2y, _c_p2z, _c_wx, _c_wy, _c_wz, ctypes.byref(_c_intersectionID))
        catch_error(errorCode, 'tiglIntersectWithPlaneSegment', componentUid, p1x, p1y, p1z, p2x, p2y, p2z, wx, wy, wz)

        _py_intersectionID = decode_for_py(_c_intersectionID.value)

        return _py_intersectionID



    def getCurveIntersection(self, curvesID1, curve1Idx, curvesID2, curve2Idx, tolerance):
        # input arg conversion
        _c_curvesID1 = ctypes.c_char_p(encode_for_c(curvesID1))
        _c_curve1Idx = ctypes.c_int(curve1Idx)
        _c_curvesID2 = ctypes.c_char_p(encode_for_c(curvesID2))
        _c_curve2Idx = ctypes.c_int(curve2Idx)
        _c_tolerance = ctypes.c_double(tolerance)

        # output arg preparation
        _c_intersectionID = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglGetCurveIntersection(self._handle, _c_curvesID1, _c_curve1Idx, _c_curvesID2, _c_curve2Idx, _c_tolerance, ctypes.byref(_c_intersectionID))
        catch_error(errorCode, 'tiglGetCurveIntersection', curvesID1, curve1Idx, curvesID2, curve2Idx, tolerance)

        _py_intersectionID = decode_for_py(_c_intersectionID.value)

        return _py_intersectionID



    def intersectGetLineCount(self, intersectionID):
        # input arg conversion
        _c_intersectionID = ctypes.c_char_p(encode_for_c(intersectionID))

        # output arg preparation
        _c_lineCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglIntersectGetLineCount(self._handle, _c_intersectionID, ctypes.byref(_c_lineCount))
        catch_error(errorCode, 'tiglIntersectGetLineCount', intersectionID)

        _py_lineCount = _c_lineCount.value

        return _py_lineCount



    def getCurveIntersectionCount(self, intersectionID):
        # input arg conversion
        _c_intersectionID = ctypes.c_char_p(encode_for_c(intersectionID))

        # output arg preparation
        _c_pointCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglGetCurveIntersectionCount(self._handle, _c_intersectionID, ctypes.byref(_c_pointCount))
        catch_error(errorCode, 'tiglGetCurveIntersectionCount', intersectionID)

        _py_pointCount = _c_pointCount.value

        return _py_pointCount



    def intersectGetPoint(self, intersectionID, lineIdx, eta):
        # input arg conversion
        _c_intersectionID = ctypes.c_char_p(encode_for_c(intersectionID))
        _c_lineIdx = ctypes.c_int(lineIdx)
        _c_eta = ctypes.c_double(eta)

        # output arg preparation
        _c_pointX = ctypes.c_double()
        _c_pointY = ctypes.c_double()
        _c_pointZ = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglIntersectGetPoint(self._handle, _c_intersectionID, _c_lineIdx, _c_eta, ctypes.byref(_c_pointX), ctypes.byref(_c_pointY), ctypes.byref(_c_pointZ))
        catch_error(errorCode, 'tiglIntersectGetPoint', intersectionID, lineIdx, eta)

        _py_pointX = _c_pointX.value
        _py_pointY = _c_pointY.value
        _py_pointZ = _c_pointZ.value

        return (_py_pointX, _py_pointY, _py_pointZ)



    def getCurveIntersectionPoint(self, intersectionID, pointIdx):
        # input arg conversion
        _c_intersectionID = ctypes.c_char_p(encode_for_c(intersectionID))
        _c_pointIdx = ctypes.c_int(pointIdx)

        # output arg preparation
        _c_pointX = ctypes.c_double()
        _c_pointY = ctypes.c_double()
        _c_pointZ = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglGetCurveIntersectionPoint(self._handle, _c_intersectionID, _c_pointIdx, ctypes.byref(_c_pointX), ctypes.byref(_c_pointY), ctypes.byref(_c_pointZ))
        catch_error(errorCode, 'tiglGetCurveIntersectionPoint', intersectionID, pointIdx)

        _py_pointX = _c_pointX.value
        _py_pointY = _c_pointY.value
        _py_pointZ = _c_pointZ.value

        return (_py_pointX, _py_pointY, _py_pointZ)



    def getCurveParameter(self, curveID, curveIdx, pointX, pointY, pointZ):
        # input arg conversion
        _c_curveID = ctypes.c_char_p(encode_for_c(curveID))
        _c_curveIdx = ctypes.c_int(curveIdx)
        _c_pointX = ctypes.c_double(pointX)
        _c_pointY = ctypes.c_double(pointY)
        _c_pointZ = ctypes.c_double(pointZ)

        # output arg preparation
        _c_eta = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglGetCurveParameter(self._handle, _c_curveID, _c_curveIdx, _c_pointX, _c_pointY, _c_pointZ, ctypes.byref(_c_eta))
        catch_error(errorCode, 'tiglGetCurveParameter', curveID, curveIdx, pointX, pointY, pointZ)

        _py_eta = _c_eta.value

        return _py_eta



    def exportIGES(self, filenamePtr):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))

        # call to native function
        errorCode = self.lib.tiglExportIGES(self._handle, _c_filenamePtr)
        catch_error(errorCode, 'tiglExportIGES', filenamePtr)



    def exportFusedWingFuselageIGES(self, filenamePtr):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))

        # call to native function
        errorCode = self.lib.tiglExportFusedWingFuselageIGES(self._handle, _c_filenamePtr)
        catch_error(errorCode, 'tiglExportFusedWingFuselageIGES', filenamePtr)



    def exportSTEP(self, filenamePtr):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))

        # call to native function
        errorCode = self.lib.tiglExportSTEP(self._handle, _c_filenamePtr)
        catch_error(errorCode, 'tiglExportSTEP', filenamePtr)



    def exportFusedSTEP(self, filenamePtr):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))

        # call to native function
        errorCode = self.lib.tiglExportFusedSTEP(self._handle, _c_filenamePtr)
        catch_error(errorCode, 'tiglExportFusedSTEP', filenamePtr)



    def exportMeshedWingSTL(self, wingIndex, filenamePtr, deflection):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedWingSTL(self._handle, _c_wingIndex, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedWingSTL', wingIndex, filenamePtr, deflection)



    def exportMeshedWingSTLByUID(self, wingUID, filenamePtr, deflection):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedWingSTLByUID(self._handle, _c_wingUID, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedWingSTLByUID', wingUID, filenamePtr, deflection)



    def exportMeshedFuselageSTL(self, fuselageIndex, filenamePtr, deflection):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedFuselageSTL(self._handle, _c_fuselageIndex, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedFuselageSTL', fuselageIndex, filenamePtr, deflection)



    def exportMeshedFuselageSTLByUID(self, fuselageUID, filenamePtr, deflection):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedFuselageSTLByUID(self._handle, _c_fuselageUID, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedFuselageSTLByUID', fuselageUID, filenamePtr, deflection)



    def exportMeshedGeometrySTL(self, filenamePtr, deflection):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedGeometrySTL(self._handle, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedGeometrySTL', filenamePtr, deflection)



    def exportVTKSetOptions(self, key, value):
        # input arg conversion
        _c_key = ctypes.c_char_p(encode_for_c(key))
        _c_value = ctypes.c_char_p(encode_for_c(value))

        # call to native function
        errorCode = self.lib.tiglExportVTKSetOptions(_c_key, _c_value)
        catch_error(errorCode, 'tiglExportVTKSetOptions', key, value)



    def exportMeshedWingVTKByIndex(self, wingIndex, filenamePtr, deflection):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedWingVTKByIndex(self._handle, _c_wingIndex, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedWingVTKByIndex', wingIndex, filenamePtr, deflection)



    def exportMeshedWingVTKByUID(self, wingUID, filenamePtr, deflection):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedWingVTKByUID(self._handle, _c_wingUID, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedWingVTKByUID', wingUID, filenamePtr, deflection)



    def exportMeshedFuselageVTKByIndex(self, fuselageIndex, filenamePtr, deflection):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedFuselageVTKByIndex(self._handle, _c_fuselageIndex, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedFuselageVTKByIndex', fuselageIndex, filenamePtr, deflection)



    def exportMeshedFuselageVTKByUID(self, fuselageUID, filenamePtr, deflection):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedFuselageVTKByUID(self._handle, _c_fuselageUID, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedFuselageVTKByUID', fuselageUID, filenamePtr, deflection)



    def exportMeshedGeometryVTK(self, filenamePtr, deflection):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedGeometryVTK(self._handle, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedGeometryVTK', filenamePtr, deflection)



    def exportMeshedWingVTKSimpleByUID(self, wingUID, filenamePtr, deflection):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedWingVTKSimpleByUID(self._handle, _c_wingUID, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedWingVTKSimpleByUID', wingUID, filenamePtr, deflection)



    def exportMeshedGeometryVTKSimple(self, filenamePtr, deflection):
        # input arg conversion
        _c_filenamePtr = ctypes.c_char_p(encode_for_c(filenamePtr))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportMeshedGeometryVTKSimple(self._handle, _c_filenamePtr, _c_deflection)
        catch_error(errorCode, 'tiglExportMeshedGeometryVTKSimple', filenamePtr, deflection)



    def exportFuselageColladaByUID(self, fuselageUID, filename, deflection):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))
        _c_filename = ctypes.c_char_p(encode_for_c(filename))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportFuselageColladaByUID(self._handle, _c_fuselageUID, _c_filename, _c_deflection)
        catch_error(errorCode, 'tiglExportFuselageColladaByUID', fuselageUID, filename, deflection)



    def exportWingColladaByUID(self, wingUID, filename, deflection):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))
        _c_filename = ctypes.c_char_p(encode_for_c(filename))
        _c_deflection = ctypes.c_double(deflection)

        # call to native function
        errorCode = self.lib.tiglExportWingColladaByUID(self._handle, _c_wingUID, _c_filename, _c_deflection)
        catch_error(errorCode, 'tiglExportWingColladaByUID', wingUID, filename, deflection)



    def exportFusedBREP(self, filename):
        # input arg conversion
        _c_filename = ctypes.c_char_p(encode_for_c(filename))

        # call to native function
        errorCode = self.lib.tiglExportFusedBREP(self._handle, _c_filename)
        catch_error(errorCode, 'tiglExportFusedBREP', filename)



    def exportFuselageBREPByUID(self, fuselageUID, filename):
        # input arg conversion
        _c_fuselageUID = ctypes.c_char_p(encode_for_c(fuselageUID))
        _c_filename = ctypes.c_char_p(encode_for_c(filename))

        # call to native function
        errorCode = self.lib.tiglExportFuselageBREPByUID(self._handle, _c_fuselageUID, _c_filename)
        catch_error(errorCode, 'tiglExportFuselageBREPByUID', fuselageUID, filename)



    def exportWingBREPByUID(self, wingUID, filename):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))
        _c_filename = ctypes.c_char_p(encode_for_c(filename))

        # call to native function
        errorCode = self.lib.tiglExportWingBREPByUID(self._handle, _c_wingUID, _c_filename)
        catch_error(errorCode, 'tiglExportWingBREPByUID', wingUID, filename)



    def wingComponentSegmentGetMaterialCount(self, compSegmentUID, structureType, eta, xsi):
        # input arg conversion
        _c_compSegmentUID = ctypes.c_char_p(encode_for_c(compSegmentUID))
        _c_structureType = ctypes.c_int(structureType)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)

        # output arg preparation
        _c_materialCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetMaterialCount(self._handle, _c_compSegmentUID, _c_structureType, _c_eta, _c_xsi, ctypes.byref(_c_materialCount))
        catch_error(errorCode, 'tiglWingComponentSegmentGetMaterialCount', compSegmentUID, structureType, eta, xsi)

        _py_materialCount = _c_materialCount.value

        return _py_materialCount



    def wingComponentSegmentGetMaterialUID(self, compSegmentUID, structureType, eta, xsi, materialIndex):
        # input arg conversion
        _c_compSegmentUID = ctypes.c_char_p(encode_for_c(compSegmentUID))
        _c_structureType = ctypes.c_int(structureType)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)
        _c_materialIndex = ctypes.c_int(materialIndex)

        # output arg preparation
        _c_uid = ctypes.c_char_p()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetMaterialUID(self._handle, _c_compSegmentUID, _c_structureType, _c_eta, _c_xsi, _c_materialIndex, ctypes.byref(_c_uid))
        catch_error(errorCode, 'tiglWingComponentSegmentGetMaterialUID', compSegmentUID, structureType, eta, xsi, materialIndex)

        _py_uid = decode_for_py(_c_uid.value)

        return _py_uid



    def wingComponentSegmentGetMaterialThickness(self, compSegmentUID, structureType, eta, xsi, materialIndex):
        # input arg conversion
        _c_compSegmentUID = ctypes.c_char_p(encode_for_c(compSegmentUID))
        _c_structureType = ctypes.c_int(structureType)
        _c_eta = ctypes.c_double(eta)
        _c_xsi = ctypes.c_double(xsi)
        _c_materialIndex = ctypes.c_int(materialIndex)

        # output arg preparation
        _c_thickness = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingComponentSegmentGetMaterialThickness(self._handle, _c_compSegmentUID, _c_structureType, _c_eta, _c_xsi, _c_materialIndex, ctypes.byref(_c_thickness))
        catch_error(errorCode, 'tiglWingComponentSegmentGetMaterialThickness', compSegmentUID, structureType, eta, xsi, materialIndex)

        _py_thickness = _c_thickness.value

        return _py_thickness



    def fuselageGetVolume(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetVolume(self._handle, _c_fuselageIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglFuselageGetVolume', fuselageIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def wingGetVolume(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetVolume(self._handle, _c_wingIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglWingGetVolume', wingIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def wingGetSegmentVolume(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentVolume(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglWingGetSegmentVolume', wingIndex, segmentIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def fuselageGetSegmentVolume(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_volumePtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSegmentVolume(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_volumePtr))
        catch_error(errorCode, 'tiglFuselageGetSegmentVolume', fuselageIndex, segmentIndex)

        _py_volumePtr = _c_volumePtr.value

        return _py_volumePtr



    def wingGetSurfaceArea(self, wingIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSurfaceArea(self._handle, _c_wingIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglWingGetSurfaceArea', wingIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def fuselageGetSurfaceArea(self, fuselageIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSurfaceArea(self._handle, _c_fuselageIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglFuselageGetSurfaceArea', fuselageIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def wingGetSegmentSurfaceArea(self, wingIndex, segmentIndex):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentSurfaceArea(self._handle, _c_wingIndex, _c_segmentIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglWingGetSegmentSurfaceArea', wingIndex, segmentIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def wingGetSegmentUpperSurfaceAreaTrimmed(self, wingIndex, segmentIndex, eta1, xsi1, eta2, xsi2, eta3, xsi3, eta4, xsi4):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta1 = ctypes.c_double(eta1)
        _c_xsi1 = ctypes.c_double(xsi1)
        _c_eta2 = ctypes.c_double(eta2)
        _c_xsi2 = ctypes.c_double(xsi2)
        _c_eta3 = ctypes.c_double(eta3)
        _c_xsi3 = ctypes.c_double(xsi3)
        _c_eta4 = ctypes.c_double(eta4)
        _c_xsi4 = ctypes.c_double(xsi4)

        # output arg preparation
        _c_surfaceArea = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentUpperSurfaceAreaTrimmed(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta1, _c_xsi1, _c_eta2, _c_xsi2, _c_eta3, _c_xsi3, _c_eta4, _c_xsi4, ctypes.byref(_c_surfaceArea))
        catch_error(errorCode, 'tiglWingGetSegmentUpperSurfaceAreaTrimmed', wingIndex, segmentIndex, eta1, xsi1, eta2, xsi2, eta3, xsi3, eta4, xsi4)

        _py_surfaceArea = _c_surfaceArea.value

        return _py_surfaceArea



    def wingGetSegmentLowerSurfaceAreaTrimmed(self, wingIndex, segmentIndex, eta1, xsi1, eta2, xsi2, eta3, xsi3, eta4, xsi4):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)
        _c_eta1 = ctypes.c_double(eta1)
        _c_xsi1 = ctypes.c_double(xsi1)
        _c_eta2 = ctypes.c_double(eta2)
        _c_xsi2 = ctypes.c_double(xsi2)
        _c_eta3 = ctypes.c_double(eta3)
        _c_xsi3 = ctypes.c_double(xsi3)
        _c_eta4 = ctypes.c_double(eta4)
        _c_xsi4 = ctypes.c_double(xsi4)

        # output arg preparation
        _c_surfaceArea = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSegmentLowerSurfaceAreaTrimmed(self._handle, _c_wingIndex, _c_segmentIndex, _c_eta1, _c_xsi1, _c_eta2, _c_xsi2, _c_eta3, _c_xsi3, _c_eta4, _c_xsi4, ctypes.byref(_c_surfaceArea))
        catch_error(errorCode, 'tiglWingGetSegmentLowerSurfaceAreaTrimmed', wingIndex, segmentIndex, eta1, xsi1, eta2, xsi2, eta3, xsi3, eta4, xsi4)

        _py_surfaceArea = _c_surfaceArea.value

        return _py_surfaceArea



    def fuselageGetSegmentSurfaceArea(self, fuselageIndex, segmentIndex):
        # input arg conversion
        _c_fuselageIndex = ctypes.c_int(fuselageIndex)
        _c_segmentIndex = ctypes.c_int(segmentIndex)

        # output arg preparation
        _c_surfaceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglFuselageGetSegmentSurfaceArea(self._handle, _c_fuselageIndex, _c_segmentIndex, ctypes.byref(_c_surfaceAreaPtr))
        catch_error(errorCode, 'tiglFuselageGetSegmentSurfaceArea', fuselageIndex, segmentIndex)

        _py_surfaceAreaPtr = _c_surfaceAreaPtr.value

        return _py_surfaceAreaPtr



    def wingGetReferenceArea(self, wingIndex, symPlane):
        # input arg conversion
        _c_wingIndex = ctypes.c_int(wingIndex)
        _c_symPlane = ctypes.c_int(symPlane)

        # output arg preparation
        _c_referenceAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetReferenceArea(self._handle, _c_wingIndex, _c_symPlane, ctypes.byref(_c_referenceAreaPtr))
        catch_error(errorCode, 'tiglWingGetReferenceArea', wingIndex, symPlane)

        _py_referenceAreaPtr = _c_referenceAreaPtr.value

        return _py_referenceAreaPtr



    def wingGetWettedArea(self, wingUID):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))

        # output arg preparation
        _c_wettedAreaPtr = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetWettedArea(self._handle, _c_wingUID, ctypes.byref(_c_wettedAreaPtr))
        catch_error(errorCode, 'tiglWingGetWettedArea', wingUID)

        _py_wettedAreaPtr = _c_wettedAreaPtr.value

        return _py_wettedAreaPtr



    def profileGetBSplineCount(self, profileUID):
        # input arg conversion
        _c_profileUID = ctypes.c_char_p(encode_for_c(profileUID))

        # output arg preparation
        _c_curveCount = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglProfileGetBSplineCount(self._handle, _c_profileUID, ctypes.byref(_c_curveCount))
        catch_error(errorCode, 'tiglProfileGetBSplineCount', profileUID)

        _py_curveCount = _c_curveCount.value

        return _py_curveCount



    def profileGetBSplineDataSizes(self, profileUID, curveid):
        # input arg conversion
        _c_profileUID = ctypes.c_char_p(encode_for_c(profileUID))
        _c_curveid = ctypes.c_int(curveid)

        # output arg preparation
        _c_degree = ctypes.c_int()
        _c_nControlPoints = ctypes.c_int()
        _c_nKnots = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglProfileGetBSplineDataSizes(self._handle, _c_profileUID, _c_curveid, ctypes.byref(_c_degree), ctypes.byref(_c_nControlPoints), ctypes.byref(_c_nKnots))
        catch_error(errorCode, 'tiglProfileGetBSplineDataSizes', profileUID, curveid)

        _py_degree = _c_degree.value
        _py_nControlPoints = _c_nControlPoints.value
        _py_nKnots = _c_nKnots.value

        return (_py_degree, _py_nControlPoints, _py_nKnots)



    def profileGetBSplineData(self, profileUID, curveid, nControlPoints, nKnots):
        # input arg conversion
        _c_profileUID = ctypes.c_char_p(encode_for_c(profileUID))
        _c_curveid = ctypes.c_int(curveid)
        _c_nControlPoints = ctypes.c_int(nControlPoints)
        _c_nKnots = ctypes.c_int(nKnots)

        # output arg preparation
        cpx_len = 1 * nControlPoints
        _c_cpx = (ctypes.c_double * cpx_len)()
        cpy_len = 1 * nControlPoints
        _c_cpy = (ctypes.c_double * cpy_len)()
        cpz_len = 1 * nControlPoints
        _c_cpz = (ctypes.c_double * cpz_len)()
        knots_len = 1 * nKnots
        _c_knots = (ctypes.c_double * knots_len)()

        # call to native function
        errorCode = self.lib.tiglProfileGetBSplineData(self._handle, _c_profileUID, _c_curveid, _c_nControlPoints, ctypes.byref(_c_cpx), ctypes.byref(_c_cpy), ctypes.byref(_c_cpz), _c_nKnots, ctypes.byref(_c_knots))
        catch_error(errorCode, 'tiglProfileGetBSplineData', profileUID, curveid, nControlPoints, nKnots)

        cpx_array_size = cpx_len
        _py_cpx = tuple(_c_cpx[i] for i in range(cpx_array_size))
        cpy_array_size = cpy_len
        _py_cpy = tuple(_c_cpy[i] for i in range(cpy_array_size))
        cpz_array_size = cpz_len
        _py_cpz = tuple(_c_cpz[i] for i in range(cpz_array_size))
        knots_array_size = knots_len
        _py_knots = tuple(_c_knots[i] for i in range(knots_array_size))

        return (_py_cpx, _py_cpy, _py_cpz, _py_knots)



    def logToFileEnabled(self, filePrefix):
        # input arg conversion
        _c_filePrefix = ctypes.c_char_p(encode_for_c(filePrefix))

        # call to native function
        errorCode = self.lib.tiglLogToFileEnabled(_c_filePrefix)
        catch_error(errorCode, 'tiglLogToFileEnabled', filePrefix)



    def logToFileDisabled(self):

        # call to native function
        errorCode = self.lib.tiglLogToFileDisabled()
        catch_error(errorCode, 'tiglLogToFileDisabled')



    def logSetFileEnding(self, ending):
        # input arg conversion
        _c_ending = ctypes.c_char_p(encode_for_c(ending))

        # call to native function
        errorCode = self.lib.tiglLogSetFileEnding(_c_ending)
        catch_error(errorCode, 'tiglLogSetFileEnding', ending)



    def logSetTimeInFilenameEnabled(self, enabled):
        # input arg conversion
        _c_enabled = ctypes.c_int(enabled)

        # call to native function
        errorCode = self.lib.tiglLogSetTimeInFilenameEnabled(_c_enabled)
        catch_error(errorCode, 'tiglLogSetTimeInFilenameEnabled', enabled)



    def logSetVerbosity(self, level):
        # input arg conversion
        _c_level = ctypes.c_int(level)

        # call to native function
        errorCode = self.lib.tiglLogSetVerbosity(_c_level)
        catch_error(errorCode, 'tiglLogSetVerbosity', level)



    def checkPointInside(self, px, py, pz, componentUID):
        # input arg conversion
        _c_px = ctypes.c_double(px)
        _c_py = ctypes.c_double(py)
        _c_pz = ctypes.c_double(pz)
        _c_componentUID = ctypes.c_char_p(encode_for_c(componentUID))

        # output arg preparation
        _c_isInside = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglCheckPointInside(self._handle, _c_px, _c_py, _c_pz, _c_componentUID, ctypes.byref(_c_isInside))
        catch_error(errorCode, 'tiglCheckPointInside', px, py, pz, componentUID)

        _py_isInside = _c_isInside.value

        return _py_isInside



    def componentGetHashCode(self, componentUID):
        # input arg conversion
        _c_componentUID = ctypes.c_char_p(encode_for_c(componentUID))

        # output arg preparation
        _c_hashCodePtr = ctypes.c_int()

        # call to native function
        errorCode = self.lib.tiglComponentGetHashCode(self._handle, _c_componentUID, ctypes.byref(_c_hashCodePtr))
        catch_error(errorCode, 'tiglComponentGetHashCode', componentUID)

        _py_hashCodePtr = _c_hashCodePtr.value

        return _py_hashCodePtr



    def getErrorString(self, errorCode):
        # input arg conversion
        _c_errorCode = ctypes.c_int(errorCode)

        # call to native function
        self.lib.tiglGetErrorString.restype = ctypes.c_char_p
        _c_ret = self.lib.tiglGetErrorString(_c_errorCode)

        _py_ret = decode_for_py(_c_ret)

        return _py_ret



    def configurationGetLength(self):

        # output arg preparation
        _c_pLength = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglConfigurationGetLength(self._handle, ctypes.byref(_c_pLength))
        catch_error(errorCode, 'tiglConfigurationGetLength')

        _py_pLength = _c_pLength.value

        return _py_pLength



    def wingGetSpan(self, wingUID):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))

        # output arg preparation
        _c_pSpan = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetSpan(self._handle, _c_wingUID, ctypes.byref(_c_pSpan))
        catch_error(errorCode, 'tiglWingGetSpan', wingUID)

        _py_pSpan = _c_pSpan.value

        return _py_pSpan



    def wingGetMAC(self, wingUID):
        # input arg conversion
        _c_wingUID = ctypes.c_char_p(encode_for_c(wingUID))

        # output arg preparation
        _c_mac_chord = ctypes.c_double()
        _c_mac_x = ctypes.c_double()
        _c_mac_y = ctypes.c_double()
        _c_mac_z = ctypes.c_double()

        # call to native function
        errorCode = self.lib.tiglWingGetMAC(self._handle, _c_wingUID, ctypes.byref(_c_mac_chord), ctypes.byref(_c_mac_x), ctypes.byref(_c_mac_y), ctypes.byref(_c_mac_z))
        catch_error(errorCode, 'tiglWingGetMAC', wingUID)

        _py_mac_chord = _c_mac_chord.value
        _py_mac_x = _c_mac_x.value
        _py_mac_y = _c_mac_y.value
        _py_mac_z = _c_mac_z.value

        return (_py_mac_chord, _py_mac_x, _py_mac_y, _py_mac_z)



