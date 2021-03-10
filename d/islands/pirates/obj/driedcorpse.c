#include <std.h>
#include "../piratedefs.h"
inherit OBJECT;

void create() {
    ::create();
    set_id(({"corpse","dried up corpse","dried"}));
    set_name("corpse");
    set_short("A dried-up corpse");
    set_long("This is a dried-up human corpse, its skin shrivelled and parched from exposure.  It smells "
"absolutely terrible, and has probably remained here, unfound, for quite some time.  Only scraps of ragged "
"cloth enshroud the body, at a brief glance you can see nothing of value worth keeping, unless you take a "
"closer look?");
    set_weight(50);
    set_value(0);
}

