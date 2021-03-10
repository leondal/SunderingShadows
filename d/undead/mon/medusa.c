// medusa.c
// mods noted to fix buggy deaths where the person doesn't go through the death
// sequence and changed to using aggressive function so they get in the room
// before the first attack happens and can see what hits them.  Also to use
// std move_around rather than heartbeat.  *Styx*  5/11/02
//checks added by Circe 12/6/03 to hopefully fix remaining bugs
// rebuilt by Ares 2-13-05, wow this mob was fubar
//Updated with loot and more combat skills Nov 2016 - Essyllis
//A few lines added to make her gaze attack take death ward into account. Lujke March 2018

#include <std.h>
#include "../undead.h"

inherit CREATURE;

int gaze(object targ);

void create()
{
    ::create();
    set_name("medusa");
    set_id(({"medusa","Medusa"}));
    set_short("%^GREEN%^A Medusa%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This medusa appears to be quite shapely and human.  "
        "However, her face is of horrid visage and her snaky hair writhes, so once "
        "you get fairly close that gives her away for what she is.  She also has "
        "glaring red-rimmed eyes.");
    set_overall_ac(0);
    set_race("medusa");
    set_body_type("human");
    add_limb("snake head 1","head",0,0,0);
    add_limb("snake head 2","head",0,0,0);
    add_limb("snake head 3","head",0,0,0);
    add_limb("snake head 4","head",0,0,0);
/*    set_attack_limbs(({"right hand",
                       "left hand", 
                       "snake head 1", 
                       "snake head 2",
                       "snake head 3", 
                       "snake head 4"
                    })); */
    set_attacks_num(5);
//    set_base_damage_type("slashing");
    set_funcs(({"bite","gaze", "bite","arrows" }));
    set_func_chance(65);
    set_size(2);
    set_alignment(9);
    set_damage(2,4);
    set_property("magic",1);
    set_hd(40,10);
    set_hp(1000);
    set_exp(50000);
    set_new_exp(25,"boss");
    set_gender("female");
    set("aggressive","gaze_em");
    set_property("not random monster", 1); //to avoid this spawning as a random monster in one of the alternative world quests - Saide
    set_speed(30);
    new(OBJS"medusa_snake.c")->move(TO);
    command("wear snake");
	new(OBJS"aspbow.c")->move(TO);
    command("wield bow");
	new("/d/common/obj/lrweapon/limitlessquiver")->move(TO);
	command("wear arrows");
	set_monster_feats(({
     "deadeye",                       
     "manyshot",                      
     "point blank shot",              
     "preciseshot",
	 "parry",
     "shot on the run" 
	  
   }));
}
/*
void init() 
{
    string *exits;
    int i;
    object *inven;
    exits = (string *)environment(TO)->query_exits();
    for(i = 0;i<sizeof(exits);i++) { add_action("chase",exits[i]); }
    ::init();
}

int chase() 
{
    string verb;
    verb = query_verb();
    if((object *)TO->query_attackers() != ({})) { call_out("go",1,verb); return 1; }
}

void go(string verb) { command(verb); return; }
*/
int gaze_em() 
{
    if(!TP->query_true_invis()) 
    {
        if(!objectp(TP)) return 1;
        kill_ob(TP,1);
        tell_room(ETO, "%^BOLD%^GREEN%^The Medusa rushes you so its asp-like head growth "
            "can bite you.");
        gaze(TP);
        return 1;
    }
    return 1;
}


