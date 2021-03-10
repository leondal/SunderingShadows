#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id( ({"arrows","tcarrows","quiver","missiles"}) );
   set_name("triple crossbow arrows");
   set_short("A quiver of triple crossbow arrows");
   set_long("This is a quiver of arrows for a triple crossbow.");
   set_shots(20);
   set_wc(3,5);
   set_large_wc(3,5);
}
