#include <std.h>
#include "../area_stuff.h"
inherit NPC;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"eldebaro_healer", "nomad"}));
}