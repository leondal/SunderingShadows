//updated by Circe 9/9/04 to current code and color
//main1.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("Inside the North Gates of Tharis");
   set_short("Inside the North Gates of Tharis");
   set_long(
@JAVAMAKER
%^MAGENTA%^Inside the North Gates of Tharis%^RESET%^
You stand inside the %^BOLD%^north gates %^RESET%^of Tharis. To the north stand
the thick dwarven-built %^BOLD%^%^BLACK%^walls %^RESET%^of the city. To the south stretches
the %^MAGENTA%^main road%^RESET%^ to the %^YELLOW%^marketplace%^RESET%^. The road during the day is
packed with %^ORANGE%^travelers%^RESET%^, %^CYAN%^merchants%^RESET%^, and other less savory types.

%^BOLD%^%^BLUE%^To the east and west of the North Gate, stairs wind upward to the
walls.
JAVAMAKER
   );
   set_smell("default","The road smells of the people and the busy city.");
   set_listen("default","Around you bustle many folk - criers yell, and women gossip.");
   set_items(([
      ({"walls","wall"}) : "The walls are thick and well built.  The "+
         "dwarves mined the stones from the very mountains Tharis "+
         "is built into.",
      "stairs" : "The stairs wind upward towards the guard houses "+
         "that straddle the gate.",
      ({"gate","north gate","gates"}) : "The gates of the city are made "+
         "of thick wood reinforced with iron bands.  They are set "+
         "within the stone gate posts built by the dwarves.",
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
         "others of a less-than-wholesome looking sort."
   ]));

   set_exits(([
      "estairs":ROOMS"tower6",
      "north":"/d/tharis/road/road9",
      "south":ROOMS"main2",
      "wstairs":ROOMS"tower1",
   ]));

   set_pre_exit_functions(({"east","west"}),({"pre_function","pre_function"}));
}

int pre_function(){
    string verb = query_verb();

   tell_object(TP,"%^BOLD%^As you move "+verb+", a set of stairs leads you up to the walls.");
    return 1;
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/