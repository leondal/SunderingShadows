#include <std.h>
inherit ROOM;

void look_bones(string str);

int hound_wait = 0;

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
  set_long("%^RESET%^%^ORANGE%^Well life is just not dealing you a very nice deck at the moment, is it, adventurer? This room doesn't contain much except for a rather large pile of %^RESET%^bones%^RESET%^%^ORANGE%^ that seems to shift and shuffle from time to time.\n");
  set_smell("default", "There is definitely a very bad stench coming the bones.");
  set_listen("default", "The bones creak and crack.");
  set_exits( ([
     "north" : "/d/koenig/town/dungeon3",
     //"well" : "/d/koenig/town/well1",
     "east" : "/d/koenig/town/dungeon1"
]) );
}
void init()
{
  ::init();
  add_action("look_bones", "look");
}
int look_bones(string str)
{
  object bones;
  if(str != "bones" || hound_wait != 0)
  return 0;
  if(present("skeleton hound", TP))
{
  tell_object(this_player(),"You find nothing of interest there.\n");
  tell_room(environment(TP),TPQCN+" looks the pile of bones over but finds nothing of interest.", TP);
  return 1;
}
  hound_wait = 1;
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  new("/d/koenig/town/mon/skelhound.c")->move(this_object());
  tell_object(this_player(),"%^RESET%^%^CYAN%^Your search has brought forth %^RESET%^skeleton hounds%^CYAN%^! As they burst from the pile of bones one of them %^BOLD%^%^RED%^bites%^RESET%^%^CYAN%^ you in the butt and backs off! They all wait patiently for your reaction with a %^RESET%^skeletal grin%^CYAN%^.\n");

  tell_room(environment(TP),TPQCN+" searches the pile of bones and arouses the attention of skeletal hounds...one rushes forward and bites "+TPQCN+" in the butt then backs off to join the others and wait for the next move to be made...all of them wearing skeletal grins of satisfaction.",TP);
  return 1;
}
void reset()
{
  ::reset();
  if(hound_wait != 0)
  hound_wait--;
}