#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Northern Plains");
    set_terrain(NAT_CAVE);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
%^YELLOW%^Northern Plains%^RESET%^
The entrance to this cave is dark and lonesome.  Light bellows 
up above but further into the cave, light becomes darkness.  
What eerie thing could lie within.
KAYLA
    );
     set_listen("default","A long moan can be heard, or maybe it's just the wind from above.");
    set_exits(([
       "up" : "/d/deku/plains/plains15",
       "north" : "/d/deku/plains/cave02"
    ] ));
    set_items(([
       "walls" : "The walls are natural made.  Rough stone lines the walls and ceiling."
    ] ));
}
