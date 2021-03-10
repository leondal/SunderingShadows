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
"There are many foot prints that looks to be almost like cleric feet prints "
"all over the path.  There are many trees that form strange shapes, that make "
"you wonder where you are going, and if it will be safe.  There is some sort of "
"strange looking thing to the south, that looks to almost look like an enterance "
"to something."
"");

     set_listen("default","You hear dirt crunch under your feet.");
     set_smell("default","You smell dust.");
 
    set_exits(([

       "west" : "/d/mine2/sandy/room/sandy4",
       "south" : "/d/mine2/sandy/room/sandy2",

    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are swaying in the gentle breaze.",
         "dirt" : "It is a very dusty sand, which is very hot.",
         "path" : "The path is made of dirt, and is very narrow.",
         "foot prints" : "The foot prints apear to be made by clerics.",
    ] ));
}
