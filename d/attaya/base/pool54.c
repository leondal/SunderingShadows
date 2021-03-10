#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("A small boat in the reflection pool docked.");
     set_long("
    You are sitting in a small wooden boat floating on the reflection pool of the crystalline tower.  Your boat is docked currently.
    A steel ladder protrudes from the pier and you can easily climb out of the tiny boat.
    The waters are somewhat dark here, as if very deep beneath the dock.  Perhaps something is down there!
");
set_smell("default", "%^BOLD%^%^MAGENTA%^Several small boats are here.");
   set_exits( ([
       "north" : "/d/attaya/base/pool49",
       "east" : "/d/attaya/base/pool55",
       "west" : "/d/attaya/base/pool53"
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
add_action("climb_out", "climb");
add_action("swim", "swim");
}
int climb_out(string str) {
write("%^BOLD%^You climb out of the boat onto the dock.\n");
say((string)this_player()->query_cap_name()+" climbs out of the small boat onto the dock.\n");
this_player()->move_player("/d/attaya/base/boatdock");
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
this_player()->move_player("/d/attaya/base/oubliette1",);
return 1;
}

