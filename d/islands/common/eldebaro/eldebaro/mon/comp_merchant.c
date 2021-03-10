#include <std.h>
#include "../area_stuff.h"
inherit "/std/comp_vend.c";

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"comp merchant"}));
    set_components(250);
}