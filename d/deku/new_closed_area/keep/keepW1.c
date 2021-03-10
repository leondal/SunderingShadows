#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are just to the west of the entrance gate of Keep Blacktongue.
To the north there is a pub.  Obviously a lot of people are there
because you hear a lot of noise.  The cobblestone path continues to
the east and west.  To the west is a small guard tower and, in the 
middle of the Keep, a huge tower rises.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/pub",
       "west" : "/d/deku/keep/keepW2",
       "east" : "/d/deku/keep/keep1"
    ] ));
    set_listen("default","There seems to be a lot of noise coming from the north.");
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
