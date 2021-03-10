#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("no teleport", 1);
    set_short("You shouldn't be here.");
    set_long("You shouldn't be here.");
    set_exits( (["out" : "/d/shadowgate/adv_main.c"]) );
}
