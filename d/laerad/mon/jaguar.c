//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    object ob;
    int level;
    ::create();
    set_id(({"jaguar","Jaguar", "forestmon" }));
    set_name("Jaguar");
    set_short("A ferocious Jaguar");
    set_long(
	"Standing crouched before you is a large jaguar.  Its body is covered "+
	"in black fur, the muscles underneath are rippling and trembling.  "+
	"It growls at you and prepares for its next meal."
    );
    set_body_type("quadruped");
    set_race("cat");
    set_gender("male");
    set_size(2);
    level = 14 + random(8); 
    set_hd(level,8);
//    set_hp(96);
    if (TO->query_hp() < 125) set_hp(125);
//    set_exp(2400);
    set_new_exp(level,"normal");
    set_alignment(5);
    set_overall_ac(0);
    set("aggressive",18);
    set_property("swarm",1);
    set_attack_limbs(({"right forepaw","left forepaw","head"}));
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(1,10);
    set_funcs(({"dive"}));
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

void dive(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	tell_object(targ,"%^RED%^The Jaguar leaps on you tearing all of its claws across your body!");
	tell_room(ETO,"%^RED%^The Jaguar leaps on "+targ->query_cap_name()+" tearing its claws across "+targ->query_possessive()+" body!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
	targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
	targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
	targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
	return 1;
    }
    tell_object(targ,"%^RED%^The Jaguar leaps at you but misses!");
    tell_room(ETO,"%^RED%^The Jaguar leaps at "+targ->query_cap_name()+" but misses!",targ);
    return 1;
}
