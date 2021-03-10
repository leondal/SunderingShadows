#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long("%^BOLD%^%^CYAN%^
This is the main street through the town of %^GREEN%^Sanctuary%^CYAN%^. Buildings
seem to line the street eastward and westward.  This is the more residence
side of %^GREEN%^Sanctuary%^CYAN%^.  The streets are bare except for the few strange
people walking the streets.  In the front of the residence to the north,
an old horse-drawn cart sits with its wheels mired in mud.
    ");
    set_exits(([
        "east" : "/d/dragon/town/roadE4",
       "north" : "/d/dragon/town/build2",
       "west" : "/d/dragon/town/roadE2"
    ] ));
    set_items(([
       "cart" : "You know from rummors that Ezekiel wants to leave the town\n"+
                 "but cannot afford to buy horses from the local traders to \n"+
                 "pull the cart that sits in the front yard.\n"
    ] ));
}
