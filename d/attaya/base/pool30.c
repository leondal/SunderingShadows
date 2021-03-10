#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(1);
     set_indoors(1);
     set_short("On a small boat in the reflection pool");
     set_long("
   %^BLUE%^You are in a small boat floating beneath a high bridge in the reflection pool.  The waters lap against the hull almost melodically.
    It is very calm under here and you wouldn't mind simply sitting for a moment and gazing at your reflection in the water.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "%^BOLD%^%^MAGENTA%^A small boat is here.\n");
   set_exits( ([
       "west" : "/d/attaya/base/pool29",
       "south" : "/d/attaya/base/pool42",
       "east" : "/d/attaya/base/pool31"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
        "boat" : "The small boat is quite sturdy.  It is just large enough for 1 passenger.",
        "wall" : "The wall is built of marble against the water, to a height of about 40 feet, then it becomes a vast array of glass panels.",
         "reflection" : "Your reflection seems as clear as a mirror.",
         "bridge" : "You can see the wooden suupot planks beneath the bridge above you that hold the marble tiles in place.  They are in perfect shape as if built yesterday.",
]) );
}
void init() {
     ::init();
add_action("swim", "swim");
}
int swim(string str) {
           object ob;
write("You dive into the water.\n");
write("%^BOLD%^%^GREEN%^You are lifted from the water by a magical force and carried high into the air.\n");
say((string)this_player()->query_cap_name()+" dives into the waters and %^BOLD%^a magical force carries them away in a sphere of light.
.\n");
this_player()->move_player("/d/attaya/tower/tower8",);
write("%^CYAN%^You are safely placed on one of the crystalline platforms high in the chamber!\n");
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
