#include <std.h>

inherit OBJECT;


void create() {
    ::create();
   set_id(({"bait","worm","earthworm"}));
    set_name("worm");
    set("short", "earthworm");
    set("long", "A long and juicy worm.\n");
    set_weight(0);
    set("value", 1);
}

