//	moat4.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@MOAT4
You are standing in the moat. You have reached the corner of the castle.
You see a long strip of water stretching out from here.
MOAT4
    );
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"west" : CASTLE+"moat3",
"north" : CASTLE+"moat5"
    ] ));
    set_items(([
       "fish" : "You see the fish in the clear water. It looks they are playing follow the leader.",
       "water" : "The water is here and making it possible for the fish to swim."
    ] ));
}
