#include <std.h>
inherit "/std/weapon";

void create() {
   ::create();
   set_name("butchering axe");
   set_id(({ "axe", "butchering axe" }));
   set_short("butchering axe");
   set_long(
      "A creation of orc smiths, this axe has an oversized head bristling with spikes "+
       "and a long, thick haft that only barely counterbalances its weight."
   );
   set_value(65);
   set_size(3);
   set_type("slashing");
   set_prof_type("double axe");
   set_weapon_prof("exotic");
   set_wc(3,6);
   set_large_wc(3,6);
   set_weight(25);
   set_weapon_speed(11);
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}