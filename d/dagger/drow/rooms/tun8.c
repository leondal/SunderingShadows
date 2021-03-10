// getting rid of the cloak search since it's been moved into the drow city and improved
// *Styx* 12/12/03, last change 4/15/03

#include "/d/dagger/drow/short.h"
#include <std.h>

inherit "/std/room";

// int FLAG; 

void init() {
    ::init();
//    add_action("search","search");
}

void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(RUBBLE);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
	"%^BLUE%^You clamber up on top of the pile of rubble which fills "
	"the entire room, crouch down, and squeeze into the chamber. The "
	"rubble has filled the room so much that whatever, if anything, "
	"was in here has long since been buried. "
	"The same %^MAGENTA%^lichen%^BLUE%^ as found throughout the cavern "
	"tunnels grows here, but most of it lays within the rubble and "
	"seems to slowly be fading away."
    );
//    FLAG = 0;
    set_listen("default",
	"You expect to hear the sound of further rocks falling "
	"if you linger here much longer."
    );
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern tunnel.%^RESET%^",
	"rubble":"%^RED%^You notice a human hand sticking out of the "
	"rubble.%^RESET%^",
	"hand":"%^RED%^The hand most likely is attached to a corpse... buried "
	"under the rubble.%^RESET%^",
	"corpses":"The corpses are of two dead humans. They were obviously "
	"crushed when the ceiling collapsed in the chamber.",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows on "
	"the walls here."
    ]));
    set_exits(([
    	"southwest": RPATH "tun7"
    ]));
    set_search("rubble", "There are indeed two corpses buried in the rubble.");
    set_search("corpse", "All you find are brittle bones and decaying gear.");
    set_search("corpses", "There are two but there is nothing of value left on them.");
}

/* the robe is moved to the city now and we need to use a function pointer for the search if anyone puts it back  *Styx*
int search (string str) {
   object obj;
    if(str != "corpses" && str !="rubble") {
        notify_fail ("Search what?");
	return 0;
    }
    if(str == "rubble") {
	message("my_action",
	    "You find two corpses buried among the rubble."
	,TP);
	message("other_action",
	    "%^RESET%^"+TPQCN+" searches the rubble and unearths two "
	    "corpses."
	,environment(TP),TP);
	return 1;
    } else {
        if(FLAG == 0) {
        FLAG = 1;
	message("my_action",
	    "%^BLUE%^You search the corpses and find a "
	    "%^BOLD%^%^BLACK%^black robe%^RESET%^%^BLUE%^ on one of "
	    "them!%^RESET%^"
	,TP);
	message("other_action",
	    "%^BLUE%^"+TPQCN+" searches the corpses and finds a "
           "%^BLACK%^%^BOLD%^black robe%^RESET%^%^BLUE%^ on one of "
	    "them!%^RESET%^"
	,environment(TP),TP);
	new( OPATH "blcloak")->move(TO);
   obj = present("black robe");
   if((int)obj->query_property("enchantment") < 1) return 1;
   if(!random(2)) {
     while ((int)obj->query_property("enchantment") != -2) {
      obj->remove_property("enchantment");
      obj->set_property("enchantment",-2);
     }
   }
	return 1;
    } else {
	tell_object(TP,
	    "There is nothing left of value in the corpses."
	);
	return 1;
    }
}
}
*/