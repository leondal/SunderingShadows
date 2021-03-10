#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "staff", "quarter staff", "wooden staff", "quarter_staff" }));
    set_name("staff");
    set_short("A mithril-banded quarter staff");
    set_long("This is a sturdy six foot long wooden staff.  It has bands of mithril around its far edges and along its length to afford it more support.  A staff as a traveling tool has many uses, of which the street thugs are aware enough of one to keep away from them.");
    set_property("enchantment", 1);
    set_wc(1,6);
    set_large_wc(1,6);
    set_weight(4);
    set_size(3);
    set("value", 310);
    set_type("bludgeoning");
    set_prof_type("staff");
   set_weapon_speed(4);
   set_weapon_prof("simple");
}
