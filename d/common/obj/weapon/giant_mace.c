//giant weapon by Circe 6/14/05
#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_id(({"mace","giant mace","large mace","huge mace"}));
   set_name("giant mace");
   set_short("A giant mace");
   set_long(
@GARRETT
This is a blunt striking weapon, suitable for fighting on foot or from
horseback.  The head of the mace is a single piece of cast iron, and the
handle is made from the heartwood of an oak tree.  This particular
version is massive, reaching nearly five feet in length.
GARRETT
   );
   set_weight(14);
   set_size(4);
   set_value(25);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_weapon_speed(6);
   set_weapon_prof("simple");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_damage_type("bludgeoning");
   set_property("repairtype",({"weaponsmith"}));
}
