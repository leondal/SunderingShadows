#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange objects.  The tunnel stretches off for miles 
toward the south.  Light comes from the room toward the east.
    ");
    set_exits(([
       "east" : "/d/dragon/sewer/sewer01",
       "south" : "/d/dragon/sewer/sewer06"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}
