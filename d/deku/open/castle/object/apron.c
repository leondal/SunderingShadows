#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("apron");
    set_id( ({"apron", "armour"}) );
    set_short("An ancient Smithing apron");
    set_weight(10);
    set_type("leather");
    set_ac(1);
    set_limbs( ({"torso", "right arm", "left arm"}) );
    set_value(15);
    set_long("This finely crafted apron has been fashioned from the "+
             "thick hide of some creature now long extinct.  Its "+
             "unusual stitching and foreign design foretell of "+
             "ancient workmanship.  It appears unmarked even after "+
             "the many centuries of use by the forge.");
}
