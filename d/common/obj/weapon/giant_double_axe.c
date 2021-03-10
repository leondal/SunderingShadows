#include <std.h>
inherit "/std/weapon";

void create() {
   ::create();
   set_name("giant double axe");
   set_id(({"axe", "double axe"}));
   set_short("giant double axe");
   set_long(
      "This axe was built from strong metals to form a sturdy shaft between"+
     " the two full battle axes connected to each end of the weapon. This allows"+
      " a well trained person to use both axes in combat."
   );
   set_value(50);
   set_size(4);
   set_type("slashing");
   set_prof_type("double axe");
   set_weapon_prof("exotic");
   set_wc(2, 6);
   set_large_wc(2, 6);
   set_weight(20);
   set_weapon_speed(11);
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
   set_property("double weapon", 1);
}
