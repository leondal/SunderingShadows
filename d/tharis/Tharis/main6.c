//updated by Circe 9/9/04 to current code and color
//main6.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("The bustling main street through Tharis");
   set_short("The bustling main street through Tharis");
   set_long(
@JAVAMAKER
%^MAGENTA%^The bustling main street through Tharis%^RESET%^
The street has started to get more crowded.  The criers seem to
yell louder and the %^CYAN%^merchants %^RESET%^seem more frequent here than to the north.
The street runs north and south here.  There are two %^YELLOW%^well-lit side
streets%^RESET%^, both are packed with %^ORANGE%^people %^RESET%^coming and going.
JAVAMAKER
   );
   set_smell("default","The smells of the city mingle around you.");
   set_listen("default","The low hum of the crowd can be heard around you.");
   set_items(([
      ({"side streets","streets"}) : "These side streets lead to a "+
         "%^ORANGE%^tavern %^RESET%^on the west and a %^GREEN%^general "+
         "store %^RESET%^on the east.",
      ({"road","main road","ground"}) : "The road here is paved with "+
         "smooth stone slabs crafted by the dwarves.  Here and there "+
         "one has cracked and fallen into disrepair, but for the "+
         "most part the main road is well-kept.",
      ({"market","marketplace"}) : "The open market place to the "+
         "south is visible from here.",
      ({"merchants","travelers","people","types"}) : "A crowd of "+
         "people mingle together, walking up and down the street "+
         "and entering various shops.  Well-dressed merchants "+
         "walk flanked by their guards, while travelers in somewhat "+
         "disheveled clothing peer around curiously.  Lurking "+
         "among the shadows and walking brazonly in the crowd are "+
         "others of a less-than-wholesome looking sort."
   ]));
   set_exits(([
      "southeast":ROOMS"side1",
      "south":ROOMS"main7",
      "north":ROOMS"main5",
      "southwest":ROOMS"side2"
   ]));
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/