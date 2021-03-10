//  /d/dragon/town/build1.c
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Abandoned Building");
    set_long("%^BOLD%^%^BLUE%^
This is one of the many abandoned buildings in the city of %^CYAN%^Sanctuary%^BLUE%^.
The room contains a blood-soaked bed, an overturned trunk and a bearskin
rug.  The straw stuffing inside the mattress has been strewn across the
floor along with the contents of the trunk.
    ");
    set_exits(([
       "north" : "/d/dragon/town/roadE2"
    ] ));
    set_items(([
       "trunk" : "The trunk which lays on the floor turned upside down, contains\n"+
                  "pieces of hide and two wooden candlesticks, which are all \n"+
                 "worthless.\n"
    ] ));
}
