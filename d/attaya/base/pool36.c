#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("A small boat in the reflection pool docked.");
     set_long("
    You are sitting in a small wooden boat floating on the reflection pool of the crystalline tower.  Your boat is at the base of a metal ladder fastened to the side of a large pillar.
    The pillar seems to have been purposely placed here.  It is completely smooth and would be unclimbable if not for the ladder.
");
set_smell("default", "%^BOLD%^%^MAGENTA%^A small boat is here.");
   set_exits( ([
       "northeast" : "/d/attaya/base/pool25",
       "east" : "/d/attaya/base/pool37",
       "north" : "/d/attaya/base/pool24"
]) );
set_items( ([
       "boat" : "The tiny boat is just large enough for 1 rider.  It appears quite stable and well constructed.  It has been constructed of cedar and resin.",
       "water" : "The water is so clear that you can trace the pillar underwater for hundreds of feet.",
        "ladder" : "The ladder is a fairly new steel runged ladder with no rust.",
        "pillar" : "The pillar is completely smooth white marble with a steel runged ladder fastened to it here.",
]) );
}
void init() {
     ::init();
add_action("climb_out", "climb");
add_action("swim", "swim");
}
int climb_out(string str) {
write("%^BOLD%^You climb out of the boat and up the ladder.\n");
say((string)this_player()->query_cap_name()+" climbs out of the small boat and scurries up the ladder.\n");
this_player()->move_player("/d/attaya/base/pillar1");
write("%^CYAN%^The small boat rocks wildly in the water beneath you.");
return 1;
}
int swim(string str) {
           object ob;
write("You dive into the water.\n");
write("%^BOLD%^%^RED%^You feel your body begin to stiffen and you can no longer see or breathe.\n");
write("%^BOLD%^%^BLUE%^A shadowy form slips past you!\n");
say((string)this_player()->query_cap_name()+" dives into the waters and vanishes into the depths.
.\n");
this_player()->move_player("/d/attaya/base/oubliette42",);
return 1;
}

