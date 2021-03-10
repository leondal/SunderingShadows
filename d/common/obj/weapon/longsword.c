#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "sword", "longsword", "long sword" }));
    set_name("longsword");
    set_short("A long sword");
    set_long("This is a straight bladed, double-edged sword, commonly known as a "
    "longsword.  "
    "The blade is thinner than the broad and bastard sword, but a bit longer.  "
    "It looks very effective, as its combination of an edge, point, speed and "
    "length makes it more versatile than many other weapons.");
    set_weight(4);
    set_size(2);
    set_value(15);
    set_wc(1,8);
    set_large_wc(1,8);
    set_type("slashing");
    set_weapon_speed(5);
    set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}

string ldesc(string str) {
  return("This is a straight bladed, double-edged sword, commonly known as a "
    "longsword.  "
    "The blade is thinner than the broad and bastard sword, but a bit longer.  "
    "It looks very effective as its combination of an edge, point, speed and "
    "length make it more versatile than many other weapons.");
}
