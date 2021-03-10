inherit "/std/weapon";
#include "std.h";
drop(str);

create() {
    ::create();
set_id(({"claw"}));
set_name("claw");
set_short("a claw");
    set_property("monsterweapon",1);
   set_long(
"This is a long claw, to be found on many types of beasts, fowls and the undead"
   );
   set_weight(1);
   set_size(1);
   set("value", 400);
   set_wc(40,40);
   set_large_wc(50,50);
   set_type("slashing");
}
