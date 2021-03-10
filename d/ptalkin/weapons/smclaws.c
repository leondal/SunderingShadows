inherit "/std/weapon";
#include "std.h";
drop(str);

create() {
    ::create();
set_id(({"claws"}));
set_name("claws");
set_short("claws");
set_property("monsterweapon",1);
set_long("claws");
   set_weight(1);
   set_size(1);
set_wc(5,5);
set_large_wc(8,8);
   set_type("slashing");
}
