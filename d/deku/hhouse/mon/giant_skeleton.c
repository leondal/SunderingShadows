#include <std.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    object ob;
    ::create();
    set_name("gleaming black skeleton");
    set_id( ({ "skeleton", "giant skeleton", "black skeleton", 
    "gleaming black skeleton", "gleaming skeleton"}) );
    set_race("undead");
    set_gender("male");
    set_short("%^BOLD%^%^BLACK%^%^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^"+
    "l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g "+
    "black skeleton%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This massive skeletal "+
    "creature towers approximately ten feet in the air. "+
    "Its body is composed of thick bones, which have apparently "+
    "been charred by a ferocious fire and then doused "+
    "in some unknown liquid which makes them gleam. "+
    "Many of the bones still contain remnants of "+
    "what was once armor that is now nothing more than "+
    "a melted mass. The skull is exceptionally odd "+
    "with a %^BOLD%^%^BLUE%^rune%^BOLD%^%^BLACK%^ "+
    "which resembles a %^BOLD%^%^RED%^dagger plunging "+
    "into a heart%^BOLD%^%^BLACK%^ inscribed into the "+
    "very center of the forehead. There are two "+
    "%^BOLD%^%^CYAN%^cold blue%^BOLD%^%^BLACK%^ "+
    "orbs resting deep in the eye sockets.%^RESET%^");

    set_body_type("human");
    set_alignment(9);
    set_size(4);
    set_hd(32,1);
    set_hp(475 + random(226));
    set_new_exp(32, "normal");
    ob = new(AOITEMS+"life_stealing_weapon");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield hammer");
    command("wield axe");
    ob = new(AOITEMS+"life_stealing_weapon");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield hammer");
    command("wield axe");
  	
    add_money("electrum",random(1000));
    add_money("silver",random(1000));
    add_money("gold",random(425));
    add_money("copper",random(1000));
    set_property("undead",1);
    set_property("swarm",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_overall_ac(-14);
    set_property("no paralyze",1);
    set("aggressive",26);
    set_func_chance(25); 
    set_property("full attacks", 1);
    set_funcs(({"destroy", "maim"}));
    
    set_stats("strength",18);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",9);
    set_stats("charisma",8);
    set_stats("constitution",9);
    
}

void destroy(object targ)
{
    int hits;
    object wpn, *wpns;
    string me, tlim, wpn_string, wpn_type;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();

    tell_room(ETO, me + "%^BOLD%^%^RED%^'s cold %^BOLD%^%^BLUE%^blue%^BOLD%^%^RED%^ "+
    "orbs begin %^BOLD%^%^BLUE%^p%^BOLD%^%^CYAN%^u%^BOLD%^%^BLUE%^l%^BOLD%^%^CYAN%^"+
    "s%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^g"+
    " %^BOLD%^%^RED%^rapidly!%^RESET%^");
    TO->force_me("speech mumble");
    TO->force_me("speak wizish");

    TO->force_me("say must %^BOLD%^%^RED%^DESTROY%^RESET%^ "+targ->QCN+"!");
    
    tell_room(ETO, me + "%^BOLD%^%^BLACK%^ begins %^BOLD%^%^CYAN%^spinning "+
    "%^BOLD%^%^BLACK%^and %^BOLD%^%^CYAN%^whirling%^BOLD%^%^BLACK%^ about "+
    "rapidly, its attacks focused on "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", targ);

    tell_object(targ, me + "%^BOLD%^%^BLACK%^ begins %^BOLD%^%^CYAN%^spinning "+
    "%^BOLD%^%^BLACK%^and %^BOLD%^%^CYAN%^whirling%^BOLD%^%^BLACK%^ about "+
    "rapidly, its attacks focused on you!%^RESET%^");	

    hits = 2 + random(3);
    while(hits--)
    {
        if(targ->reflex_save(30)) 
        {
            tell_object(targ, "%^BOLD%^%^RED%^You quickly %^BOLD%^%^BLUE%^"+
            "dodge%^BOLD%^%^RED%^ one of "+me+"%^BOLD%^%^RED%^'s vicious "+
            "attacks!%^RESET%^");
			
            tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ quickly %^BOLD%^%^BLUE%^"+
            "dodges%^BOLD%^%^RED%^ one of "+me+"%^BOLD%^%^RED%^'s vicious "+
            "attacks!%^RESET%^", targ);
            continue;
        }
        else
        {
            tlim = targ->return_target_limb();
            wpns = TO->query_wielded();
            wpn = wpns[random(sizeof(wpns))];
            if(!objectp(wpn)) 
            {
                wpn_string = "weapon";
                wpn_type = "bludgeoning";
            }
            else 
            {
                wpn_string = wpn->query_short();
                wpn_type = wpn->query_damage_type();
            }
            tell_object(targ, me+"%^BOLD%^%^BLACK%^'s "+wpn_string+
            "%^BOLD%^%^RED%^ SLAMS %^BOLD%^%^BLACK%^into your "+tlim+
            "!%^RESET%^");

            tell_room(ETO, me+"%^BOLD%^%^BLACK%^'s "+wpn_string+
            "%^BOLD%^%^RED%^ SLAMS%^BOLD%^%^BLACK%^ into "+targ->QCN+
            "%^BOLD%^%^BLACK%^'s "+tlim+"!%^RESET%^", targ);

            targ->cause_typed_damage(targ, tlim, roll_dice(6,6), wpn_type);
            continue;
        }
    }
    return;
}

void maim(object targ)
{
    string me, tlim, wpn_string, wpn_type;
    object wpn, *wpns;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
	
    tell_room(ETO, me + "%^BOLD%^%^RED%^'s cold %^BOLD%^%^BLUE%^blue%^BOLD%^%^RED%^ "+
    "orbs begins %^BOLD%^%^YELLOW%^f%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^s"+
    "%^BOLD%^%^YELLOW%^h%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g%^BOLD%^%^RED%^ "+
    "rapidly!%^RESET%^");

    TO->force_me("speech stutter");
    TO->force_me("speak wizish");

    TO->force_me("say must %^BOLD%^%^BLACK%^MAIM%^RESET%^ "+targ->QCN+"!");
    wpns = TO->query_wielded();
    wpn = wpns[random(sizeof(wpns))];
    if(!objectp(wpn)) 
    {
        wpn_string = "weapon";
        wpn_type = "bludgeoning";
    }
    else 
    {
        wpn_string = wpn->query_short();
        wpn_type = wpn->query_damage_type();
    }
    tlim = targ->return_target_limb();
    tell_room(ETO, me +"%^BOLD%^%^WHITE%^ emits a guttural roar and "+
    "%^BOLD%^%^RED%^SLAMS%^BOLD%^%^WHITE%^ its "+wpn_string+" into "+
    targ->QCN+"%^BOLD%^%^WHITE%^'s "+tlim+"!%^RESET%^", targ);

    tell_object(targ, me+"%^BOLD%^%^WHITE%^ emits a guttural roar "+
    "and %^BOLD%^%^RED%^SLAMS%^BOLD%^%^WHITE%^ its "+wpn_string+" into "+
    "your "+tlim+"!%^RESET%^");

    targ->cause_typed_damage(targ, tlim, roll_dice(8,8), wpn_type);

    if(!targ->will_save(12)) 
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^The %^BOLD%^%^RED%^SEARING"+
        "%^BOLD%^%^WHITE%^ pain in your "+tlim+" clouds your "+
        "mind!%^RESET%^");
        targ->set_paralyzed(10, "%^BOLD%^%^RED%^You are recovering "+
        "from the blow to your "+tlim+"!%^RESET%^");
    }
    destroy(targ);
}