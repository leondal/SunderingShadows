inherit "/std/weapon";
#include "std.h";
drop(str);

create() {
    ::create();
set_id(({"hoof"}));
set_name("hoof");
set_short("hoof");
    set_property("monsterweapon",1);
   set_long(
"This is a hoof, large, with very sharp edges, has this thing been filing them?"
   );
   set_weight(1);
   set_size(1);
   set("value", 400);
   set_wc(40,40);
   set_large_wc(50,50);
   set_type("slashing");
}
