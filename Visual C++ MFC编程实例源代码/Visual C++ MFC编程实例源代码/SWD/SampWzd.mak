# Microsoft Developer Studio Generated NMAKE File, Based on SampWzd.dsp
!IF "$(CFG)" == ""
CFG=SampleWzd - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SampleWzd - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SampleWzd - Win32 Release" && "$(CFG)" != "SampleWzd - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SampWzd.mak" CFG="SampleWzd - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SampleWzd - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SampleWzd - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "SampleWzd - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\SW.exe"


CLEAN :
	-@erase "$(INTDIR)\DirDlg.obj"
	-@erase "$(INTDIR)\Page1.obj"
	-@erase "$(INTDIR)\Page2.obj"
	-@erase "$(INTDIR)\Page3.obj"
	-@erase "$(INTDIR)\Page4.obj"
	-@erase "$(INTDIR)\Page5.obj"
	-@erase "$(INTDIR)\SampWzd.obj"
	-@erase "$(INTDIR)\SampWzd.pch"
	-@erase "$(INTDIR)\SampWzd.res"
	-@erase "$(INTDIR)\SampWzdS.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\SW.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\SampWzd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SampWzd.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SampWzd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\SW.pdb" /machine:I386 /out:"$(OUTDIR)\SW.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DirDlg.obj" \
	"$(INTDIR)\Page1.obj" \
	"$(INTDIR)\Page2.obj" \
	"$(INTDIR)\Page3.obj" \
	"$(INTDIR)\Page4.obj" \
	"$(INTDIR)\Page5.obj" \
	"$(INTDIR)\SampWzd.obj" \
	"$(INTDIR)\SampWzdS.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SampWzd.res"

"$(OUTDIR)\SW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SampleWzd - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\SW.exe"


CLEAN :
	-@erase "$(INTDIR)\DirDlg.obj"
	-@erase "$(INTDIR)\Page1.obj"
	-@erase "$(INTDIR)\Page2.obj"
	-@erase "$(INTDIR)\Page3.obj"
	-@erase "$(INTDIR)\Page4.obj"
	-@erase "$(INTDIR)\Page5.obj"
	-@erase "$(INTDIR)\SampWzd.obj"
	-@erase "$(INTDIR)\SampWzd.pch"
	-@erase "$(INTDIR)\SampWzd.res"
	-@erase "$(INTDIR)\SampWzdS.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SW.exe"
	-@erase "$(OUTDIR)\SW.ilk"
	-@erase "$(OUTDIR)\SW.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\SampWzd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SampWzd.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SampWzd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\SW.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SW.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DirDlg.obj" \
	"$(INTDIR)\Page1.obj" \
	"$(INTDIR)\Page2.obj" \
	"$(INTDIR)\Page3.obj" \
	"$(INTDIR)\Page4.obj" \
	"$(INTDIR)\Page5.obj" \
	"$(INTDIR)\SampWzd.obj" \
	"$(INTDIR)\SampWzdS.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SampWzd.res"

"$(OUTDIR)\SW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("SampWzd.dep")
!INCLUDE "SampWzd.dep"
!ELSE 
!MESSAGE Warning: cannot find "SampWzd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SampleWzd - Win32 Release" || "$(CFG)" == "SampleWzd - Win32 Debug"
SOURCE=.\DirDlg.cpp

"$(INTDIR)\DirDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\Page1.cpp

"$(INTDIR)\Page1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\Page2.cpp

"$(INTDIR)\Page2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\Page3.cpp

"$(INTDIR)\Page3.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\Page4.cpp

"$(INTDIR)\Page4.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\Page5.cpp

"$(INTDIR)\Page5.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\SampWzd.cpp

"$(INTDIR)\SampWzd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\SampWzd.rc

"$(INTDIR)\SampWzd.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\SampWzdS.cpp

"$(INTDIR)\SampWzdS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SampWzd.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "SampleWzd - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\SampWzd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SampWzd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SampleWzd - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\SampWzd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SampWzd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

