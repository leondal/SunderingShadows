#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("store");
    set_short("Tonovi Hotel");
    set_long(
    "You are on the second, and top, floor of the hotel.  On each side of the hall there are large rooms for the guests of the hotel.  All around expensive looking candleholders on the walls above the opulent carpets.  All around you see great wealth within the building."
    );
    set_smell("default", "You can smell the burning of the scented candles.");
    set_listen("default", "You can hear an orchestra playing in the distance.");

    set_items( ([
      "carpets" : "The carpets were made by the finest weavers in all the land",
      "candleholders" : "The gilded candleholders hold several long burning candles, lighting the room.",
    ]) );
    set_exits( ([
      "north" : RPATH "hotel3",
      "east" : RPATH "hroom5",
      "west" : RPATH "hroom6",
    ]) );
}
