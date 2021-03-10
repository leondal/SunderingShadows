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
"%^BOLD%^BLUE%^ "
"You can not see much because there is only about an inch of air at the top " 
"of the shaft, the rest is under water."
""
""
"");

     set_listen("default","You hear rushing water.");
     set_smell("default","You smell something bad.");
    set_exits(([
       "up" : "/d/mine2/rooms/mine5",
       "east" : "/d/mine2/rooms/mine9",
    ] ));
    set_items(([
         "cavern" : "It is filled with water.",
         "water" : "It is very deap.",
         "air" : "There is only an inch above the water to breath it.",
         "shaft" : "It is almost totally filled with water.",
         "gold" : "You can not if there is any gold in here because of how deep the water is.",
         "room" : "It is filled with water.",
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
