//	The Center of The Imperial Gardens of Tsarven
//	Thorn@Shadowgate
//	11/24/95
//	The Emperor's Palace, Tsarven
//	ebridge.c

#include <std.h>

inherit ROOM;

void create() {
  object ob;
    ::create();
    set_light(2);
    set_indoors(0);
    set_short("On a bridge in the Emperor's Garden");
		set_long(
@THORN
You are now standing on one of four bridges that leads to a small
gazebo on an island in the middle of a large pond.  This bridge 
emerges from a small grove of trees to the east.  Looking down, 
you notice that the pond drains into a little stream going in that
direction.  You notice the obvious sound of a waterfall.  
THORN
);
    set_exits(
              (["east" : "/d/tsarven/garden/glen1",
                "west" : "/d/tsarven/garden/gazebo"]) );
}

reset() {
	::reset();
	if(!present("impguard"))
		new("/d/tsarven/mon/impguard")->move(this_object());
}
