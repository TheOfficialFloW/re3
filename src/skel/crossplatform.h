#include <time.h>

#ifdef PSP2

#define GLFW_RELEASE                0
#define GLFW_PRESS                  1

#define GLFW_KEY_D                  68
#define GLFW_KEY_R                  82

#define GLFW_MOUSE_BUTTON_1         0
#define GLFW_MOUSE_BUTTON_2         1
#define GLFW_MOUSE_BUTTON_3         2
#define GLFW_MOUSE_BUTTON_4         3
#define GLFW_MOUSE_BUTTON_5         4
#define GLFW_MOUSE_BUTTON_6         5
#define GLFW_MOUSE_BUTTON_7         6
#define GLFW_MOUSE_BUTTON_8         7
#define GLFW_MOUSE_BUTTON_LAST      GLFW_MOUSE_BUTTON_8
#define GLFW_MOUSE_BUTTON_LEFT      GLFW_MOUSE_BUTTON_1
#define GLFW_MOUSE_BUTTON_RIGHT     GLFW_MOUSE_BUTTON_2
#define GLFW_MOUSE_BUTTON_MIDDLE    GLFW_MOUSE_BUTTON_3

#define GLFW_JOYSTICK_1             0
#define GLFW_JOYSTICK_2             1
#define GLFW_JOYSTICK_3             2
#define GLFW_JOYSTICK_4             3
#define GLFW_JOYSTICK_5             4
#define GLFW_JOYSTICK_6             5
#define GLFW_JOYSTICK_7             6
#define GLFW_JOYSTICK_8             7
#define GLFW_JOYSTICK_9             8
#define GLFW_JOYSTICK_10            9
#define GLFW_JOYSTICK_11            10
#define GLFW_JOYSTICK_12            11
#define GLFW_JOYSTICK_13            12
#define GLFW_JOYSTICK_14            13
#define GLFW_JOYSTICK_15            14
#define GLFW_JOYSTICK_16            15
#define GLFW_JOYSTICK_LAST          GLFW_JOYSTICK_16

#define GLFW_GAMEPAD_BUTTON_A               0
#define GLFW_GAMEPAD_BUTTON_B               1
#define GLFW_GAMEPAD_BUTTON_X               2
#define GLFW_GAMEPAD_BUTTON_Y               3
#define GLFW_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define GLFW_GAMEPAD_BUTTON_BACK            6
#define GLFW_GAMEPAD_BUTTON_START           7
#define GLFW_GAMEPAD_BUTTON_GUIDE           8
#define GLFW_GAMEPAD_BUTTON_LEFT_THUMB      9
#define GLFW_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define GLFW_GAMEPAD_BUTTON_DPAD_UP         11
#define GLFW_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define GLFW_GAMEPAD_BUTTON_DPAD_DOWN       13
#define GLFW_GAMEPAD_BUTTON_DPAD_LEFT       14
#define GLFW_GAMEPAD_BUTTON_LAST            GLFW_GAMEPAD_BUTTON_DPAD_LEFT

#define GLFW_GAMEPAD_BUTTON_CROSS       GLFW_GAMEPAD_BUTTON_A
#define GLFW_GAMEPAD_BUTTON_CIRCLE      GLFW_GAMEPAD_BUTTON_B
#define GLFW_GAMEPAD_BUTTON_SQUARE      GLFW_GAMEPAD_BUTTON_X
#define GLFW_GAMEPAD_BUTTON_TRIANGLE    GLFW_GAMEPAD_BUTTON_Y

#define GLFW_GAMEPAD_AXIS_LEFT_X        0
#define GLFW_GAMEPAD_AXIS_LEFT_Y        1
#define GLFW_GAMEPAD_AXIS_RIGHT_X       2
#define GLFW_GAMEPAD_AXIS_RIGHT_Y       3
#define GLFW_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define GLFW_GAMEPAD_AXIS_LAST          GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER

#define GLFW_CURSOR                 0x00033001
#define GLFW_CURSOR_HIDDEN          0x00034002
#define GLFW_CURSOR_DISABLED        0x00034003

typedef struct GLFWgamepadstate
{
    unsigned char buttons[15];
    float axes[6];
} GLFWgamepadstate;

typedef struct GLFWvidmode
{
	int width;
	int height;
} GLFWvidmode;

typedef void GLFWmonitor;
typedef void GLFWwindow;

GLFWmonitor* glfwGetPrimaryMonitor(void);
int glfwWindowShouldClose(GLFWwindow* window);
const GLFWvidmode* glfwGetVideoMode(GLFWmonitor* monitor);
int glfwGetKey(GLFWwindow* window, int key);
int glfwGetMouseButton(GLFWwindow* window, int button);
void glfwGetCursorPos(GLFWwindow* window, double* xpos, double* ypos);
void glfwSetCursorPos(GLFWwindow* window, double xpos, double ypos);
int glfwJoystickPresent(int jid);
float* glfwGetJoystickAxes(int jid, int* count);
unsigned char* glfwGetJoystickButtons(int jid, int* count);
int glfwJoystickIsGamepad(int jid);
const char* glfwGetJoystickName(int jid);
int glfwGetGamepadState(int jid, GLFWgamepadstate* state);
void glfwSetInputMode(GLFWwindow* handle, int mode, int value);

