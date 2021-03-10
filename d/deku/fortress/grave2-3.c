#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD2;

void create() {
  ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A massive ancient %^RESET%^chapel%^BOLD%^ "+
    "%^WHITE%^rests here among the ruins of the statues and headstones.  A dilapidated wooden "+
    "door futilely attempts to block the entrance.%^RESET%^");

    add_item("chapel","%^BOLD%^%^WHITE%^This massive chapel is made from a once black stone "+
    "that has faded over the course of time.  There are several windows on each of its four "+
    "walls, most of them are broken and have been patched with old boards from the inside.  "+
    "The two windows on the front of the building, on either side of the door have not been "+
    "broken, you think that they may offer a glimpse of what is within the chapel, if one "+
    "wanted to peer in them.%^RESET%^");
	
    set_exits(([
    "south" : GY_ROOMS +"grave1-3",
    "north" : GY_ROOMS + "grave3-3",
    "chapel" : GY_ROOMS +"chapel1",
    "west":GY_ROOMS +"grave2-4",
    "east" : GY_ROOMS +"grave2-2"
    ] ));
 
    set_door("wooden door",GY_ROOMS +"chapel1","chapel");
	
    set_string("wooden door", "open", "%^RED%^The wooden door swings open silently.%^RESET%^");
    set_door_description("wooden door","%^MAGENTA%^This dilapidated wooden door stands barely "+
    "in place, futilely attempting to block access to the ancient chapel.  It has no obvious "+
    "lock and opens by means of a makeshift handle on the left side of it.%^RESET%^");		
}

void init() {
    ::init();
    add_action("peer_action","peer");
}

int peer_action(string str) {
    int i;
    object *objects_in_room;
    if(!str) {
        return 0;
    }
    if(str == "through windows" || str == "windows" || str == "window" || 
        str == "through window" || str == "in windows" || str == "in window") {
        if(!objectp(TP)) return 1;
        if(!TP->query_invis()) { 
            tell_room(TO,TPQCN+"%^MAGENTA%^ walks up to one of the windows on the front of the chapel "+
            "and seems to peer through it.%^RESET%^",TP);
        }
        tell_object(TP,"%^MAGENTA%^You walk up to one of the windows on the front of the chapel "+
        "and peer through it.%^RESET%^");
        tell_object(TP,"%^BOLD%^%^WHITE%^Foyer of An Ancient Chapel%^RESET%^");
        objects_in_room = all_inventory(find_object_or_load(GY_ROOMS+"chapel1"));
        for(i = 0;i < sizeof(objects_in_room);i++) {
            if(!objects_in_room[i]->query_invis()) {
                if(!objectp(TP)) return 1;
                    tell_object(TP,objects_in_room[i]->query_short());
		    }
		}
		return 1;
    }
    return 0;
}
