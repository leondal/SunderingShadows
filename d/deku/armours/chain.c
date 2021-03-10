#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
    ::create();
    set_name("chain");
    set_id(({"chain", "chainmail"}));
    set("short", "A suit of chainmail");
     set("long", "Elven chainmail.  This armor is made of interlocking\n"+
                "metal rings.  It is always worn with a layer of quilted\n"+
               "fabric underneath, to prevent painful chafing and to\n"+
               "cushion the impact of blows.  It fits perfectly on \n"+
                "your torso area.  It also seems to be lightweight.\n");
    set("value", 125);
}
