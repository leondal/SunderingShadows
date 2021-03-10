#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Kitchen");
  set_long("%^RESET%^%^RED%^You pass through the double doors and into %^BOLD%^hell's%^RESET%^%^RED%^ very own kitchen! Um, maybe it wasn't such a good idea that you followed the urgings of your stomach. Those smells are certainly tantalizing though. Well, maybe you can grab a quick bite to eat and hold off the cook and his helpers, huh? %^BOLD%^I mean how tough can these guys be?%^RESET%^\n");
  set_smell("default", "There are many tantalizing and undefinable smells here.");
  set_smell("food", "The roasting meats and spices waft readily to your nostrils.");
  set_listen("default", "There is a lot of banging and shouting... and singing?!");
  set_listen("banging", "You hear pots being banged around... they must be cooking a feast.");
  set_listen("shouting", "You can hear the assistant cook yelling at the underlings to move it or end up on the dining table.");
  set_exits( ([
     "exit" : "/d/koenig/town/tower10",
     "east" : "/d/koenig/town/kitchen2",
     "south" : "/d/koenig/town/kitchen3"
]) );
}
void reset()
{
  ::reset();
  if( !present("cook") || !present("underling"))
   {
     new("/d/koenig/town/mon/asscook.c")->move(this_object());
     new("/d/koenig/town/mon/assunder1.c")->move(this_object());
   }
}
