#include <std.h>
#include <conf.h>
#include <rooms.h>

inherit ROOM;

nosave private object* old;

void create()
{
    ::create();
    set_property("light", 1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set("short", "The freezer");
    set("long", "The local freezer.  A place for the link-dead.");
    set_exits((["exit" : "/d/shadow/room/forest/road30"]));
    set_pre_exit_functions(({ "exit" }), ({ "GoThroughDoor" }));
    set_no_clean(1);
    call_out("clean_room", MAX_NET_DEAD_TIME);
}

void clean_room()
{
    object* in_here, * to_clean;
    int i;

    if (!sizeof(in_here = livings() & all_inventory(this_object()))) {
        old = in_here;
        call_out("clean_room", MAX_NET_DEAD_TIME);
        return;
    }
    i = sizeof(to_clean = in_here & (pointerp(old) ? old : ({})));
    old = in_here - to_clean;
    while (i--) {
        to_clean[i]->clean_net_dead();
    }
    i = sizeof(to_clean = all_inventory(this_object()) - in_here);
    while (i--) {
        to_clean[i]->remove();
    }
    call_out("clean_room", MAX_NET_DEAD_TIME);
}

int GoThroughDoor()
{
    if (!objectp(TP)) {
        return 0;
    }
    if (!newbiep(TP)) {
        return 1;
    }
    write("You drift back to where you belong.");
    TP->move_player("/d/newbie/rooms/town/square");
    return 0;
}
