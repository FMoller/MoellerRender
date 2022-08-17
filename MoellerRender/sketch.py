import colorama
import os
from math import floor, ceil

def changeFontSize(size=2): #Changes the font size to *size* pixels (kind of, but not really. You'll have to try it to chack if it works for your purpose ;) )
    from ctypes import POINTER, WinDLL, Structure, sizeof, byref
    from ctypes.wintypes import BOOL, SHORT, WCHAR, UINT, ULONG, DWORD, HANDLE

    LF_FACESIZE = 32
    STD_OUTPUT_HANDLE = -11

    class COORD(Structure):
        _fields_ = [
            ("X", SHORT),
            ("Y", SHORT),
        ]

    class CONSOLE_FONT_INFOEX(Structure):
        _fields_ = [
            ("cbSize", ULONG),
            ("nFont", DWORD),
            ("dwFontSize", COORD),
            ("FontFamily", UINT),
            ("FontWeight", UINT),
            ("FaceName", WCHAR * LF_FACESIZE)
        ]

    kernel32_dll = WinDLL("kernel32.dll")

    get_last_error_func = kernel32_dll.GetLastError
    get_last_error_func.argtypes = []
    get_last_error_func.restype = DWORD

    get_std_handle_func = kernel32_dll.GetStdHandle
    get_std_handle_func.argtypes = [DWORD]
    get_std_handle_func.restype = HANDLE

    get_current_console_font_ex_func = kernel32_dll.GetCurrentConsoleFontEx
    get_current_console_font_ex_func.argtypes = [HANDLE, BOOL, POINTER(CONSOLE_FONT_INFOEX)]
    get_current_console_font_ex_func.restype = BOOL

    set_current_console_font_ex_func = kernel32_dll.SetCurrentConsoleFontEx
    set_current_console_font_ex_func.argtypes = [HANDLE, BOOL, POINTER(CONSOLE_FONT_INFOEX)]
    set_current_console_font_ex_func.restype = BOOL

    stdout = get_std_handle_func(STD_OUTPUT_HANDLE)
    font = CONSOLE_FONT_INFOEX()
    font.cbSize = sizeof(CONSOLE_FONT_INFOEX)

    font.dwFontSize.X = size
    font.dwFontSize.Y = size

    set_current_console_font_ex_func(stdout, False, byref(font))

changeFontSize(size=10)
os.system(f'mode con: cols={100} lines={80}')

colorama.init()

ramp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. "


def move (l, c):
    print("\033[%d;%dH" % (l, c), end="")

def point(x, y, value):
    move(y+1,x+1)
    #print((str(y+1),str(2*x +1)))
    r_value = int(value*70)
    try:
        print(ramp[r_value])
    except:
        print("$")
    #move(1,1)

def line(xi,yi,xf,yf,value):
    if xf-xi == 0:
        #print("a")
        for i in range(yf+1-yi):
            yn = yi + i 
            point(xi,yn,value)
    elif yf-yi == 0:
        #print("b")
        for i in range(xf+1-xi):
            xn = xi + i
            point(xn,yi,value)
    else:
        if abs(xf-xi) >= abs(yf-yi):
            #print("c")
            for i in range(xf+1-xi):
                xn = xi+i
                yn = yi + round((yf-yi)*i/(xf-xi))
                point(xn,yn,value)
        else:
            #print("d")
            for i in range(yf+1-yi):
                xn = xi + ceil((xf-xi)*i/(yf-yi))
                yn = yi + i
                #print(xn,yn,i)
                point(xn,yn,value)




#move(10,10)
#print(len(ramp))
#point(4,13,0)
#point(5,10,0.1)
#line(10,10,10,20,0)
#line(10,10,20,20,0)
#line(10,10,20,10,0)
#line(10,10,5,2,0)
line(15,20,25,40,.5)

"""
1,1 -> 0,0 (x,y) 
1,2 -> 1,0 
2,1 -> 0,1
l,c -> c-1, l-1

x,y -> y+1,2(x+1)-1 y+1,2(x+1)
"""