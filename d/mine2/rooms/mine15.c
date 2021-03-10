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
"%^BOLD%^ORANGE%^ "
"This mine shaft is large, and is very bright.  You know that there "
"must be some hole or something letting the light in.  "
"There are several small rocks sitting around the room, but you do not "
"bother to see what type they are at the moment.  "
"A large dead bird is sitting in the room, which makes you wonder why he is "
"dead.");

     set_listen("default","You hear air rushing in.");
     set_smell("default","You smell a dead bird.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine12",
       "west" : "/d/mine2/rooms/mine16",
    ] ));
    set_items(([
         "bird" : "It has been smashed by a mining pick.\nYou feel mad and want to KILL the person who killed it!",
         "hole" : "As you look at the hole, You can see some of the out side world.",
         "out" : "As you look at the hole, you see poeple having fun, but the hole is to small for you to get out through,",
         "shaft" : "It very large.",
         "gold" : "There are little gold pieces in here, but it's not worth it to take the time to get them.",
         "rock" : "As you look closer at the rock, they look like nothing valuable.",
         "air" : "You can't see air moron!",
         "world" : "You can't see much of it from in here!",
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
