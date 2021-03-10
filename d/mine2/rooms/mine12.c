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
"%^BOLD%^CYAN%^"
"This shaft is some what a well.  The water in this room is up to your chest.  "
"You have a very hard time moving around in it.  Because of the water, it "
"probably hasn't been mined in that often.  "
"There are several bubbles that are coming up from the floor.  "
""
"");

     set_listen("default","You hear rushing water.");
     set_smell("default","You smell fish.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine7",
       "south" : "/d/mine2/rooms/mine13",
       "west" : "/d/mine2/rooms/mine15",
    ] ));
    set_items(([
         "water" : "It is very deep!",
         "bubble" : "There is one giant on, in the far corner of the room.",
         "well" : "There is no well, but the room looks like one!",
         "shaft" : "It is filling up with water fast.",
         "gold" : "You can not see any at the monent.",
         "rock" : "You can't see them!  They are under the water!",
         "ground" : "You can't! The water covers it!",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(2);
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
