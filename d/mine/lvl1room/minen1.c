#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Passageway in a Mine");
    set_long(
@KAYLA
The large main passageway continues here, leading south back to the
crossroads, or north to the mine proper.  The walls here are well
worn after years of mining.  You see some sort of obstruction
to the north, but you can't make any details out from here.
KAYLA
    );
    set_exits(([
       "north" : "minen2",
       "south" : "minexroad"
    ] ));
    set_items(([
       "walls" : "A thousands picks have struck this wall.",
       "obstruction" : "You can't really see what it is from here, maybe you should go and find out what it is."
    ] ));
}
