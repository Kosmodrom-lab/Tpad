[Tpad.zip](https://github.com/user-attachments/files/33352282/Tpad.zip)

# Tpad

**Tpad** is a fast, lightweight, zero-dependency Win32 text and source code editor built in **IWBasic**. It combines a low-overhead native GDI interface with the power of the Scintilla edit control to provide responsive, low-footprint code editing.

---

## Key Features

* **High-Performance Architecture:** Native Win32 API implementation with zero external runtime requirements.
* **Scintilla Engine:** Full UTF-8 support, line gutter rendering, configurable white-space visibility, caret styles, and margin management.
* **Syntax Highlighting:** Built-in lexer support and keyword sets for:
  * C / C++ (`.c`, `.cpp`, `.h`, `.hpp`, `.rc`)
  * IWBasic / FreeBASIC (`.iwb`, `.inc`, `.bas`)
  * x86 Assembly (`.asm`, `.s`)
  * Python (`.py`, `.pyw`)
* **Custom Theme Engine:** Built-in theme switching (Warm Gruvbox Dark / Classic Solarized Light) using direct BGR Hex color assignments.
* **Memory-Mapped I/O:** Handles large files cleanly with optimized threshold loading.
* **Navigation & Tools:** Bookmark arrays, dynamic ruler display, line search, and custom GDI-skinned UI components.

---

## Configuration

Application preferences, active theme selection, and layout states are automatically saved to `Tpad.ini` on exit:

```ini
[Settings]
ThemeID=1
FontSize=10
FontName=Courier New
