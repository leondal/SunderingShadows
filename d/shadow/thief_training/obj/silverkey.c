// Chernobog (10/27/20)

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"key","silver key","tutor_2"}));
	set_name("silver key");
	set_short("%^BOLD%^%^BLACK%^A s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r key%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a simple iron key, with a s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r s%^RESET%^k%^BOLD%^u%^RESET%^l%^BOLD%^%^BLACK%^l embossed on the bow.%^RESET%^");
	set_weight(1);
	set_value(0);
}

