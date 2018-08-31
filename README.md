Build-Status: [![Build Status](https://travis-ci.org/DLR-SC/tigl.svg?branch=master)](https://travis-ci.org/DLR-SC/tigl) [![Build status](https://ci.appveyor.com/api/projects/status/twbrx01mbb043uj5/branch/master?svg=true)](https://ci.appveyor.com/project/rainman110/tigl/branch/master)

[![Anaconda-Server Badge](https://anaconda.org/dlr-sc/tigl/badges/installer/conda.svg)](https://conda.anaconda.org/dlr-sc)

 - Binary Downloads:  https://github.com/DLR-SC/tigl/wiki/Downloads
 - API Documentation: http://tigl.sourceforge.net/Doc/index.html
 - Issue Tracker:     https://github.com/DLR-SC/tigl/issues
 - Wiki:              https://github.com/DLR-SC/tigl/wiki

# About CPACSCreator

The CPACSCreator framework can be used for the computation, the modification 
and processing of aircraft geometries stored inside [CPACS](https://github.com/DLR-LY/CPACS) files.
CPACSCreator is build on top of the [TiGl](https://github.com/DLR-SC/tigl) project. It provides 
the same features as TiGL and add features to edit the CPACS files via high level parameters.   

TiGL offers many geometry related functions such as
 - Point retrieval functions to compute points on the aircraft surface
 - Intersection functions to compute the intersection of the aircraft with planes
 - Export functions for standard CAD file formats (STEP + IGES) or mesh formats, 
   including VTK, Collada, and STL.
 
CPACSCreator offers additional functions as:
  - Computation high level parameters of the wing as the wing aspect ratio, the wing sweep, the wing dihedral, the wing area
  - Modification of CPACS files base on these high level parameters 
  - Modification of airfoils of a wing
  - Standardization of the description of the wing and airfoils
   
   
The TiGL library uses the OpenCASCADE CAD kernel to represent the airplane geometry 
by NURBS surfaces. The library provides external interfaces for C, C++, Python, Java, MATLAB, and FORTRAN.

CPACSCreator provides the new features in a C++ library called CPACSCreatorLib. 
This library use  

TiGL is shipped with the Qt based _TiGL Viewer_ for visualizing aircraft
geometries or viewing CAD files.

![Screenshot of the CPACSCreator Viewer](doc/images/cpacscreator-interface.png)
