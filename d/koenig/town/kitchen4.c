#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The kitchen in tower with stairs leading up.");
  set_long("%^RESET%^%^RED%^Ok, adventurer, you have made it through most of the %^BOLD%^horrors%^RESET%^%^RED%^ of the kitchen and have found some stairs that lead up. I can only see one problem, though: The Head Cook. This guy does not look friendly and he isn't going to let you waltz by him either. Matter of fact, he is eyeing you over and determining just how tasty you might be for his masters table, or maybe for himself.%^RESET%^\n");
  set_smell("default", "You can smell the food and spices thickly here.");
  set_listen("default", "You can hear lots of demented singing.");
  set_exits( ([
     "north" : "/d/koenig/town/kitchen2",
     "west" : "/d/koenig/town/kitchen3",
     "up" : "/d/koenig/town/tower11"
]) );
  set_pre_exit_functions( ({"up"}), ({"go_up"}) );
}
int go_up() {
  if(present("head cook")) {
  write("%^MAGENTA%^Head Cook says: %^RESET%^I think not! You would look much better on a platter, spiced with a few seasonings for flavor!");
  return 0;
}
  return 1;
}
void reset() 
{
  ::reset();
  if(!present("head cook"))new("/d/koenig/town/mon/headcook.c")->move(this_object());
}
