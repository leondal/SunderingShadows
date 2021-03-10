#include <std.h>
#include "../keep.h"
#include "/d/common/common.h"

inherit MONSTER;

object ob;
int num;

void create() 
{
    ::create();
    set_name("Ingmar");
    set_id(({"ingmar","Ingmar","anti paladin","anti-paladin","unholy knight","Unholy Knight","knight","Knight"}));
    set_race("human");
    set_gender("male");
    set_short("Ingmar, Unholy Knight");
    set_long("%^BOLD%^%^BLACK%^This unholy, human knight is decked out in a suit of darkened plate "+
    "mail.  On the right shoulderplate of the armor is an emblem, an ashen background with "+
    "a %^RED%^red%^BOLD%^%^BLACK%^ hawk in front.  The emblem is the insignia of Lord Hawk, "+
    "in his pursuit of power this knight has pledged his allegiance and his life to Lord "+
    "Hawk.%^RESET%^");
    set_class("antipaladin");
    add_search_path("/cmds/antipaladin");
    set("aggressive", 25);
    set_alignment(9);
    set_hd(26,3);
    set_overall_ac(-10);
    set_stats("strength", 20);
    set_stats("wisdom", 15);
    set_stats("intelligence", 16);
    set_stats("charisma", 17);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    ob = new("/d/common/obj/armour/plate");
    ob->set_name("platemail");
    ob->set_short("A suit of dark platemail");
    ob->set_id(({"plate","platemail","plate mail","armor",
    "dark armor","dark plate"}));
    ob->set_long("%^BOLD%^%^BLACK%^This plate mail is formed from an obsidian chain that is "+
    "covered in several areas with thicker plates of metal.  The entire armor is unnaturally "+
    "dull as if to prevent any reflection of light.  On the right shoulderplate of the armor "+
    "is the insignia of %^RED%^Lord Hawk%^BOLD%^%^BLACK%^, an ashen gray background with "+
    "a %^RED%^red%^BOLD%^%^BLACK%^ hawk in front of it. %^RESET%^");
    if(random(10) == 8) {  ob->set_property("enchantment",4);  }
    ob->move(TO);
    command("wear platemail");
    RANDGEAR->arm_me(TO, "edgedm", 15, 1);
    add_money("gold", random(200));
    set_hp(315 + random(21));
    set_new_exp(20, "normal");
    set_mob_magic_resistance("average");
    set_funcs(({"thrust","heal_self"}));
    set_func_chance(50);
    num = 1;
    MOB_TR_D->do_treasure(TO,"B");
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
	  "sunder",
	  "rush"
   }));	 	
}

void thrust(object targ) 
{
    tell_room(environment(targ), "%^RED%^The Unholy Knight impales "+targ->query_cap_name()+"%^RED%^ with his weapon!!\n%^RESET%^",targ);
    tell_object(targ, "%^RED%^Ingmar impales you with his weapon!%^RESET%^\n");
    targ->do_damage("torso", roll_dice(8,10));
    return 1;
}

void heal_self() 
{
    if(num > 0) 
    {
        tell_room(ETO, "Ingmar places his hands upon his platemail.\n");
        add_hp(30);
        num = random(3);
        return 1;
    }
    tell_room(ETO, "%^MAGENTA%^Ingmar places his hands upon his platemail.%^RESET%^\n");
    add_hp(60);
    num = random(3);
    return 1;
}

void init() 
{
    ::init();
    TO->force_me("block up");
}

