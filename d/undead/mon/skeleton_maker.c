//Added feats - Octothorpe 6/22/10
//Coded by Bane for invasions...hordling monster that makes itself//
// added riding nwp - last change 7/00 *Styx* 8/15/03
#include <std.h>
#include "../undead.h"

inherit CREATURE;

void make_me();
void terror_me(object targ);
void charge();

void create()
{
    object ob;
    ::create();
    set_id(({"skeleton","warrior","skeleton warrior"}));
    set_name("skeleton warrior");
    set_long("These undead lords were created when their life essences were "
        "trapped within their golden circlets by Lord Kartakass. Now they "
        "can do nothing but obey the commands of their evil maker and help "
        "to advance his diabolical cause.");
    set_body_type("human");
    set_race("undead");
    set_size(2);
    set_alignment(9);
    add_money("gold",random(1000));
    add_money("platinum",random(50));
    set_property("aggressive",8);
    set_speed(35);
    nogo("one");
    make_me();
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    if(!objectp(ETO)) { return; }
    ::init();
    if(TP->query_true_invis()) return;
    if((int)TP->query_alignment() == 1 || (int)TP->query_alignment() == 4 || (int)TP->query_alignment() == 7)
    {
        kill_ob(TP,1);
    }
}

void make_me()
{
    object ob;
    int i,j,k,hd,exp,ac;
    string myclass,short;
    i = random(5);
    
    switch(i)
    {
    case 0: 
        hd = 10;
        exp = 5000;
        break;
    case 1: 
        hd = 15;
        exp = 7000;
        break;
    case 2: 
        hd = 20;
        exp = 10000;
        break;
    case 3: 
        hd = 25;
        exp = 15000;
        break;
    case 4: 
        hd = 29;
        exp = 21000;
        break;
    }

    //TO->set_exp(exp);
    set_new_exp(hd,"high");
    i = random(5);
    
    switch(i)
    {
    case(0): 
        myclass = "fighter";
        break;
    case(1): 
        myclass = "thief";
        break;
    case(2): 
        myclass = "mage";
        break;
    case(3): 
        myclass = "cleric";
        break;
    case(4): 
        myclass = "antipaladin";
        break;
    }
    
    TO->set_class(myclass);
    TO->set_mlevel(myclass, hd);
    TO->set_level(hd);
//    TO->set_hd(hd,8);
    TO->set_hd(hd,50);
    
    switch(myclass)
    {
    case "fighter": 
        ob = new(CWEAP"bastard");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield sword");
        ob = new(CARMOR"mshield");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        add_search_path("/cmds/fighter");
        command("wear shield");
	    set_property("full attacks",1);
//       set_hp(hd * 10);
	    set_stats("strength",19);
		set_monster_feats(({
		    "shieldbash",
			"shieldwall",
			"deflection",
			"counter",
			"reflection",
			"powerattack",
			"shatter",
			"sunder",
			"rush"
		}));
		set_func_chance(35);
		set_funcs(({"rushit","flashit","bashit"}));
		set_fighter_style("soldier");
	    break;
    
    case "thief":
        ob = new(CWEAP"shortsword");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        ob = new(CWEAP"shortsword");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        add_search_path("/cmds/thief");
        command("wield sword");
        command("wield sword 2");
//        set_hp(hd * 6);
	    set_stats("strength",17);
        set_stats("dexterity",19);
        set_scrambling(1);
		set_monster_feats(({
		   "dodge",
		   "evasion",
		   "mobility",
		   "scramble",
		   "spring attack"
		}));
	    break;
    
    case "mage":
//        set_hp(hd * 4);
        set_guild_level("mage",hd);
        add_search_path("/cmds/wizard");
	    set_stats("strength",16);
        set_stats("intelligence",19);
	    set_spells(({
	        "magic missile",
	        "scorcher",
	        "fireball",
	        "lightning bolt",
	        "cone of cold",
	        "powerword stun",
            "chain lightning"
	              }));
		set_monster_feats(({
		   "resistance",
		   "improved resistance",
		   "increased resistance",
		   "spell reflection"
		}));
	    set_spell_chance(100);
	    break;
    
    case "cleric":
        ob = new(CWEAP"mace");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield mace");
        ob = new(CARMOR"mshield");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        set_guild_level("priest",hd);
        add_search_path("/cmds/priest");
//        set_hp(hd * 8);
	    set_stats("strength",18);
        set_stats("wisdom",19);
        set_property("full attacks",1);
	    set_spells(({
	        "dark bolt",
	        "call lightning",
	        "flame strike"
                  }));
	    set_spell_chance(50);
		set_monster_feats(({
		    "shieldbash",
			"shieldwall",
			"deflection",
			"counter",
			"reflection",
		}));	
		set_func_chance(35);
		set_funcs(({"bashit"}));		
	    break;
    
    case "antipaladin":
        ob = new(CWEAP"two_hand_sword");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        ob = new(CWEAP"hhlance");
        ob->set_property("enchantment",hd/10);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        ob = new(CARMOR"fullplate");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment",1);
        ob->move(TO);
        set_guild_level("antipaladin",hd);
        add_search_path("/cmds/antipaladin");
        command("wear plate");
//        set_hp(hd * 10);
	    set_stats("strength",19);
        set_nwp("riding", hd+1);	// added 8/15/03 to fix horses throwing them *Styx*
		set_skill("athletics", hd+1);
        if(!present("horse"))
        call_out("do_horse",1,TP);	
        set_spells(({
	        "call lightning",
	        "cause serious wounds"
	              }));
	    set_spell_chance(25);
		set_monster_feats(({
		   "charge",
		   "mounted combat",
		   "ride-by attack",
		   "trample"
		}));
	    set_funcs(({"terror_me","charge"}));
	    set_func_chance(25);
        break;
    }
    
    i = random(5);

    switch(i)
    {
    case 0: 
        ac = -1;
        break;
    case 1: 
        ac = -2;
        break;
    case 2: 
        ac = -3;
        break;
    case 3: 
        ac = -4;
        break;
    case 4: 
        ac = -5;
        break;
    }
    
    set_overall_ac(ac);    
    i = random(5);

    switch(i)
    {   
    case 0: 
        short = "A intimidating Skeleton Warrior";
        break;
    case 1: 
        short = "A horrific Skeleton Warrior";
        break;
    case 2: 
        short = "A vengeful Skeleton Warrior";
        break;
    case 3: 
        short = "A monstrous Skeleton Warrior";
        break;
    case 4: 
        short = "A deformed Skeleton Warrior";
        break;
    }
    
    if(myclass == "antipaladin") { short = "A towering Skeletal Knight"; }

    set_short(short);
}

