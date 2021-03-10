inherit "std/room";
#include "../dragon.h"

void create()
{
  ::create();
set_property("indoors",1);
  set_property("light",1);
  set_short("Cathardon's Lair");
set("long","%^RED%^%^BOLD%^As soon as you look in this room you realize your mistake.  The room is lined with treasure you have only dreamed of.  However you realize the problem as soon as you see Cathardon sitting atop the treasure.  Getting it won't be easy.  Then again, neither will leaving with your life.");
  set_exits(([ "out" : " "]));
  set_items(([
]));
new(MONDIR +"rdragon")->move(TO);
}
void init()
{
  ::init();
}
