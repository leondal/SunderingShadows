#include <std.h>

inherit ROOM;

void create ()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Gnome Home");
  set("day long","%^ORANGE%^A Nice Gnome Home%^RESET%^\n"
      "This cozy brick home is larger then you would expect. "
      "Probably due to the vast number of merchants that pass "
      "through this village on their way to somewhere else. "
      "This home consists of 2 good sized rooms. The one you "
      "stand in now has comfortable funrniture for visiting in "
      "front of the fireplace and in the far corner is the "
      "kitchen. There are stairs leading up to the sleeping room.");
  set("night long","%^ORANGE%^A Nice Gnome Home%^RESET%^\n"
      "This cozy brick home is larger then you would expect. "
      "Probably due to the vast number of merchants that pass "
      "through this village on their way to somewhere else. "
      "This home consists of 2 good sized rooms. The one you stand "
      "in now has comfortable furniture and is lit mainly by the "
      "crackling fire in the fireplace. In the far corner is the "
      "kitchen and there are stairs leading up to the sleeping room.");
  set_smell("default","Smells of freshly baked bread and other good smells.");
  set_listen("default","Children play while the mother busys herself.");
  set_items( ([
     "furniture" : "It is big enough for humans to sit in and looks "
                   "comfortable.",
     "fireplace" : "Doesnt look to be used much during the day but come "
                   "night time your sure it blazes warmly.",
     "kitchen" : "It is small but everything for good cooking is right "
                 "at the fingertips."
	        ]) );
  set_exits( ( [
     "out" : "/d/darkwood/forest/village/str5",
     "up"  : "/d/darkwood/forest/village/room4"
		]) );
  }
