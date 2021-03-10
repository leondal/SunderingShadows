#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id( ({"arrows","carrows","quiver","missiles"}) );
   set_name("crossbow arrows");
   set_short("A quiver of crossbow arrows");
   set_long("This is a quiver of arrows for a crossbow.");
   set_shots(20);
   set_wc(3,3);
   set_large_wc(3,3);
}
