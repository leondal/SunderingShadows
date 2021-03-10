//Added feats - Octothorpe 6/22/10

#include <std.h>
#include "../undead.h"

inherit CREATURE;


void create() 
{
    ::create();
    set_name("minotaur");
    set_id(({"minotaur"}));
    set_short("%^RED%^Giant Minotaur%^RESET%^");
    set_long("The Giant Minotaur is a hulking seven feet of pure hair and muscle.  "
        "His horns have been sharpened to sharp and deadly points, and have been "
        "decorated with many strange runes. In one hand he carries a giant, jagged "
        "edged blade, and in the other hand he wields a delicate punching dagger.  "
        "Sitting in his throne looking down upon you he is a truly awe inspiring sight.");
    set_race("minotaur");
    set_gender("male");
    set_hd(30,9);
    set_size(3);
    set_overall_ac(-5);
    set_class("fighter");
	set_class("thief");
	set_level(30);
    set_guild_level("fighter",30);
	set_guild_level("thief",30);
	set_mlevel("fighter",30);
	set_mlevel("thief",30);
    add_search_path( "cmds/fighter" );
    set_max_hp(1000);
    set_hp(query_max_hp());
    set_wielding_limbs(({"right hand","left hand"}));
    //set_body_type("humanoid");
   // set_body_type("minotaur");
    set_property("swarm",1);
    set_property("no bows",1);
    set_property("full attacks",1);
    set_stats("strength", 20);
    set_stats("dexterity",16);
    set_stats("constitution",19);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(50000);
    set_new_exp(25,"boss");
    set_alignment(9);
    set_funcs(({"smite","trample","hug","rushit","flashit","kdit","shatterit","sunderit","thunderstomp"}));
    set_func_chance(35);
    set_monster_feats(({
       "impale",
	  "light weapon",
	  "improved two weapon fighting",
	  "strength of arm",
	  "sweepingblow",
	  "blade block",
	  "toughness",
	  "exotic weapon proficiency",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance",
	  "regeneration",
	   "knockdown",
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush",
	   "Ambidexterity",
       "Improved two weapon fighting",
       "Two weapon fighting",
       "Unassailable parry",
		"Whirl"
		}));
	switch(random(10)){	
	case 0..4:
    new(OBJS"minoaxe.c")->move(TO);
    command("wield axe");
	break;
	case 5..9:
    new(OBJS"katar.c")->move(TO);
    command("wield katar");
	new(OBJS"clabbard_sword.c")->move(TO);
    command("wield sword");
	break;
	}
    new(OBJS"minotaur_horn.c")->move(TO);
    command("wear horn");
    new(OBJS"thunderous_hooves.c")->move(TO);
    command("wear shoes");
}

void smite() 
{
    object *vars;
    int i;
    vars = all_living(ETO);
    
    for(i=0;i<sizeof(vars);i++)
    {
        if(vars[i]->query_true_invis()) continue;
        if(vars[i] == TO) continue;
        tell_object(vars[i],"%^BOLD%^%^RED%^The Minotaur smashes his mighty hoof into the ground throwing you across the room!");
        
        if(!ROLLSAVE(vars[i],PPD))
        {
            tell_object(vars[i],"%^GREEN%^You smack head first into the wall and fall to the floor dazed!");
            vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(5,10));
            vars[i]->set_paralyzed(15,"%^BOLD%^Intense pain wracks your body making it impossible to fight!");
        } 
        else 
        {
            tell_object(vars[i],"%^RED%^You quickly gather your wits and re-enter the melee!");
            vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(4,6));
        }
    }
}

void trample(object targ) 
{
    int hp;
    hp=targ->query_max_hp();
    tell_object(targ,"The Minotaur lowers his horns and charges towards you!");
    tell_object(targ,"The Minotaur impales you upon his giant horns, then proceeds to trample over you!");
    tell_room(ETO,"The Minotaur charges at "+targ->query_cap_name()+"!",targ);
    tell_room(ETO,"The Minotaur rams into "+targ->query_cap_name()+" impaling "+targ->QO+" upon his horns!",targ);
    targ->do_damage("torso",hp/1.5);
    return 1;
}

void hug (object targ) 
{
    if(!ROLLSAVE(targ,RSW,-2))
    {
        tell_object(targ,"The Minotaur grabs you into a bear hug, and begins crushing the life out of you!");
        tell_room(ETO,"The Minotaur grabs "+targ->QCN+" in a bear hug!",targ);
        targ->do_damage("torso",roll_dice(4,10));
        targ->set_paralyzed(10,"You are held strong by the Minotaur's iron grip!");
        return 1;
    }
     
    tell_object(targ,"The Minotaur reaches to grab you but you duck out of the way!");
    tell_room(ETO,"The Minotaur reaches to grab "+targ->query_cap_name()+" but "+targ->query_subjective()+" ducks out of the way!",targ);
    targ->do_damage("torso",roll_dice(2,12));
    return 1;
}

void aggfunc() 
{
    if (TP->query_true_invis()) { return; } 
    command("say You shall not leave here alive, scum!");
    command("rush "+TP->query_name());
    return;
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void thunderstomp(object targ){
	command("say I will crush you under my hooves!");
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("thunderstomp "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}