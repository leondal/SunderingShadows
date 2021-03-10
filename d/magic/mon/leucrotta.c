//Coded by the one and only master of monsters...BANE//
#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"leucrotta","Leucrotta", "laeradmon"}));
    set_name("Leucrotta");
    set_short("An ugly Leucrotta");
    set_long(
	"The leucrotta is a creature of ugly appearance and "+
	"temperament that haunts deserted places in search of "+
	"prey. This beast stands a full seven feet tall at the "+
	"shoulders. Its body resembles that of a stag, with a "+
	"leonine tufted tail and cloven hooves. Its head resembles "+
	"that of a huge badger, but with bony jagged bony ridges "+
	"in place of teeth."
    );
    set_body_type("equine");
    set_race("leucrotta");
    set_gender("male");
    set_alignment(6);
    set_size(2);
    set_hd(17,14);  // was 7,14
    set_max_level(25);  // was 15
    set_hp(170);	// was 70
    set_exp(1000);
    set_overall_ac(-5);  // was 3
    set("aggressive",17);
    set_attack_limbs(({"head", "right fore hoof", "left fore hoof"}));
    set_attacks_num(3);   // was 1
    set_base_damage_type("bludgeoning");
    set_damage(3,6);
    set_stats("strength",17);
    set_stats("dexterity",16);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("constitution",12);
    set_stats("charisma",5);
}
