#include <std.h>
inherit WEAPON;
create() {
    ::create();
   set_id(({ "pick" }));
   set_name("icepick");
set_short("icepick");
   set_long("this is a freshly sharpened icepick.");
   set_weight(1);
   set_size(1);
   set("value", 100);
   set_wc(3,5);
   set_large_wc(3,5);
set_type("slash");
   set_prof_type("tool");
set_property("enchantment", 2);
}
