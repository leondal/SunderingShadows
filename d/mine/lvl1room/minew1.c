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
You are in a large passageway in the huge mine of Shadowgate.  The
lighting is ever decreasing as you progress into the depths.
The walls also look a little more rocky and less taken care off; you
guess that this part of the mine is in use.  The railway travels
along here, leading east and northwest.
KAYLA    
    );
    set_exits(([
                "east" : "minexroad",
                "northwest" : "minew2"
    ]) );
set_items( ([
      "walls" :
@KAYLA
Faint traces of minerals can be detected on closer inspection, probably
minor pieces of only slightly valuable material that the miners have
ignored.
KAYLA      
]) );
}
