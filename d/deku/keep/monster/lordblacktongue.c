#include <std.h>
#include "../keep.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("lord blacktongue");
    set_short("%^BOLD%^%^BLACK%^Lord BlackTongue, Unseen Master of Keep BlackTongue%^RESET%^");
    set_id(({"Werewolf","werewolf","massive werewolf","Massive Werewolf","blacktongue","lord blacktongue","lord"}));
   
    set_long("%^BOLD%^%^WHITE%^This massive creature towers over "+
    "twelve feet tall.  It is a hybrid, to your horror, of what "+
    "appears to be some type of giant and a massive wolf creature.  "+
    "The entire body of this creature is covered with a thick and "+
    "dark fur that ripples with the toned and powerful mucles "+
    "that rest just beneath the surface.  The two legs of this "+
    "creature are that of a powerful wolf and each of its arms "+
    "end in clawed appendages.  Strangely, the face of this "+
    "monstrous creature almost resembles a human, with "+
    "%^BLUE%^deep blue%^BOLD%^%^WHITE%^ eyes that shine "+
    "with a far more than animal intelligence.  It is "+
    "garbed with a dull %^BOLD%^%^BLACK%^obsidian"+
    "%^BOLD%^%^WHITE%^ robe and resting atop its head "+
    "is a %^RED%^g%^BOLD%^%^GREEN%^e%^BLUE%^m %^YELLOW%^encrusted "+
    "gold crown%^BOLD%^%^WHITE%^.%^RESET%^");

    set_hd(26,2);
    set_max_hp(1400 + random(61));
    set_hp(query_max_hp());
    add_search_path("/cmds/fighter");
    set_new_exp(25, "boss");
    set_overall_ac(-15);
    set_body_type("humanoid");
    set_size(3);
    set_gender("male");
    set_race("werewolf");
    set_stats("strength", 22);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    set_stats("intelligence", 14);
    set_stats("charisma", 6);
    set_stats("wisdom", 12);
    set_alignment(9);
    set_max_level(28);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set_attacks_num(4);
    set("aggressive","aggression");
    set_func_chance(45);
    set_funcs( ({"attacks"}) );
    set_damage(3,6);
    new(KEEPO + "blacktonguemasterkey")->move(TO);
    new(KEEPO + "obsidianrobe")->move(TO);
    new(KEEPO + "goldencrown")->move(TO);
    command("wear crown");
    command("wear robe");
    MOB_TR_D->do_treasure(TO,"C");			
    add_money("gold",random(1000) + 500);
    //add_attack_bonus(10); 
    set_parrying(1);   
}

void aggression(object targ)
{		
    if(!TP->query_invis()) 
    {
        command("speak common");
        command("say WHAT?  DIE INTRUDER SCUM!");
        command("kill " + TP->query_name());
        command("block south");
    }
}

void do_help(int x, int chance, int how_many) 
{
    int i;
    switch(x) 
    {
        case (3): 
        if(chance > 90) 
        {
            for(i = 0;i < how_many;i++) 
            {
                new(KEEPM + "massivewerewolf")->move(TO);
            }
            tell_room(ETO,"%^RED%^Reinforcements arrive to aide their Lord!%^RESET%^");
        }
        break;
    }

    if(x < 3) 
    {
        x++;
        call_out("do_help",x,chance,how_many);
        return;
    }
}
		
void attacks(object targ) 
{
    int hits,x,what,what_next,dead,chance,how_many,delay;

    what = random(200);
    dead = random(1000);
    hits = random(2) + 1;
    what_next = random(10);

    if(what > 185) 
    {
        command("yell GUARDS! HELP!");
        chance = random(100);
        how_many = random(2) + 1;
        call_out("do_help",0,chance,how_many);
        return;
    }
    else 
    {
        if(dead == 999) 
        {
            set_property("magic",1);
            tell_room(ETO,"%^BOLD%^%^RED%^Lord blacktongue shoves his hand into " +
            targ->query_cap_name() + "'s chest and tears out " + targ->query_possessive() + 
            "%^BOLD%^%^RED%^ heart!%^RESET%^",targ);
            tell_object(targ,"%^BOLD%^%^RED%^Lord blacktongue shoves his hand into your chest and "+
            "tears out your heart!%^RESET%^");
            targ->do_damage("torso",(int)targ->query_max_hp() + 200);
            set_property("magic",-1);   
            return;
        }
        if(what_next != 9) 
        {
            for(x = 0;x < hits;x++) 
            {
                tell_room(ETO,"%^BOLD%^%^RED%^Lord blacktongue growls loudly and hits " + 
                targ->query_cap_name() + "%^BOLD%^%^RED%^ in the head with his massive hand!"+
                "%^RESET%^",targ);
                tell_object(targ,"%^BOLD%^%^RED%^Lord blacktongue growls loudly and hits you in the head "+
                "with his massive hand!%^RESET%^");
                targ->do_damage("head",roll_dice(8,6));
            }
            return;
        }
        if(what_next == 9) 
        {
            tell_room(ETO, "%^BOLD%^%^WHITE%^Lord blacktongue jumps onto " + targ->query_cap_name() + 
            "%^BOLD%^%^WHITE%^ knocking " + targ->query_objective() + "%^BOLD%^%^WHITE%^ to the "+
            "ground!%^RESET%^", targ);
            tell_object(targ,"%^BOLD%^%^WHITE%^Lord blacktongue jumps onto you and knocks you to the "+
            "ground!%^RESET%^");
            targ->set_paralyzed(10,"%^RED%^You struggle to get back to your feet!%^RESET%^");
            return;
        }
		
        return;	
	}
}


