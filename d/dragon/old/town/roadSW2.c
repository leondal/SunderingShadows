#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long("%^CYAN%^%^BOLD%^
This is a side street through the town of %^GREEN%^Sanctuary%^CYAN%^.  Buildings
line the street.  This place, buildings and all, looks as though something
terrible has ravaged the land.  The street is bare except for the few
strange people walking around.  To the east a sign reads %^RED%^Sanctuary
Bank%^CYAN%^ and a sign to the west reads %^RED%^Blacksmith%^CYAN%^.
    ");
    set_exits(([
        "south" : "/d/dragon/town/mshop",
        "north" : "/d/dragon/town/roadSW1",
        "west" : "/d/dragon/town/wshop",
       "east" : "/d/dragon/town/bank"
    ] ));
    set_items(([
    ] ));
}
