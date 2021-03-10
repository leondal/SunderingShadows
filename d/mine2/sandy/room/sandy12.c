#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, north gate road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"The road here has been freshly paved, but is already starting to crack."
"  The north gate of Sandy is the the north, and to the west is the Magic Shop.  "
"To the south, leads to the center of Sandy, where it is very noisy.  "
"There is not much to see from here, because large palm trees block the view.  "
""
"");


     set_smell("default","You smell something good.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy11",
       "south" : "/d/mine2/sandy/room/sandy13",

       "west" : "/d/mine2/sandy/room/magic",
    ] ));
    set_items(([
         "palm trees" : "The trees are very large, and block your view.",
         "road" : "The road has been freshly paved, but there are already cracks in it.",
         "cracks" : "The cracks are small right now, but they are growing as time goes on.",
         "trees" : "The are large palm trees.",
    ] ));
}
