#include <std.h>

/* changing to inherit from /d/common *Styx* 12/24/03, last change 3/8/00
inherit "/std/armour";
*/

inherit "/d/common/obj/armour/chain.c";

void create() {
	::create();
	set_name("light chainmail");
	set_short("Light Chainmail");
	set_id(({"chainmail","light chainmail","Light Chainmail"}));
	set_long(
	"This is a suit of light chainmail made especially for the guards of Antioch."+
	"  The armor has been carefully crafted of a combination of mithril and"+
	" silver and is a much lighter weight than normal chainmail."
	);
	set_weight(25);
	set_value(50);
//	set_type("chain");
//	set_limbs(({"torso"}));
//	set_ac(4); regular is 5 and since it says it has mithril, let's let it be as good
	if(!random(5)) {
		set_property("enchantment",1);
	}
}

	