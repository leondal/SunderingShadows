#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
          ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("mine enterance");
    set_long(""
"%^ORANGE%^ "
"This mine shaft is very dark.  You inhale gold dust as you breath in this room.  " 
"There are water drops dripping from the top of the room, and then falling dowm "
"in to many little puddles.  There are several little rocks sitting around the "
"room, and you notice several spots where miners have dug at the wall hoping "
"for gold.");

     set_listen("default","You hear water driping from the top of the room.");
     set_smell("default","You smell gold dust.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine22",
       "west" : "/d/mine2/rooms/mine17",
    ] ));
    set_items(([
         "darkness" : "It is covers the room, making it hard to see.",
         "water" : "It is driping form the top of the room and making several little puddles.",
         "marks" : "The marks were made by picks.",
         "shaft" : "It is very dark, and smell like gold.",
         "gold" : "The only thing to do with gold in this room is the gold dust.",
         "rock" : "There is several pieces of chiped rock on the ground.",
         "ground" : "It is covered with chiped rock.",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(3);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
  if(!ob || member_array(ob, all_inventory(this_object())) == -1)
    if(random(5) == 1)
     {

       switch(random(5))
        {
        case 0: ob  = this_player()->move_player("/d/mine2/rooms/trap1");
                  break;
        case 1: ob  = this_player()->move_player("/d/mine2/rooms/trap2");
                  break;
        case 2: ob  = this_player()->move_player("/d/mine2/rooms/trap3");
                  break;
        case 3: ob  = this_player()->move_player("/d/mine2/rooms/trap4");
                  break;
        case 4: ob  = this_player()->move_player("/d/mine2/rooms/trap5");
                  break;
       }
}
}
