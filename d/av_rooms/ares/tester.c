// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tester");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("short desc");

    set_long("long desc");

    set_smell("default","
smells bad");
    set_listen("default","sounds worse");

}