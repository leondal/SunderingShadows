#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, dirt road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a narrow dirt road.\n%^RESET%^"
"The dirt road is very narrow and winding.  There are trees all along the sides "
"of the road.  There are many small foot prints, that you can not tell what they "
"are from.  There is a small stream running along the side of the road, creating "
"a peacefull area.  There are sounds coming from close by, and it makes you wonder "
"what is making them...."
""
""
"");

     set_listen("default","You hear something close by.");
     set_smell("default","You smell dust.");
 
    set_exits(([

       "east" : "/d/mine2/sandy/room/sandy3",
       "west" : "/d/mine2/sandy/room/sandy1",

    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are swaying in the gentle breaze.",
         "dirt" : "It is very soft.",
         "road" : "The road is made of dirt.",
         "stream" : "The cool water makes you feel peacefull.",
    ] ));
}
