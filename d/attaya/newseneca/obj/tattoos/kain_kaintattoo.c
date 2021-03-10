#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(25000);
	set_id(({ "tattoo", "dark tattoo", "large tattoo", "kain's tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A large, dark tattoo of a %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rp%^BOLD%^l%^RESET%^%^MAGENTA%^e di%^BOLD%^s%^RESET%^%^MAGENTA%^k%^RESET%^");
