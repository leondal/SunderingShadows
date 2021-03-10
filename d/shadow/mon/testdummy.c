//adapted from Ares' testdummy for new Seneca
//used in the mage guild
//~Circe~ 1/9/08
#include <std.h>

inherit "/std/monster.c";

void create()
{
    ::create();
    set_name("dummy");
    set_id(({ "dummy", "test dummy", }));
    set_race("test dummy");
    set_body_type("human");
    set_short("ooc test dummy");
    set_long("Come at me, bro!");
    set_hd(1, 1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(10000000);
}

int do_typed_damage_effects(victim, limb, damage, damage_type)
{
    tell_room(ETO, "%^MAGENTA%^Dummy says%^RESET%^: I got hit to " + limb + " for " + damage + " " + damage_type + " damage!");
    return damage;
}
