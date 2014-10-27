/* WzdStatic.h : Non-MFC Static Library
 *
 *************************************************************/

#if !defined WZDSTATIC_H
#define WZDSTATIC_H

#ifdef __cplusplus
extern "C" {
#else
#endif  /* __cplusplus */

void WzdMessageBox(LPSTR pszString);
void DestroyWzdWindow(HWND hWnd);
void WzdFunc3(BOOL b);

#ifdef __cplusplus
}
#endif

#endif
