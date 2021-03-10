#include <std.h>
inherit ROOM;

void look_shackles(string str);

int zombie_wait;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("no teleport", 1);
  set_property("no magic", 1);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("The Dungeons of Muileann");
  set_long("%^RESET%^%^ORANGE%^As you wander about this %^RED%^horrid%^RESET%^%^ORANGE%^ place you see many signs of there being past visitors here. There are %^RESET%^bones%^RESET%^%^ORANGE%^ and %^RED%^rags%^RESET%^%^ORANGE%^ and plenty of %^BOLD%^%^BLACK%^shackles%^RESET%^%^ORANGE%^ that look to have had much use, past and present. I'd be careful of where you look, dear adventurer, if you dare look around.%^RESET%^\n");
  set_items( ([
     "bones" : "Just a few scattered bones.",
     "rags" : "Some of the rags look to be just peasant clothing but you notice that some - just a few - appear to be of silk, something royalty would wear."
]) );
  set_smell("default", "It smells awful in here.");
  set_listen("default", "You can hear the rattle of shackles and chains clearly here.");
  set_exits( ([
     "south" : "/d/koenig/town/dungeon1",
     "west" : "/d/koenig/town/dungeon3"
]) );
  zombie_wait = 0;
}

void init()
{
  ::init();
  add_action("look_shackles", "look");
}
  int look_shackles(string str)
{
  object zombie;
  if((str != "shackles") || (zombie_wait != 0))
  return 0;
  if(present("zombie"))
{
  tell_object(this_player(), "%^BOLD%^%^RED%^Are you nuts?! It's as if you want to be eaten alive by zombies!%^RESET%^");
  tell_room(environment(TP),TPQCN+" is crazy, they look to see if anymore zombies lie within the shackles!",TP);
  return 1;
}
  zombie_wait = 1;

   zombie = new("/d/koenig/town/mon/zombie.c");
   zombie -> move(this_object());
   zombie -> kill_ob(this_player(),1);

  tell_object(this_player(), "%^BOLD%^%^GREEN%^A zombie in shackles attacks you!");
  
  tell_room(environment(TP),TPQCN+" looks upon the shackles and for his curiosity is attacked by a zombie!",TP);
  return 1;
}
void reset()
{
  ::reset();
  if(zombie_wait != 0)
  zombie_wait--;
}
