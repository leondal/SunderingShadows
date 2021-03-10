//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

void create(){
	::create();
	set_name("zombie");
     set_id(({"zombie","undead","monster","walking corpse","corpse"}));
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
	set_overall_ac(-1);
	set_gender("male");
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",13);
	set_stats("charisma",1);
	set_alignment(8);
	set_max_hp(random(20)+145);
	set_hp(query_max_hp());
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,20);
	set("aggressive",25);
	set_property("swarm",1);
//        set_exp(9500);
	set_new_exp(15,"normal");
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}
