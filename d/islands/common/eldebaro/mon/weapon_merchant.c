#include <std.h>
#include "../area_stuff.h"
inherit VENDOR;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"weapon merchant"}));
    set_items_allowed("weapon");
    set_storage_room(ELPATH+"w_storage");
}