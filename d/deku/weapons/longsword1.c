#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
  set_id(({"sword", "longsword"}));
  set_name("longsword");
  set_short("A longsword");
   set_long(
        "A crude longsword."
   );
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slash");
}


