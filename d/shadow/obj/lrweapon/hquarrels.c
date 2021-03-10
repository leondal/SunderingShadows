#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id(({ "heavy quarrels","quarrels", "bolts", "quiver" }));
   set_name("arrows");
   set_short("A quiver of heavy crossbow bolts");
   set_long(
@OLI
   This is a quiver of approximately two foot long quarrels. They are
obviously for the heavy crossbow. These bolts when fired can pierce armor
and do a lot of damage.
OLI
   );
   set_shots(20);
   set_wc(1,10);
   set_large_wc(1,10);
   set_ammo_type("heavy quarrels");
}
