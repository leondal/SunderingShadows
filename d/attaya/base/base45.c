#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Edge of the main platform inside the Crystalline Tower");
     set_long("
    You stand at the southern edge of the great red marble platform at the center of the crystalline tower's base.  Before you stretches a reflection pool that extends to the inside of the tower's southern wall.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "The water seems to crackle like parchment.\n");
   set_exits( ([
       "west" : "/d/attaya/base/base44",
       "east" : "/d/attaya/base/base46",
       "north" : "/d/attaya/base/base37"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
         "wall" : "The wall is built of marble against the water, to a height of about 40 feet, then it becomes a vast array of glass panels.",
        "platform" : "The marble base upon which you stand is elevated slightly from the water of the reflection pool.",
]) );
}
void reset(){
   object mon;
   ::reset();
    if(!present("silver wyvern")) {
         mon = new("/d/attaya/mon/swyvern");
        mon->move(this_object());
    }
}
void init() {
     ::init();
add_action("swim", "swim");
}
int swim(string str) {
           object ob;
write("You dive into the water.\n");
write("%^BOLD%^%^RED%^You feel your body begin to stiffen and you can no longer see or breathe.\n");
say((string)this_player()->query_cap_name()+" dives into the waters and is instantly pulled under.
.\n");
this_player()->move_player("/d/attaya/base/oubliette13",);
return 1;
}

