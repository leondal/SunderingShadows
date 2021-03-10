#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Small boat dock in the crystalline tower");
     set_long("
    You are standing on a small wooden dock over the reflection pool.  A small ladder hangs over the edge of the dock in front of you and several small boats are tied to it.
    You could easily climb into one of the boats and safely navigate the reflection pool.
    The waters are somewhat dark here, as if very deep beneath the dock.  Perhaps something is down there!
");
set_listen("default", "The water seems to crackle like parchment.\n");
set_smell("default", "%^BOLD%^%^MAGENTA%^Several small boats are here.");
   set_exits( ([
       "south" : "/d/attaya/base/base9"
]) );
set_items( ([
       "boats" : "The tiny boats are just large enough for 1 rider.  They appear quite stable and well constructed.  They have been constructed of cedar and resin.",
       "water" : "The water beneath the pier is exceptionally dark and may be hiding something.",
        "dock" : "The dock is simply several wooden planks on a base of wooden piers.",
        "ladder" : "The ladder is a fairly new steel runged ladder with no rust."
]) );
}
void init() {
     ::init();
add_action("climb_boat", "climb");
add_action("swim", "swim");
}
int climb_boat(string str) {
write("%^BOLD%^You climb into the small boat.\n");
say((string)this_player()->query_cap_name()+" climbs into the small boat.\n");
this_player()->move_player("/d/attaya/base/pool54");
write("%^CYAN%^The small boat rocks wildly.");
return 1;
}
int swim(string str) {
           object ob;
write("You dive into the water.\n");
write("%^BOLD%^%^RED%^You feel your body begin to stiffen and you can no longer see or breathe.\n");
say((string)this_player()->query_cap_name()+" dives into the waters and vanishes into the depths.
.\n");
this_player()->move_player("/d/attaya/base/oubliette1",);
return 1;
}
