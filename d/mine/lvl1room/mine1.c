#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": 0, "indoors": 1 ]) );
    set_short("Entryway in a mine");
    set_long(
@KAYLA
You in a well kept up entraway into a large commercial mining operation.
Small torches are attached to the walls, giving the mine an eerie flicker.
The walls are smoothed here, obviously stripped of all the valuable
elements within.  The corridor leads south to the entrance, and north
deeper into the mine. 
KAYLA    
    );
    set_exits(([
                "north" : "mine2",
                "south" : "enter"
    ]) );
set_items( ([
      "torches" :
@KAYLA
The torches are securely fastened to the walls, and give off a semi
constant red glow, lighting the passageway.
KAYLA
,
      "walls" :
@KAYLA
The walls are as smooth and as cold as ice.
KAYLA            
]) );
}
