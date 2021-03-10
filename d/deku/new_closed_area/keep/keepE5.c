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
This is the northeastern part of the Keep.  To the west is the
side of the smithy.  To the southeast is a guard tower as well
as another somewhat northeast.  To the southwest is some kind
of arcane magic shop.  The cobblestone path continues north-south.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keepE6",
       "south" : "/d/deku/keep/keepE4"
    ] ));
    set_smell("default","Dust and ale permeate the halls of this Keep.");
    set_items(([
    ] ));
}
