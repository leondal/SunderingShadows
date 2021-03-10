//Octothorpe (1/22/12)
//Shadow, West Wall 5

#include <std.h>
#include "../defs.h"
inherit INH+"westwall";

void create(){
    ::create();
    set_exits(([
        "northwest" : ROOMS"westwall4",
        "southeast" : ROOMS"westwall6",
        "north" : ROOMS"jail_main",      
    ]));
    set_long("%^BOLD%^%^BLACK%^West Wall Road, Shadow%^RESET%^\n "+
        "This bustling road travels along the base of %^BOLD%^%^BLACK%^"+
        "Shadow's %^RESET%^defensive wall. The road is wider than those "+
        "found in most large cities in the North, and seems to have "+
        "been designed to more than adequately handle the throngs of "+
        "Shadow's citizenry, or an army on parade. Dark octogonal "+
        "%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^"+
        "pavers form the surface of the roadway, and there's a small grate here. A multitude of "+
        "%^ORANGE%^wooden %^RESET%^and st%^BOLD%^o%^RESET%^ne buildings "+
        "line the eastern side of the road, consisting mostly of "+
        "storefronts on the ground floor and apartments reaching up "+
        "a story or two above that. The opposite side of the road is "+
        "dominated by the %^BOLD%^%^BLACK%^dark st%^RESET%^o%^BOLD%^"+
        "%^BLACK%^ne %^RESET%^wall that protects the city.\n\n");
    set_items(([
        ({"street","avenue","road","roadway","pavers"}) : "The wide "+
            "street allows for four horse-drawn wagons to travel abreast "+
            "of each other. Thousands of octogonal pavers carved out of a "+
            "fairly mundane dark %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
            "%^BLACK%^ne %^RESET%^compose the surface of the road. The "+
            "center of the street is crested, with the edges slightly "+
            "graded to provide runoff during inclement weather.",
        ({"buildings","stone buildings","wooden buildings","storefronts"}) : 
            "A barricade of buildings line the eastern side of the street. Most "+
            "reach up to two or three stories and contain storefronts in "+
            "the ground floor, with apartments above. The buildings themselves "+
            "are fairly unremarkable and appear to be stereotypical of those "+
            "seen north of the Tsarven Empire.",
        ({"walls","wall","stone wall","dark stone wall"}) : "The sturdy "+
            "defensive wall that surrounds %^BOLD%^%^BLACK%^Shadow %^RESET%^"+
            "is constructed out of %^BOLD%^%^BLACK%^black basalt tuff"+
            "%^RESET%^, which is an unusual building material in the "+
            "region. The wall measures roughly twelve feet thick at its "+
            "base and reaches up to nearly forty feet in height.",
        ({"prison tower","tower"}) : "Three story high this %^BOLD%^%^BLACK%^gloomy stone tower%^RESET%^ raises above surrounding city.",
        ({"grate"}) : "%^BOLD%^%^BLACK%^It might be possible to move the grate in order to open or close it.%^RESET%^",
    ]));
}

void reset(){
    ::reset();
	if(member_array("down",TO->query_exits()) != -1) {
        tell_room(TO,"%^ORANGE%^The grate in the grate in the road slides shut with a heavy thud.%^RESET%^");
        remove_exit("down");
        if(member_array("up",ROOMS"sewer42"->query_exits()) != -1) {
            tell_room(ROOMS"sewer42","%^ORANGE%^The grate in the ceiling shuts with a heavy thud.%^RESET%^");
            ROOMS"sewer42"->remove_exit("up");
        }
    }
}

void init() {
  	::init();
  	add_action("open","open");
	add_action("close","close");
}

int close(string str) {
 	if(!str) {
   	tell_object(TP,"Open what?");
        return 1;
    }
  	if(str == "grate"){
  		if(member_array("down",TO->query_exits()) != -1) {
     		tell_object(TP,"You slide the grate back into place.\n");
			remove_exit("down");
			if(member_array("up",ROOMS"sewer42"->query_exits()) != -1) {
                tell_room(ROOMS"sewer42","The sewer falls into darkness as someone slides the grate shut from above.\n",TP);
                ROOMS"sewer42"->remove_exit("up");
                return 1;
            }
            tell_object(TP,"The grate is as closed as it can possibly be.");
            return 1;
        }
    }
}

int open(string str) {
 	if(!str) {
   	tell_object(TP,"What are you trying to open?");
        return 1;
    }
  	if(str == "grate"){
        tell_object(TP,"%^BOLD%^%^WHITE%^You slowly move aside the heavy grate leading to the sewers.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" slowly moves aside the heavy grate leading to the sewers.%^RESET%^",TP);
        add_exit(ROOMS"sewer42","down");
        tell_room(ROOMS"sewer42","%^BOLD%^%^WHITE%^Light suddenly floods the tunnel as the grate overhead opens.RESET%^");
        ROOMS"sewer42"->add_exit(ROOMS"westwall5","up");
        return 1;
    }
}

