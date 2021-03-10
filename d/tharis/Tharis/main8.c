//updated by Circe 9/9/04 to current code and color
//main8.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("Before the marketplace of Tharis");
   set_short("Before the marketplace of Tharis");
   set_long(
@JAVAMAKER
%^MAGENTA%^Before the marketplace of Tharis%^RESET%^
Immediately to the south is the %^YELLOW%^marketplace %^RESET%^of Tharis.  To the north
the %^MAGENTA%^main street%^RESET%^ extends.  You can hear the shouts and bellows
from the %^YELLOW%^marketplace%^RESET%^.  There are %^ORANGE%^signs %^RESET%^hanging over the doors
to the east and west.  The %^BOLD%^building%^RESET%^ on the west has a type of %^ORANGE%^patio
%^RESET%^or open %^GREEN%^foyer %^RESET%^before its door.  You can make out that the large
%^YELLOW%^marketplace %^RESET%^to the south has a general octagonal shape.
JAVAMAKER
   );

   set_smell("default","You smell a mixture of rich prefumes and the sweat of laborers.");
   set_listen("default","Criers yell, a man swears, many folk seem to take issue to others.");
   set_items(([
      ({"sign","signs"}) : "There are two wooden signs here, one to the "+
         "west and one to the east.",
      "east sign" : ({"This simple wooden sign hangs over the door "+
         "to the east.  You could probably read it.","%^YELLOW%^Bank "+
         "of Tharis","common"}),
      "west sign" : ({"This simple wooden sign hangs over the door "+
         "to the west.  You could probably read it.","%^BOLD%^Merchant's "+
         "Portal%^RESET%^","common"}),
      ({"patio","foyer","open foyer"}) : "The typically straight walls "+
         "that line the city fold outward slightly on the west here to "+
         "allow extra space before this door.  A wooden railing closes "+
         "the patio in while leaving it open to the elements.",
      ({"road","main road","ground"}) : "The road here is paved with "+
         "smooth stone slabs crafted by the dwarves.  Here and there "+
         "one has cracked and fallen into disrepair, but for the "+
         "most part the main road is well-kept.",
      ({"market","marketplace"}) : "The open market place to the "+
         "south is visible from here.  This close, you can tell "+
         "that many merchants are arranged in the octagonal area.",
      ({"merchants","travelers","people","types"}) : "A crowd of "+
         "people mingle together, walking up and down the street "+
         "and entering various shops.  Well-dressed merchants "+
         "walk flanked by their guards, while travelers in somewhat "+
         "disheveled clothing peer around curiously.  Lurking "+
         "among the shadows and walking brazonly in the crowd are "+
         "others of a less-than-wholesome looking sort."
   ]));
   set_exits(([
      "southwest":ROOMS"market1",
      "north":ROOMS"main7",
      "west":ROOMS"portal",
      "east":ROOMS"bank",
      "southeast":ROOMS"market2",
   ]));
    set_door("bank door",ROOMS"bank","east","blah");
   set_open("bank door",0);
    "/d/tharis/Tharis/bank"->set_open("bank door",0);
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/
