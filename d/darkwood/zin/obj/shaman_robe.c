#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("robe");
    set_id( ({"robe", "shaman robe"}) );
    set_short("A hooded black Shaman robe");
    set_weight(10);
    set_type("clothing");
    set_ac(1);
    set_limbs( ({"torso", "right arm", "left arm", "head"}) );
    set_value(150);
    set_long("This is a very large black robe.  It contains a "+
             "dark hood which enables the user to hide their "+
             "face in the shadows which it casts.  The ends of "+
             "the sleeves are very wide, and crested with what "+
             "appears to be some ancient runes.");
}
