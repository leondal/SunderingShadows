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
  set_short("The streets of Muileann.");
  set("day long", "%^ORANGE%^There really isn't much to see here except for the occasional person trying to get out of your way and away from you. You are simply amazed by the %^BOLD%^%^BLACK%^depressive%^RESET%^%^ORANGE%^ atmosphere of this town and wish you could change it - or leave it. In the distance to the northeast you see what might be a %^BOLD%^%^BLACK%^graveyard%^ORANGE%^.%^RESET%^\n");

  set("night long", "%^BLUE%^You are realizing a little late the reasons behind this towns %^BOLD%^fearful%^RESET%^%^BLUE%^ aura. I bet you would give almost anything for a safe place to hide about now... %^BOLD%^%^BLACK%^You see something move in the shadows. %^RESET%^%^BLUE%^Time to move!%^RESET%^\n");

  set_items( ([
           "street" : "FILTHY! Makes you wonder how these people can stand it.",
		   "shadows" : "Whatever that was seems to be long gone, but the terror it struck in your soul still lingers."
           ]) );
  set_smell("default", "You smell nothing appealing here!");
  set_listen("default", "You can hear the crying of a small child.");
  set_listen("crying", "The crying appears to come from the east somewhere.");
  set_exits( ([
     "north" : "/d/koenig/town/room7",
     "south" : "/d/koenig/town/room4",
     "east" : "/d/koenig/town/room8"
           ]) );
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "dawn" || time == "day")
{
  if(!present("maiden"))new("/d/koenig/town/mon/maiden")->move(this_object());
}
  else {
  if(!present("bhut"))new("/d/koenig/town/mon/fbhut")->move(this_object());
  }
}
