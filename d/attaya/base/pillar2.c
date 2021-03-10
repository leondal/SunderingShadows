#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Atop a pillar in the crystalline tower");
     set_long("
    You are standing atop one of the large marble pillars in the reflection pool.  There is quite a view from up here and you take a moment to look over your surroundings.  At your back is the southern wall fortress and the reflection pool stretches out before you.  To the northwest, hundreds of wyverns scurry around the central platform.
    Your boat bobs in the water beneath you.
");
set_listen("default", "It is quiet and serene up here.\n");
set_items( ([
        "pool" : "The reflection pool is remarkable and reflects the entire room.",
        "platform" : "The grand central platform is not too far away to the northwest.  Wyverns move about upon it.",
        "fortress" : "The southern wall fortress stands to a height of about 15 stories.  Archers watch you from it's openings.",
        "floor" : "The floor beneath you is the top of the massive pillar.  It is quite smooth.",
        "archers" : "The archers watch you carefully from above.",
        "ladder" : "The ladder is a fairly new steel runged ladder with no rust."
]) );
}
void init() {
     ::init();
add_action("climb_boat", "climb");
add_action("swim", "swim");
}
int climb_boat(string str) {
write("%^BOLD%^You climb down the ladder into the small boat.\n");
say((string)this_player()->query_cap_name()+" climbs down the ladder to the small boat.\n");
this_player()->move_player("/d/attaya/base/pool47");
write("%^CYAN%^The small boat rocks wildly.");
return 1;
}
int swim(string str) {
           object ob;
write("You dive off the pillar into the water.\n");
write("%^BOLD%^%^RED%^You feel your body begin to stiffen and you can no longer see or breathe.\n");
say((string)this_player()->query_cap_name()+" dives into the waters and vanishes into the depths.
.\n");
this_player()->move_player("/d/attaya/base/oubliette48",);
return 1;
}

