#include <std.h>
#include "../area_stuff.h"
inherit VENDOR;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"general merchant"}));
    set_items_allowed("misc");
    set_storage_room(ELPATH+"gs_storage");
}