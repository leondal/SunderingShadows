#include <std.h>
#include "../area_stuff.h"
inherit VENDOR;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"armor merchant"}));
    set_items_allowed("armor");
    set_storage_room(ELPATH+"a_storage");
}