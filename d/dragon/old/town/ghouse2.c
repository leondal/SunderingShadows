//  /d/dragon/town/ghouse2.c
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_short("Crumbled Guardhouse");
    set_long("%^BOLD%^%^RED%^
%^YELLOW%^Rebuilt Guardhouse%^RED%^
Several of the chamber's walls show signs of recent repair.  Huge holes
have been replaced with solid brickwork, and pieces of wood that have
fallen from the ceiling lie neatly stacked on the floor.  Through a
hole in the ceiling, you can see the upper level of the gate house, but
there is no sign of stairs or ladders.
    ");
    set_exits(([
       "west" : "/d/dragon/town/shit"
    ] ));
    set_items(([
    ] ));
}
