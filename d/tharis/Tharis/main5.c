//updated by Circe 9/9/04 to current code and color
//main5.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

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
The street here continues to the north and south.  About halfway
between the %^BOLD%^north gates %^RESET%^and the %^YELLOW%^marketplace%^RESET%^, you can see yourself
getting quickly caught up in the flow of the people as they brush
by you.  There is a %^ORANGE%^sign %^RESET%^over the door to the west, and a small
%^BOLD%^%^BLACK%^alley %^RESET%^heads toward the east.
JAVAMAKER
   );
   set_smell("default","The smells of the city mingle around you.");
   set_listen("default","The low hum of the crowd can be heard around you.");
   set_items(([
      ({"sign","wooden sign"}) : ({"This simple wooden sign hangs "+
         "over the door to the west.  You could probably read it.",
         (:TO,"readsign":),"common"}),
      "alley":"This alley does in fact seem to be a different world.  "+
         "Seems plain enough where the %^YELLOW%^light %^RESET%^hits, "+
         "but your nose tells you differently.",
      ({"gate","north gate","gates"}) : "The gates of the city are "+
         "barely visible above the heads of the people here.  They "+
         "stand far to the north.",
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
      "east":ROOMS"a7",
      "south":ROOMS"main6",
      "west":ROOMS"clothier",
      "north":ROOMS"main4"
   ]));
   set_door("clothier door",ROOMS"clothier","west",0);
}


void reset(){
   ::reset();
   set_open("clothier door",0);
   "/d/tharis/Tharis/clothier"->set_open("clothier door",0);
}

void readsign(){
   return(
@CIRCE

            %^YELLOW%^Peppy's Perfect Fashions

   %^BLUE%^For the most impressive Tharisian fashions
CIRCE
   );
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/