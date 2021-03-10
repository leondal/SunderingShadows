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
"There is a large cave that leads to some place dark and special to certain "
"people.  The road looks to not have been traveled that much, probably because "
"those who do travel it are very skilled in not being noticed.  "
"The gold road continues to the north a ways.  "
""
"");


     set_smell("default","You smell nothing strange.");
    set_exits(([

       "north" : "/d/mine2/sandy/room/sandy8",

       "cave" : "/d/mine2/sandy/room/ac_thief",
    ] ));
    set_items(([
         "cave" : "The cave is very dark.",
         "road" : "The road is made of fine gold.",
         "gold" : "The gold is way to much for you to carry.",
         "zeek" : "Zeek coded this area!",
    ] ));
}
