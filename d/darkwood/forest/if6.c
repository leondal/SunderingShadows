#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set_climate("temperate");
  set_short("Inner Darkwood");
  set("day long","%^GREEN%^Deep Darkwood%^RESET%^\n"
      "This is Deep Darkwood. The way to travel is clear in most places, "
      "though things are a bit hidden in the shadows. The trees and "
      "undergrowth are thinner here but by all standards still "
      "pretty thick. Here the rock formations are large and you "
      "can make out a cave.");
  set("night long","%^BOLD%^%^BLUE%^Deep Darkwood%^RESET%^\n"
      "This is Deep Darkwood. In the darkness of night the only thing "
      "you can make out are the large rock formations and possibly a cave.");
  set_smell("default","It is musty and dank.");
  set_listen("default","A leapord cries from somewhere in the trees.");
  set_items( ([
     "trees" : "They grow tall and thick. Their higher branches weaving "
               "into a canaopy to block most light from here. In some of "
               "the trees you can see webbing.",
     "webbing":"The webbing of a GIANT spider.",
     "cave"  : "The cave is very dark.",
     "undergrowth" : "Thick and plush but you can see which direction "
                     "to travel."
	       ]) );
  set_exits( ([
     "south" : "/d/darkwood/forest/if8",
     "enter" : "/d/darkwood/forest/caves/cave2"
	       ]) );
  }

