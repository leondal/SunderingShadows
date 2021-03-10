//updated by Circe 9/9/04 to current code and color
//main2.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

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
The bustling main portion of the %^MAGENTA%^street %^RESET%^streches out before you.
You can see the %^BOLD%^main gates %^RESET%^of the city to the north.  Opening to the 
south is more of the city.  A quick glance around shows you 
that the less prosperous looking people in the street seem to 
be quick of finger and light of foot, often finding their way 
near the wealthier %^CYAN%^merchants%^RESET%^.

%^BOLD%^%^BLUE%^There are signs over each of the two doors here.
JAVAMAKER
   );
   set_smell("default","The road smells of the people and the busy city.");
   set_listen("default","Around you bustle many folk - criers yell, and women gossip.");
   set_items(([
      "signs" : "There are two signs here you could read, the "+
         "east sign and the west sign.",
      "east sign" : ({"This simple wooden sign hangs over the door "+
         "to the east.  You could probably read it.",(:TO,"eastsign":),"common"}),
      "west sign" : ({"This simple wooden sign hangs over the door "+
         "to the west.  You could probably read it.",(:TO,"westsign":),"common"}),
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
      "north":ROOMS"main1",
      "south":ROOMS"main3",
      "east":ROOMS"recruiter",
      "west":ROOMS"armorer",
   ]));
   set_door("armorer door",ROOMS"armorer","west",0);
   set_door("recruiter door",ROOMS"recruiter","east",0);
}


void reset(){
   ::reset();
   set_open("recruiter door",0);
   set_open("armorer door",0);
   "/d/tharis/Tharis/recruiter"->set_open("recruiter door",0);
   "/d/tharis/Tharis/armorer"->set_open("armorer door",0);
}

void eastsign(){
   write(
@CIRCE
      %^BOLD%^Join the battle today!

          %^BLUE%^Recruiter here
CIRCE
   );
   return;
}

void westsign(){
   write(
@CIRCE
               %^BOLD%^The Stone Breastplate

   %^YELLOW%^Finest armor and shields in all of the south!
CIRCE
   );
   return ;
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/