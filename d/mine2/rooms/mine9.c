#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
            ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^CYAN%^ "
"This mine shaft is is half way full of water.  There are frogs swimming " 
"around in the water.  There are several things that make you shiver in this "
"room, like the cold water.  You can not see much else because of the water "
"covering the ground."
"");

     set_listen("default","You hear water.");
     set_smell("default","You smell frogs.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine10",
       "west" : "/d/mine2/rooms/mine8",
    ] ));
    set_items(([
         "cavern" : "It is half way full with water.",
         "frog" : "There is one from that looks like he is somewhat a tadpole.",
         "frogs" : "They are swimming around in the water.",
         "shaft" : "It is filled with water.",
         "water" : "The water fills the room half way up.",
         "room" : "The is water in the room.",
         "ground" : "It is covered with water.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
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
