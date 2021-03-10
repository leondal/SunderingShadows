#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("On a small boat in the reflection pool");
     set_long("
   %^BLUE%^You are in a small boat floating in the reflection pool.  The waters lap against the hull almost melodically.
    %^RED%^The wall of the red marble platform is just to the north of you and a magnificent marble and gold bridge spans the pool to the east.%^RESET%^
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "%^BOLD%^%^MAGENTA%^A small boat is here.\n");
   set_exits( ([
       "west" : "/d/attaya/base/pool28",
       "south" : "/d/attaya/base/pool41",
       "east" : "/d/attaya/base/pool30"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
        "boat" : "The small boat is quite sturdy.  It is just large enough for 1 passenger.",
        "wall" : "The wall is built of marble against the water, to a height of about 40 feet, then it becomes a vast array of glass panels.",
        "bridge" : "It is a magnificent structure with marble supports and walnut railings.  The sides are carved with intricate patterns.",
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
this_player()->move_player("/d/attaya/base/oubliette17",);
return 1;
}

