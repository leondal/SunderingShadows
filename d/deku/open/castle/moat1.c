//	moat1.c
//	Written by : Pator@ShadowGate
//	Tue Apr 11 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_indoors(0);
    set_light(2);
    set_short("In the moat");
    set_long(
@PATOR
You are standing in the moat.  The water looks still fresh here.
You see some fish.
PATOR
    );
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"west" : CASTLE+"moat10",
"east" : CASTLE+"moat2",
"out"  : CASTLE+"castle1"
    ] ));
    set_items(([
       "fish" : "You see the fish in the clear water. It looks they are playing follow the leader."
    ] ));
}
