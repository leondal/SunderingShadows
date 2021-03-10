#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Corner of the main platform inside the Crystalline Tower");
     set_long("
    This is the northeast corner of the grand base platform of red marble tiles.  The reflection pool is just below you and extends to the north and west.  Looking around, you begin to realize how very tiny you actually are!
    A large pillar rises from the water against the corner between the two walls in the distance.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "The water seems to crackle like parchment.\n");
   set_exits( ([
       "west" : "/d/attaya/base/base9",
       "south" : "/d/attaya/base/base18"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
          "pillar" : "The pillar is rising from the water near the corner of the north and east walls.  It is a good distance away, but may be large enough to walk around upon!",
        "wall" : "The wall is built of marble against the water, to a height of about 40 feet, then it becomes a vast array of glass panels.",
        "platform" : "The marble base upon which you stand is elevated slightly from the water of the reflection pool.",
]) );
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
this_player()->move_player("/d/attaya/base/oubliette22",);
return 1;
}

