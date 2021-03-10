#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": -1, "indoors": 1 ]) );
    set_short("Dank Passageway in a Mine");
    set_long(
@KAYLA
You are standing in a dank portion of the mine of Shadowgate.  The
hallways are getting darker as you progress deeper into the cavern.
To the northeast you see what looks like a drop off of some kind.
The railing continues along here, making the turn from the southwest
to the northeast.
KAYLA    
    );
    set_exits(([
                "northeast" : "minee3",
                "southwest" : "minee1"
    ]) );
set_items( ([
      "railing" :
@KAYLA
The metal minecar railing is following the passageway here.
KAYLA
]) );
}
