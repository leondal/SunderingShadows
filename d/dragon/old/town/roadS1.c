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
strange people walking around.  To the east a sign reads %^RED%^Armorer
%^CYAN%^and the street continues to the north and south.
    ");
    set_exits(([
        "south" : "/d/dragon/town/roadS2",
        "north" : "/d/dragon/town/square",
         "west" : "/d/dragon/town/storage",
       "east" : "/d/dragon/town/armorer"
    ] ));
    set_items(([
    ] ));
}
