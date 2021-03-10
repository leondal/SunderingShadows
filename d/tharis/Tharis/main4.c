//updated by Circe 9/9/04 to current code and color
//main4.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_name("Between two bustling pubs");
   set_short("Between two bustling pubs");
   set_long(
@JAVAMAKER
%^MAGENTA%^Between two bustling pubs%^RESET%^
You stand between two bustling %^CYAN%^pubs%^RESET%^.  Their %^ORANGE%^swinging doors
%^RESET%^rattle as folk walk through them.  The %^YELLOW%^signs %^RESET%^hanging over their
doors name them.  The %^GREEN%^drunken outcasts %^RESET%^struggle to both
stand and walk, pausing to lean against the heavy %^BOLD%^stone buildings%^RESET%^.
JAVAMAKER
   );

   set_smell("default","The road smells of the people and the past times of the city.");
   set_listen("default","Around you bustle many folk - criers yell, and women gossip.");
   set_items(([
      "signs" : "There are two signs here you could read, one "+
         "on the east and one on the west.",
      "east sign" : ({"This simple wooden sign hangs over the door "+
         "to the east.  You could probably read it.","%^BOLD%^%^MAGENTA%^"+
         "The Last Stand%^RESET%^","common"}),
      "west sign" : ({"This simple wooden sign hangs over the door "+
         "to the west.  You could probably read it.","%^YELLOW%^The "+
         "Merchant's Cup%^RESET%^","common"}),
      ({"outcasts","drunken outcasts"}) : "Stumbling through the "+
         "streets and leaning against the buildings are several "+
         "drunken men and women.  A few look like they haven't "+
         "been home in days, and all of them could definitely "+
         "use a good meal and a hot shower.",
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
      ({"building","buildings","pubs","stone buildings"}) : "The two "+
         "pubs are built in similar manners - both featuring top-"+
         "notch dwarven stonework.  They are short, squat buildings "+
         "with swinging wooden doors that seem to be almost "+
         "constantly opening, revealing a drunken crowd inside."
   ]));

   set_exits(([
      "north":ROOMS"main3",
      "south":ROOMS"main5",
      "east":ROOMS"stand",
      "west":ROOMS"cup"
   ]));
   set_post_exit_functions(({"east","west"}),({"east_postExit","west_postExit"}));
   set_door("cup door",ROOMS"cup","west",0);
   set_door("stand door",ROOMS"stand","east",0);
}


void reset(){
   ::reset();
   set_open("cup door",0);
   set_open("stand door",0);
   "/d/tharis/Tharis/stand"->set_open("stand door",0);
   "/d/tharis/Tharis/cup"->set_open("cup door",0);
   if(!present("worker") && random(3)){
      switch(random(6)){
         case 0:  new("/d/common/mons/worker1")->move(TO);
                  break;
         case 1:  new("/d/common/mons/worker3")->move(TO);
                  break;
         default:  new("/d/common/mons/worker4")->move(TO);
                  break;
      }
   }

}

int east_postExit(){
   tell_object(TP,"The door swings on its double hinge as you step "+
      "through it and notice that, yes, this was someone's last stand, "+
      "for tonight at least.");
}

int west_postExit(){
   tell_object(TP,"The door swings shut as you step into a room full "+
      "of above average dressed drunkards.");
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/