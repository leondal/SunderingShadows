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
  set_short("Inside the Gates of Muileann");
  set("day long","%^ORANGE%^Standing just inside the gates this town at "
      "first glance looks like any other town. There is a restaurant, "
      "bar, and stable here open for business. The townspeople mill about "
      "the streets and keep a cautious eye on you as they pass. The %^BOLD%^gates%^RESET%^%^ORANGE%^ "
      "lead out of town while the street leads east and further in. "
      "Looking further into town you can see a %^RESET%^tower%^ORANGE%^, tall and "
      "%^BOLD%^%^BLACK%^ominous%^RESET%^%^ORANGE%^.");
  set("night long","%^BOLD%^%^BLUE%^Standing just inside the gates of this "
      "town you see that its %^YELLOW%^night life%^BLUE%^ is nothing like its day. Every place "
      "seems to be closed except for the bar. %^RESET%^%^ORANGE%^Hyenas%^BOLD%^%^BLUE%^ roam freely on the "
      "streets, bringing down prey and feasting, while other strange and "
      "wild-looking %^RESET%^%^GREEN%^humanoid creatures%^BOLD%^%^BLUE%^ do the same.%^RESET%^");
  set_smell("default","You can smell fear in the air.");   
  set_listen("default","You can hear the mocking laughter of hyenas.");
  set_exits( ([
     "restaurant":"/d/koenig/town/rest1",
     "bar" : "/d/koenig/town/bar1",
     "stable" : "/d/koenig/town/stable1",
     "east" : "/d/koenig/town/room4",
     "gate" : "/d/koenig/road/room3"
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
