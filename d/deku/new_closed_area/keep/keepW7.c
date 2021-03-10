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
This is the northwestern part of the Keep.  To the south is the
Blacktongue's armorer.  To the northeast is a guard tower, as well
as somewhat toward the northwest.  The cobblestone path continues
to the east and west.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/keep/keep3",
       "south" : "/d/deku/keep/armorer",
       "west" : "/d/deku/keep/keepW6"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
