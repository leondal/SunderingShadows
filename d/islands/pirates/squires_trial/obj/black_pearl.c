#include <std.h>
#include "../squires_trial.h"

inherit OBJECT;

void create()
{
	::create();
	set_name("black pearl");
	set_id( ({"pearl","black pearl"}) );
	set_short("%^BOLD%^%^BLACK%^bl%^BLUE%^a%^BLACK%^ck " +
	"pe%^BLUE%^a%^BLACK%^rl%^RESET%^%^WHITE%^");
	set_long(
	"%^BOLD%^%^BLACK%^This small bl%^BLUE%^a%^BLACK%^ck " +
	"pe%^BLUE%^a%^BLACK%^rl shimmers with some sort of energy " +
	"within.%^RESET%^%^WHITE%^"
	);
	set_weight(1);
	set_value(50);
}