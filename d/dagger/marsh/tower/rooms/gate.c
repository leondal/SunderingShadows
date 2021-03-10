#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit ROOM;
int VECNA = 0;
int SEARCH = 0;
object VEC,ob;
void init() {
    ::init();
    add_action("search_fun","search");
}
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("no pocket space",1);
    set_long("%^BOLD%^%^BLACK%^"
	"The large circular chamber is composed entirely of blackened marble slabs. Large %^WHITE%^"
	"ivory pillars%^BLACK%^ are positioned in a wide semi-circle near the rear of the chamber. "
	"Flowing %^RED%^blood-red tapestries%^BLACK%^ hang from the ceiling depicting strange "
	"and arcane rituals of an ancient time. A large %^ORANGE%^stone altar%^BLACK%^ lays upon a "
	"raised %^BLUE%^dais%^BLACK%^ in the center of the chamber. A circle of %^WHITE%^humanoid skulls "
	"%^BLACK%^and %^WHITE%^bones%^BLACK%^ surround the %^ORANGE%^altar%^BLACK%^. A strange %^MAGENTA%^ "
	"glowing portal%^BLACK%^ hovers in the air behind the %^ORANGE%^altar%^BLACK%^." 
	"%^RESET%^" 
    );
    set_short("%^BOLD%^%^BLACK%^Vecna's Chamber%^RESET%^");
    set_listen("default",
        "A loud howling fills the chamber causing your blood to curdle."
    );
    set_smell("default",
        "The cold damp air within the chamber smells horrible."
    );
    set_items(([
	"altar":"%^ORANGE%^The altar is merely a large slab of marble set upon a raised dais. It's use "
	"is not clear. Small holes are located upon it's front.%^RESET%^",
	"portal":"%^MAGENTA%^The portal is transparent and hazy activity and movement can be "
	"seen through it. It appears as though one could walk through it to another place.%^RESET%^",
	"skulls":"%^WHITE%^There are numerous skulls of the dead around the altar's base.%^RESET%^",
	"bones":"%^WHITE%^There are numerous bones of the dead around the altar's base.%^RESET%^",
	"skull":"%^WHITE%^There are numerous skulls of the dead around the altar's base.%^RESET%^",
	"bones":"%^WHITE%^There are numerous bones of the dead around the altar's base.%^RESET%^",
	"skulls and bones":"%^WHITE%^There are numerous skulls and bones of the dead around the altar's base.%^RESET%^",
	"dais":"The raised dais adorns an altar. Littered around the altar's base are numerous "
	"skulls and bones.",
        "pillars":"%^WHITE%^A semi-circle of ivory pillars are located to the rear of the chamber.%^RESET%^",
	"tapestries":"%^RED%^The pictures upon the blood-red tapestries are of ancient and arcane rituals, "
	"none of which make any sense to you.%^RESET%^",
	"slabs":"The chamber is composed entirely of blackened marble slabs.",
        "holes":"The strange holes in the altar could perhaps be used for storing things in."
    ]));
    set_exits(([
	"portal": "/d/darkwood/room/road1",
    ]));
    set_pre_exit_functions(({"portal"}),({"exit_fun"}));
    if(VECNA == 0) 
    {
        new( MPATH "vecna")->move(TO);
        VECNA = 1;
    }
    set_property("no phase",1);
}

int exit_fun() {
    if(VEC = present("vecna")) {
	VEC->force_me("yell You will remain within my grasp even unto undeath, "+TPQCN+"!");
        VEC->force_me("cackle");
	message("info",
	    "%^BOLD%^%^RED%^"
	    "Vecna blocks the entrance to the portal!%^RESET%^"
	,TP);
	message("info",
	    "%^BOLD%^%^RED%^"
	    +TPQCN+" is blocked by Vecna!%^RESET%^"
	,ETP,TP);
	return 0;
    } else {
	message("info",
	    "%^CYAN%^"
	    "You walk through the portal and appear in a more familiar and peaceful place!"
	,TP);
	message("info",
	    "%^CYAN%^"
	    +TPQCN+" slowly walks through the portal.%^RESET%^"
	,ETP,TP);
	return 1;
    }
}

void reset() {
    ::reset();
    if(VECNA == 0) {
	new( MPATH "vecna")->move(TO);
	VECNA = 1;
    }
}
int search_fun(string str) {
    if(!str) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str != "holes") {
	notify_fail("Search what?\n");
	return 0;
    }
    if(SEARCH != 0) {
	message("info",
	    "You search the altar holes, but come up empty handed."
	,TP);
        message("info",
	    ""+TPQCN+" searches the holes in the altar."
	,ETP,TP);
        return 1;
    }
    message("info",
	"You search the holes in the altar and find Vecna's treasure!"
    ,TP);
    message("info",
	""+TPQCN+" searches the holes in the altar and finds Vecna's treasure!"
    ,ETP,TP);
//    TP->add_money("gold",random(15000)+5000);
//    TP->add_money("silver",random(50000)+10000);
    ob = new("/std/obj/coins");
    ob->set_money("gold", random(15000)+5000);
    ob->set_money("silver", random(50000)+10000);
    ob->move(TO);
//Switched treasure to load in the room after bug reports
//that no treasure was found (apparently the players didn't 
//know money had been added to them. ~Circe~ 12/1/07
/*
new( OPATH "bag" )->move(TP);
*/
    SEARCH = 1;
    return 1;
}
