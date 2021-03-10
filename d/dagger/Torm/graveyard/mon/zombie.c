#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit F_WANDER;

void create()
{
	::create();
	set_name("zombie");
	set_id(({"zombie","undead","monster","corpse","walking corpse"}));
	set_short("A walking corpse");
	set_long(
	"This walking corpse has flesh falling off of it, what skin"+
	" it has left is a pale grey in color and earth still"+
	" clings to it in places. The eyes are sunken in and"+
	" vacant, it simply obeys the commands of its master. A"+
	" putrid stench comes from it, the smell of a graveyard"+
	" mingled with rotting flesh."
	);
	set_property("undead",1);
	set_hd(13,2);
	set_max_level(20);
	set_race("zombie");
	set_body_type("human");
	set_size(2);
	set_overall_ac(8);
	set_gender("male");
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",1);
	set_stats("charisma",1);
	set_alignment(8);
	set_max_hp(random(20)+45);
	set_hp(query_max_hp());
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(1);
	set_base_damage_type("slashing");
	set_damage(1,10);
	set("aggressive",25);
	set_property("swarm",1);
	set_exp(65);
}
