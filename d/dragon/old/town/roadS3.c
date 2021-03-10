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
You notice that over the city wall to the south, the forest extends.
The sign over the west door reads %^RED%^City Glazier%^CYAN%^.
    ");
    set_exits(([
        "exit" : "/d/deku/plains/road35",
        "north" : "/d/dragon/town/roadS2",
       "west" : "/d/dragon/town/glazier"
    ] ));
    set_items(([
    ] ));
}
