// Chernobog (10/27/20)

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"key","copper key","tutor_1"}));
	set_name("copper key");
	set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^ORANGE%^copper %^BOLD%^%^BLACK%^key%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a simple iron key, with a %^RESET%^%^ORANGE%^copper skull %^BOLD%^%^BLACK%^embossed on the bow.%^RESET%^");
	set_weight(1);
	set_value(0);
}

