#include <std.h>

inherit ARMOUR;

void create() {
	::create();
	set_name("glasses");
	set_id(({ "glasses","spectacles" }));
	set_short("a pair of glasses");
	set_long("A pair of old, wire-framed spectacles.");
	set_type("clothing");
	set_ac(0);
	set_weight(2);
	set_limbs(({ "head" }));
}
