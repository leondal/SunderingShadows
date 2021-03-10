#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("store");
    set_short("Tonovi Hotel");
    set_long(
    "You are on the second, and top, floor of the hotel.  Here the grand staircase leads back down to the foyer.  To the north and south you can see several large rooms on each side of the hallway.  All around expensive looking candleholders on the walls above the opulent carpets.  All around you see great wealth within the building."
    );
    set_smell("default", "You can smell the burning of the scented candles.");
    set_listen("default", "You can hear an orchestra playing in the distance.");

    set_items( ([
      "carpets" : "The carpets were made by the finest weavers in all the land",
    ]) );
    set_exits( ([
      "down" : RPATH "hotel1",
      "east" : RPATH "hroom1",
      "west" : RPATH "hroom2",
      "north" : RPATH "hotel4",
      "south" : RPATH "hotel5",
    ]) );
}
