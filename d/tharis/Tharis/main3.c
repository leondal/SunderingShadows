//updated by Circe 9/9/04 to current code and color
//main3.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("On the main street through Tharis");
   set_short("On the main street through Tharis");
   set_long(
@JAVAMAKER
%^MAGENTA%^On the main street through Tharis%^RESET%^
Here on the main thoroughfare of Tharis, %^ORANGE%^travelers %^RESET%^from the great
northern cities like %^YELLOW%^Shadow %^RESET%^and %^CYAN%^Daggerdale%^RESET%^ come to purchase
many of the finely crafted %^BOLD%^dwarven trinkets%^RESET%^ and the %^ORANGE%^raw minerals
%^RESET%^that are abundant in the %^RED%^mountains%^RESET%^.  Crossing the road here
is a %^BOLD%^%^BLACK%^dark alley%^RESET%^.  About half as wide as the street, it 
looks to be a home for the unsavory.
JAVAMAKER
   );
   set_smell("default","The road smells of the people and the busy city.");
   set_listen("default","Around you bustle many folk - criers yell, and women gossip.");
   set_items(([
      ({"alley","dark alley"}) : "The alley looks narrow and dark.  "+
         "As you peer down the alley to the east, smells of rot and "+
         "urine attack your senses.  The western way seems slightly "+
         "cleaner, if still cramped.",
      ({"road","main road","ground"}) : "The road here is paved with "+
         "smooth stone slabs crafted by the dwarves.  Here and there "+
         "one has cracked and fallen into disrepair, but for the "+
         "most part the main road is well-kept.",
      ({"market","marketplace"}) : "The open market place to the "+
         "south is barely visible from here.",
      ({"merchants","travelers","people","types"}) : "A crowd of "+
         "people mingle together, walking up and down the street "+
         "and entering various shops.  Well-dressed merchants "+
         "walk flanked by their guards, while travelers in somewhat "+
         "disheveled clothing peer around curiously.  Lurking "+
         "among the shadows and walking brazonly in the crowd are "+
         "others of a less-than-wholesome looking sort.",
      ({"mountain","mountains"}) : "The tall mountains rise to the "+
         "south, visible against the horizon here."
   ]));

   set_exits(([
      "west":ROOMS"a2",
      "east":ROOMS"a3",
      "south":ROOMS"main4",
      "north":ROOMS"main2"
   ]));
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/