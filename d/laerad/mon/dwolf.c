//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    object ob;
    int level;
    ::create();
    set_id(({"wolf","dire wolf","Wolf","Dire Wolf", "forestmon", "animal"}));
    set_name("Dire Wolf");
    set_short("A Dire Wolf");
    set_long(
	"This is a massive 10 foot long wolf.  Its hair is tangled and dirty.  "+
	"It crouches down when it sees you and snarls angrily.  It looks "+
	"very fearsome."
    );
    set_body_type("quadruped");
    set_race("wolf");
    set_gender("male");
    set_size(2);
    level = 16 + random(10);
    set_hd(level,100);
//    set_hp(85);
//    set_exp(2000);
    set_new_exp(level,"normal");
    set_alignment(5);
    set_overall_ac(0);
    set_property("swarm",1);
    set("aggressive",18);
    set_attack_limbs(({"right forepaw","left forepaw","head"}));
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(1,8);
    set_attack_bonus(1);
    set_moving(1);
    set_speed(100);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }

}
