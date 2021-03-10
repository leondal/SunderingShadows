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
  set("day long", "%^RESET%^%^ORANGE%^Well there is nothing you havent seen here before on your wanderings through this town. However, as you glance to the west you see a very welcomed site, a %^RESET%^weapons%^RESET%^%^ORANGE%^ and %^RESET%^armour%^RESET%^%^ORANGE%^ store! You look around to see if there is anything else as good nearby, and you notice to the east is what appears to be a %^BOLD%^%^BLACK%^graveyard%^RESET%^%^ORANGE%^.%^RESET%^\n");

  set("night long", "%^RESET%^%^BLUE%^Wouldn't it be nice to be nothing more then a mere child in the protective arms of your mother about now? The store to the west is closed, and you find it hard to determine which is worse: going into the %^BOLD%^%^BLACK%^graveyard%^RESET%^%^BLUE%^ at night or facing the %^GREEN%^cackling laughter%^RESET%^%^BLUE%^ of those %^ORANGE%^hyenas%^RESET%^%^BLUE%^ and whatever travels with them!%^RESET%^\n");

set_items( ([
   "graveyard" : "It appears to be surrounded by an 8-foot wall made of stone, but you can see what appears to be the top of a crypt or two.",
   "wall" : "Along the top of the wall every so many feet there sits a small gargoyle.",
   "gargoyle" : "Each one is different but they all appear VERY lifelike."
]) );
  set_smell("default","You smell death and decay.");
  set_listen("default", "The child's crying has grown fainter.");
  set_listen("crying", "As you listen carefully you determine the crying to be coming from the southeast somewhere.");
  set_exits( ([
     "south" : "/d/koenig/town/room5",
     "enter": "/d/koenig/town/general1"
]) );
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight" || time == "night")
    if(!present("hyena2"))
        new("/d/koenig/town/mon/hyena2.c")->move(this_object());
}
