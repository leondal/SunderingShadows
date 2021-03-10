#include <std.h>
inherit "/std/weapon";

void create() {
   ::create();
   set_id(({"sword", "double bladed sword"}));
   set_name("giant double bladed sword");
   set_short("giant double bladed sword");
   set_long(
      "This sword consist of steel and wood. The shaft of the weapon is crafted"+
      " in a fashion similar to a thick staff. Set on both sides of the staff are"+
      " long blades so that the wielder can use either side of the weapon"+
      " to attack, giving weapon much versatility in combat."
   );
   set_weight(20);
   set_size(4);
   set_value(50);
   set_wc(2,6);
    set_type("slashing");
   set_large_wc(2,6);
   set_weapon_prof("exotic");
   set_weapon_speed(10);
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
   set_property("double weapon", 1);
}
