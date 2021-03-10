#include <std.h>

inherit ROOM;

string time;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  set_property("light",1);
  set_property("indoors",0);
  set_short("The Streets of Muileann");
  set("day long", "%^RESET%^%^ORANGE%^You are still traveling the %^BOLD%^%^BLACK%^filthy%^RESET%^%^ORANGE%^ streets of Muileann, but are thankful not to be traveling them at night. You notice the street continues to the east and to the south. You can make out what appears to be a %^GREEN%^herbal shop%^RESET%^%^ORANGE%^ of some kind to your southwest.%^RESET%^\n");
  set("night long", "%^BLUE%^By this time you are wishing very hard that you were elsewhere about now. Traveling the streets of this town at night just doesn't appear to be all that safe and the %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^ are beginning to add credence to this thought.%^RESET%^\n");
  set_smell("default", "If its possible, you smell something very evil near by.");
  set_listen("default", "You hear the rustling of cloth and strange laughter.");
  set_exits( ([
     "north" : "/d/koenig/town/room4",
     "south" : "/d/koenig/town/room11",
     "east" : "/d/koenig/town/room12"
]) );
   set_items( ([
           "street" : "FILTHY! Makes you wonder how these people can stand it.",
		   "shadows" : "Out of the corner of your eye, it seems the shadows dart here and there. But when you take a closer look, you find only normal shadows."
           ]) );
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "dawn" || time == "day")
{
if(!present("peasant"))new("/d/koenig/town/mon/peasant.c")->move(this_object());
}
  else {
if(!present("bhut"))new("/d/koenig/town/mon/bhut")->move(this_object());
  }
}
