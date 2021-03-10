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
This is the northeastern part of the Keep.  To the south is the
Blacktongue's smithy.  To the northwest is a guard tower, as well
as somewhat toward the northeast.  The cobblestone path continues
to the east and west.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/keep/keep3",
       "south" : "/d/deku/keep/smithy",
       "east" : "/d/deku/keep/keepE6"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
