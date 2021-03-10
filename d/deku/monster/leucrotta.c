//Coded by the one and only master of monsters...BANE//
//copied with an adapted describe by Styx for Deku

#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"leucrotta","Leucrotta"}));
    set_name("Leucrotta");
    set_short("A small leucrotta");
    set_long("The leucrotta is an ugly creature with an ugly "
     	"temperament that generally haunts deserted places in search of "
      "prey.  This one is probably young, being only about five "
      "feet tall at the shoulders.  Its body resembles that of a stag, with  "
	   "a tufted tail and cloven hooves.  The head resembles that of a huge "
           "badger, but with jagged bony ridges in place of teeth.  They are "
	   "sly and often imitate the sounds of an injured person or animal to "
      "lure prey to striking distance."
    );
    set_body_type("equine");
    set_race("leucrotta");
    set_gender("male");
    set_alignment(5);
    set_size(2);
    set_hd(8,14);
    set_max_level(15);
    set_hp(70);
    set_exp(800);
    set_overall_ac(6);
    set("aggressive",17);
    set("intelligence",15);
    set_attack_limbs(({"head", "right front hoof", "left front hoof"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(3,5);
}
