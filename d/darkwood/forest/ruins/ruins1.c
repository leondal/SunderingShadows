#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set_short("Glimpse of a ruined ancient city");
  set("day long","%^GREEN%^The Darkwood%^RESET%^\n" 
      "A large irregular mass stretches off to either side "
      "out of sight, in most places as high as the trees that grow right "
      "up to it, with even taller spires here and there. Leafless vines "
      "and creepers cover it all in thick layers."); 
  set("night long","%^BOLD%^%^BLUE%^The Darkwood%^RESET%^\n"
      "Here at night there are only shadows for the growth is thick "
      "and the trees so high that very little moonlight can cast down "
      "through them. It may be wise to wait till daylight.");
  set_smell("default","The air is heavy.");
  set_listen("default","There is merely silence here.");
  set_items( ([
     "mass" : "On closer inspection you can make out the walls and towers"
              "of an ancient city!",
     "spires":"On closer inspection you can see they use to be guard towers "
              "of an ancient city!",
     "towers":"The towers are bigger then anything you have ever seen!",
     "walls" :"The are covered in vines and creepers.",
     "vines": "You might be able to use them to climb over the walls.",
     "city" : "It is very old indeed and overgrown with vines, creepers, "
              "and trees. In some places it has crumbled or fallen."
	       ]) );
    set_exits( ([
       "north" : " ",
       "south" : " ",
       "east"  : " ",
       "west"  : " ",
		 ]) );
  }

