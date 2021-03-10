#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, gold road");
    set_long(""
"%^BOLD%^WHITE%^You are on a gold road.\n%^RESET%^"
"The road has been made out of fine gold, and is very seldom traveled.  "
"There is no evidence even that it has been traveled at all!  There are large "
"trees that line the sides of the road, and make a perfect place to rest.  "
"The road continues to the south and to the west is a paved road.  "
""
"");


     set_smell("default","You smell gold.");
    set_exits(([

       "south" : "/d/mine2/sandy/room/sandy8",

       "west" : "/d/mine2/sandy/room/sandy15",
    ] ));
    set_items(([
         "trees" : "The trees are large palm trees.",
         "road" : "The road is made of fine gold.",
         "gold" : "The gold is way to much for you to carry.",
         "people" : "There arn't any people that you can see around!",
    ] ));
}
