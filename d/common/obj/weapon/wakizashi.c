#include <std.h>
inherit "/std/weapon";

void create()
{
    ::create();
    set_id(({ "sword", "wakizashi", "blade", "dagger" }));
    set_name("wakizashi");
    set_short("A wakizashi");
    set_long("This long curved blade is of a metal " +
             "you've never seen.   Its shiny blade has kept an" +
             " incredible edge, even though the sword's been " +
             "through a lot from the wear on its hilt.");
    set_weight(4);
    set_size(1);
    set_prof_type("short blades");
    set_value(75);
    set_wc(1, 6);
    set_large_wc(1, 6);
    set_type("slashing");
    set_weapon_speed(3);
    set_weapon_prof("exotic");
    set_critical_threat_range(2);
    set_critical_hit_multiplier(3);
    set_damage_type("slashing");
    set_property("repairtype", ({ "weaponsmith" }));
}
