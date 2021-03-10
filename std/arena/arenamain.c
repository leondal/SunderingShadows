#include <std.h>
#include <arena.h>

inherit ROOM;

void create(){
    ::create();
    set_property("no teleport", 1);
    set_property("arena entrance", 1);
    set_travel(DIRT_ROAD);
    set_terrain(CITY);
}

void init(){
    ::init();
    add_action("enter", "enter");
}

int enter(string str){
    if (str != "arena") {
        return 0;
    }

    tell_object(TP, "You are entering the arena prepared for mock combat.");
    TP->set_property("safe arena", 1);

    return 1;
}

void set_enter_room(string str)
{
    set_property("enter room", str);
}
