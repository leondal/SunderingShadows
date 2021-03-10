#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("outdoors",1);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The woods around you smell of fresh pine needles."
    );
    set_listen("default","You hear the sounds of woodland animals roaming around.");

    set_items(([
	"clearing":"%^CYAN%^You stand within a clearing.",
	"ceiling":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	"ceiling like canopy.%^RESET%^",
	"canopy":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	"ceiling like canopy.%^RESET%^",
	"trees":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	"ceiling like canopy.%^RESET%^",
    ]));
    set_exits(([
        "east": RPATH "fountain"
	    ]));
}
string lng_fun(string str) {
    str = 
            "%^CYAN%^You stand within a clearing. The "
	    "%^GREEN%^trees%^CYAN%^ here provide a ceiling like canopy. "
	    "A large pile of %^ORANGE%^logs%^CYAN%^ lays blocking the path "
	    "to the west."
	    "%^CYAN%^ ";
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt."
	       "%^CYAN%^";
    }
    if(present("old man")) {
	str += "\n%^GREEN%^An old man lies bleeding and near death in front "
	"of the pile of logs.%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
	str = "%^CYAN%^Under the trees%^RESET%^";
    return str;
}
void reset() {
    ::reset();
/* he's outlived and outsuffered his usefulness  *Styx*  10/28/02
    if(!present("old man")) {
	new("/d/shadow/room/city/cguild/mons/man.c" )->move(TO);
    }
*/
}

