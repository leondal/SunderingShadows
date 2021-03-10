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
	set_value(30000);
	set_id(({ "tattoo", "vine tattoo", "vines" }));
	set_short("%^RESET%^%^ORANGE%^A huge %^GREEN%^t%^ORANGE%^w%^GREEN%^i%^ORANGE%^s%^GREEN%^t%^ORANGE%^i%^GREEN%^n%^ORANGE%^g tattoo of %^GREEN%^vin%^ORANGE%^e%^GREEN%^s%^RESET%^");
