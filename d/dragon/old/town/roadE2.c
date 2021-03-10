#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long(
@GRAY
%^CYAN%^%^BOLD%^This is the main street through the town of %^GREEN%^Sanctuary%^RESET%^%^CYAN%^%^BOLD%^.  Buildings
%^CYAN%^%^BOLD%^seem to line the street eastward and westward.  This place looks as
%^CYAN%^%^BOLD%^though something terrible has ravaged the land.  The street is pretty
%^CYAN%^%^BOLD%^bare except for the few strange people walking the streets. The
%^CYAN%^%^BOLD%^sign over the north door reads %^RED%^Stables%^CYAN%^.
GRAY
    );
    set_exits(([
        "east" : "/d/dragon/town/roadE3",
       "north" : "/d/dragon/town/stable",
       "south" : "/d/dragon/town/build1",
       "west" : "/d/dragon/town/roadE1"
    ] ));
    set_items(([
    ] ));
}
