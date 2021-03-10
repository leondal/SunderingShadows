#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Corner of the main platform inside the Crystalline Tower");
     set_long("
    This is the southwest corner of the grand marble platform.  The reflection pool glimmers to the south and to the west.  In the corner of this great hall, across the water, you can make out the top of a large pillar that is protruding from the water against the wall.  It is large enough to walk around upon.
    The wall on this side has a tall brick section with holes for archers to shoot from.  It is across the reflection pool, but still you can make out movement within the walls.
    The waters of the reflection pool seem to strangely crackle, and a golden glimmer rides the small wave crests.
");
set_listen("default", "The water seems to crackle like parchment.\n");
   set_exits( ([
       "east" : "/d/attaya/base/base44",
       "north" : "/d/attaya/base/base35"
]) );
    set_items( ([
        "pool" : "The reflection pool glimmers from the light that shines in upon it.  If you sit and stare into it long enough, you think you can make out a maze in the depths.",
        "wall" : "The wall across from you is a tall stone fortress to a hight of about 150 feet.  You can see movement inside the openings to the fortress where archers shoot from.",
        "platform" : "The marble base upon which you stand is elevated slightly from the water of the reflection pool.",
         "pillar" : "The pillar is rising from the water near the corner of the north wall and the west wall.  It is a good distance away, but may be large enough to walk around upon!",
]) );
}
void reset(){
   object mon;
   ::reset();
    if(!present("arctic wyvern")) {
         mon = new("/d/attaya/mon/wyvern");
        mon->move(this_object());
    }
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

