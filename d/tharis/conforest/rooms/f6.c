#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(GAME_TRACK);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^Deep Within Darkwood Forest%^RESET%^");
  set_long("Bones from all forms of creatures lay in several "+
	"large piles.  The ground and trees around you seem "+
	"stained a dark rust color.  Dangling from a few low "+
	"limbs are grotesque chimes made from small animal "+
	"bones.  The site around you combines with the stench of "+
	"rotting flesh, making you feel a bit sick.");
  set_smell("default","It smells as if something has died "+
	"and is decaying nearby.");
  set_listen("default","The bone chimes clatter together as "+
	"the wind blows.");
  set_items(
    ([
    ({"bones","piles"}):"The piles of bones look like they "+
	"have been picked clean.  They obviously are the remains "+
	"of somethings dinner.",
   "chimes":"The chimes clatter noisily in the wind."
    ]) );
  set_exits(
    ([
    "east" : ROOMS+"f7",
    "south" : ROOMS+"f11",
    "north" : ROOMS+"f1"
    ]) );
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(!present("ogre mercenary"))
  {
  return 1;
  }
  if(TP->query_invis())
  {
  return 1;
  }
  else
  {
  tell_object(TP,"The ogre manages to grab you and toss you "+
	"back as you try to get by.");
  tell_room(ETP,"The ogre throws "+TPQCN+" aside, blocking "+
	""+TP->query_possessive()+" way north.",TP);
  return 0;
  }
}


void reset()
{
  ::reset();
  if(!present("ogre"))
  {
    new(MONS+"ogre")->move(this_object());
    new(MONS+"ogre")->move(this_object());
  }
}
