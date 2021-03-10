#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_name("foyer of an ancient chapel");
    set_short("%^BOLD%^%^WHITE%^Foyer of An Ancient Chapel%^RESET%^");
    set_long("%^RED%^You find yourself inside the foyer of this massive %^RESET%^ancient"+
    " chapel%^RED%^.  The walls, floor, and ceiling of the building are made from a %^BOLD%^"+
    "%^BLACK%^black stone%^RESET%^%^RED%^ and have been kept in remarkable condition, so much "+
    "so that they actually seem to %^RESET%^sparkle%^RED%^.  An out of place dilapidated "+
    "%^MAGENTA%^wooden door%^RESET%^%^RED%^ has been inset into the center of the southern "+
    "wall, in a feeble attempt to block access to the graveyard beyond, two %^CYAN%^stained "+
    "glass windows%^RESET%^%^RED%^ have been set into the wall on either side of it.  There "+
    "is an %^BLUE%^open doorway%^RED%^ on both the eastern and western walls of this room, "+
    "each leading into a smaller room.  A %^BOLD%^%^BLACK%^metal door%^RESET%^%^RED%^ has "+
    "been inset into the northern wall, effectively blocking access to the room to the "+
    "north.%^RESET%^\n");
					
    set_exits(([
    "out" : GY_ROOMS+"grave2-3",
    "north" : GY_ROOMS+"chapel4",
    "east" : GY_ROOMS+"chapel2",
    "west" : GY_ROOMS+"chapel3"
    ]));
    set_door("wooden door",GY_ROOMS +"grave2-3","out");
    set_string("wooden door", "open", "%^RED%^The wooden door swings open silently.%^RESET%^");
    set_door_description("wooden door","%^MAGENTA%^This dilapidated wooden door stands barely "+
    "in place, futilely attempting to block access to the ancient chapel.  It has no obvious "+
    "lock and opens by means of a makeshift handle on the right side of it.%^RESET%^");		

    set_door("metal door",GY_ROOMS+"chapel4","north","ancient chapel key","lock");
    set_locked("metal door",1,"lock");
    set_lock_description("metal door","lock","%^BOLD%^%^BLACK%^The keyhole of this lock "+
    "is cylindrical in shape.  It awaits a small cylinder rather "+
    "than a key.%^RESET%^");
    set_door_description("metal door","%^BOLD%^%^BLACK%^This metal door is inset directly "+
    "into the center of the northern wall.  It has a lone knob on the left side with a "+
    "cylindrical keyhole in the center of it.  Its made from a simple metal that has been blackened."+
    "%^RESET%^");	
    lock_difficulty("metal door",-5,"lock");

    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","A loud chanting seems to echo from the very walls.");
 
    set_items(([
    ({"chapel","ancient chapel"}) : "%^BOLD%^%^WHITE%^This chapel is made entirely out of a "+
    "%^BOLD%^%^BLACK%^black stone%^BOLD%^%^WHITE%^.  The chanting that seems to be echoing "+
    "from the very walls suggests that it may not be so ancient afterall.  It is probably "+
	"even inhabited right now.%^RESET%^",
    ({"windows","stained glass","glass windows","stained glass windows"}) : "%^CYAN%^These "+
    "windows are made from a stained glass and are set into the southern wall, on either side "+
    "of the wooden door.  You could easily peer through them to see what's outside.%^RESET%^",
    ({"stone","black stone"}) : "%^BOLD%^%^BLACK%^The foyer is made entirely out of this "+
    "strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
    ({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
    "it is constantly cleaned and suprisingly it has been kept in remarkably good "+
    "condition.%^RESET%^",
    ({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
    "been kept in remarkably good condition.%^RESET%^",
    ({"walls","wall"}) : "%^BOLD%^%^BLACK%^The walls of this foyer are made from a black stone "+
    "and have been kept in remarkably good condition.  A wooden door is inset into the southern "+
    "one, open doorways are centerened in the eastern and western walls, and a metal door "+
    "has been inset into the northern wall.%^RESET%^",
    ({"doorway","open doorway"}) : "%^BLUE%^One of these adorn the eastern and another the "+
    "western walls of this foyer.  They each lead into a smaller room.%^RESET%^",
    "sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this foyer seems "+
    "to continually sparkle and glisten, even in pitch black.",			
    ]));
}

void init() {
    ::init();
    add_action("peer_action","peer");
}

void reset() {
    int x;
    ::reset();
    if(!present("antipaladin")) {
        for(x = 0;x < random(2) + 1;x++) {
            if(random(4) >= 2) {
                new("/d/deku/monster/antipaladin")->move(TO);
            }
        }
    }
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
            tell_room(TO,TPQCN+"%^MAGENTA%^ walks up to one of the "+
            "windows and seems to peer through it.%^RESET%^",TP);
        }
        tell_object(TP,"%^MAGENTA%^You walk up to one of the "+
        "windows and peer through it.%^RESET%^");
        tell_object(TP,"%^BOLD%^%^WHITE%^Shadowlord Graveyard%^RESET%^");
        
        objects_in_room = all_inventory(find_object_or_load(GY_ROOMS+"grave2-3"));
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
