// #include <std.h>
// #include "../antioch.h"

inherit "/d/common/obj/armour/padded.c";

void create() {
   ::create();
   set_value(10);
}

/* changing to use the /d/common file *Styx* 12/24/03
inherit "/std/armour";

void create()
{
	::create();
	set_name("padded");
	set_id(({"padded","padded armour","padded armor","armor"}));
	set_short("A suit of padded armor");
	set_long(
	"This is one of the simplest types of armor, crafted from quilted layers"+
	" of cloth and batting. It provides a cushion against blows, but is not"+
	" incredibly good protection. It needs to be washed frequently to prevent"+
	" it from becoming foul with sweat, grime, lice, and fleas. "
	);
	set_weight(10);
	set_value(10);
	set_type("leather");
	set_limbs(({"torso"}));
	set_ac(2);
}
*/