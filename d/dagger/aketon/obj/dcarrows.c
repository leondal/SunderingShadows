#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id( ({"arrows","dcarrows","quiver","missiles"}) );
   set_name("double crossbow arrows");
   set_short("A quiver of double crossbow arrows");
   set_long("This is a quiver of arrows for a double crossbow.");
   set_shots(20);
   set_wc(3,4);
   set_large_wc(3,4);
}
