#include <std.h>
#include "crypt.h"
inherit ROOM;

void look_ceiling(string str);

int decapus_wait;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("no teleport", 1);
  set_property("no magic", 1);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("The dungeons of Muileann");
  set_long("%^RESET%^%^ORANGE%^You are wandering in circles here adventurer. Is this your second, third, or fourth trip around now? You feel in your very bones there is a way out of here if you could only find some clue as to how or where. Given time I am sure you will find it. If not, well, I guess you will die here like so many others. And what a %^RED%^pity%^RESET%^%^ORANGE%^! You showed such promise too...%^RESET%^\n");
  set_smell("default", "%^GREEN%^It smells as bad here if not worse than the other rooms.%^RESET%^");
  set_listen("default", "%^RESET%^You can hear %^BOLD%^%^BLACK%^slithering%^RESET%^ noises above you... the ceiling?");
  set_exits( ([
     "east" : "/d/koenig/town/dungeon2",
     "south" : "/d/koenig/town/dungeon4"
]) );
    decapus_wait = 0;
}
void init()
{
  ::init();
  add_action("look_ceiling", "look");
}
  int look_ceiling(string str)
{
  object ceiling;
  if(str != "ceiling" || decapus_wait != 0)
  return 0;
  if(present("decapus", TP))
{
  tell_object(this_player(),"You see nothing above you.\n");
  tell_room(environment(TP),TPQCN+" looks up at the ceiling but finds nothing lurking there.",TP);
  return 1;
}
  decapus_wait = 1;
  new("/d/koenig/town/mon/decapus.c")->move(this_object());
  tell_object(this_player(),"%^RESET%^As you look up a %^RESET%^%^ORANGE%^Decapus%^RESET%^ lowers itself down to meet your gaze with its own and a %^BOLD%^%^RED%^sadistic grin%^RESET%^.");
  tell_room(environment(TP),TPQCN+" looks up at the ceiling and finds a Decapus slowly lowering itself to meet their gaze.\n", TP);
  return 1;
}
void reset()
{
  ::reset();
  if(decapus_wait != 0)
  decapus_wait--;
}