': ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
': BrushedMenu.inc - Streamlined Resource Menu Background Skinning
': ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

$IFNDEF __BRUSHEDMENU_INC__
$DEFINE __BRUSHEDMENU_INC__

CONST BM_MAX_ICON_ID = 200      ' icon maps hold command IDs 0..199
CONST BM_MAX_SLOTS   = 1024     ' owner-draw text/command slots (static menus + dynamic lists)

DECLARE IMPORT, GetDCA ALIAS "GetDC"(HWND hWnd), HDC
DECLARE IMPORT, SetMenuA ALIAS "SetMenu"(HWND hWnd, HMENU hMenu), INT

' Debugging toggle flag
' GLOBAL INT g_Debug

' Standalone Callback & Module Drawing Procedures
DECLARE CBrushedMenu_SubclassProc(hwnd : INT, uMsg : INT, wParam : INT, lParam : INT), INT
DECLARE BM_Measure(hwnd : INT, p : INT, slot : INT)
DECLARE BM_Draw(hwnd : INT, p : INT, slot : INT)
DECLARE BlendHighlightRect(HDC hdc, POINTER pRc, DWORD highlightColor)


CLASS CBrushedMenuBase
    ' Constructor & Destructor
    DECLARE CBrushedMenuBase()
    DECLARE _CBrushedMenuBase()

    ' Public Methods
    DECLARE SetImages(HBITMAP bmp, COLORREF clrTransparent), HBITMAP
    DECLARE SetImageLists(UINT himlHot, UINT himlDisabled)
    DECLARE SetStateBitmaps(HBITMAP bmpHot, HBITMAP bmpDisabled)
    DECLARE SetTextureBrush(HBRUSH hBrush)
    DECLARE AttachMenu(HWND hwnd, HMENU menu)
    DECLARE SkinPopup(HMENU menu)
    DECLARE AssignBitmapIndex(WORD wID, INT index)
    DECLARE SkinSubmenus(HMENU menu)
    DECLARE SetMenuFont(HFONT hFont)
    DECLARE SlotText(INT slot), STRING

    ' Resource-Aware Owner-Draw Extensions
    DECLARE EnableOwnerDraw(HMENU menu)
    DECLARE OnMeasureItem(HWND hwnd, POINTER pLparam)
    DECLARE OnDrawItem(HWND hwnd, POINTER pLparam)
    DECLARE HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam), INT

    ' Internal Icon Mapping Array
    INT     m_iconMap[BM_MAX_ICON_ID]

    ' Byte pool string storage (1024 slots * 96 bytes) and command mappings
    BYTE    m_textPool[98304]
    INT     m_itemCmd[BM_MAX_SLOTS]
    INT     m_nextSlot
    INT     m_baseSlot

    COLORREF BitmapTransparentColor
    HMENU    m_menu
    HWND     m_hwnd
    HBITMAP  m_bmp
    HBRUSH   m_hbrBrushed
    HFONT    m_hFont
ENDCLASS

$ENDIF