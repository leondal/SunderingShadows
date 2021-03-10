#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are just east of the entrance gate.  There seems to be some sort
of barracks just to the north.  The cobblestone path continues to the
east and to the west.  To the east is a small guard tower.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/barrack1",
       "west" : "/d/deku/keep/keep1",
       "east" : "/d/deku/keep/keepE2"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
