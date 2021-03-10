#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("On a small boat in the reflection pool");
     set_long("
   %^BLUE%^You are in a small boat floating in the reflection pool.  The waters lap against the hull almost melodically.
    %^RED%^The wall of the red marble platform is just to the east of you.%^RESET%^
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "%^BOLD%^%^MAGENTA%^A small boat is here.\n");
   set_exits( ([
       "west" : "/d/attaya/base/pool14",
       "south" : "/d/attaya/base/pool17",
       "north" : "/d/attaya/base/pool13"
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
this_player()->move_player("/d/attaya/base/oubliette17",);
return 1;
}

void reset(){
        int num, i;
       ::reset();
       if(!present("waterdemon")){
             num = random(8)+1;
           for(i=0;i<num;i++)
            new("/d/attaya/mon/waterdemon")->move(TO);
     }
}
