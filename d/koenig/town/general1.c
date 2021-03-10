#include <std.h>
#include <objects.h>

inherit ROOM;

string time;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("Tolo's Adventurer Shop");
  set_long("%^CYAN%^This shop has many %^ORANGE%^shelves%^CYAN%^, each lined with many various items. Look around "+
"and take your time, you need to choose carefully the tools you will take on "+
"your journey here. Have fun, and get ready to enjoy the %^BOLD%^adventure%^RESET%^%^CYAN%^ of a lifetime!%^RESET%^\n");
  set_smell("default", "There is a pleasant floral scent here.");
  set_listen("default", "You hear the sounds from the street outside.");
  set_exits( ([
     "out"  : "/d/koenig/town/room7",
     "up" : "/d/koenig/town/store2"
]) );
  set_items( ([
     "shelves" : "The shelves are lined with everything an adventurer could hope for."
]) );
}
void reset()
{
  ::reset();
  time = "daemon/events_d"->query_time_of_day();
  if(time == "dawn" || time == "day")
{
  if(!present("Mrs. Tolo the Shopkeep",TO))
  new("/d/koenig/town/mon/mstolo.c")->move(TO);
}
  else {
   if (!present("bhut",TO))
  new("/d/koenig/town/mon/bhutmstolo.c")->move(TO);
  }
}