int arrows(object targ)
{
	    object ob2;
		int i,fodder;
		i = 0;
	targ = TO->query_current_attacker();
	
   
//	if(!objectp(targ) ||!objectp(TO)) {return 0;}
	
	switch(random(4)){
		
		case 0:
		command("preciseshot attacker");
		break;
		
		case 1:
		command("manyshot attacker");
		break;
		
		case 2..3:
		 
		tell_room(ETO,"%^BOLD%^%^GREEN%^Medusa say:%^CYAN%^ Foolish mortals, your statues will adorn my lair!");
		tell_room(ETO,"%^GREEN%^Fire a swarm of Asp Snakes with her bow");
		fodder = roll_dice(3,4);
		for(i=0;i<fodder;i++){
			tell_object(targ,"%^RESET%^%^GREEN%^You are struck by the %^BOLD%^Asp Arrow!");
			tell_room(ETO,targ->QCN+"%^RESET%^%^GREEN%^ is struck by the %^BOLD%^asp arrow!",({targ}));
			targ->do_damage(targ->return_target_limb(),roll_dice(1,10)+10);
			tell_object(targ,"%^RESET%^%^GREEN%^The asp snake falls to the ground after hitting you, and slithers back to the Medusa");
			tell_room(ETO,"%^RESET%^%^GREEN%^The Asp snake falls to the ground after hitting "+targ->QCN+" %^RESET%^%^GREEN%^and slithers back to the Medusa",({targ}));
			ob2 = new(MON"aspsumsnake.c");
            if(objectp(ob2))
            {
                ob2->move(ETO);
                ob2->kill_ob(targ);
				ob2->set_property("minion", TO);
				TO->add_protector(ob2);
                TO->add_follower(ob2);
            }
			
		}
		break;
	}
	return 1;
	
}

int bite(object targ) 
{
    if(!objectp(targ)) return 1;

    if(ROLLSAVE(targ,PPD,)) 
    {
        tell_object(targ, "%^YELLOW%^Medusa rushes you, so that her asp-like head "
            "growth can bite you.");
        tell_room(ETO,"%^BOLD%^%^YELLOW%^Medusa rushes toward "+targ->QCN+", so that "
            "her asp-like head growths can bite "+targ->QO+".",targ);
        targ->do_damage("torso", roll_dice(3,6));
        return 1;
    } 
    
    tell_object(targ, "%^GREEN%^Medusa rushes you, so that her asp-like head "
        "growth can bite you.");
    tell_room(ETO,"%^BOLD%^%^GREEN%^Medusa rushes toward "+targ->QCN+", so that "
        "her asp-like head growths can bite "+targ->QO+".",targ);
    targ->do_damage("torso", roll_dice(10,10));
    tell_object(targ, "%^RED%^You feel the life drain from you as Medusa's asp-like head "
        "connects with a solid hit.");
    targ->add_poisoning(roll_dice(5,10));
    targ->set_paralyzed(roll_dice(10,4), "The venom of the bite siezes your muscles.");
    return 1;
}

