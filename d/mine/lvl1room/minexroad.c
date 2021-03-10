#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": -1, "indoors": 1 ]) );
    set_short("Crossroads in the mines");
    set_long(
@KAYLA
You are at a crossroads of sorts in the giant mines of Shadowgate.
A railing is here, obviously for the mine cars to ride along, 
leading east to west.  A large passageway has been carved along
the rail's path, however, so travel is possible along the
railways.  The main passageway of the mine continues north and
south.
KAYLA    
    );
    set_exits(([
                "north" : "minen1",
                "south" : "mine2",
                "east"  : "minee1",
                "west"  : "minew1"
    ]) );
set_items( ([
      "rail" :
@KAYLA
The metal portion of this railing looks quite sturdy, though thin.  Mine
cars would be very safe to ride along the railway.  However, I wouldn't
put money on how much weight the wooden planks could stand.
KAYLA      
]) );
}
