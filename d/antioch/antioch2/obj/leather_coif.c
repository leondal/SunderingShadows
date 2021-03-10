#include <std.h>

inherit "/d/common/obj/armour/coif_leather.c";

/* changing to make this the standard /d/common/ item & inherit from it *Styx* 12/24/03
   last change 7/6/01
inherit "/std/armour";

void create() {
	::create();
	set_name("leather coif");
	set_short("A leather coif");
	set_id(({"helm","helmet","A leather coif","leather coif","coif"}));
	set_long(
	"This coif has been made from leather that has been boiled to be especially"+
	" hard. It is round in shape, fitting closely to one's head. It looks"+
	" like it would provide adequate protection."
	);
	set_weight(6);
	set_value(25);
	set_type("leather");
// Must be type leather for thiefs to sneak in.
	set_limbs(({"head"}));
	set_ac(1);
}
*/