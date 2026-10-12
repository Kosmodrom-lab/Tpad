': ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
': BrushedMenu.inc - Streamlined Resource Menu Background Skinning
': ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

$IFNDEF __BRUSHEDMENU_INC__
$DEFINE __BRUSHEDMENU_INC__

DECLARE IMPORT, GetDCA ALIAS "GetDC"(HWND hWnd), HDC
DECLARE IMPORT, SetMenuA ALIAS "SetMenu"(HWND hWnd, HMENU hMenu), INT

CLASS CBrushedMenuBase
    DECLARE CBrushedMenuBase()
    DECLARE _CBrushedMenuBase()

    DECLARE SetImages(HBITMAP bmp, COLORREF clrTransparent), HBITMAP
    DECLARE SetTextureBrush(HBRUSH hBrush)
    DECLARE AttachMenu(HWND hwnd, HMENU menu)
    DECLARE AssignBitmapIndex(WORD wID, INT index)
    DECLARE SkinSubmenus(HMENU menu)
    DECLARE SetMenuFont(HFONT hFont)

    COLORREF BitmapTransparentColor

    HMENU   m_menu
    HWND    m_hwnd
    HBITMAP m_bmp
    HBRUSH  m_hbrBrushed
    HFONT m_hFont
ENDCLASS

$ENDIF