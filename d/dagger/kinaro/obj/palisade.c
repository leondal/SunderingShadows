#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/misc/street_light.c";

void create() {
    ::create();
    set_id(({"palisade","rough palisade","wooden palisade"}));
    set_name("wooden palisade");
    set_short("%^RESET%^%^ORANGE%^A rough wooden palisade%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^A rough wooden palisade%^RESET%^");
    set_dayShort("%^RESET%^%^ORANGE%^A rough wooden palisade%^RESET%^");
    set_nightShort("%^RESET%^%^ORANGE%^A rough wooden palisade%^RESET%^");
    set_long("%^ORANGE%^This thick palisade is formed of heavy %^RED%^redwood "
"%^ORANGE%^trunks, hacked free of limbs and branches and stacked to block "
"most of the passageway.  Only small openings across the top and upon the "
"left side would allow any way past them.%^RESET%^");
}
