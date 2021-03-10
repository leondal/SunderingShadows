//     /d/dragon/tower1/room2.c

#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Ivory Tower");
    set_long("%^BLUE%^%^BOLD%^
This is obviously someone's bedroom.  There is a large bed, a small table with    
a silver globe attached to a black base, and a trunk beneath the bed.  A
strange stone construction juts out of the southeast corner.
    ");
    set_exits(([
       "west" : "/d/dragon/tower2/tower"
    ] ));
    set_listen((["default","There is a very slight howl within the wind."]));
    set_items(([
        "trunk" : "The trunk opens easily, but the contents inside have been stolen.",
       "stone construction" : " A toilet-sink constructed of stone.",
       "globe" : "A 1' diameter silver sphere enchanted with magic.  It is\n"+
                 "fixed in place and impossible to remove."
    ] ));
}
