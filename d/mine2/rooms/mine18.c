#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
           ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine shaft"
    "shaft");
    set_long(""
"%^BOLD%^ORANGE%^ "
"This part of the mine has very sharps rocks sticking out from the walls.  " 
"As you get closer to the rocks, you cut your self just a little on them.  "
"Strangly enough, you do not bleed, and it heals quickly.  There are many things "
"that make you wonder what this mine is really.  There is a small gold nugget "
"on the ground.");

     set_listen("default","You hear the the mountain rumble.");
     set_smell("default","You smell somthing rotting.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine17",
       "south" : "/d/mine2/rooms/mine20",
    ] ));
    set_items(([
         "cavern" : "It is farly small, and lined with sharp rocks.",
         "rocks" : "They lie along the walls, and some are stained with blood.",
         "blood" : "The blood is stained on the rocks.",
         "shaft" : "It is very small, with walls made of sharp rock.",
         "gold" : "The little gold chunk turn out to be just fools gold.",
         "cut" : "The cut on your arm, now seams to have vanished.",
         "ground" : "There is a small gold chunk on it.",
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
