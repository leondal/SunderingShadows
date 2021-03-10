//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;

void create(){
    int level;
    ::create();
    set_id(({"bear","ghost","Ghost Bear","Bear", "forestmon","animal"}));
    set_name("Ghost Bear");
    set_short("A Ghost Bear");
    set_long(
	"This is the ancient spirit of a bear.  The creature seems to made "+
	"from the mist itself, almost completely transparent.  It wanders "+
	"through the woods as a lost soul seeking to find its eternal rest."
    );
    set_body_type("quadruped");
    set_race("bear");
    set_gender("male");
    set_size(2);
    level = 16 + random(8);
    set_hd(level,4);
//   set_hp(100);
    if (TO->query_hp() < 150) set_hp(150);
//    set_exp(3000);
    set_new_exp(level,"normal");
    set_alignment(5);
    set_overall_ac(0);
    set("aggressive",1);
    set_attack_limbs(({"right forepaw","left forepaw","head"}));
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(2,6);
    set_achats(2, ({"The Ghost Bear moans loudly.",
          "The Ghost Bear paws at a tree aimlessly.",
          "The Ghost Bear moans loudly.", 1 }) );
    set_moving(1);
    set_speed(120);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case


}
