//Coded by Odin
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "curved blade", "elven curved blade", "blade" }));
   set_name("elven curved blade");
   set_short("An elven curved blade");
   set_long("Essentially a longer version of a scimitar, but with a thinner blade, the elven curve blade is exceptionally rare.");
   set_weight(7);
   set_size(3);
   set_value(80);
   set_wc(1, 10);
   set_large_wc(1, 10);
   set_type("slashing");
   set_weapon_speed(10);
   set_weapon_prof("exotic");
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
   set_property("finesse", 1);
}
