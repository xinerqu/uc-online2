/**
 *  Core loader interface for the secondary DLL.
 *  This provides the functions that steam_api.dll will call into.
 *
 *  ~veeλnti<3 2026
 */

#pragma once

#include <Windows.h>
#include <cstdint>

#ifdef UC_CORE_EXPORTS
#define UC_CORE_API __declspec(dllexport)
#else
#define UC_CORE_API __declspec(dllimport)
#endif

extern "C" {

typedef void (WINAPI* UC_Core_Init_t)();
typedef void (WINAPI* UC_Core_Shutdown_t)();
typedef uint32_t (WINAPI* UC_Core_GetAppId_t)();
typedef uint32_t (WINAPI* UC_Core_GetOgAppId_t)();

UC_CORE_API void UC_Core_Init();
UC_CORE_API void UC_Core_Shutdown();

UC_CORE_API uint32_t UC_Core_GetAppId();
UC_CORE_API uint32_t UC_Core_GetOgAppId();
UC_CORE_API bool UC_Core_GetSteamStubEnabled();

UC_CORE_API void UC_Core_SetAppIDEnv();
UC_CORE_API void UC_Core_WriteAppIDFile();

} // extern "C"