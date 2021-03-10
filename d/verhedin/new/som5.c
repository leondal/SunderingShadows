// Prophet Square, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^MAGENTA%^Prophet Square, Verhedin%^RESET%^");
  set_long("%^BOLD%^MAGENTA%^Prophet Square, Verhedin%^RESET%^\n"
    "You are at the intersection of two streets through the city.  Everything\n"
    "around you seems to be chaos.  There are street merchants on the edges\n"
    "of the square selling birds and goats from stalls.  On the corners,\n"
    "grubby mad prophets scream out their messages about the end of the\n"
    "world, or the coming of a Golden Age.  Grubby diviners tell fortunes in\n"
    "entrails and with tea leaves all around and pilgims sacrifice animals on\n"
    "portable altars to their gods. \n"
    "\n"
    "To the northeast, you see a store whose %^BOLD%^BLUE%^dark blue awnings"
    "%^RESET%^ are covered\n"
    "with %^BOLD%^YELLOW%^arcane symbols in gold%^RESET%^.  To the northwest,"
    "there is a ornate\n"
    "keyhole shaped entry to a shop with %^RED%^red awnings%^RESET%^ and"
    " %^WHITE%^BOLD%^silver runes%^RESET%^ sown\n"
    "into them.  To the southeast, you see what appears to be a temple of\n"
    "some kind, although you see no indication of the god to whom it is\n"
    "dedicated.  Finally, to the southwest, you see an entry to a stone\n"
    "building with large glass display windows.\n"
    "\n"
    "There is a signpost here.\n"
  );
  set_exits(([
    "north" : VNEW+"som4",
    "west" : VNEW+"aoa2",
    "south" : VNEW+"som6",
    "east" : VNEW+"aoa3",
    "northeast" : VNEW+"alhazred",
    "northwest" : VNEW+"fatwah",
    "southeast" : VNEW+"utemple",
    "southwest" : VNEW+"ali"
    ]));
  set_listen("default","You hear a maddening babble of vendors and preachers.");
  set_smell("default","The overwhelming smells of this area are blood, burnt flesh and stale perspiration.");
  set_items( ([
    "signpost" : "%^RED%^BOLD%^North - South:%^WHITE%^ Street of the Merchants\n"
	             "%^RED%^BOLD%^East - West:  %^WHITE%^ Avenue of the Astrologers",
  ]) );
}

void reset(){
	::reset();
}