int gaze(object targ) 
{
    object obj,shield;
    string targ_name,targ_desc;
    
    if(!objectp(targ)) { return 1; }

    targ_name = (string)targ->QCN;
    if(targ->is_player()) { targ_desc = (string)targ->query_description(); }
    else if(!targ->is_player()) { targ_desc = (string)targ->base_desc(); }

    TO->kill_ob(targ,0);
  
    if(obj = present("crystaline shield",targ))
    {
        tell_object(targ,"%^BOLD%^Medusa's menacing gaze reflects off of your shield!");
        tell_room(ETO,"%^BOLD%^The Medusa's menacing gaze reflects off of "+targ->QCN+"'s "
            "shield!",targ);
        return 1;
    }
  if(FEATS_D->has_feat(targ,"death ward"))
  {
    tell_object(targ, "%^BOLD%^%^WHITE%^The"
    +" %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^e%^BOLD%^d"
    +"%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^%^GREEN%^a%^BOLD%^'s"
    +" %^RESET%^%^GREEN%^gaze%^BOLD%^%^WHITE%^ falls upon you,"
    +" but your %^RESET%^%^CYAN%^spirit's%^BOLD%^%^BLACK%^"
    +" death ward%^WHITE%^ fights off the attack that might"
    +" otherwise have turned you to"
    +" %^RESET%^stone%^BOLD%^%^WHITE%^.");
    tell_room("%^BOLD%^%^WHITE%^The %^BOLD%^%^GREEN%^m%^RESET%^"
    +"%^GREEN%^e%^BOLD%^d%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^"
    +"%^GREEN%^a%^BOLD%^'s %^RESET%^%^GREEN%^gaze"
    +" %^BOLD%^%^WHITE%^falls upon " + targ->QCN 
    +"%^BOLD%^%^WHITE%^, but "+ targ->QS + " seems somehow"
    +" able to fight off the attack that might otherwise have"
    +" turned " + targ->QO + " to %^RESET%^stone%^BOLD%^%^WHITE%^."
     , targ);
   return 1;
  }
  if(targ->query_property("no death"))
  {
    tell_object(targ, "%^BOLD%^%^WHITE%^The"
    +" %^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^e%^BOLD%^d"
    +"%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^%^GREEN%^a%^BOLD%^'s"
    +" %^RESET%^%^GREEN%^gaze%^BOLD%^%^WHITE%^ falls upon you,"
    +" but you fight off the attack that might"
    +" otherwise have turned you to"
    +" %^RESET%^stone%^BOLD%^%^WHITE%^.");
    tell_room("%^BOLD%^%^WHITE%^The %^BOLD%^%^GREEN%^m%^RESET%^"
    +"%^GREEN%^e%^BOLD%^d%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^"
    +"%^GREEN%^a%^BOLD%^'s %^RESET%^%^GREEN%^gaze"
    +" %^BOLD%^%^WHITE%^falls upon " + targ->QCN 
    +"%^BOLD%^%^WHITE%^, but "+ targ->QS + " seems somehow"
    +" able to fight off the attack that might otherwise have"
    +" turned " + targ->QO + " to %^RESET%^stone%^BOLD%^%^WHITE%^."
     , targ);
    return 1;
  }

    if(ROLLSAVE(targ,PPD,-4) && !targ->id("summoned monster")) 
    {
        tell_object(targ, "%^GREEN%^You avert the gazing eyes of Medusa!");
        tell_room(ETO,"%^GREEN%^"+targ->QCN+" averts "+targ->QP+" eyes from the Medusa's gaze");
        return 1;
    } 

    tell_object(targ, "%^RED%^You gaze into Medusa's glaring red-rimmed eyes.");
    if(FEATS_D->has_feat(targ, "death ward"))
    {
        tell_object(targ, "%^RED%^You feel your life being pulled from you but your death ward allows you to resist at the "+
        "last instant!%^RESET%^");
        return 1;
    }
    tell_object(targ, "%^RED%^You feel your life escaping you, as the gaze causes your muscles to stiffen as hard as stone!");
    tell_room(ETO,"%^BOLD%^"+targ->QCN+" looks into the eyes of the medusa and "
        "turns to stone!",targ);
    targ->do_damage("torso", roll_dice(100,100000));
    if(!avatarp(targ)) { targ->die(); }
    call_out("make_statue",1,targ_name,targ_desc);
    return 1;
}

void make_statue(string str,string desc)
{
    object ob,statue;

    if(ob = present("corpse", environment(TO))) 
    {
        statue = new(OBJECT);
        statue->set_name("statue");
        statue->set_id(({"statue"}));
        statue->set_short("%^MAGENTA%^A stone statue of a "+str);
        statue->set_weight(100000);
        statue->set_long("%^RED%^This is a statue of "+str+".  In life it looked "
            "something like:%^RESET%^\n"+str+" "+desc);
        statue->move(ETO);
        ob->remove();
    }
    return;
}

void heart_beat() 
{
    int i;
    object *fodder;

    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    fodder = filter_array(all_inventory(ETO), "is_fodder", CREATURE);
    
    if(!sizeof(fodder)) { return; }

    for(i=0;i<sizeof(fodder);i++) 
    {
        gaze(fodder[i]);
        continue;
    }
}
