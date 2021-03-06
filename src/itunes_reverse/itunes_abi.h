#ifndef ABI_ITUNES_REVERSE_ITUNES_ABI_H_
#define ABI_ITUNES_REVERSE_ITUNES_ABI_H_
//////////////////////////////////////////////////////////////////////////
#include <string>
#include "ABI/base/basetypes.h"
//////////////////////////////////////////////////////////////////////////
namespace ABI{
	namespace ReverseEngineering{
		std::string AddressCodeOptimize(const char* code);
		unsigned long GetAddress(wchar_t *Abnormal,wchar_t *name,const std::string& sign);
	}
}
//////////////////////////////////////////////////////////////////////////
#endif