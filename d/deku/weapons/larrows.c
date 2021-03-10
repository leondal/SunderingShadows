#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id(({ "arrows","larrows", "quiver", "missiles" }));
   set_name("arrows");
   set_short("A quiver of flight arrows");
   set_long(
	"This is a quiver of flight arrows for a longbow. "
   );
   set_shots(20);
   set_wc(1,8);
   set_large_wc(1,8);
}
