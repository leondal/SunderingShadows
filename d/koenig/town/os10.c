#include <std.h>
inherit ROOM;

int bloodrose_wait;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",0);
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^As you walk along you see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining the fence here, "+
  "and further to the east you notice a very large %^BOLD%^%^BLACK%^misshapen tree%^RESET%^%^GREEN%^. The roses fragrance is %^MAGENTA%^sweet%^RESET%^%^GREEN%^ "+
  "and %^MAGENTA%^alluring%^RESET%^%^GREEN%^. it makes you want to get closer to smell them, or maybe even "+ 
  "%^BOLD%^pick%^RESET%^%^GREEN%^ one.%^RESET%^\n");
  set_listen("default","You hear someone keening for help.");
  set_listen("keening","The keening is louder here, and to the east.");
  set_smell("default", "You can smell the sweet fragrance of roses.");
  set_smell("roses","So sweet and very alluring... you have a desire to pick one.");
  set_items( ([
     "bushes" : "The dominating color of rose here is golden yellow.",
     "rose" : "You take a close look and notice that there are tints of red in the golden yellow colored roses."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os11",
     "west":"/d/koenig/town/os9"
]) );
  bloodrose_wait = 0;
}

void init() {
  ::init();
  add_action("pick_rose","pick");
}
int pick_rose(string str) {
  object rose;
  if(str != "rose" || bloodrose_wait != 0)
  return 0;
  if(present("bloodrose",TP))
{
  tell_object(this_player(),"You can pick one now.");
  tell_room(environment(TP),TPQCN+" searches for a rose to pick and cant find one.");
  return 1;
}
  bloodrose_wait = 1;
  new("/d/koenig/town/mon/ywbloodrose.c")->move(this_object());
  tell_object(this_player(),"%^BOLD%^%^RED%^You go to pick a rose and are attacked by the rosebush!");
  tell_room(environment(TP),TPQCN+" goes to pick a rose and is attacked by the rosebush!",TP);
  return 1;
}
void reset() {
  ::reset();
  if(bloodrose_wait != 0)
  bloodrose_wait--;
}
