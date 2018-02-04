# Microsoft Developer Studio Project File - Name="wilkscalc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=wilkscalc - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wilkscalc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wilkscalc.mak" CFG="wilkscalc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wilkscalc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "wilkscalc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "wilkscalc - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=fl32.exe
# ADD BASE F90 /I "Release/"
# ADD F90 /I "Release/"
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /Zp1 /MD /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /force

!ELSEIF  "$(CFG)" == "wilkscalc - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
F90=fl32.exe
# ADD BASE F90 /I "Debug/"
# ADD F90 /I "Debug/"
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT LINK32 /force

!ENDIF 

# Begin Target

# Name "wilkscalc - Win32 Release"
# Name "wilkscalc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Calc.cpp
# End Source File
# Begin Source File

SOURCE=.\Men.cpp
# End Source File
# Begin Source File

SOURCE=.\sheet.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\vector.cpp
# End Source File
# Begin Source File

SOURCE=.\vector_sorted.cpp
# End Source File
# Begin Source File

SOURCE=.\wilkscalc.cpp
# End Source File
# Begin Source File

SOURCE=.\Women.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\Calc.h
# End Source File
# Begin Source File

SOURCE=.\Men.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\sheet.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# Begin Source File

SOURCE=.\vector_sorted.h
# End Source File
# Begin Source File

SOURCE=.\wilkscalc.h
# End Source File
# Begin Source File

SOURCE=.\Women.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\wilkscalc.ico
# End Source File
# Begin Source File

SOURCE=.\wilkscalc.rc
# End Source File
# Begin Source File

