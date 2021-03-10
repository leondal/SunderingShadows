//First main bad guy for the catacombs on deku - should auto attack invis
//is pretty vicious - very good large hammer he has - Saide
//moved him to the roof of the haunted house - Saide - April 2013
#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    object ob;
    int x;
    ::create();
    set_race("giant zombie");
    set_name("husk of zhour");
    set_id(({"husk", "zhour", "husk of zhour", "towering husk", 
    "towering husk of zhour", "towering zhour", "zombie", "giant zombie"}));

    set_short("%^BOLD%^%^BLACK%^The Towering Husk of %^BOLD%^%^WHITE%^"+
    "Zh%^BOLD%^%^CYAN%^ou%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^This massive creature stands over "+
    "ten feet tall.  Its body has long since fallen into a state of "+
    "grotesque rot, however, this has not diminished the muscle mass.  "+
    "Every exposed part of its flesh is rippling with so much muscle "+
    "that it looks as if it is about to pop out and spill the "+
    "hidden contents all over.  The head of this creature is probably "+
    "three feet wide, much larger than it should be for its body, "+
    "and the veins beneath the surface of the rotted flesh pulse "+
    "constantly, as if its heart was still beating in its decaying "+
    "chest.  Its mouth seems to be stuck in a smile - though this "+
    "offers you no comfort - for the exposed teeth are viciously "+
    "sharp and pointed.  To make matters worse, much worse, you "+
    "notice that it carries two large blue warhammers, and swings "+
    "them about with extraordinary ease.%^RESET%^");

    set_hd(32, 1);
    add_search_path("/cmds/fighter");
    set_property("full attacks", 1);
    set_body_type("humanoid");
    set_size(4);
    set_hp(3700 + random(250));
    set_new_exp(32, "high");
    
    set_stats("strength",20);
    set_stats("intelligence",7);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",22);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive", "rush_em");
    set_property("full attacks",1); 
    set_func_chance(45);
    set_funcs(({"destroy_you", "bite"}));
    set_property("attack bonus", 5);
    set_property("damage bonus", 5);
    set_property("no tripped", 1);
    set_overall_ac(-26);
    new(HHOB+"thundering_might")->move(TO);
    command("wield hammer");
    ob = new(HHOB"thundering_might");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield hammer");
    set_monster_feats(({"rush"}));
}

void destroy_you(object targ)
{
    int roll, tac, need;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    roll = roll_dice(1,20);
    need = "/daemon/bonus_d.c"->thaco(TO->query_level(), "fighter");
    tac = targ->query_ac();
    if(roll > (need - tac) || roll == 20) 
    {
        tell_object(targ, "%^BOLD%^%^CYAN%^The towering creature "+
        "slams both of its hammers into your head, with such "+
        "force that the world goes black!%^RESET%^");   
        
        tell_room(ETO, "%^BOLD%^%^CYAN%^With unimaginable force "+
        "the towering creature slams both of its hammers into "+
        targ->QCN+"%^BOLD%^%^CYAN%^'s head!%^RESET%^", targ);   
        
        targ->set_paralyzed(10, "%^BOLD%^%^BLACK%^The force of "+
        "the blow has left you paralyzed and unable to see!%^RESET%^");

        targ->set_temporary_blinded(1, "%^BOLD%^%^BLACK%^The force "+
        "of the blow has left you unable to see!%^RESET%^");
        targ->cause_typed_damage(targ, "head", roll_dice(18,12), "bludgeoning");
        return;
    }
    tell_object(targ, "%^BOLD%^%^CYAN%^The towering creature "+
    "swings both of its hammers into your head, but you manage to "+
    "dodge the full force of the blow!%^RESET%^");
    targ->cause_typed_damage(targ, "head", roll_dice(9, 12), "bludgeoning");

    tell_room(ETO, "%^BOLD%^%^CYAN%^The towering creature swings "+
    "both of its hammers into "+targ->QCN+"%^BOLD%^%^CYAN%^'s "+
    "head, but "+targ->QS+" manages to dodge the full "+
    "force of the blow!%^RESET%^", targ);
    return;
}

void bite(object targ)
{
    int roll, tac, need;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    roll = roll_dice(1,20);
    need = "/daemon/bonus_d.c"->thaco(TO->query_level(), "fighter");
    tac = targ->query_ac();
    if(roll > (need - tac) || roll == 20) 
    {
        tell_object(targ, "%^BOLD%^%^BLACK%^The towering creature "+
        "grabs you by the neck and lifts you up, sinking its "+
        "vicious teeth into your head, then tosses you across "+
        "the room with ease!%^RESET%^");
		
        targ->cause_typed_damage(targ, "head", roll_dice(20, 12), "piercing");
		
        tell_room(ETO, "%^BOLD%^%^BLACK%^The towering creature "+
        "grabs "+targ->QCN+"%^BOLD%^%^BLACK%^ by the neck and lifts "+
        targ->QO+" up, sinking its teeth into "+targ->QP+" head, then "+
        "tosses "+targ->QO + " across the room!%^RESET%^", targ);
        return;
    }
    tell_object(targ, "%^BOLD%^%^BLACK%^The tower creature "+
    "grabs at you, but you manage to dodge away from its grasp!%^RESET%^");

    tell_room(ETO, "%^BOLD%^%^BLACK%^The towering creature "+
    "grabs at "+targ->QCN+"%^BOLD%^%^BLACK%^ but "+targ->QS+
    " manages to dodge away from its grasp!%^RESET%^");
    return;
}

void rush_em()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    command("speak wizish");
    command("yell NOW YA DIE AND I FEAST ON YOUR CORPSE!");
    vics = all_living(ETO);
    vics -= ({TO});
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(TO)) return;
        if(!objectp(vics[x])) continue;
        if(vics[x]->query_true_invis()) continue;
        if(!interactive(vics[x])) continue;
        TO->force_me("rush "+vics[x]->query_name());
        return;
    }
} 
