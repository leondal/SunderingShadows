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
line the street to the north and south.  This place, buildings and all,
looks as though something terrible has ravaged the land in the near past.
The street is bare except for the few strange people walking around.
To the east a sign over the door reads %^RED%^Herbalist%^CYAN%^.
    ");
    set_exits(([
        "south" : "/d/dragon/town/roadS3",
        "north" : "/d/dragon/town/roadS1",
       "east" : "/d/dragon/town/hshop"
    ] ));
    set_items(([
    ] ));
}
