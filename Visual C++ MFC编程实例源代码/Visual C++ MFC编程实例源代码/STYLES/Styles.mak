# Microsoft Developer Studio Generated NMAKE File, Based on Styles.dsp
!IF "$(CFG)" == ""
CFG=Styles - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Styles - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Styles - Win32 Release" && "$(CFG)" != "Styles - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Styles.mak" CFG="Styles - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Styles - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Styles - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Styles - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Styles.exe"


CLEAN :
	-@erase "$(INTDIR)\AnimtDlg.obj"
	-@erase "$(INTDIR)\BttnDlg.obj"
	-@erase "$(INTDIR)\CalDlg.obj"
	-@erase "$(INTDIR)\Combodlg.obj"
	-@erase "$(INTDIR)\DtTimDlg.obj"
	-@erase "$(INTDIR)\editdlg.obj"
	-@erase "$(INTDIR)\HdrDlg.obj"
	-@erase "$(INTDIR)\LstBxDlg.obj"
	-@erase "$(INTDIR)\LstVwDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Pln1Dlg.obj"
	-@erase "$(INTDIR)\Pln2Dlg.obj"
	-@erase "$(INTDIR)\ProgDlg.obj"
	-@erase "$(INTDIR)\ScrllDlg.obj"
	-@erase "$(INTDIR)\SldrDlg.obj"
	-@erase "$(INTDIR)\spindlg.obj"
	-@erase "$(INTDIR)\StaticDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Styles.obj"
	-@erase "$(INTDIR)\Styles.pch"
	-@erase "$(INTDIR)\Styles.res"
	-@erase "$(INTDIR)\StylsDoc.obj"
	-@erase "$(INTDIR)\StylsVw.obj"
	-@erase "$(INTDIR)\tabdlg.obj"
	-@erase "$(INTDIR)\TestDlg.obj"
	-@erase "$(INTDIR)\TrVwDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XtCmbDlg.obj"
	-@erase "$(OUTDIR)\Styles.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Styles.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Styles.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Styles.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Styles.pdb" /machine:I386 /out:"$(OUTDIR)\Styles.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AnimtDlg.obj" \
	"$(INTDIR)\BttnDlg.obj" \
	"$(INTDIR)\CalDlg.obj" \
	"$(INTDIR)\Combodlg.obj" \
	"$(INTDIR)\DtTimDlg.obj" \
	"$(INTDIR)\editdlg.obj" \
	"$(INTDIR)\XtCmbDlg.obj" \
	"$(INTDIR)\HdrDlg.obj" \
	"$(INTDIR)\LstBxDlg.obj" \
	"$(INTDIR)\LstVwDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Pln1Dlg.obj" \
	"$(INTDIR)\Pln2Dlg.obj" \
	"$(INTDIR)\ProgDlg.obj" \
	"$(INTDIR)\ScrllDlg.obj" \
	"$(INTDIR)\SldrDlg.obj" \
	"$(INTDIR)\spindlg.obj" \
	"$(INTDIR)\StaticDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Styles.obj" \
	"$(INTDIR)\StylsDoc.obj" \
	"$(INTDIR)\StylsVw.obj" \
	"$(INTDIR)\tabdlg.obj" \
	"$(INTDIR)\TestDlg.obj" \
	"$(INTDIR)\TrVwDlg.obj" \
	"$(INTDIR)\Styles.res"

"$(OUTDIR)\Styles.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Styles - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Styles.exe"


