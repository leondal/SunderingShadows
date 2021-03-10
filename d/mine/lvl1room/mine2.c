#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": 0, "indoors": 1 ]) );
    set_short("Passageway in a mine");
    set_long(
@KAYLA
The passageway here continues north and south, leading to what looks
to be a crossroads of passages.  You can faintly hear the sounds
of mine cars swiftly carrying minerals from place to place.
A pair of torches adorn the walls, for decoration and for light.
To the south, you can see the blaring light from the outside.
KAYLA    
    );
    set_exits(([
                "north" : "minexroad",
                "south" : "mine1"
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
The walls here are less smooth as to the south, but are still bare of
elements.
KAYLA            
]) );
}
