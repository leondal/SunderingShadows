//sorta tweaked for guard killers
#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit NPC;

void create()
{ 
    ::create();
    set_name("Elven Assassin");
    set_id(({"elf","assassin","elven assassin","monster"}));
    set_short("%^BOLD%^%^GREEN%^elven %^GREEN%^ass%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^in%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This elf has an intense look and very sharp features. Dressed completely in black with a swath of black cloth wrapped around the elf's face, only bright, piercing eyes can be seen.%^RESET%^");
    set_race("elf");
    set_gender("female");
    set_class("fighter");
    set_mlevel("fighter",50);
    add_search_path("/cmds/feats");
    add_search_path("/cmds/assassin");
    set_hd(60,10);
    set_level(60);
    set_hp(random(1000)+1000);
    set_overall_ac(-20);
    set_alignment(6);
    set_stats("intelligence",10);
    set_stats("wisdom",10);
    set_stats("strength",25);
    set_stats("charisma",3);
    set_stats("dexterity", 25);
    set_stats("constitution",16);
    add_money("gold",random(2000));
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_monster_feats(({"dodge","evasion","knockdown","expertise",
    "mobility","powerattack","rush","combat reflexes",
    "dodge","evasion","scramble","spring attack"}));
    set_skill("stealth",50);
    set_skill("athletics",50);
    set_property("damage resistance",2); 
    set_funcs(({"strik"}));
    set_func_chance(30);
    set_scrambling(1);
    set_attacks_num(7);
    set_damage(4,20);
    add_attack_bonus(20);
    set_new_exp(33,"boss");
    set_max_level(35);
    set_base_damage_type("bludgeoning");  
}


void strik(object targ)
{  
    int x;
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    
    if(!objectp(targ))
    {
        targ = TO->query_current_attacker();
        if(!objectp(targ)) { return 0; }
    }
        
    tell_object(targ,"%^ORANGE%^Elf throws a giant chakram "+
        "that shreads into you repeatedly as it spins !");
    tell_room(ETO,"%^ORANGE%^The elf throws a giant chakram into"+
        " "+targ->QCN+" and strikes them and keeps spinning, "+
        "sending a spray of %^BOLD%^blood%^RESET%^%^ORANGE%^ "+
        "and %^RED%^chunks of flesh%^ORANGE%^ flying off them!",targ);
   
    for(x=0;x<random(5)+5;x++)
    {
        targ->cause_typed_damage(targ,0,roll_dice(4,10),"slashing");
    }

    if(!targ->reflex_save(40))
    {
        targ->set_paralyzed(10+random(30), "%^MAGENTA%^Oh god.. it %^RED%^hurts..");
    }
    
    return 1;
}


void set_paralyzed(int time,string message)
{
    force_me("emote %^BOLD%^%^RED%^SCREAMS%^RESET%^ and continues attacking.");
    execute_attack();
    execute_attack();
    return 0;
}


void set_tripped(int time,string message)
{
    force_me("emote is %^GREEN%^flung%^RESET%^ from his feet"+
        " but %^GREEN%^flips%^RESET%^ over and continues attacking.");
    execute_attack();
    execute_attack();
    return 0;
}


void crit(object targ)
{
    tell_object(targ, "%^BOLD%^%^RED%^A slender blade appears in the elf's hand before driving it deep into your body incapacitating you!");
    tell_room(ETO,"%^BOLD%^%^RED%^A slender weapon appears in the elf's hand before driving it deep into "+targ->QCN+"%^BOLD%^%^RED%^ leaving "
        ""+targ->QO+" twitching when it is pulled out.",targ);
    targ->cause_typed_damage(targ,0,roll_dice(2,100),"piercing");
    targ->set_paralyzed(5,"%^RED%^That last hit %^BOLD%^HURT!");
}


void heart_beat()
{
    object *ppl, targ;
    int i;
    
    ::heart_beat();
    
    if(!objectp(TO) || !objectp(ETO)) { return; }

    ppl = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    
    for(i=0;sizeof(ppl),i<sizeof(ppl);i++)
    {
        if(!objectp(ppl[i])) { continue; }
        if(ppl[i]->query_unconscious())
        {
            ppl[i]->move(ROOMS"death"); //if knocked out send to justice
            ppl[i]->set_bound(100);
            tell_room(ETO,"%^GREEN%^The elf tosses an orb at "+ppl[i]->QCN+", and it engulfs "+ppl[i]+" in a green light, leaving nothing behind.");
        }
    }
    
    if(!sizeof(TO->query_attackers()))
    {
        tell_room(ETO,"%^GREEN%^The elf tosses an orb at "+TO->QP+" feet and it engulfs "+TO->QO+" in green smoke, leaving nothing behind.");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    
    targ = TO->query_current_attacker();
    if(!objectp(targ)) { return; }
 
    if(!random(2)) { force_me("knockdown "+targ->query_name()); }
    else { crit(targ); }

    return;
}

