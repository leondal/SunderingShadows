
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
      set_travel(LEDGE);
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious tropical paradise");
        set_long("%^CYAN%^You are on a small metal platform that holds a metal rung %^BLUE%^l%^BOLD%^%^BLACK%^ad%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^BLUE%^.%^CYAN%^ The %^BLUE%^l%^BOLD%^%^BLACK%^add%^RESET%^%^BLUE%^e%^BLUE%^r%^CYAN%^ decends to the %^CYAN%^rushing %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^ater%^CYAN%^ below, and spray wafts all the way up here! Just to the north, you can see a strange %^BOLD%^%^BLACK%^bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k %^BLACK%^veil.%^RESET%^");
    set_listen("default", "The crashing water below is deafening in here!");
       set_exits(([
       "down" : "/d/attaya/tower/floor25",
       "north" : "/d/attaya/tower/floor19",
]));
  set_invis_exits( ({"north"}) );
       set_items(([
    "ladder" : "It is a sturdy metal ladder.",
    "veil" : "%^BLUE%^A phantom veil of deception hangs here, placed to hide this passage from the other side where the veil mimics a normal wall!",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
