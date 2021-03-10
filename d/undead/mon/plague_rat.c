#include <std.h>
#include "../undead.h"

inherit CREATURE;

create() 
{
    ::create();
    set_name("Plague Rat");
    set_id( ({ "rat","plague","plague rat" }) );
    set_short("A Plague Rat");
    set("long", "%^RED%^This rat is much larger than any ordinary rodent.  The "
        "creature stands an easy eighteen inches at the shoulders and looks to "
        "be heavier than a large cat.  It has glowing red eyes and sharp looking "
       "teeth that %^RESET%^%^BOLD%^drip%^RESET%^%^RED%^ with %^BOLD%^%^GREEN%^"
        "venom%^RESET%^%^RED%^.  The rat's tail has been gnawed on in several "
        "places and it's scraggly coat of fur is torn free to reveal glistening "
        "white bones underneath.  Like so many other things on this cursed island,"
        "the rat is undead.%^RESET%^");
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set_mlevel("fighter",15);
    set_gender("male");
    set_race("undead");
    set_body_type("quadruped");
    set_alignment(9);
    set_ac(0);
    set_speed(35);
    nogo("one");
    set_property("swarm",1);
    set_attacks_num(3);
    set_exp(5000);
    set_new_exp(25,"normal");
    set("aggressive",25);
    set_size(1);
    set_stats("intelligence",1);
    set_stats("wisdom",4);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set_hp(roll_dice(5,10));
    add_money("gold",random(3));
    add_money("copper",random(5));
    set_funcs(({"bite"}));
    set_func_chance(5);
}

void bite(object targ)
{
    if(!ROLLSAVE(targ,PPD))
    {
        tell_object(targ,"%^GREEN%^The rat digs into your flesh with its poisoned "
            "teeth!%^RESET%^");
        tell_room(ETO,"%^GREEN%^The rat digs into "+targ->QCN+"'s flesh with its "
            "poisoned teeth!%^RESET%^",targ);
        targ->do_damage(targ->return_limb(),roll_dice(2,6));
        targ->add_poisoning(roll_dice(3,6));
        return;
    }

    tell_object(targ,"%^YELLOW%^The rat gnashes at you with its teeth but you "
        "dodge out of the way!");
    tell_room(ETO,"%^YELLOW%^The rat gnashes at "+targ->QCN+"with its teeth "
        "but "+targ->QS+" dodges out of the way!%^RESET%^",targ);
    return;
}
