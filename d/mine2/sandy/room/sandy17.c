#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, south road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"This road road is very well paved.  The road leads to the south gate of Sandy.  "
"To the north is the town of Sandy, which has many shops that can help you.  "
"To the south is the south gate of Sandy which leads to many distant places.  "
"There are large palm trees that block most of your vie, but you do not mind.  "
"There is a small piece of paper with something writen on it, but is very blury.  "
".");

     set_listen("default","You hear the you hear nothing.");
     set_smell("default","You smell something good.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy16",
       "south" : "/d/mine2/sandy/room/sandy18",


    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are blocking your view of the area.",
         "paper" : "The paper is to wet to read right now.",
         "writing" : "The writing is to blury to read.",
         "road" : "The road is very well paved, making travel easy.",
    ] ));
}
