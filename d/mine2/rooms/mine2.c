#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
       ::create();
    set_property("light",1);
    set_property("indoors",1);
     set_short("mine shaft");
    set_long(""
"%^BOLD%^YELLOW%^ "
"You are in a large cavern that stretches a long ways down.  The darkness "
"starts to get to you after a while, but you are glad to be in here.  A long "
"stream runs down the center of the cavern.  There are several marks where "
"picks have left marks in the walls.");

     set_listen("default","You hear running water.");
     set_smell("default","The smell of wetness is all around.");
    set_exits(([
           "east" : "/d/mine2/rooms/mine3",
    ] ));
    set_items(([
         "cavern" : "It is very dark and stuffy in this cavern.",
         "stream" : "There is a small stream running down the center of the room.",
         "marks" : "The marks are from picks  from earlier tried to get gold.",
         "darkness" : "The darkness is caused by the enterance being somewher blocked.",
         "gold" : "You do not see any gold right off, only rock.",
         "rock" : "There is several pieces of chiped rock on the ground.",
         "ground" : "it is covered with chiped rock.",
    ] ));
}
