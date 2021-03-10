#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id(({"arrows","quiver","missiles","shortbow arrow","shortbow arrows"}));
   set_name("arrows");
   set_short("A quiver of arrows");
   set_long(
      "This is a quiver of arrows for a short bow."
   );
   set_shots(20);
   set_wc(1,6);
   set_large_wc(1,6);
   set_ammo_type("shortbow arrow");
}
