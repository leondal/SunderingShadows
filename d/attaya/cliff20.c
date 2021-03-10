#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",1);
    set_travel(DIRT_ROAD);
    set_terrain(STONE_BUILDING);
    set_short("%^BOLD%^%^WHITE%^Guard station of the Kinnesaruda");    
    set_long("%^BOLD%^%^WHITE%^Guard station of the Kinnesaruda
%^RESET%^%^ORANGE%^You are inside a small guard station high in the mountainside. A large window displays a view of the %^ORANGE%^is%^BOLD%^%^GREEN%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^n%^RESET%^%^ORANGE%^d%^ORANGE%^ and the %^BOLD%^%^BLUE%^oc%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^n%^ORANGE%^ beyond it. A few benches and tables surround you, nothing much of interest. A dark tunnel leads straight down near the center of the room. Metal rungs fastened to the walls form a ladder. It is pitch black within there, and you would much rather not go that way!");
       set_exits(([
          "down":"/d/attaya/cliff19",
          "west":"/d/attaya/cliff21",
          "east":"/d/attaya/cliff62",
]));
      set_listen("default", "You can hear faint screams coming from deep within the dark tunnel");
}

void reset(){
	int num, i;
	::reset();
	
if(!present("paladin"))
new("/d/attaya/mon/spal.c")->move(TO);
	
}
