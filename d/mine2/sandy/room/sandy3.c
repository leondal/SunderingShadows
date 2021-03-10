#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, east gate.");
    set_long(""
"%^BOLD%^WHITE%^You at the east gate of Sandy.\n%^RESET%^"
"To the east is the grasslands where many things come to be good from there.  "
"To the west is the rest of the great town of Sandy.  To the north is a dirt "
"road that leads in a winding fasion.  The great gates are here to protect the "
"city from any people who should not be in them, and to keep peace."
""
"");

     set_listen("default","You hear people talking as they travel through the gate.");
     set_smell("default","You smell dust from the people walking.");
 
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy3",
       "east" : "/d/shadow/room/grassland/grass3",
       "west" : "/d/mine2/sandy/room/sandy5",

    ] ));
    set_items(([
         "gate" : "The gate is currently open for travel, and it stands tall and powerfull.",
         "road" : "It is a very often used.",
         "people" : "They are traveling in and out of the town.",
         "dirt road" : "The dirt road leads to a distant place.",
    ] ));
}
init() {
  ::init();
   add_action("go_north","east");
}
int go_north(string str){
write("%^BOLD%^WHITE%^The gate is currently open.");
return 0;
}
