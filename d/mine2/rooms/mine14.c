
#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
           ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^BLUE%^ "
"This mine shaft is large and very dark.  You can not see much much in here "
"but you do notice a few little things.  "
"There are some little gold chunks that are sitting on the floor, but "
"you know that they are to good to be true, but you never can now unless you "
"look at them closly."
"");

     set_listen("default","You hear nothing!");
     set_smell("default","You smell something good.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine17",
       "west" : "/d/mine2/rooms/mine13",
    ] ));
    set_items(([
         "darkness" : "It makes everything hard to see.",
         "gold" : "As you look closer at the gold, you notice that is just fools gold.",
         "fools gold" : "Fools gold is only for fools, and is not worth a melted silver piece!.",
         "shaft" : "It very large and dark.",
         "closly" : "As you look closly, you see not much more.",
         "rocks" : "They are all over the floor.",
         "floor" : "It is covered with fools gold.",
         "room" : "It is very dark.",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(1);
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
