#include <std.h>
#include "../keep.h"

inherit MONSTER;

void create()
{
    object ob;
    ::create();
    set_name("A drow");
    set_id(({"drow","shaltul","elf","assassin"}));
    set_short("%^RED%^A drow%^RESET%^");
    set_long("%^CYAN%^This %^BOLD%^%^BLACK%^dark%^RESET%^%^CYAN%^ skinned elf stands only a "+
    "little over four feet tall.  His eyes are a light %^RED%^red%^CYAN%^ and his hair an "+
    "off white color.  Several %^RED%^scars%^RESET%^%^CYAN%^ criscross his face and form "+
    "various patterns, the obvious result of some %^BLUE%^grotesque%^RESET%^%^CYAN%^ "+
    "torture.  His body is thin and well toned and he looks to be a very active and "+
    "proficient warrior.  A lone %^BOLD%^%^WHITE%^bone%^CYAN%^ ring adorns a finger of his "+
    "right hand and he fights with blue metal shards.%^RESET%^");
    set_gender("male");
    set_race("drow");
    set_class("thief");
    set_class("assassin");
    add_search_path("/cmds/assassin");
    add_search_path("/cmds/thief");
    set_alignment(9);
    set_mlevel("thief",26);  
    set_mlevel("assassin",26);
   // set_property("no rush",1);
    set_mob_magic_resistance("average");
    set_overall_ac(-2 - random(5));
    set_hp(795 + random(41));
    set_new_exp(20, "very high");
    set_funcs(({"knee_kick"}));
    set_func_chance(25);
    set_stats("strength",18);
    set_stats("intelligence",18);
    set_stats("wisdom",15);
    set_stats("constitution",19);
    set_stats("dexterity",20);
    set_stats("charisma",8);
    set("aggressive","aggression");
    set_property("full attacks",1);
    set_property("swarm",1);
    ob = new(KEEPO + "insigniaring");
    ob->set_long("%^BOLD%^%^WHITE%^This ring is made from what appears to be a bone fragment.  "+
    "It is remarkably simple with two words etched into the underside of the band.%^RESET%^");
    ob->delete("read");
    ob->delete("language list");
    ob->delete("language");
    ob->set_id(({"ring","bone ring","shaltul's ring"}));
    ob->set_read("Shaltul Eldire");
    ob->set_language("drow");
    ob->move(TO);
    command("wear bone ring");
    new(KEEPO + "metalshard")->move(TO);
    command("wield shard");
    switch(random(2)) 
    {
        case 0:
            new(KEEPO+"frostbitesickle")->move(TO);
            command("wield sickle");
            break;
        case 1:
            new(KEEPO + "metalshard")->move(TO);
            command("wield shard");
            break;
    }
    MOB_TR_D->do_treasure(TO,"C");
    add_money("gold",random(500) + 500);
    TO->set_invis(1);
    set_monster_feats(({
        "dodge",
        "mobility",
        "evasion",
        "combat reflexes",
        "parry",
        "scramble"
    }));  	
}

void aggression(object targ)
{		
    int what;
    if(!TP->query_invis()) 
    {
        command("speak drow");
        command("say All who oppose Lord BlackTongue shall perish!");
        what = random(2);
        if(!objectp(TP) || !interactive(TP)) return;
        if(what == 0) {
            command("crit "+TPQN);
        }
        if(what == 1) 
        {
            command("stab "+TPQN);
        }		
    }
}


void knee_kick(object targ)
{
    tell_room(ETO,"%^BLUE%^Someone kicks " +targ->QCN+ "%^BLUE%^ in "+
    "the knee, causing " +targ->QO + "%^BLUE%^ to fall to the "+
    "ground!%^RESET%^",targ);
    
    tell_object(targ,"%^BLUE%^Someone %^BLUE%^kicks you in the "+
    "knee, causing you to fall to the "+
    "ground!%^RESET%^");
    targ->set_paralyzed(20,"%^BLUE%^You're getting back to your feet!%^RESET%^");
    return 1;
}

