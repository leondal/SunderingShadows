inherit "/std/weapon";
#include "std.h";
drop(str);

create() {
    ::create();
set_id(({"horn"}));
set_name("horn");
set_short("horn");
    set_property("monsterweapon",1);
   set_long(
"This is a two foot long, curved, wickedly pointed horn."
   );
   set_weight(1);
   set_size(1);
   set("value", 400);
   set_wc(40,40);
   set_large_wc(50,50);
   set_type("slashing");
}
