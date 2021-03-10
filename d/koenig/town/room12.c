#include <std.h>
inherit VAULT;

string time;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  set_door("gate","/d/koenig/town/house1.c","gate","open_gate");
  set_open("gate", 0);
  set_string("gate", "open", "With a loud creaking of its hinges the gate opens at your touch.");
  set_property("light",1);
  set_property("indoors",0);
  set_short("A Street in Muileann");
  set("day long", "%^RESET%^%^ORANGE%^That %^BOLD%^%^BLACK%^tower%^RESET%^%^ORANGE%^ is really a bit unnerving, and it's surprising that there is such a %^YELLOW%^warm%^RESET%^%^ORANGE%^ and %^YELLOW%^inviting%^RESET%^%^ORANGE%^ house within clear view of it. The same %^BOLD%^%^BLACK%^wrought iron fence%^RESET%^%^ORANGE%^ blocks your way to the north, but to the south is a gate leading up to the house. Maybe you should check it out?%^RESET%^\n");
  set("night long", "%^RESET%^%^BLUE%^Looking at the %^BOLD%^%^BLACK%^tower%^RESET%^%^BLUE%^ to your north, and then at the %^YELLOW%^house%^RESET%^%^BLUE%^ to your south you think of how contradicting they are to one another. Well, as far as you can make out there is no way to the tower, but the way to the house is blocked only by a simple %^BOLD%^%^BLACK%^gate%^RESET%^%^BLUE%^. That house looks very %^YELLOW%^inviting%^RESET%^%^BLUE%^ about now, as you hear the %^RESET%^cackling laughter%^RESET%^%^BLUE%^ of those %^ORANGE%^hyenas%^RESET%^%^BLUE%^ again.%^RESET%^\n");
  set_smell("default", "You can smell something very evil here.");
  set_listen("default", "You can hear the soft, sultry laugh of a woman.");
  set_exits( ([
     "west" : "/d/koenig/town/room6",
     "gate" : "/d/koenig/town/house1"
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
