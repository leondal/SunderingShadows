#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

void create() 
{
    object ob;
    int x;
    ::create();
    set_race("angry spirit");
    set_name("spirit of the tomb");
    set_id(({"spirit", "tomb spirit", "angry spirit", 
    "spirit of the tomb"}));

    set_short("%^BOLD%^%^WHITE%^Sp%^CYAN%^i%^BOLD%^%^WHITE%^r"+
    "%^CYAN%^i%^BOLD%^%^WHITE%^t %^CYAN%^O%^BOLD%^%^WHITE%^f "+
    "Th%^CYAN%^e%^BOLD%^%^WHITE%^ T%^CYAN%^o%^BOLD%^%^WHITE%^"+
    "mb%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^This angry spirit "+
    "is almost completely transparent.  It towers "+
    "almost six feet high, but seems even taller as it "+
    "is constantly hovering above the ground.  You cannot "+
    "make out exactly any of its features, but from what you can "+
    "tell its body was once scarred horribly, perhaps "+
    "the result of a fire.  The orbs that serve as its "+
    "eyes are glowing a strange %^RESET%^%^BLUE%^dark "+
    "blue%^RESET%^%^BOLD%^%^WHITE%^ and you shiver as "+
    "their gaze falls upon you.%^RESET%^");

    set_property("posed", "%^BOLD%^%^CYAN%^Hovering In The Air%^RESET%^");
    command("speech cackle insanely");
    command("speak wizish");
    set_hd(34, 1);
    set_class("mage");
    set_guild_level("mage", 34);
    set_mlevel("mage", 34);
    set_property("full attacks", 1);
    set_body_type("humanoid");
    set_size(2);
   	set_hp(650 + random(101));
    set_new_exp(28, "normal");
    set_stats("strength",15);
    set_stats("intelligence",19);
    set_stats("wisdom",19);
    set_stats("charisma",6);
    set_stats("constitution",17);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive","agg_func");
    set_func_chance(50);
    set_funcs(({"strip_protections", "refresh_em"}));
    set_spells(({"fireball"}));
    set_spell_chance(50);
    set_overall_ac(-17);
}

void strip_protections(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    command("say magical protections, you have?");
    new("/cmds/spells/d/_dispel_magic")->use_spell(TO, 0, 100, 100, "mage");
    command("say away they go!");
    return;
}

void refresh_me(object targ)
{
    int amt;
    string dam_str;
    object guard;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
    amt = roll_dice(10, 12);
    switch(amt) 
    {
        case 1..10:
            dam_str = "minor";
            break;
        case 11..25:
            dam_str = "moderate";
            break;
        case 26..40:
            dam_str = "substantial";
            break;
        case 41..60:
            dam_str = "major";
            break;
        default:
            dam_str = "moderate";
            break;
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^The tomb spirit "+
    "points its hands at "+targ->QCN+"%^BOLD%^%^CYAN%^ "+
    "and seems to drain "+
    "away a %^BOLD%^%^WHITE%^"+dam_str+"%^BOLD%^%^CYAN%^ "+
    "portion of "+targ->QP+" very life "+
    "force!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^CYAN%^The tomb spirit "+
    "points its hands at you, draining away a "+
    "%^BOLD%^%^WHITE%^"+dam_str+"%^BOLD%^%^CYAN%^ portion of your very "+
    "force!%^RESET%^"); 

    if(!objectp(guard = present("tomb guardian", ETO)))
    {
        tell_room(ETO, "%^BOLD%^%^WHITE%^The spirit seems to use "+
        "the energy to mend the bones of the "+
        guard->query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^");
        guard->heal(amt);
    }
    set_property("magic", 1);
    targ->cause_typed_damage(targ, "torso", amt, "negative energy");
    set_property("magic", -1);
    return;
}

void agg_func() 
{
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    command("say come out, come out!!");
    command("kill "+TP->query_name());
    strip_protections(TP);
}
