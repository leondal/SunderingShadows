#include <std.h>
#include "../antioch.h"
inherit "/d/antioch/antioch2/d_animal.c";

void create()
{
	::create();
	set_name("kitten");
	set_id(({"kitten","cute kitten","little kitten"}));
	set_short("A kitten");
	set_long(
	"This is a cute little kitten."
	);
	set_hd(2,1);
	set_max_hp(15);
	set_hp(15);
	set_body_type("quadruped");
	set_race("cat");
	set_gender("female");
	set_alignment(5);
	set_size(1);
	set_attack_limbs(({"right forepaw","left forepaw"}));
	set_damage(1,3);
	set_base_damage_type("slashing");
	set_exp(5);
	set_overall_ac(4);
	set_level(10);
	set_stats("dexterity",25);
	set_value(2);
}
