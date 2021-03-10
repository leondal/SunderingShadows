// changed to use the description, etc. from Crystal's one in Antioch *Styx* 12/24/03

#include <std.h>
inherit "/std/armour";

void create() {
	::create();
    set_max_dex_bonus(7);
    set_armor_prof("light");
	set_name("hide");
	set_short("A suit of hide armor");
	set_id(({"hide","armor","hide armor","armour"}));
	set_long(
	"This armor has been prepared from the thick hide of some creature and"+
	" has been double layered for protection.  The hide has been boiled to"+
	" toughen it, which also makes it stiff and harder to move in. "
	);
	set_weight(16);
	set_value(15);
	set_ac(4);
	set_type("leather");
	set_limbs(({"torso"}));
}

int is_metal() { return 0; }

