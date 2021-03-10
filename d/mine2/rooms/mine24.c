#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
           ::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^CYAN%^ "
"This mine shaft is very cold and dark.  You are not sure what is in here because " 
"it is so dark.  all that you can see, it the light comming from another room above."
""
""
"");

     set_listen("default","You hear nothing strange.");
     set_smell("default","You smell nothing odd.");
    set_exits(([
       "up" : "/d/mine2/rooms/mine11",
   
    ] ));
    set_items(([
         "cavern" : "It is farly small, and is very dark.",
         "it" : "It is it and nothing else.",
         "zeek" : "%^BOLD%^CYAN%^There is a sign reading, /n ZEEK ROCKS!",
         "demonforce" : "%^BOLD%^CYAN%^There is a sign reading, /n Demonforce ROCKS!",
         "brandon" : "Brandon is accually zeek.",
         "that" : "That is that.",
         "why" : "why is why.",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(2);
set_nugget( ([ "1":1, ]) );
}
