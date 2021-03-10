//Coded by the one and only master of monsters...BANE//
#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"hyena", "laeradmon"}));
    set_name("hyena");
    set_short("A vicious Hyena");
    set_long(
	"This hyena is an ugly creature indeed.  Roughly the "+
	"size of a large boar, its body is covered with a light "+
	"brown or golden fur.  Its feet, markings, and belly "+
	"are black.  The hyena circles around you waiting to "+
	"pounce."
    );
    set_body_type("quadruped");
    set_race("hyena");
    set_gender("male");
    set_size(2);
    set_alignment(6);   // was 5
    set_hd(15,10);	// was 5,10
    set_max_level(20);  // was 15
    set_hp(150);       // was 50
    set_exp(500);
    set_overall_ac(5);
    set("aggressive",15);
    add_limb("teeth","head", 0, 0, 0);
    set_attack_limbs(({ "teeth" }));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(3,4);
}
