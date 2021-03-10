#include <std.h>
#include "../area_stuff.h"
inherit "/std/comp_vend.c";

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"psion merchant"}));
    set_shop_type("psion");    
    set_components(250);
}