SOURCE=.\res\wilkscalc.rc2
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Target
# End Project
# Section OLE Controls
# 	{4F5F826A-8AAF-11CE-A77F-08002B2F4E98}
# 	{C932BA85-4374-101B-A56C-00AA003668DC}
# 	{FAEEE760-117E-101B-8933-08002B2F4F5A}
# 	{02A69B00-081B-101B-8933-08002B2F4F5A}
# End Section
# Section wilkscalc : {C932BA85-4374-101B-A56C-00AA003668DC}
# 	0:9:Picture.h:C:\mfc42\nonship\wilkscalc\Picture.h
# 	0:8:Font.cpp:C:\mfc42\nonship\wilkscalc\Font.cpp
# 	0:6:Font.h:C:\mfc42\nonship\wilkscalc\Font.h
# 	0:11:Picture.cpp:C:\mfc42\nonship\wilkscalc\Picture.cpp
# 	0:8:Msmask.h:C:\mfc42\nonship\wilkscalc\Msmask.h
# 	0:10:Msmask.cpp:C:\mfc42\nonship\wilkscalc\Msmask.cpp
# 	2:21:DefaultSinkHeaderFile:msmask.h
# 	2:16:DefaultSinkClass:CMsmask
# End Section
# Section wilkscalc : {4F5F8265-8AAF-11CE-A77F-08002B2F4E98}
# 	2:5:Class:CMcsDsc
# 	2:10:HeaderFile:mcsdsc.h
# 	2:8:ImplFile:mcsdsc.cpp
# End Section
# Section wilkscalc : {FAEEE761-117E-101B-8933-08002B2F4F5A}
# 	2:5:Class:CCbox1Ctrl
# 	2:10:HeaderFile:cboxctrl.h
# 	2:8:ImplFile:cboxctrl.cpp
# End Section
# Section wilkscalc : {FAEEE760-117E-101B-8933-08002B2F4F5A}
# 	0:8:Font.cpp:C:\mfc42\nonship\wilkscalc\Font.cpp
# 	0:9:Picture.h:C:\mfc42\nonship\wilkscalc\Picture.h
# 	0:6:Font.h:C:\mfc42\nonship\wilkscalc\Font.h
# 	0:11:Cbox1Ctrl.h:C:\mfc42\nonship\wilkscalc\Cbox1Ctrl.h
# 	0:11:Picture.cpp:C:\mfc42\nonship\wilkscalc\Picture.cpp
# 	0:13:Cbox1Ctrl.cpp:C:\mfc42\nonship\wilkscalc\Cbox1Ctrl.cpp
# 	2:21:DefaultSinkHeaderFile:cboxctrl.h
# 	2:16:DefaultSinkClass:CCbox1Ctrl
# End Section
# Section wilkscalc : {4F5F826A-8AAF-11CE-A77F-08002B2F4E98}
# 	0:8:Font.cpp:C:\mfc42\nonship\wilkscalc\Font.cpp
# 	0:25:rdoPreparedStatements.cpp:C:\mfc42\nonship\wilkscalc\rdoPreparedStatements.cpp
# 	0:12:rdoColumns.h:C:\mfc42\nonship\wilkscalc\rdoColumns.h
# 	0:13:rdoColumn.cpp:C:\mfc42\nonship\wilkscalc\rdoColumn.cpp
# 	0:14:rdoResultset.h:C:\mfc42\nonship\wilkscalc\rdoResultset.h
# 	0:6:Font.h:C:\mfc42\nonship\wilkscalc\Font.h
# 	0:15:rdoParameters.h:C:\mfc42\nonship\wilkscalc\rdoParameters.h
# 	0:11:rdoColumn.h:C:\mfc42\nonship\wilkscalc\rdoColumn.h
# 	0:10:rdoTable.h:C:\mfc42\nonship\wilkscalc\rdoTable.h
# 	0:8:McsDsc.h:C:\mfc42\nonship\wilkscalc\McsDsc.h
# 	0:23:rdoPreparedStatements.h:C:\mfc42\nonship\wilkscalc\rdoPreparedStatements.h
# 	0:17:rdoConnection.cpp:C:\mfc42\nonship\wilkscalc\rdoConnection.cpp
# 	0:18:rdoEnvironment.cpp:C:\mfc42\nonship\wilkscalc\rdoEnvironment.cpp
# 	0:15:rdoConnection.h:C:\mfc42\nonship\wilkscalc\rdoConnection.h
# 	0:17:rdoParameters.cpp:C:\mfc42\nonship\wilkscalc\rdoParameters.cpp
# 	0:11:rdoTables.h:C:\mfc42\nonship\wilkscalc\rdoTables.h
# 	0:14:rdoParameter.h:C:\mfc42\nonship\wilkscalc\rdoParameter.h
# 	0:14:rdoColumns.cpp:C:\mfc42\nonship\wilkscalc\rdoColumns.cpp
# 	0:10:McsDsc.cpp:C:\mfc42\nonship\wilkscalc\McsDsc.cpp
# 	0:18:rdoConnections.cpp:C:\mfc42\nonship\wilkscalc\rdoConnections.cpp
# 	0:12:rdoTable.cpp:C:\mfc42\nonship\wilkscalc\rdoTable.cpp
# 	0:16:rdoConnections.h:C:\mfc42\nonship\wilkscalc\rdoConnections.h
# 	0:16:rdoEnvironment.h:C:\mfc42\nonship\wilkscalc\rdoEnvironment.h
# 	0:13:rdoTables.cpp:C:\mfc42\nonship\wilkscalc\rdoTables.cpp
# 	0:24:rdoPreparedStatement.cpp:C:\mfc42\nonship\wilkscalc\rdoPreparedStatement.cpp
# 	0:17:rdoResultsets.cpp:C:\mfc42\nonship\wilkscalc\rdoResultsets.cpp
# 	0:16:rdoResultset.cpp:C:\mfc42\nonship\wilkscalc\rdoResultset.cpp
# 	0:15:rdoResultsets.h:C:\mfc42\nonship\wilkscalc\rdoResultsets.h
# 	0:16:rdoParameter.cpp:C:\mfc42\nonship\wilkscalc\rdoParameter.cpp
# 	0:22:rdoPreparedStatement.h:C:\mfc42\nonship\wilkscalc\rdoPreparedStatement.h
# 	2:21:DefaultSinkHeaderFile:mcsdsc.h
# 	2:16:DefaultSinkClass:CMcsDsc
# End Section
# Section wilkscalc : {B541C03A-63BC-11CE-920C-08002B369A33}
# 	2:5:Class:CrdoColumn
# 	2:10:HeaderFile:rdocol.h
# 	2:8:ImplFile:rdocol.cpp
# End Section
# Section wilkscalc : {02A69B01-081B-101B-8933-08002B2F4F5A}
# 	2:5:Class:CLbox1Ctrl
# 	2:10:HeaderFile:lboxctrl.h
# 	2:8:ImplFile:lboxctrl.cpp
# End Section
# Section wilkscalc : {2E746492-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoColumns
# 	2:10:HeaderFile:rdocols.h
# 	2:8:ImplFile:rdocols.cpp
# End Section
# Section wilkscalc : {02A69B00-081B-101B-8933-08002B2F4F5A}
# 	0:8:Font.cpp:C:\mfc42\nonship\wilkscalc\Font.cpp
# 	0:9:Picture.h:C:\mfc42\nonship\wilkscalc\Picture.h
# 	0:6:Font.h:C:\mfc42\nonship\wilkscalc\Font.h
# 	0:11:Picture.cpp:C:\mfc42\nonship\wilkscalc\Picture.cpp
# 	0:11:Lbox1Ctrl.h:C:\mfc42\nonship\wilkscalc\Lbox1Ctrl.h
# 	0:13:Lbox1Ctrl.cpp:C:\mfc42\nonship\wilkscalc\Lbox1Ctrl.cpp
# 	2:21:DefaultSinkHeaderFile:lboxctrl.h
# 	2:16:DefaultSinkClass:CLbox1Ctrl
# End Section
# Section wilkscalc : {C932BA86-4374-101B-A56C-00AA003668DC}
# 	2:5:Class:CMsmask
# 	2:10:HeaderFile:msmask.h
# 	2:8:ImplFile:msmask.cpp
# End Section
# Section wilkscalc : {B541C03D-63BC-11CE-920C-08002B369A33}
# 	2:5:Class:CrdoTable
# 	2:10:HeaderFile:rdotable.h
# 	2:8:ImplFile:rdotable.cpp
# End Section
