#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Keep Blacktongue");
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Keep Blacktongue%^RESET%^
You are in the southeastern part of the Keep.  To the east is the
side of the pub.  To the northeast is an arcane looking barracks,
and to the northwest is another guard tower.  The cobblestone path
continues north and south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keepW4",
       "south" : "/d/deku/keep/keepW2"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
