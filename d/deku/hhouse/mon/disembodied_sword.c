#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

void create() 
{
    object ob;
    int x;
    ::create();
    set_race("sword");
    set_name("massive, disembodied sword");

    set_id(({"sword", "massive sword", "disembodied sword", 
    "bastard sword"}));
    set_short("%^BOLD%^%^WHITE%^A massive, disembodied, sword (%^BOLD%^%^CYAN%^ hovering in the air%^BOLD%^%^WHITE%^ )%^RESET%^");
    
    set_long("%^BOLD%^%^CYAN%^This massive bastard sword is several "+
    "feet long.  It is constantly giving off a deep "+
    "blue glow.  The blade has been forged from some type of "+
    "dark red metal and runes are incribed the "+
    "entire length of it.  The hilt is viciously spiked, as if "+
    "trying to prevent anyone from ever grabbing it.%^RESET%^");
    set_property("full attacks", 1);
    set_body_type("humanoid");
    set_size(4);
    set_hd(22, 1);
    set_hp(350 + random(200));
    set_exp(1);
    set_stats("strength",18);
    set_stats("intelligence",25);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",22);
    set_stats("dexterity",12);
}

void vape_me()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO, "%^BOLD%^%^WHITE%^The massive sword %^BOLD%^%^CYAN%^"+
    "blinks%^BOLD%^%^WHITE%^ away, fading from "+
    "%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^x%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^"+
    "n%^BOLD%^%^WHITE%^c%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^!%^RESET%^");
    TO->remove();
}

void hit_em(object targ)
{
    int hits, roll, need, tac;
    if(!objectp(TO)) return;
    if(!objectp(targ)) 
    {
        vape_me();
        return;
    }
    hits = 1 + random(3);
    while(hits)
    {
        hits--;
        roll = roll_dice(1,20);
        need = "/daemon/bonus_d.c"->thaco(TO->query_level(), "fighter");
        tac = targ->query_ac();
        if(roll > (need - tac) || roll == 20) 
        {
            tell_object(targ, "%^BOLD%^%^WHITE%^The massive disembodied "+
            "sword slices v%^BOLD%^%^CYAN%^"+
            "i%^BOLD%^%^WHITE%^c%^BOLD%^%^CYAN%^"+
            "i%^BOLD%^%^WHITE%^o%^BOLD%^%^CYAN%^u%^BOLD%^%^WHITE%^"+
            "s%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^y%^BOLD%^%^WHITE%^"+
            " into your torso!%^RESET%^");

            tell_room(ETO, "%^BOLD%^%^WHITE%^The massive disembodied "+
            "sword slices v%^BOLD%^%^CYAN%^"+
            "i%^BOLD%^%^WHITE%^c%^BOLD%^%^CYAN%^"+
            "i%^BOLD%^%^WHITE%^o%^BOLD%^%^CYAN%^u%^BOLD%^%^WHITE%^"+
            "s%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^y%^BOLD%^%^WHITE%^"+
            " into "+targ->QCN+"%^BOLD%^%^WHITE%^'s torso!%^RESET%^", targ);
            targ->cause_typed_damage(targ, "torso", roll_dice(12,6), "slashing");
            continue;
        }
        tell_object(targ, "%^BOLD%^%^WHITE%^The massive disembodied "+
        "sword swipes at you, but you manage to dodge out of the way just "+
        "in time!%^RESET%^");

        tell_room(ETO, "%^BOLD%^%^WHITE%^The massive disembodied "+
        "sword swipes at "+targ->QCN+"%^BOLD%^%^WHITE%^ but "+
        targ->QS+"%^BOLD%^%^WHITE%^ manages to dodge out of the way just "+
        "in time!%^RESET%^");
        continue;
    }
    vape_me();
    return;		
}
