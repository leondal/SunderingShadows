#include <std.h>
#include "../keep.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("a massive gargoyle");
    set_short("%^RED%^A massive gargoyle%^RESET%^");
    set_id(({"Gargoyle","gargoyle","Massive Gargoyle","massive gargoyle"}));
    set_long("%^MAGENTA%^This massive creature towers over twelve feet high, its body is made "+
        "from what appears to be solid stone.  It has two enormous wings which spread out to "+
        "either side of its great shoulders and attached to each of its arms is a hand like "+
        "appendage that ends in four claws.  The eyes of this creature are a glowing %^RED%^"+
        "red%^MAGENTA%^.%^RESET%^");   
    set_hd(25,1);
    set_max_hp(585 + random(41));
    set_hp(query_max_hp());
    add_search_path("/cmds/fighter");
    set_new_exp(20, "normal");
    set_max_level(25);
    set_overall_ac(-8 - random(3));
    set_body_type("humanoid");
    set_size(4);
    set_gender("male");
    set_race("gargoyle");
    add_money("gold",1000 + random(2500));
    set_stats("strength",22);
    set_stats("dexterity", 19);
    set_stats("constitution", 14);
    set_stats("intelligence", 14);
    set_stats("charisma", 10);
    set_stats("wisdom", 14);
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    command("speak common");
    command("speech snarl angrily");
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    add_limb("right wing","torso",0,0,0);
    add_limb("left wing","torso",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set_attacks_num(5);
    set_property("magic",1);
    set_func_chance(35);
    set_funcs( ({"bite"}) );
    set_damage(2,8);
    set_property("weapon resistance",1);
    set("aggressive","aggression");
    new(KEEPO + "oddskull")->move(TO);
    MOB_TR_D->do_treasure(TO,"B"); 
}


void aggression() 
{
    if(!objectp(TP) && !interactive(TP) || TP->query_invis()) return;
    command("emoteat "+TPQN+" growls at $N");
    command("kill "+TPQN);
    return;
}

void bite(object targ) 
{
    tell_room(ETO, "%^RED%^The gargoyle shoves its claws into " + targ->query_cap_name() + "'s%^RED%^ neck and bites " + targ->query_objective() + "%^RED%^ in the face!%^RESET%^", targ);
    tell_object(targ,"%^RED%^The gargoyle shoves its claws into your neck and bites you in the face!%^RESET%^");
    targ->do_damage("head",roll_dice(10,10));
    //targ->set_paralyzed(25,"You are paralyzed by the searing pain!%^RESET%^");
    return;	
}



