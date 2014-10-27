# Microsoft Developer Studio Generated NMAKE File, Based on WzdDllRc.dsp
!IF "$(CFG)" == ""
CFG=WzdDllRc - Win32 Debug
!MESSAGE No configuration specified. Defaulting to WzdDllRc - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WzdDllRc - Win32 Release" && "$(CFG)" != "WzdDllRc - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WzdDllRc.mak" CFG="WzdDllRc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WzdDllRc - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WzdDllRc - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WzdDllRc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\WzdDllRc.dll"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WzdDllRc.obj"
	-@erase "$(INTDIR)\WzdDllRc.pch"
	-@erase "$(INTDIR)\WzdDllRc.res"
	-@erase "$(INTDIR)\WzdDllRx.obj"
	-@erase "$(OUTDIR)\WzdDllRc.dll"
	-@erase "$(OUTDIR)\WzdDllRc.exp"
	-@erase "$(OUTDIR)\WzdDllRc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDllRc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\WzdDllRc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDllRc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\WzdDllRc.pdb" /machine:I386 /def:".\WzdDllRc.def" /out:"$(OUTDIR)\WzdDllRc.dll" /implib:"$(OUTDIR)\WzdDllRc.lib" 
DEF_FILE= \
	".\WzdDllRc.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WzdDllRc.obj" \
	"$(INTDIR)\WzdDllRx.obj" \
	"$(INTDIR)\WzdDllRc.res"

"$(OUTDIR)\WzdDllRc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WzdDllRc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\WzdDllRc.dll"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WzdDllRc.obj"
	-@erase "$(INTDIR)\WzdDllRc.pch"
	-@erase "$(INTDIR)\WzdDllRc.res"
	-@erase "$(INTDIR)\WzdDllRx.obj"
	-@erase "$(OUTDIR)\WzdDllRc.dll"
	-@erase "$(OUTDIR)\WzdDllRc.exp"
	-@erase "$(OUTDIR)\WzdDllRc.ilk"
	-@erase "$(OUTDIR)\WzdDllRc.lib"
	-@erase "$(OUTDIR)\WzdDllRc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDllRc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\WzdDllRc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDllRc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\WzdDllRc.pdb" /debug /machine:I386 /def:".\WzdDllRc.def" /out:"$(OUTDIR)\WzdDllRc.dll" /implib:"$(OUTDIR)\WzdDllRc.lib" /pdbtype:sept 
DEF_FILE= \
	".\WzdDllRc.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WzdDllRc.obj" \
	"$(INTDIR)\WzdDllRx.obj" \
	"$(INTDIR)\WzdDllRc.res"

"$(OUTDIR)\WzdDllRc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("WzdDllRc.dep")
!INCLUDE "WzdDllRc.dep"
!ELSE 
!MESSAGE Warning: cannot find "WzdDllRc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WzdDllRc - Win32 Release" || "$(CFG)" == "WzdDllRc - Win32 Debug"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "WzdDllRc - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDllRc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\WzdDllRc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WzdDllRc - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDllRc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\WzdDllRc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WzdDllRc.cpp

"$(INTDIR)\WzdDllRc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WzdDllRc.pch"


SOURCE=.\WzdDllRc.rc

"$(INTDIR)\WzdDllRc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\WzdDllRx.cpp

"$(INTDIR)\WzdDllRx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WzdDllRc.pch"



!ENDIF 

