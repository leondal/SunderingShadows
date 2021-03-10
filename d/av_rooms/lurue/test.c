// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("blah");

    set_long("blah");

    set_smell("default","
blah");
    set_listen("default","blah");

}