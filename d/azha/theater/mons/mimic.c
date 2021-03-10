#include <std.h>
#include "../theater.h"

inherit WEAPONLESS;
      void create(){
      object obj; 
      ::create();
	set_name("mimic");
	set_id(({"mimic", "monster", "theater_mon"}));
	set_short("A mimic");
	set_long("%^GREEN%^Able to assume the form of mundane"+
		" everyday objects, mimics offer a vicious surprise to"+
		" the curious or nosey. Because they are a shapeshifter"+
		" race, a mimic is able to create pseudo-arms when they "+
		"are ready to attack.  It is as this point as well that "+
		"they reveal a large %^RED%^mouth%^GREEN%^ in the center"+
		" of their 'torso'.  These carnivorous creatures have "+
		"sharp teeth that allow them to rend the flesh off of "+
		"their prey.  Their %^BOLD%^sickly green%^RESET%^%^GREEN%^"+
		" tongues often hang outside their mouths, dripping with"+
		" %^BOLD%^greenish %^WHITE%^white%^RESET%^%^GREEN%^ saliva.%^RESET%^");
	set_race("mimic");
	set_gender("neuter");
	set_body_type("snake");
	set_overall_ac(-5);
	set_hd(20,0);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_guild_level("fighter",20);
	set_size(2);
	set_max_level(15);
	set_stats("strength",20);
	set_stats("intelligence",10);
	set_stats("dexterity",14);
	set_stats("charisma",8);
	set_stats("constitution",18);
	set_stats("wisdom",10);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	remove_limb("tail");
	remove_limb("head");
	add_limb("mouth","torso",0,0,0);
      add_limb("right arm","torso",0,0,0);
      add_limb("left arm","torso",0,0,0);
	set_attack_limbs(({"right arm","left arm","mouth"}));
	set_attacks_num(3);
      set_base_damage_type("slashing");
     	set_damage(2,4);
	set_funcs(({"lickit","stick"}));
	set_func_chance(50);
	add_money("electrum",random(1000)+900);
	set_max_hp(random(50)+300);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
	add_attack_bonus(4);
	set_property("no dominate",1);
	set_property("no trip",1);
	set_property("no paralyze",1);
	set_exp(random(500)+2000);
	set_languages( ({ "common" }) );
}
void lickit(object targ)
{
	if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
	//if(!"daemon/saving_d"->saving_throw(targ,"spell",-2)) {
    		tell_object(targ,"%^ORANGE%^The mimic rolls its long tongue"+
			" across your face, its saliva burning your flesh.");
     		tell_room(ETO,"%^ORANGE%^The mimic rolls its long tongue"+
			" across "+targ->QCN+"'s face, causing "+targ->QO+""+
			" to sudder.",targ);
			targ->cause_typed_damage(targ, "torso", roll_dice(1, 8) + 6, "acid");
        	return 1;
	}
else {
    	tell_object(targ,"%^ORANGE%^The mimic tries to roll its long tongue"+
		" across your face, but you manage to move just in time.");
     	tell_room(ETO,"%^ORANGE%^"+targ->QCN+" leaps back as the mimic tries"+
		" to roll its long tongue across "+targ->QP+" face.",targ);
	return 1;
}
}
void stick(object targ)
{
if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-15)){
//if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
    	tell_object(targ,"%^YELLOW%^The mimic bumps into you, causing you "+
	"to stick to it's body!.");
     	tell_room(ETO,"%^YELLOW%^"+targ->QCN+"bumps into the mimic, causing"+
	" "+targ->QO+" stick to the creature.",targ);
    	targ->set_paralyzed(25,"%^BOLD%^%^RED%^You are stuck to the mimic"+
	" and can't move!");
        		return 1;
}
else {
    	tell_object(targ,"%^YELLOW%^Leaping back, you manage to avoid bumping into the mimic.");
     	tell_room(ETO,"%^YELLOW%^"+targ->QCN+" leaps back as the mimic tries"+
	" to bump into "+targ->QP+".",targ);
			return 1;
     }
}
void die(object obj) {
	switch(random(60)){
		case 0..5:
			new(OBJ"womendress")->move(TO);
		break;
		case 6..14:
			obj = new("/d/antioch/valley/obj/jewelry.c")->move(TO);
			obj = new("/d/antioch/valley/obj/jewelry.c")->move(TO);
		break;
		case 15..20:
			new(OBJ"menshirt")->move(TO);
		break;
		case 21..40:
			new(OBJ"r_shoes")->move(TO);
		break;
		case 51..59:
			obj = new("/d/antioch/valley/obj/jewelry.c")->move(TO);
		break;
		default:
		break;
}
	tell_room(ETO,"%^BOLD%^%^ORANGE%^As it's arms crash to the floor "+
	"the mimic dies.  With a final belch, the mimic coughs up some "+
	"hidden tresures held within it.");
    	::die(obj);
}
