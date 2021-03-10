#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "short sword", "a short sword", "short" }));
  set_name("shortsword");
   set_short("A short sword");
   set_long(
  "  This short sword is a perfect weapon for some, a good backup weapon for others."
   "  It's shorter than the average sword but that just makes it more manageable, while its sharp edge and point could never be counted completely out by an opponent."
   );
   set_weight(4);
   set_size(1);
   set_prof_type("short blades");
   set("value", 10);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("slashing");
   set_weapon_speed(3);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
