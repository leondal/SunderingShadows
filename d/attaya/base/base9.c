#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Bordering on a small dock inside the Crystalline Tower");
     set_long("
To the north of you is a dock for small boats.  Apparantly made to safely cross the reflection pool.  The marble tiles beneath your feet are visibly more scuffed than they are in other places.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "The water seems to crackle like parchment.\n");
   set_exits( ([
       "west" : "/d/attaya/base/base8",
       "east" : "/d/attaya/base/base10",
       "dock" : "/d/attaya/base/boatdock",
       "south" : "/d/attaya/base/base17"
]) );
}
void reset(){
   object mon;
   ::reset();
    if(!present("black wyvern")) {
         mon = new("/d/attaya/mon/wyvern");
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
this_player()->move_player("/d/attaya/base/oubliette22");
return 1;
}