void stab_me(object targ)
{
    if(!ROLLSAVE(targ,PPD))
    {
        tell_object(targ, "%^BOLD%^The Skeleton Warrior stabs you in the back with a "
            "hidden dagger!");
        tell_room(ETO, "%^BOLD%^The Skeleton Warrior stabs "+targ->QCN+" in the back "
            "with a hidden dagger!",targ);
	    targ->do_damage(targ->return_limb(),roll_dice(TO->query_level(),5));
	    return 1;
    }
    tell_object(targ,"%^BOLD%^The Skeleton Warrior tries to stab you in the back!");
    tell_room(ETO,"%^BOLD%^The Skeleton Warrior tries to stab "+targ->QCN+" in "
        "the back!",targ);
    return 1;
}

void terror_me(object targ)
{
    int i;
    if(TO->query_in_vehicle()) { charge(); return; }
    tell_object(targ,"%^RED%^The Skeleton Warrior stares at you.");
    tell_room(ETO,"%^RED%^The Skeleton Warrior stares at "+targ->QCN+".",targ);
    if(!ROLLSAVE(targ,SP))
    {
	    tell_object(targ,"%^BOLD%^BLUE%^An immense feeling of terror overcomes you!");
	    tell_room(ETO,"%^BOLD%^BLUE%^"+targ->QCN+" starts to shake and quiver!",targ);
	    for(i=0;i<roll_dice(2,6);i++)
        {
            targ->run_away();
        }
	    return;
    }
    tell_object(targ,"%^BOLD%^BLUE%^You feel a little scared.");
    tell_room(ETO,"%^BOLD%^BLUE%^"+targ->QCN+" shivers a little.",targ);
    return;
}

void charge()
{    
    object targ;
    targ = TO->query_current_attacker();
    if(!objectp(targ)) { return; }
    if(!TO->query_in_vehicle()) { terror_me(targ); return; }
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
    if(!TO->is_class("antipaladin")) { return; }

    if(TO->query_in_vehicle())
    {
        command("unwield sword");
        command("wield lance");
    }

    if(!sizeof(query_wielded())) { command("wield sword"); }
    return;
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

void bashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shieldbash "+targ->query_name());
}
