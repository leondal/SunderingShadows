
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long" }));
   set_name("longsword");
   set_short("A long sword");
   set_long(
        "This is a shiney, well kept long sword. "
   );
   set_weight(7);
   set_size(2);
   set("value", 15);
   set_wc(1,8);
   set_large_wc(1,12);
set_type("slash");
}
