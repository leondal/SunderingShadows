#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
            ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^WHITE%^ "
"A white light blocks your view of the mine shaft."
""
""
""
"");

     set_listen("default","You hear nothing odd.");
     set_smell("default","You smell northing odd.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine5",
       "west" : "/d/mine2/rooms/mine3",
    ] ));
    set_items(([
         "cavern" : "It is to bright!",
         "room" : "It it to bright!",
         "zeek" : "He is to cool to be looked at.",
         "shaft" : "It is to bright!",
         "gold" : "It is to bright!.",
         "rock" : "It is to bright!",
         "ground" : "It is to bright!",
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




