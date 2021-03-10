#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, west gate.");
    set_long(""
"%^BOLD%^WHITE%^You are at the west gate of Sandy.\n%^RESET%^"
"You can see the center of Sandy to the very far east.  To the west is the " 
"great ocean, and a dock where you can sail out onto it from.  There are many "
"trees that blow in the wind.  The road is wet from the ocean being so close "
"by.  There are small white streaks from salt that has deposited from people "
"walking up this road after being out on the ocean.  There is a large gate that "
"controls travel in and out of the oceans and the village Sandy.  The great gate "
"stands tall, and can keep almost anything out."
"");

     set_listen("default","You hear the wind blow in the trees.");
     set_smell("default","You smell salt from the ocean.");
    set_exits(([


       "east" : "/d/mine2/sandy/room/sandy23",
       "west" : "/d/mine2/sandy/room/dock",
    ] ));
    set_items(([
         "ocean" : "The ocean is close to the west.",
         "trees" : "They stand tall and strong.",
         "salt" : "The salt forms streaks on the road.",
         "road" : "The road is covered with water and salt.",
    ] ));
}
