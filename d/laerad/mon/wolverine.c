//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    object ob;
    ::create();
    set_id(({"wolverine","Wolverine", "forestmon"}));
    set_name("Wolverine");
    set_short("A wild Wolverine");
    set_long(
	"Before you stands a 5 foot long wolverine.  It has grown larger than "+
	"most normal beasts of the same type.  It snarls at you angrily, foam "+
	"and saliva dripping from its mouth.  The hair on its back stands up "+
	"as it prepares for a fight."
    );
    set_body_type("quadruped");
    set_race("wolverine");
    set_gender("male");
    set_size(2);
    set_hd(9,3);
    set_hp(75);
    set_alignment(5);
    set_overall_ac(2);
    set_exp(1100);
    set("aggressive",18);
    set_base_damage_type("slashing");
    set_attack_limbs(({"head","right forepaw","left forepaw"}));
    set_attacks_num(3);
    set_damage(1,6);
    set_funcs(({"frenzy"}));
    set_func_chance(25);
    set_moving(1);
    set_speed(90);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

void frenzy(){
    tell_room(ETO,"%^GREEN%^The Wolverine goes into a frenzy!");
    set_damage_bonus(1);
    set_func_chance(0);
    call_out("calm_down",25,TP);
    return 1;
}
int calm_down(){
    tell_room(ETO,"The Wolverine appears to calm down.");
    set_damage_bonus(0);
    set_func_chance(25);
    return 1;
}
