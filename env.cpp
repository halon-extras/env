#include <HalonMTA.h>
#include <stdlib.h>

HALON_EXPORT
int Halon_version()
{
	return HALONMTA_PLUGIN_VERSION;
}

void _getenv(HalonHSLContext* hhc, HalonHSLArguments* args, HalonHSLValue* ret)
{
	HalonHSLValue* a;

	char* name_ = nullptr;
	a = HalonMTA_hsl_argument_get(args, 0);
	if (a && HalonMTA_hsl_value_type(a) == HALONMTA_HSL_TYPE_STRING)
		HalonMTA_hsl_value_get(a, HALONMTA_HSL_TYPE_STRING, &name_, nullptr);
	else
	{
		HalonHSLValue* x = HalonMTA_hsl_throw(hhc);
 		HalonMTA_hsl_value_set(x, HALONMTA_HSL_TYPE_EXCEPTION, "Invalid or missing name parameter", 0);
		return;
	}

	char* env = getenv(name_);
	if (env)
		HalonMTA_hsl_value_set(ret, HALONMTA_HSL_TYPE_STRING, env, 0);
}

HALON_EXPORT
bool Halon_hsl_register(HalonHSLRegisterContext* ptr)
{
	HalonMTA_hsl_register_function(ptr, "getenv", &_getenv);
	HalonMTA_hsl_module_register_function(ptr, "getenv", &_getenv);
	return true;
}
