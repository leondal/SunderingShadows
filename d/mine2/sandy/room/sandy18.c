#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, south gate");
    set_long(""
"%^BOLD%^WHITE%^You are at the south gate of Sandy.\n%^RESET%^"
"To the south are to lands of great adventure.  To the north, is the great "
"town of Sandy.  To the east is a restaurant where you can fill your self "
"up with foods better than you have tasted before. "
"You can see many things from the gate, like the large ocean to the west.  "
"You can tell from the large gate, that this town is a large one, full of great "
"things that can help you on your adventure.");

     set_listen("default","You hear the gates squick a little.");
     set_smell("default","The smell dust from travel.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy17",
       "south" : "/d/shadow/room/maze/enterance",
 
       "east" : "/d/mine2/sandy/room/restaurant",

    ] ));
    set_items(([
         "gate" : "The gate is very large, and is currently closed.",
         "road" : "The road is very often used here.",
         "ocean" : "The ocean covers the whole mud, and is very close by.",
         "lands" : "There are many places you can travel to from here.",
    ] ));
}
init() {
  ::init();
  add_action("go_north","south");
}
int go_north(string str){
write("%^BOLD%^WHITE%^The gate is currently closed");
return 1;
}
