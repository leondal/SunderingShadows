
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
	set_name("Inner Sanctum of the Kinnesaruda");
	set_short("Inner Sanctum of the Kinnesaruda");
	set_property("indoors",1);
	set_property("light",2);
set_long("
    A great chamber takes up nearly the entire tower.  The ceiling rises into the mist above, and a few vines hang down from the stone walls.  All around you are carved stone statues and symbols in the walls.  The marking that gives you the most fear is the ensignia in the floor...  That which means %^RED%^Intruder.
    %^RESET%^A door on the north wall looks promising.  Gold glitters from behind it.  A large circular hole in the center of the chamber looks much less promising.
");
       set_exits(([
         "out":"/d/attaya/tower/floor22",
          "north":"/d/attaya/tower/treasure",
         "down":"/d/attaya/tower/intruderhall"
]));
	
      set_smell("default", "The air smells of death somehow.");
      set_listen("default", "A strange grinding comes from the hole.");
    set_items(([
    "vines" : "They hang from the sloping ceiling, and climb over the walls.",
    "statues" : "They are quite worn, many are broken.",
    "symbols" : "You cannot read them.  A few look familiar from other parts of the tower.",
    "hole" : "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Yes, that's it...  Go Ahead!  I am waiting for you.",
    "symbol" : "This is Intruder's symbol.  It was on the tomb in the jungle!",
    "ensignia" : "The symbol of Intruder covers the large round floor.",
    "walls" : "The walls are carved everywhere with statues and symbols protruding from them.",
    "door" : "It leads to the treasure vault...  It is open."
]));
	
}
void reset(){
        ::reset();
    if(!present("sign"))
     new("d/attaya/obj/warning2")->move(this_object());
}
