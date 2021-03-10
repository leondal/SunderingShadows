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
   set_short("A Street in Muileann");
   set("day long", "%^ORANGE%^Well Adventurer, you have now reached the other side of this town and to your pleasure you can see an %^GREEN%^herbal shop%^ORANGE%^ of some kind directly to your west. There is a %^BOLD%^warm%^RESET%^%^ORANGE%^ and %^BOLD%^inviting%^RESET%^%^ORANGE%^ house to your east. It seems kind of out of place here in this small and %^BOLD%^%^BLACK%^eerie%^RESET%^%^ORANGE%^ town. Your way to the east is blocked by a rather thick %^GREEN%^hedge%^RESET%^%^ORANGE%^ standing six feet tall.%^RESET%^\n");
  set("night long", "%^RESET%^%^BLUE%^It would appear you're running out of luck. The shop to your west appears to be closed, and your way to the east is blocked by a 6-foot %^GREEN%^hedge%^RESET%^%^BLUE%^. You notice a %^YELLOW%^warm%^RESET%^%^BLUE%^ and %^YELLOW%^inviting%^RESET%^%^BLUE%^ home beyond the %^GREEN%^hedge%^RESET%^%^BLUE%^ and it appears that there is a fire burning there, you can see %^BOLD%^%^BLACK%^smoke%^RESET%^%^BLUE%^ coming from its chimney. Maybe whoever lives there will put you up for the night and keep you safe.%^RESET%^\n");
  set_smell("default", "You can smell herbs and other things.");
  set_listen("default", "You can hear a woman's soft laughter.");
  set_items( ([
     "hedge" : "It is definitely 6 feet tall and its branches and leaves appear to be very tightly woven together to prevent access."
]) );
  set_exits( ([
     "enter": "/d/koenig/town/herbshop1",
     "north" : "/d/koenig/town/room6"
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
