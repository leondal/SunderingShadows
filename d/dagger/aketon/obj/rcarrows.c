#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id( ({"arrows","rcarrows","quiver","missiles"}) );
   set_name("rosewood crossbow arrows");
   set_short("A quiver of rosewood crossbow arrows");
   set_long("This is a quiver of arrows for the rosewood crossbow made by "
      "Ziliot the archer in Aketon.");
   set_shots(40);
   set_wc(2,5);
   set_large_wc(3,5);
}
