//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit "/d/laerad/mon/wander/swwander.c";
void create(){
    ::create();
    set_id(({"feyr","Great Feyr","magical beast"}));
    set_name("Great Feyr");
    set_short("A Great Feyr");
    set_long(
	"The Feyr appears as a hunched, humpbacked creature, grim and "+
	"inhuman in appearance. Its hide is mottled and warped like the "+
	"surface of the human brain. The creature is supported by two "+
	"main tentacles which act as legs, and by a handful of other "+
	"tentacled limbs. Massive horizontal jaws line its underside, "+
	" and the forepart of the beast has 5 eyes."
    );
    set_body_type("snake");
    set_race("feyr");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(16,22);
    set_hp(150);
    set_stats("strength",14);
    set_stats("dexterity",14);
    set_exp(7000);
    set_overall_ac(-3);
    set_mob_magic_resistance("average");
    set_property("alignment adjustment",6);
    set_property("swarm",1);
    set("aggressive",20);
    remove_limb("tail");
    remove_limb("mouth");
    add_limb("mouth1", "head", 0, 0, 0);
    add_limb("mouth2", "head", 0, 0, 0);
    add_limb("mouth3", "head", 0, 0, 0);
    add_limb("right foretentacle", "torso", 0, 0, 0);
    add_limb("left foretentacle", "torso", 0, 0, 0,);
    add_limb("tentacle1", "torso", 0, 0, 0);
    add_limb("tentacle2", "torso", 0, 0, 0);
    add_limb("tentacle3", "torso", 0, 0, 0);
    add_limb("tentacle4", "torso", 0, 0, 0);
    set_attack_limbs(({"mouth1","mouth2","mouth3"}));
    set_attacks_num(4);
    set_base_damage_type("piercing");
    set_damage(2,6);
    set_attack_bonus(4);
    set_hit_funcs((["mouth1":(:TO,"fear":),"mouth2":(:TO,"fear":),"mouth3":(:TO,"fear":)]));
    set_funcs(({"runaway"}));
    set_func_chance(15);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void fear(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	tell_object(targ,"%^BOLD%^BLUE%^You are consumed with fear and run for your life!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" is consumed with fear and runs away!",targ);
	targ->run_away();
   	return 1;
    }
    return 1;
}
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO))  return;
    if(random(50) < 3){
	tell_room(ETO,TO->query_cap_name()+"'s body shimmers.");
	TO->set_invis();
    }
}
void runaway(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Feyr emits an aura of fear towards you forcing you to run in terror!");
	tell_room(ETO,"%^BOLD%^BLUE%^The Feyr concentrates on "+targ->query_cap_name()+" forcing "+targ->query_objective()+" to run in terror!",targ);
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	return 1;
    }
    tell_object(targ,"%^BOLD%^BLUE%^The Feyr emits an aura of fear towards you but you resist it!");
    tell_room(ETO,"%^BOLD%^BLUE%^The Feyr concentrates on "+targ->query_cap_name()+" but "+targ->query_subjective()+" is unaffected!",targ);
    return 1;
}
