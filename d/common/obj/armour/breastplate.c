#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
    set_max_dex_bonus(5);
    set_armor_prof("medium");
	set_name("breastplate");
	set_short("A shiny breastplate");
	set_id(({"breastplate","breast plate","shiny breast plate","shiny breastplate"}));
	set_long(
	"This suit of metal armor has been carefully crafted together by an expert smith. "+
	" It covers the torso, leaving the arms free to attack, but also allowing more"+
	" flexibility of movement than other similar armors. "
	);
        set_type("armour");
	set_limbs(({"torso"}));
	set_weight(10);
	set_ac(5);
	set_value(1000);
}

int is_metal() { return 1; }
