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
You are in the southwestern part of the Keep.  To the west is the
side of the barracks.  To the northwest is an arcane looking shop
and to the northeast is another guard tower.  The cobblestone path
continues north and south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keepE4",
       "south" : "/d/deku/keep/keepE2"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
