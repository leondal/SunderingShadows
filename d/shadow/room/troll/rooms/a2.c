#include <std.h>
#include "/d/shadow/room/troll/short.h"
inherit ROOM;

inherit "/d/shadow/room/troll/cavern1.c";
inherit "/d/shadow/room/troll/actions1.c";
int MONS = random(3)+1;
void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_property("no scry",1);
    set_short("%^BOLD%^%^ORANGE%^Mine Tunnel%^RESET%^");
    set_long("%^BOLD%^%^RED%^"
             "The tunnel through the %^WHITE%^abandoned mine%^RED%^ shows signs "
             "of recent use. "
             "%^CYAN%^Tracks%^RED%^ lead back and forth from the north and south. "
             "%^ORANGE%^Old rickety wooden support beams%^RED%^ line the "
             "ceiling and the walls of the mine. "
             "Quite a bit of %^MAGENTA%^rock and rubble%^RED%^ lay scattered "
             "about the passageway. "
             "A strange %^GREEN%^moss%^RED%^ grows on the walls here."
             "%^RESET%^");
  
     set_items ( ([

	       ]) );	

     set_mine1_items(({ "mine", "mines", "moss", "glow", "light",
			    "area", "here", "wall", "walls", "floor",
			    "ground", "ceiling", "rock",  
			    "dirt", "room","beam","beams",
			    "tracks","rubble"	
		
                       }));
   
     set_exits(([
		"north": RPATH "a1",
		"south": RPATH "a3",
	       ]));
    set_pre_exit_functions(({ "south" }),({ "deeper" }));
}

int deeper() {
    object me = this_player();
    message("inf",
	"%^BOLD%^%^RED%^"
	"You slowly head deeper into the rickety mine praying you see the light "
	"of day again!"
	"%^RESET%^"
    ,me);
    message("inf",
	"%^BOLD%^%^RED%^"
	+me->query_cap_name()+
	" heads deeper into the mine! What an idiot!"
	"%^RESET%^"
    ,environment(me),me);
    return 1;		  
}

void init() {
    ::init();
    set_mine1_actions(({ "carving", "touch", "mine", "moss" }));
}

void reset() {
    int i;  
    ::reset();

    if(!present("troll")) {
        for(i = 0;i < MONS;i++) {
            new(MPATH "grunt")->move(this_object());
        } 
    }
}
    