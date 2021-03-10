//Coded by the one and only master of monsters...BANE//
#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"boar","Giant Boar"}));
    set_name("Giant Boar");
    set_short("A Giant Boar");
    set_long(
	"This massive boar stands about 6 feet tall at "+
	"the shoulder. Much like a hog this boar has a "+
	"short snout but has coarser and darker hair. "+
	"Its tail whips back and forth and it scrapes "+
	"the ground with its hooves as it begins a charge "+
	"towards you..."
    );
    set_race("boar");
    set_body_type("equine");
    set_gender("male");
    set_size(3);
    set_hd(7,9);	// was 7,9, laerad changed to 17,9, changing back for this guy
    set_hp(65);   	// was 65
   set_max_level(20);	// was 15
    set_attack_bonus(1); // was 1
    set_exp(200);
    set_overall_ac(5);  // was 5
    set("aggressive",19); // was 15
    set_attack_limbs(({"head", "right fore hoof", "left fore hoof"}));
    set_attacks_num(2);	  // was 1, laerad one had been 3
    set_base_damage_type("bludgeoning");
    set_damage(3,6);
}
