#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "staff", "quarter","quarter staff","shillelagh",
        "wooden staff", "fine wooden staff", "quarter_staff" }));
    set_name("quarter staff");
    set_short("A wooden quarter staff");
    set_long(
   "This is a sturdy six foot long wooden staff.  It has bands of metal "
   "tightened around its far edges and along its length to afford it more "
   "support.  A staff as a traveling tool has many uses and the street "
   "thugs are aware enough of one to keep away from them."
    );
    set_wc(1,6);
    set_large_wc(1,6);
    set_weight(4);
    set_size(3);
    set("value", 3);   
    set_type("bludgeoning");
    set_prof_type("staff");
   set_weapon_speed(4);
}
