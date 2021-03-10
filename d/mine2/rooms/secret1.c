#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("mine secret room");
    set_long(""
"%^BOLD%^YELLOW%^ "
"You are in a large room with gold all over.  " 
"You have found the hidden gold room, where people become rich fast.  "
"You feel very happy to have found it.  "
"If this place becomes to popular, it will soon become worth less.  "
"And you will not ever get gold here.");

     set_listen("default","You gold singing to you.");
     set_smell("default","You smell freshly mined gold.")
    set_exits(([
       "out" : "/d/mine2/rooms/mine10",

    ] ));
    set_items(([
         "cavern" : "It is filled with gold!",
         "room" : "It is filled with gold!",
         "people" : "There are not to many that have mined here!",
         "shaft" : "It is fillled with gold!",
         "gold" : "There is gold all over!",
         "walls" : "They are covered with gold!",
         "ground" : "It is coverd with gold!",
    ] ));
set_max_mining(2);
set_chance(13);
set_max_find(10);
set_nugget( ([ "1":1, "2":2, "3":3, "4":4, "5":5, ]) );
}
