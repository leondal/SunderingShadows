#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("City Glazier");
    set_long("%^BOLD%^%^BLUE%^
This building's contents are in utter disarray.  The floor of the building
is covered with broken glass.  The walls are lined with wooden display
shelves, several of which have been knocked over.  Every piece of furniture
in this room has been knocked over, pulled down or smashed to bits.  Only
a few glasses and dishes remain unbroken amidst the thousands of shattered
pieces.
    ");
    set_exits(([
       "east" : "/d/dragon/town/roadS3"
    ] ));
    set_items(([
    ] ));
}
