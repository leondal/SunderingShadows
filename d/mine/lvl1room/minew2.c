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
The passageway drops a few meters of altitude here, as the tunnel
weaves its way into the depths of the ground.  The torches from
the previous tunnels are of practically no use here.  The railing
continues northwest and southeast here.
KAYLA    
    );
    set_exits(([
                "northwest" : "minew3",
                "southeast" : "minew1"
    ]) );
set_items( ([
      "railing" :
@KAYLA
The metal minecar railing is following the passageway here.
KAYLA
]) );
}
