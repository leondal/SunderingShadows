#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
         ::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("mine enterance");
    set_long(""
"%^BOLD%^RED%^"
"As you enter the mine shaft, you notice that it is very dark, and there is blood covering most of " 
"of the ground.  There are no bodies in sight, but you know there must be "
"close by.  There are a lot of strange smells comming from the room, and there "
"is a moaning comming from a near by room.  You do not feel safe in here at all!  "
"You want out now.");

     set_listen("default","You hear moaning.");
     set_smell("default","You smell human blood.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine26",
       "south" : "/d/mine2/rooms/mine25",
       "west" : "/d/mine2/rooms/mine20",
    ] ));
    set_items(([
         "blood" : "It is human blood, and covers the gorund.",
         "bodies" : "There are now bodies in sight that you can see.",
         "room" : "It is very dark and covered in blood.",
         "shaft" : "It is very dark, and covered in blood.",
         "darkness" : "The lighting in the mine is teribbly, but this room appears to be the worst!",
         "body" : "You don't even see a body in here.",
         "ground" : "It is covered with blood.",
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
