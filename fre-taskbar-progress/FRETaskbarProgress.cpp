#include "FRETaskBarProgress.h"


FREObject setProgress(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
	ITaskbarList3 *pTaskbarList = NULL;
	CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pTaskbarList));

	int32_t value;
	int32_t max;

	FREGetObjectAsInt32(argv[0], &value);
	FREGetObjectAsInt32(argv[1], &max);
		
	pTaskbarList->SetProgressValue(hWnd, value, max);

	return NULL;
}

FREObject setSimpleProgressState(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
	ITaskbarList3 *pTaskbarList = NULL;
	CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pTaskbarList));

	pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_INDETERMINATE);

	return NULL;
}

FREObject setProgressState(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
	ITaskbarList3 *pTaskbarList = NULL;
	CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pTaskbarList));

	int32_t state;
	FREGetObjectAsInt32(argv[0], &state);

	switch(state)
	{
		case 1:
			pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_INDETERMINATE);
		break;

		case 2:
			pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_NORMAL);
		break;

		case 3:
			pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_ERROR);
		break;

		case 4:
			pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_PAUSED);
		break;

		default:
			pTaskbarList->SetProgressState(hWnd, TBPFLAG::TBPF_NOPROGRESS);
		break;
	}

	return NULL;
}

BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
{
    DWORD windowID;
    GetWindowThreadProcessId(hwnd, &windowID);

    if (windowID == lParam)
    {
		hWnd = hwnd;

        return false;
    }

    return true;
}

void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
{
	DWORD processID = GetCurrentProcessId();
	EnumWindows(EnumProc, processID);

	*numFunctions = 3;

	FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

	func[0].name = (const uint8_t*) "setProgress";
	func[0].functionData = NULL;
	func[0].function = &setProgress;

	func[1].name = (const uint8_t*) "setProgressState";
	func[1].functionData = NULL;
	func[1].function = &setProgressState;

	func[2].name = (const uint8_t*) "setSimpleProgressState";
	func[2].functionData = NULL;
	func[2].function = &setSimpleProgressState;

	*functions = func;
}

void contextFinalizer(FREContext ctx)
{
	return;
}

void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
{
	*ctxInitializer = &contextInitializer;
	*ctxFinalizer = &contextFinalizer;
}

void finalizer(void* extData)
{
	return;
}