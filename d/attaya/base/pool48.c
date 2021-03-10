#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("On a small boat in the reflection pool");
     set_long("
   %^BLUE%^You are in a small boat floating in the reflection pool.  The waters lap against the hull almost melodically.
    %^CYAN%^The great wall of the tower rises out of view just to the north and a low bridge prevents forther sailing to the west.%^RESET%^
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "%^BOLD%^%^MAGENTA%^A small boat is here.\n");
   set_exits( ([
       "east" : "/d/attaya/base/pool49",
       "south" : "/d/attaya/base/pool53"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
        "boat" : "The small boat is quite sturdy.  It is just large enough for 1 passenger.",
        "wall" : "The wall is built of marble against the water, to a height of about 40 feet, then it becomes a vast array of glass panels.",
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
this_player()->move_player("/d/attaya/base/oubliette6",);
return 1;
}

