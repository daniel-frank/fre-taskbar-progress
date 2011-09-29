#include <Windows.h>
#include "FlashRuntimeExtensions.h"
#include <ShObjIdl.h>

HWND hWnd;

extern "C"
{
	__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
	__declspec(dllexport) void finalizer(void* extData);
}