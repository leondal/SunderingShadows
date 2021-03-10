#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
  set_id(({"bolts","quiver","crossbow bolts"}));
  set_name("heavy quarrels");
  set_short("Quiver of crossbow bolts");
   set_long(
    "  This is a quiver of short sturdy looking crossbow bolts.  The whole bolt is made of steel but the head gleams with the silver of mithril.  You doubt there is much that could stop these."
   );
   set_shots(20);
    set_value(10);
    set_wc(2,6);
  set_large_wc(2,6);
}
