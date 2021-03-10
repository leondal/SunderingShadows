//	moat13.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(1);
    set_short("In the moat");
    set_long(
@MOAT6
You reached the end of the moat here. A castle wall is towering above you and it is blocking your way. When you look around you don't see another way out than the way you came.
MOAT6
    );
set_listen("default","You hear nothing than just forest noises.");
    set_exits(([
"south" : CASTLE+"moat12"
    ] ));
    set_items(([
       "water" : "The water isn't clear here.",
       "wall" : "The wall is high,solid and very dirty here."
    ] ));
}
int climb(string str) {
    if ((!str) || (!(str=="wall"))) {
      notify_fail("Climb something that isn't here ??\n");
      return 0;
              }
    if (str =="wall")
  {
     write("You try to climb the "+str+" but you find that it is to slippery.\n");
     return 1;
   }
                           }
int kill_it(string str)
{
  if (str == "fish")
    { if ((int)this_player()->query_level() > 6 && present("fish"))
	{
	  write("You want to kill a harmless animal ????\n I thought you where a real adventurer !!!!");
	  return 1;
	}
    }
  return 0;
}

int knock(string str)
{
  if (!str)
    {
      notify_fail("Your knuckles get bloody when you knock at the stone walls !\n");
      return 0;
    }
  else
    {
      if (str == "wall")
{ add_exit(CASTLE+"castleD3", "enter");
	  write("You knock at the wall and a secret passage appears !");
	  return 1;
	}
      else
	{ notify_fail("Knock Knock .... Yeeeeh, nothing happens !!!!!\n");
	  return 0;
	}
    }
}

init() {
       ::init();
       add_action("climb","climb");
       add_action("kill_it","kill");
       add_action("knock","knock");
       }


reset() {
     ::reset();
     remove_exit("enter");
     if(!(present("fish"))) {
     new(CASTLE+MONSTERS+"fish")->move(this_object());
                                 }
         }
