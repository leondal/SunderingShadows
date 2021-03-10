#include <std.h>

inherit MONSTER;

create()
{
    ::create();
    set_name("clone");
    set_id("clone");
    set_level(1);
    set_hd(1,1);
}
