#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
set_id(({ "sword" }));
set_name("sword");
set_short("A sword");
set_long("This is a finely crafted sword, and you will forever treasure it.");
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slash");
}


