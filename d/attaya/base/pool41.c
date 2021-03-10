#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("On a small boat in the reflection pool");
     set_long("
   %^BLUE%^You are in a small boat floating in the reflection pool.  The waters lap against the hull almost melodically.
    %^CYAN%^The great wall of the tower rises out of view just to the south.  High above, you can see archers' with their crossbows poised watching over the main platfrom from notches in the wall.%^RESET%^
    A magnificent marble and walnut bridge spans the reflection pool to the east.  It connects to a large door in the fortress!
    It is darker here under the shadows of the fortress south wall.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "%^BOLD%^%^MAGENTA%^A small boat is here.\n");
   set_exits( ([
       "west" : "/d/attaya/base/pool40",
       "east" : "/d/attaya/base/pool42",
       "north" : "/d/attaya/base/pool29"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
        "boat" : "The small boat is quite sturdy.  It is just large enough for 1 passenger.",
         "fortress" : "The fortress is built into the southern wall and is about 15 stories high.  High up, there are notches for archers.",
          "wall" : "The wall here is part of the southern fortress.  It rises about 15 stories, then begins the wall of glass panels.",
         "archers" : "They are watching you, but for some reason aren't attacking.",
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
this_player()->move_player("/d/attaya/base/oubliette40",);
return 1;
}

