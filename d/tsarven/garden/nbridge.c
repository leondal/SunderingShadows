//	The Center of The Imperial Gardens of Tsarven
//	Thorn@Shadowgate
//	11/24/95
//	The Emperor's Palace, Tsarven
//	nbridge.c

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
gazebo on an island in the middle of a large pond.  From here you 
can look over the side of the bridge and look at the blooming
water lilies float below you.  The water of the pond is calm and
very clear, so calm you see your reflection in the water as if in a
mirror.  Every so often a soft breeze passes over the water making 
tiny ripples and disturbing the scene ever so slightly.  Then
the peaceful scene returns as before to entrance another soul.
The gazebo is to the south, the Imperial Rose Garden is to the north.
THORN
);
    set_exits(
              (["north" : "/d/tsarven/garden/rose1",
                "south" : "/d/tsarven/garden/gazebo"]) );
}
