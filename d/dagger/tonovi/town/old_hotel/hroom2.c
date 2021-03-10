#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("store");
    set_short("Hotel room");
    set_long(
    "You are in one of the opulent rooms of the hotel.  In it, among other pieces of furniture, are a wardrobe, bed, and a large soft chair.  The rug under you softly cushions your feet.  The first thing you can think is... \n    %^RED%^Don't touch anything!!...   %^RESET%^You could get it dirty.  (You really need a bath)"
    );
    set_listen("default", "You can hear an orchestra playing in the distance.");
    set_smell("default", "You can smell the burning of the scented candles.");

    set_items( ([
      "bed" : "The large soft bed looks inviting.",
      "wardrobe" : "Looks like clothes go in there.",
      "chair" : "You're afraid to sit in it, you could get it dirty.",
      "rug" : "The beautiful rug is getting dirty as you stand on it.",
    ]) );
    set_exits( ([
      "east" : RPATH "hotel3",
    ]) );
}
