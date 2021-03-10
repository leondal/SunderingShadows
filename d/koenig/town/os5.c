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
  set_long("%^RESET%^%^GREEN%^As you walk along here you see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining the fence here. Their "+
"fragrance is %^MAGENTA%^sweet%^RESET%^%^GREEN%^ and %^MAGENTA%^alluring%^RESET%^%^GREEN%^. It makes you want to get closer to smell "+
"them, or maybe even try to %^BOLD%^pick%^RESET%^%^GREEN%^ one.%^RESET%^\n");
  set_listen("default", "You can hear the wind rustle the leaves and roses gently.");
  set_smell("default", "You can smell the sweet fragrance of roses here.");
  set_smell("roses","So sweet and very alluring...you have a desire to pick one.");
  set_items( ([
     "bushes":"The dominating color of rose here is pink.",
   "rose":"You take a close look and notice that there are tints of red in the pink colored roses."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os4",
     "west":"/d/koenig/town/os6"
]) );
  bloodrose_wait = 0;
}
void init() {
  ::init();
  add_action("pick_rose", "pick");
}
int pick_rose(string str) {
  object rose;
  if(str != "rose" || bloodrose_wait != 0)
  return 0;
  if(present("bloodrose", TP))
{
  tell_object(this_player(),"There isn't one to pick.");
  tell_room(environment(TP),TPQCN+" searches for a rose to pick but doesn't find one.", TP);
  return 1;
}
  bloodrose_wait = 1;
  new("/d/koenig/town/mon/pkbloodrose.c")->move(this_object());
  tell_object(this_player(),"%^BOLD%^%^RED%^You go to pick a rose from the bush and it attacks you!");
  tell_room(environment(TP),TPQCN+" tries to pick a rose from the bush and is attacked by it instead!", TP);
  return 1;
}
void reset() {
  ::reset();
  if(bloodrose_wait != 0)
  bloodrose_wait--;
}
