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
This is the northwestern part of the Keep.  To the east is the
side of the armorer.  To the southwest is a guard tower, as well
as somewhat toward the northwest.  To the southeast is some kind
of arcane barracks.  The cobblestone path continues north-south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keepW6",
       "south" : "/d/deku/keep/keepW4"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