#define CLOCK_MONOTONIC 0

int clock_gettime(int clk_id, struct timespec *tp);

#define PATH_MAX 1024
#define NAME_MAX 255

int lstat(const char *path, struct stat *buf);
char *realpath(const char *path, char *resolved_path);

#endif

// This is the common include for platform/renderer specific skeletons(glfw.cpp, win.cpp etc.) and using cross platform things (like Windows directories wrapper, platform specific global arrays etc.) 
// Functions that's different on glfw and win but have same signature, should be located on platform.h.

enum eWinVersion
{
    OS_WIN95 = 0,
    OS_WIN98,
    OS_WINNT,
    OS_WIN2000,
    OS_WINXP,
};

#ifdef _WIN32

// As long as WITHWINDOWS isn't defined / <Windows.h> isn't included, we only need type definitions so let's include <IntSafe.h>.
// NOTE: It's perfectly fine to include <Windows.h> here, but it can increase build size and time in *some* conditions, and maybe substantially in future if we'll use crossplatform.h more.
#ifndef _INC_WINDOWS
	#ifndef __MWERKS__
		#include <IntSafe.h>
	#else
		#include <Windows.h>
	#endif
#endif
#if defined RW_D3D9 || defined RWLIBS
#include "win.h"
#endif
extern DWORD _dwOperatingSystemVersion;
#define fcaseopen fopen
#else
char *strupr(char *str);
char *strlwr(char *str);

enum {
	LANG_OTHER,
	LANG_GERMAN,
	LANG_FRENCH,
	LANG_ENGLISH,
	LANG_ITALIAN,
	LANG_SPANISH,
};

enum {
	SUBLANG_OTHER,
	SUBLANG_ENGLISH_AUS
};

extern long _dwOperatingSystemVersion;
char *casepath(char const *path, bool checkPathFirst = true);
FILE *_fcaseopen(char const *filename, char const *mode);
#define fcaseopen _fcaseopen
#endif

#ifdef RW_GL3
typedef struct
{
    GLFWwindow* window;
    RwBool		fullScreen;
    RwV2d		lastMousePos;
    double      mouseWheel; // glfw doesn't cache it
    bool        cursorIsInWindow;
    RwInt8        joy1id;
    RwInt8        joy2id;
}
psGlobalType;

#define PSGLOBAL(var) (((psGlobalType *)(RsGlobal.ps))->var)

void CapturePad(RwInt32 padID);
void joysChangeCB(int jid, int event);
#endif

#ifdef DETECT_JOYSTICK_MENU
extern char gSelectedJoystickName[128];
#endif

enum eGameState
{
    GS_START_UP = 0,
    GS_INIT_LOGO_MPEG,
    GS_LOGO_MPEG,
    GS_INIT_INTRO_MPEG,
    GS_INTRO_MPEG,
    GS_INIT_ONCE,
    GS_INIT_FRONTEND,
    GS_FRONTEND,
    GS_INIT_PLAYING_GAME,
    GS_PLAYING_GAME,
};
extern RwUInt32 gGameState;

RwBool IsForegroundApp();

#ifndef MAX_PATH
    #if !defined _WIN32 || defined __MINGW32__
    #define MAX_PATH PATH_MAX
    #else
    #define MAX_PATH 260
    #endif
#endif

// Codes compatible with Windows and Linux
#ifndef _WIN32
#define DeleteFile unlink

// Needed for save games
struct SYSTEMTIME {
    RwUInt16 wYear;
    RwUInt16 wMonth;
    RwUInt16 wDayOfWeek;
    RwUInt16 wDay;
    RwUInt16 wHour;
    RwUInt16 wMinute;
    RwUInt16 wSecond;
    RwUInt16 wMilliseconds;
};

void GetLocalTime_CP(SYSTEMTIME* out);
#define GetLocalTime GetLocalTime_CP
#define OutputDebugString(s) re3_debug("[DBG-2]: %s\n",s)
#endif

// Compatible with Linux/POSIX and MinGW on Windows
#ifndef _WIN32
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <langinfo.h>
#include <unistd.h>

typedef void* HANDLE;
#define INVALID_HANDLE_VALUE NULL
#define FindClose(h) closedir((DIR*)h)
#define LOCALE_USER_DEFAULT 0
#define DATE_SHORTDATE 0

struct WIN32_FIND_DATA {
    char extension[32]; // for searching
    char folder[32];	// for searching
    char cFileName[256]; // because tSkinInfo has it 256
    time_t ftLastWriteTime;
};

HANDLE FindFirstFile(const char*, WIN32_FIND_DATA*);
bool FindNextFile(HANDLE, WIN32_FIND_DATA*);
void FileTimeToSystemTime(time_t*, SYSTEMTIME*);
void GetDateFormat(int, int, SYSTEMTIME*, int, char*, int);
#endif
