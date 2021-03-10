#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
         ::create();
     set_property("light",2);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(
@THORNWUZHERE
%^BOLD%^ORANGE%^ 
This shaft is very peaceful.  There are few things to worry about 
in this shaft, that makes the worries about dying fade away.  
There is a small stream that runs through the shaft, making it 
seem calm.  There is a gold nugget that has just been left on the 
floor, but as you bend over to get it, you notice that it is some 
kind of joke, because it is super-glued to the ground!
THORNWUZHERE
	);

     set_listen("default","You hear the stream gurgle.");
     set_smell("default","You smell the scent of gold.");
    set_exits(([
       "south" : "/d/mine2/rooms/mine22",

    ] ));
    set_items(([
         "stream" : "It is small, but yet it relaxes you.",
         "nugget" : "It is super glued to the floor!",
         "floor" : "There is a gold nugget sitting on it.",
         "shaft" : "It is very calm.",
         "gold" : "There is a gold nugget, thats it.",
         "rock" : "You do not see that here!",
         "ground" : "There is a gold nugget on it.",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(1);
set_nugget( ([ "1":1, ]) );
}
