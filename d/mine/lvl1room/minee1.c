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
You are in a large passageway in the huge mine of Shadowgate.
The torches' flicker is dimmer as you travel further into the mine.
The walls also look a little more rocky and less taken care off; you
guess that this part of the mine is in use.  The railway travels
along here, leading west and northeast.
KAYLA    
    );
    set_exits(([
                "west" : "minexroad",
                "northeast" : "minee2"
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
