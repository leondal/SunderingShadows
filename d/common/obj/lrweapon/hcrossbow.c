#include <std.h>
inherit LRWEAPON;

create() {
   ::create();
   set_id(({ "crossbow", "bow", "heavy cross bow"}));
   set_name("heavy crossbow");
   set_short("Heavy Crossbow");
   set_long(
@OLI
 This is a cross of two heavy pieces of wood. There is a taught
twine connecting the two ends of the cross piece. This is more
correctly referred to as the two foot cross bow. This bow is fitted
with a windlass to allow for a more powerful twine and a faster reload.
OLI
            );
   set_weight(8);
   set_size(2);
   set("value", 30);
   set_wc(1,10);
   set_large_wc(1,10);
   set_type("piercing");
   set_two_handed();
   set_lr_prof_type("crossbow");
   set_weapon_prof("simple");
  set_prof_type("club");
   set_rate_of_fire(4);
   set_range(7,12,17);
   set_ammo("heavy quarrel");
   set_decay_rate(100);
   set_property("repairtype",({"woodwork"}));
   set_weapon_speed(4);
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
}
