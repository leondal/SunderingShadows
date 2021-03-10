#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("soft boots");
    set_id(({"soft boots","boots","boots of soft leather"}));
    set_short("boots of soft leather");
    set_long("This is a pair of boots made from soft leather.  They "+
       "provide a little protection, but not much.  They will, however, "+
       "keep your feet toasty warm.");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(1);
}
