//	moat12.c
//	Written by Pator@ShadowGate
//	Tue Apr 11  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(1);
    set_short("In the moat under a tree tunnel");
    set_long(
@MOAT12
You are walking inside a dim lit tunnel formed by trees. You have no idea why the moat is hidden here.
MOAT12
    );
set_smell("default","You smell the trees and some very bad smell from the castle.");
set_listen("default","You hear nothing than just forest noises.");
    set_exits(([
"south" : CASTLE+"moat11",
"north" : CASTLE+"moat13"
    ] ));
    set_items(([
       "fish" : "You can't see no fish in the water because it isn't clear enough !",
       "water" : "The water isn't clear here,but the smell has gone.",
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


init() {
       ::init();
       add_action("climb","climb");
       add_action("kill_it","kill");
       }
// There is a little fish here
reset() {
     ::reset();
     if(!(present("fish"))) {
     new(CASTLE+MONSTERS+"fish")->move(this_object());
                                 }
         }
