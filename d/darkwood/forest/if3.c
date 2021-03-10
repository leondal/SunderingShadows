#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set_climate("temperate");
  set_short("Inner Darkwood");
  set("day long","%^GREEN%^Inner Darkwood%^RESET%^\n"
      "This is Inner Darkwood, just beyond the fringes. One can see "
      "which direction to travel a little easier now, though things "
      "are a bit more hidden in the shadows. The trees and "
      "undergrowth are a bit thinner here but by all standards still "
      "pretty thick. One can see a few rock formations here.");
  set("night long","%^BOLD%^%^BLUE%^Inner Darkwood%^RESET%^\n"
      "This is Inner Darkwood, just beyond the fringes. In the darkness "
      "of night the only thing you can make out is which direction to go.");
  set_smell("default","It is musty and dank.");
  set_listen("default","You can hear the occassional cry of a leapord from "
             "deeper in the forest.");
  set_items( ([
     "trees" : "They grow tall and thick. Their higher branches weaving "
               "into a canaopy to block most light from here.",
     "rocks" : "The rock formations are small here but appear to get "
               "larger towards the south, while to the east there "
               "appear to be none.",
     "undergrowth" : "Thick and plush but you can see which direction "
                     "to travel."
	       ]) );
  set_exits( ([
     "north" : "/d/darkwood/forest/if2",
     "south" : "/d/darkwood/forest/if5",
     "east"  : "/d/darkwood/forest/if4"
	       ]) );
  }
