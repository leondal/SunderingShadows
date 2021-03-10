#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, north gate");
    set_long(""
"%^BOLD%^WHITE%^You are at the north gate of Sandy\n%^RESET%^"
"To the north, lies the great castle, which many adventurers like your self "
"have died in, trying to finish the quest of the lost chain.  To the west is "
"town healer, and to the south is the great town Sandy, which has many shops "
"and guilds, and many other great places.  There is s sign on the road that "
"has something written on it."
"");

     set_listen("default","You hear people moaning from the west.");
     set_smell("default","You smell nothing odd.");
    set_exits(([
       "north" : "/d/mine2/room/castle2/b75",
       "south" : "/d/mine2/sandy/room/sandy11",
       "west" : "/d/mine2/sandy/room/hospital",
    ] ));
    set_items(([
         "sign" : "The sign reads, \n Enter the castle at your own risk, and do not let things fool you.",
         "castle" : "The castle is very large, and it towers above the whole city.",
         "gate" : "The town gate to the north is currently open for travel to the castle.",
         "road" : "The roads lead to many places.",
    ] ));
}
