//updated by Circe 9/9/04 to current code and color
//main7.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("On a bustling street in Tharis");
   set_short("On a bustling street in Tharis");
   set_long(
@JAVAMAKER
%^MAGENTA%^On a bustling street in Tharis%^RESET%^
The %^MAGENTA%^main street %^RESET%^through Tharis heads north here to the %^BOLD%^main
gates %^RESET%^and south to the entrance to the %^YELLOW%^marketplace%^RESET%^.  The street
here is busy and crowded.  Bustling %^ORANGE%^people %^RESET%^bump and prod
you as you look about.  On occasion, you imagine you feel some light 
fingers probing at your %^BOLD%^%^BLUE%^purse%^RESET%^, but when you look, you see
nothing but your %^BOLD%^%^BLACK%^shadow%^RESET%^.  A dank alley extends to the east.

%^BOLD%^%^BLUE%^There is a sign hanging over the door to the west.  
JAVAMAKER
   );
   set_smell("default","You smell a mixture of rich perfumes and the sweat of laborers.");
   set_listen("default","Criers yell, a man swears, many folk seem to take issue to others.");
   set_items(([
      ({"sign","wooden sign"}) : ({"This simple wooden sign hangs "+
         "over the door to the west.  You could probably read it.",
         (:TO,"readsign":),"common"}),
      "alley" : "Despite being dank and dirty, this alley seems to "+
         "be lacking some of the lurking thieves and cut throats.",
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
         "others of a less-than-wholesome looking sort.",
      ({"shadow","my shadow"}) : "Your shadow is thin in the light, "+
         "though...wait...was that a flicker?  Odd.  Shadows don't "+
         "normally do that..."
   ]));
   set_exits(([
      "north":ROOMS"main6",
      "west":ROOMS"weapon",
      "east":ROOMS"a26",
      "south":ROOMS"main8",
   ]));
   set_door("door",ROOMS"weapon","west","blah");
   set_locked("door",0);
   set_open("door",0);
   "/d/tharis/Tharis/weapon"->set_open("door",0);
}

void readsign(){
   return(
@CIRCE

     %^BOLD%^%^RED%^Dragon's Tooth Weapons

   %^BLUE%^When only the best will do
CIRCE
   );
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/