#include <std.h>
#include "../valley.h"
inherit PARMOUR;

void create()
{
	::create();
	set_name("belt pouch");
	set_id(({"pouch","belt pouch"}));
	set_short("A belt pouch");
	set_long(
	"%^GREEN%^This is a belt pouch that has been dyed a dark"+
	" green shade.%^RESET%^"
	);
	set_weight(3);
	set_value(1);
	set_max_internal_encumbrance(8);
	set_limbs(({"waist"}));
	set_type("clothing");
}

void init()
{
	::init();
	if((int)ETO->query_size() == 1) {
		set_size(1);
		return 1;
	}
	if((int)ETO->query_size() == 2) {
		set_size(2);
	}
	if((int)ETO->query_size() == 3) {
		set_size(3);
	}
}
