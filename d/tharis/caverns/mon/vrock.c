//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"vrock"}));
    set_name("Vrock");
    set_short("A Vrock");
    set_long(
	"This Vrock standing here is a massive creature, it looks to be "+
	"a cross between a human and a vulture. It stands hunched over "+
	"yet still measuring almost 9 feet. Black feathers cover its huge "+
	"wings and neck. Its legs and arms end in sharp talons. A nasty "+
	"beak protrudes from its head."
    );
    set_body_type("fowl");
    set_race("vrock");
    set_gender("male");
    set_size(2);
    set_hd(10,1);
    set_hp(101);
    set_overall_ac(-5);
    set("aggressive",18);
    set_property("swarm",1);
    set_mob_magic_resistance("average");
    set_exp(17000);
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",14);
    set_stats("wisdom",19);
    set_stats("intelligence",19);
    set_stats("charisma",10);
    set_class("mage");
    set_guild_level("mage",20);
    set_spells(({
	"magic missile",
	"lightning bolt",
	"hideous laughter",
	"dispel magic"
    }));
    set_spell_chance(30);
    add_money("gold",random(1000)+2000);
    set_funcs(({"spores","dance","summon"}));
    set_func_chance(40);
/*
    set_wielding_limbs(({"head","right claw","left claw"}));
    new("/realms/bane/obj/vrclaw")->move(this_object());
    command("wield claw in right claw");
    new("/realms/bane/obj/vrclaw")->move(this_object());
    command("wield claw in left claw");
    new("/realms/bane/obj/vrteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("teeth","head",0,0,0);
    set_damage(1,6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claw","left claw","beak"}));
}
void spores(object targ){
    string dam;
	if("/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	dam="dust";
	} else {
	dam="cover";
    }
    tell_object(targ,"%^BOLD%^GREEN%^The Vrock releases some spores from its body and they "+dam+" you!");
    tell_room(environment(targ),"%^BOLD%^GREEN%^The Vrock releases some spores from its body and they "+dam+" "+targ->query_cap_name()+"!",targ);
    if(dam =="cover"){
	targ->do_damage("torso",roll_dice(4,8));
	targ->add_poisoning(60);
	} else {
	targ->do_damage("torso",((roll_dice(4,8))/2));
	targ->add_poisoning(20);
    }
    return 1;
}
void dance(object targ){
    string dam;
    if("/daemon/saving_d"->saving_throw(targ,"spells")){
	dam="rips";
	} else {
	dam="tears";
    }
    tell_object(targ,"%^BOLD%^BLUE%^The Vrock does a dance of death and its power "+dam+" into you!");
    tell_room(environment(targ),"%^BOLD%^BLUE%^The Vrock does a dance of death and its power "+dam+" into "+targ->query_cap_name()+"!",targ);
    if(dam =="tears"){
	targ->do_damage("torso",roll_dice(4,10));
	} else {
	targ->do_damage("torso",roll_dice(2,10));
    }
    return 1;
}
void summon(object targ){
    "cmds/spells/m/_monster_summoning_ii"->use_spell(TO,targ->query_name(),20,100,"mage");
    return 1;
}
void heart_beat(){
    ::heart_beat();
    if((TO->query_hp()+1)>TO->query_max_hp()){
	TO->set_hp(TO->query_max_hp());
    }
    else TO->add_hp(1);
}
