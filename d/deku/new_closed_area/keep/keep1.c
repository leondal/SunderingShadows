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
You are standing just inside the entrance gates of the Keep.  To
the south is the drawbridge out.  To the north is a path leading
to the looming tower.  There is a path going east and west along
the battlements of the keep.  To the east there seems to be a two
story building and to the west you see the Keep's pub.
KAYLA
    );
    set_listen("default","A lot of noise seems to be coming from the west.");
    set_smell("default","Dust and the smell of ale permeate the halls of this Keep.");
    set_exits(([
       "south" : "/d/deku/keep/draw",
       "north" : "/d/deku/keep/keep2",
       "west" : "/d/deku/keep/keepW1",
       "east" : "/d/deku/keep/keepE1"
    ] ));
    set_items(([
    ] ));
}
