#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
  set_id(({"sword", "longsword"}));
  set_name("longsword");
  set_short("A longsword");
   set_long(
        "An elite longsword."
   );
   set_weight(4);
   set_size(2);
   set("value", 50);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slashing");
   set_wield("You grip a fine crafted sword.");
   set("read", "Can you read this?");
}


