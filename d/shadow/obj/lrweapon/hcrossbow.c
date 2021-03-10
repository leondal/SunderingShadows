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
   set_weight(20);
   set_size(2);
   set("value", 30);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_two_handed();
   set_lr_prof_type("crossbow");
   set_prof_type("medium clublike");
   set_rate_of_fire(4);
   set_range(7,12,17);
   set_ammo("heavy quarrels");
   set_decay_rate(100);
}
