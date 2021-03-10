#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's Grand Hall");
    set_long( "This is the grand hall of the mansion, which opens into all the other main floor rooms.  It has a cathedral beamed ceiling, walk-in fireplace, moss rock walls, an elegant patio lined with petunias in season, and a twenty ft. long %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^ac%^WHITE%^k %^BLACK%^ma%^WHITE%^r%^BLACK%^b%^WHITE%^l%^BLACK%^e %^RESET%^top bar.  A massive oak mantlepiece, over a foot thick and three feet deep, spans the length of the fireplace and is decorated with various pieces of pottery and brass, some containing exquisite dried floral arrangements.  Beams are hand-carved into likenesses of heads of various noble beasts and the fireplace blazes in any season.  The connecting patio is spacious and has a lovely view of the gardens."
    );
    set_listen("default","You hear the buzz of conversation all about.");
    set_smell("default","Delicious smells drift in from the dining room.");
    set_items(([
      "fireplace" : "The fireplace opening itself is over six feet wide with "
         "a raised stone hearth extending several feet on either side, past "
         "the 8 ft. stone alcove where the large logs for fuel are stored.",
      "bar" : "The base of the bar is a %^YELLOW%^rich, golden oak%^RESET%^ "
         "with %^YELLOW%^antique brass railings%^RESET%^.  The finely "
         "grained %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^ac%^WHITE%^k "
         "%^BLACK%^ma%^WHITE%^r%^BLACK%^b%^WHITE%^l%^BLACK%^e %^RESET%^ top "
         "has just enough swirls of white to make it shimmer even in "
         "candlelight.",
      ({"door", "doors"}) : "These pocket doors are actually a pair of doors "
     "that suspend from rollers in tracks in the ceiling rather than hanging "
     "on hinges as most do.  The walls to each side are hollow and the "
     "doors simply slide inside them to open.",
    ] ));
    set_exits(([
       "east" : "/d/guilds/fist/mansion/entry",
       "south" : "/d/guilds/fist/mansion/dining",
       "southwest" : "/d/guilds/fist/mansion/music",
       "west" : "/d/guilds/fist/mansion/library",
    ] ));
}