CLEAN :
	-@erase "$(INTDIR)\AnimtDlg.obj"
	-@erase "$(INTDIR)\BttnDlg.obj"
	-@erase "$(INTDIR)\CalDlg.obj"
	-@erase "$(INTDIR)\Combodlg.obj"
	-@erase "$(INTDIR)\DtTimDlg.obj"
	-@erase "$(INTDIR)\editdlg.obj"
	-@erase "$(INTDIR)\HdrDlg.obj"
	-@erase "$(INTDIR)\LstBxDlg.obj"
	-@erase "$(INTDIR)\LstVwDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Pln1Dlg.obj"
	-@erase "$(INTDIR)\Pln2Dlg.obj"
	-@erase "$(INTDIR)\ProgDlg.obj"
	-@erase "$(INTDIR)\ScrllDlg.obj"
	-@erase "$(INTDIR)\SldrDlg.obj"
	-@erase "$(INTDIR)\spindlg.obj"
	-@erase "$(INTDIR)\StaticDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Styles.obj"
	-@erase "$(INTDIR)\Styles.pch"
	-@erase "$(INTDIR)\Styles.res"
	-@erase "$(INTDIR)\StylsDoc.obj"
	-@erase "$(INTDIR)\StylsVw.obj"
	-@erase "$(INTDIR)\tabdlg.obj"
	-@erase "$(INTDIR)\TestDlg.obj"
	-@erase "$(INTDIR)\TrVwDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XtCmbDlg.obj"
	-@erase "$(OUTDIR)\Styles.exe"
	-@erase "$(OUTDIR)\Styles.ilk"
	-@erase "$(OUTDIR)\Styles.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\Styles.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Styles.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Styles.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Styles.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Styles.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AnimtDlg.obj" \
	"$(INTDIR)\BttnDlg.obj" \
	"$(INTDIR)\CalDlg.obj" \
	"$(INTDIR)\Combodlg.obj" \
	"$(INTDIR)\DtTimDlg.obj" \
	"$(INTDIR)\editdlg.obj" \
	"$(INTDIR)\XtCmbDlg.obj" \
	"$(INTDIR)\HdrDlg.obj" \
	"$(INTDIR)\LstBxDlg.obj" \
	"$(INTDIR)\LstVwDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Pln1Dlg.obj" \
	"$(INTDIR)\Pln2Dlg.obj" \
	"$(INTDIR)\ProgDlg.obj" \
	"$(INTDIR)\ScrllDlg.obj" \
	"$(INTDIR)\SldrDlg.obj" \
	"$(INTDIR)\spindlg.obj" \
	"$(INTDIR)\StaticDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Styles.obj" \
	"$(INTDIR)\StylsDoc.obj" \
	"$(INTDIR)\StylsVw.obj" \
	"$(INTDIR)\tabdlg.obj" \
	"$(INTDIR)\TestDlg.obj" \
	"$(INTDIR)\TrVwDlg.obj" \
	"$(INTDIR)\Styles.res"

"$(OUTDIR)\Styles.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Styles.dep")
!INCLUDE "Styles.dep"
!ELSE 
!MESSAGE Warning: cannot find "Styles.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Styles - Win32 Release" || "$(CFG)" == "Styles - Win32 Debug"
SOURCE=.\AnimtDlg.cpp

"$(INTDIR)\AnimtDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\BttnDlg.cpp

"$(INTDIR)\BttnDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\CalDlg.cpp

"$(INTDIR)\CalDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\Combodlg.cpp

"$(INTDIR)\Combodlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\DtTimDlg.cpp

"$(INTDIR)\DtTimDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\editdlg.cpp

"$(INTDIR)\editdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\HdrDlg.cpp

"$(INTDIR)\HdrDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\LstBxDlg.cpp

"$(INTDIR)\LstBxDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\LstVwDlg.cpp

"$(INTDIR)\LstVwDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\Pln1Dlg.cpp

"$(INTDIR)\Pln1Dlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\Pln2Dlg.cpp

"$(INTDIR)\Pln2Dlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\ProgDlg.cpp

"$(INTDIR)\ProgDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\ScrllDlg.cpp

"$(INTDIR)\ScrllDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\SldrDlg.cpp

"$(INTDIR)\SldrDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\spindlg.cpp

"$(INTDIR)\spindlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\StaticDlg.cpp

"$(INTDIR)\StaticDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Styles - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Styles.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Styles.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Styles - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\Styles.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Styles.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Styles.cpp

"$(INTDIR)\Styles.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\Styles.rc

"$(INTDIR)\Styles.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StylsDoc.cpp

"$(INTDIR)\StylsDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\StylsVw.cpp

"$(INTDIR)\StylsVw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\tabdlg.cpp

"$(INTDIR)\tabdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\TestDlg.cpp

"$(INTDIR)\TestDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\TrVwDlg.cpp

"$(INTDIR)\TrVwDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"


SOURCE=.\XtCmbDlg.cpp

"$(INTDIR)\XtCmbDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Styles.pch"



!ENDIF 

