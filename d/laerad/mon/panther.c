//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    object ob;
    ::create();
    set_id(({"panther","Panther", "forestmon"}));
    set_name("Panther");
    set_short("A black Panther");
    set_long(
	"The wonderful creature crouched before you is a panther.  Its dark "+
	"black fur glistens in the light while eyes glow a strange green.  "+
	"You notice its teeth and claws look exceptionally sharp as it swishes "+
	"its tail and watches your movements."
    );
    set_body_type("quadruped");
    set_race("cat");
    set_gender("female");
    set_size(2);
    set_hd(10,5);
    set_hp(85);
    set_alignment(5);
    set_overall_ac(0);
    set_exp(1500);
    set("aggressive",18);
    set_property("swarm",1);
    set_base_damage_type("slashing");
    set_attack_limbs(({"head","right forepaw","left forepaw"}));
    set_attacks_num(3);
    set_damage(1,8);
    set_funcs(({"pounce"}));
    set_func_chance(25);
    set_moving(1);
    set_speed(100);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

void pounce(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	tell_object(targ,"%^CYAN%^The Panther pounces on you pinning you to the ground!");
	tell_room(ETO,"%^CYAN%^The Panther pounces on "+targ->query_cap_name()+" pinning "+targ->query_objective()+" to the ground!",targ);
	targ->set_paralyzed(24 - BONUS_D->query_stat_bonus(targ, "strength"),"You are pinned to the ground.");
        return 1;
    }
    tell_object(targ,"%^CYAN%^The Panther leaps at you but you dodge out of the way!");
    tell_room(ETO,"%^CYAN%^The Panther leaps at "+targ->query_cap_name()+" but "+targ->query_subjective()+" dodges out of the way!",targ);
    return 1;
}
