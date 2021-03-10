#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, side road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a side road.\n%^RESET%^"
"The road has a strange glow to it, and apears to be traveled a lot by magical  "
"people.  There are several broken staffs and other things broken that have "
"been broken, and jut thrown off to the side of the road.  The things are much "
"to worthless to even bother to pick up.  To the north is a paved road, and to "
"west is a small hut where magic seams to be coming out of all cracks of the hut.  "
"Large trees blow in the wind."
"");

     set_listen("default","You hear great powers to the west.");
     set_smell("default","You smell magic in the air.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy18",


       "west" : "/d/mine2/sandy/room/ac_mage",
    ] ));
    set_items(([
         "road" : "The road is covered with magical properties.",
         "magic" : "It is all over the area.",
         "hut" : "The hut is far to the west.",
         "trees" : "The trees blow in the wind.",
    ] ));
}
