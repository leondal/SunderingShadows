#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_short("Enterence to the Hedge");
  set_long("The hedge overwelms you with it's massive size. A large giant, or "
	   "dragon could not even see over it's walls, and they could even "
	   "fit through the paths inside. Now you know that this is bigger "
	   "than you thought it was.");
  set_exits( ([
                "north" : "/d/shadow/virtual/sea/hedge.dock",
                "south" : pass_exit("2","I,I")
           ]) );
    
}

void reset()
{
  ::reset();
  set_exits( ([
                "north" : "/d/shadow/virtual/sea/hm_quest.dock",
                "south" : pass_exit("2","I,I")
           ]) );
}
