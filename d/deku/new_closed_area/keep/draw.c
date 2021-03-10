#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_short("Drawbridge to Keep Blacktongue");
    set_long(
@KAYLA
%^YELLOW%^Drawbridge to Keep Blacktongue%^RESET%^
You stand in front of the drawbridge to Keep Blacktongue.  The 
walls of the keep are made of black brick.  The Keep walls are
some 20' high and are well fortified.  There seems to be a lot
of movement coming from within the Keep.  In the middle of the
Keep rises a huge tower with small buildings surrounding it.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/keep/keep1",
       "south" : "/d/deku/open/dforest8-6"
    ] ));
    set_items(([
       "walls" : "Some 20' high, the walls to the Keep are well fortified.",
       "drawbridge" : "The drawbridge spans some 30' across."
    ] ));
}

void reset() {
  ::reset();
  if(!present("kguard")) {
    new("/d/deku/keep/monster/keep_guard")->move(TO);
  }
}
