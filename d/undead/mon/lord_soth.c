//Added feats - Octothorpe 6/22/10
//Added the Soth family sword and the option for sword&shield fightingstyle - Nov 2016 Essyllis

#include <std.h>
#include "../undead.h"

inherit CREATURE;

void fear();
void charge();

void create() 
{
    object ob;
    :: create();
    set_name("%^RED%^Lord Soth%^RESET%^");
    set_id(({ "soth","knight","death knight","lord","lord soth" }));
    set_short("%^RED%^Lord Soth%^RESET%^");
    set_long("%^GREEN%^Lord Soth speaks with a hollow, chilling voice.  His "
        "demeanor is terrifying, even to kender.  Soth often behaves to the "
        "Oath and the Measure in his daily routine.  However he adheres to the "
        "trappings of honor, no matter what his Master has ordered him to do.");
    set_gender("male");
    set_class("antipaladin");
    set_mlevel("antipaladin",30);
    set_guild_level("cleric", 30);
    set_guild_level("antipaladin",30);
    add_search_path("/cmds/cavalier");
    add_search_path("/cmds/antipaladin");
    set_guild_level("cleric",30);
	set_skill("athletics", 31);
    set_nwp("riding", 31);	// added 1/1/03 to fix his horse fighting him back *Styx*
    set_hd(20,21);
    set_hp(700);
	set_max_hp(700);
    set_size(2);
    set_overall_ac(3);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_exp(50000);
    set_new_exp(25,"boss");
    set_body_type("human");
    set_race("undead");
    set_property("full attacks",1);
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",14);
    set_stats("wisdom",18);
    set_stats("intelligence",20);
    set_stats("charisma",17);
    set_alignment(9);
    add_money("gold",random(500)+700);
 switch(random(50)){
	 case 0..24:
 	set_monster_feats(({
	    "charge",
		"mounted combat",
		"ride-by attack",
		"trample",
		"blade block",
		"impale",
		"light weapon",
		"strength of arm",
		"sweepingblow"
    }));
    set_funcs(({"fear","charge","impaleit","sweepit"}));
    set_func_chance(20);
    set_spells(({"call lightning","sticks into snakes","flame strike"}));
    set_spell_chance(35);
    ob = new(OBJS"sothsword"); 
	ob->move(TO);
	command("wield sword");
	break;
	
	case 25..49:
	 	set_monster_feats(({
	    "charge",
		"mounted combat",
		"ride-by attack",
		"trample",
		"counter",
		"deflection",
		"reflection", 
		"shieldbash",
		"shieldwall"
    }));
    set_funcs(({"fear","charge",/*"impaleit","sweepit"*/"shieldit"}));
    set_func_chance(20);
    set_spells(({"call lightning","sticks into snakes","flame strike"}));
    set_spell_chance(35);
    ob = new(OBJS"sothlongsword"); 
	ob->move(TO);
	ob = new("/d/common/obj/armour/shield"); 
	ob->set_property("enchantment",3);
	ob->move(TO);
	command("wield sword");
	command("wear shield");
	break;
	
	
	
	}
	
    if(!present("horse")) { call_out("do_horse",1,TO); }
/*
    ob = new(CWEAP"hhlance.c");
    ob->set_property("enchantment",3);
    ob->move(TO);
    ob = new(CWEAP"two_hand_sword.c");
    ob->set_property("enchantment",3);
    ob->move(TO);*/

    ob = new(CARMOR"field.c");
    if(random(2)) { ob->set_property("enchantment",3); }
    ob->move(TO);
    new(OBJS"r_helm.c")->move(TO);
    command("wear helm");
    command("wear plate");
    new(OBJS"holy_cross.c")->move(TO);
    command("wear necklace");
    return;
}

void fear()
{
    object targ;
    if(TO->query_in_vehicle()) { charge(); return; }
    targ = query_current_attacker();
    new("/cmds/spells/f/_fear.c")->use_spell(TO,targ->query_name(),30,100,"cleric");
    return;
}

void charge()
{    
    object targ;
    if(!TO->query_in_vehicle()) { fear(); return; }
    targ = TO->query_current_attacker();
    command("charge "+targ->query_name());
    return;
}
    
void do_horse()
{
    object horse;
    if(!objectp(ETO)) return;
    horse = new("/d/common/mounts/war_horse.c");
    horse->set_owner(TO);
    horse->move(ETO);
    TO->force_me("mount horse");
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	if(query_hp() < query_max_hp()){TO->add_hp(roll_dice(1,4));}

   /* if(TO->query_in_vehicle())
    {
        command("unwield sword");
        command("wield lance");
    }

    if(!sizeof(query_wielded())) { command("wield sword"); }
    return;
	*/
}

void impaleit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("impale "+targ->query_name());
}

void shieldit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("shieldbash "+targ->query_name());
	
	
}
void sweepit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return; 
   TO->force_me("sweepingblow");
}