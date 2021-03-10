#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

void equip_me();

void create() 
{
    object ob;
    int x;
    ::create();
    set_race("giant skeleton");
    set_name("guardian of the tomb");
    set_id(({"skeleton", "guardian", "tomb guardian", "giant", 
    "giant skeleton"}));
    
    set_short("%^RESET%^%^RED%^G%^BOLD%^%^WHITE%^ua%^RESET%^%^RED%^r"+
    "d%^BOLD%^%^WHITE%^ia%^RESET%^%^RED%^n %^BOLD%^%^WHITE%^O"+
    "%^RESET%^%^RED%^f Th%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^"+
    " T%^BOLD%^%^WHITE%^o%^RESET%^%^RED%^mb%^RESET%^");
    
    set_long("%^BOLD%^%^RED%^This massive skeletal creature "+
    "towers nearly twenty feet tall.  It's body is massive, perhaps "+
    "in life it was some type of enormous giant.  In death, "+
    "its bones have been scarred black and set into what were once "+
    "eye sockets are glowing %^RESET%^%^BLUE%^dark blue%^RESET%^"+
    "%^BOLD%^%^RED%^ orbs that glance about insanely.  The bones "+
    "of its legs are scribed with numerous, unknown phrases, "+
    "perhaps they are what binds it here.%^RESET%^");
    
    set_hd(32, 1);
    add_search_path("/cmds/fighter");
    set_property("full attacks", 1);
    set_body_type("humanoid");
    set_size(4);
    set_hp(650 + random(351));
    set_new_exp(28, "high");
    
    set_stats("strength",20);
    set_stats("intelligence",7);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",20);
    set_stats("dexterity",12);
    
    set_alignment(9);
    set("aggressive",27);
    set_property("full attacks",1); 
    //set_property("no bows",1);
    set_func_chance(50);
    set_funcs(({"rapid_attack", "mend_my_bones"}));
    set_property("attack bonus", 5);
    set_property("damage bonus", 5);
    set_overall_ac(-17);
    equip_me();
}

void equip_me()
{
    object ob;
    string tmp, tmp2;
    switch(random(3)) 
    {
        case 0:
            tmp = "hammer_lg";
            tmp2 = "hammer";
            break;
        case 1: 
            tmp = "large_battle_axe";
            tmp2 = "axe";
            break;
        case 2:
            tmp = "club_lg";
            tmp2 = "club";
            break;
    }
    ob = new("/d/common/obj/weapon/"+tmp);
    ob->move(TO);
    if(!random(5))
    {
        ob->set_property("enchantment", 5);
    }
    command("wield "+tmp2);
    ob = new("/d/common/obj/weapon/"+tmp);
    ob->move(TO);
    if(!random(5))
    {
        ob->set_property("enchantment", 4);
    }
    command("wield "+tmp2);
    return;
}

void rapid_attack(object targ)
{
    int roll, tac, need;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    roll = roll_dice(1,20);
    need = "/daemon/bonus_d.c"->thaco(TO->query_level(), "fighter");
    tac = targ->query_ac();

    if(roll > (need - tac) || roll == 20) 
    {
        tell_object(targ, "%^RED%^You watch in horror as the guardian "+
        "turns toward you, its strange %^RESET%^%^BLUE%^eyes"+
        "%^RESET%^%^RED%^ fixated on you, before it lands three "+
        "blows in rapid succession directly on your head!%^RESET%^");

        tell_room(ETO, "%^RED%^The guardians turns toward "+
        targ->QCN+", its strange %^RESET%^%^BLUE%^eyes"+
        "%^RESET%^%^RED%^ fixated on "+targ->QO+"%^RED%^, "+
        "before it lands three blows in rapid succession directly on "+ 
        targ->QP+" head!%^RESET%^", targ);
		
        targ->cause_typed_damage(targ, "head", roll_dice(8, 8), "bludgeoning");    
        targ->cause_typed_damage(targ, "head", roll_dice(8, 8), "bludgeoning");    
        targ->cause_typed_damage(targ, "head", roll_dice(8, 8), "bludgeoning");
        return;
    }

    tell_object(targ, "%^RED%^You watch in horror as the "+
    "guardian turns toward you, its strange %^RESET%^%^BLUE%^eyes"+
    "%^RESET%^%^RED%^ fixated on you, before it decides to turn away.%^RESET%^");

    tell_room(ETO, "%^RED%^The guardian turns toward "+
    targ->QCN +", its strange %^RESET%^%^BLUE%^eyes%^RESET%^"+
    "%^RED%^ fixated on "+targ->QO+"%^RED%^, "+
    "before it decides to turn away.%^RESET%^", targ);
    return;
}

void mend_my_bones(object targ)
{
    if(!objectp(TO)) return;
    tell_room(ETO, "%^BLUE%^The guardian suddenly glows an %^CYAN%^"+
    "eerie blue%^RESET%^%^BLUE%^ and its bones seem to instantly mend!"+
    "%^RESET%^", TO);
    TO->heal(roll_dice(10, 10));
    rapid_attack(targ);
    return;
}


