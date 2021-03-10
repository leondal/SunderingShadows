#include <std.h>
#include "../argabbr.h"
inherit WATER;


void create(){
    ::create();
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);
    set_short("Sinking into the sea");
    set_name("sea by argentrock");
    set_long("You are sinking deeper into the dark sea" );
    set_property("indoors",1);
    set_property("light",-2);
	set_property("no magic",1);
    set_smell("default","You can't smell anything with all this water in your nose!");
    set_listen("default","You can hear yourself gurgle as you try to scream while you slowly suffocate!");
}
void init(){
    ::init();
    call_out("suffocate",5,TP);
}

void suffocate(object victim){
    string *room, *rooms, *path;
    if(!present(victim, TO)) return 1;
	// escape is dependant on encum vs atheletics
    if(random(victim->query_internal_encumbrance()) < 
	             victim->query_skill("athletics")+10){
        rooms = get_dir(SHO+"*.c");
        room = rooms[random(sizeof(rooms))];
        path = SHO+room;
		if(path == "island") path = "island1"; //evil to set them back into battle
        tell_object(victim,"%^BLUE%^As you"+
		" struggle deep in the sea you manage to "+
		"grab hold of a rock and pull yourself to shore!");
        victim->move(path);
        victim->describe_current_room(1);
		victim->use_stamina(100);
        return 1;
    }

    tell_object(victim,"%^BOLD%^%^BLUE%^Eels swarm around "+
	"you biting at open flesh while possessions' weight combined with the"+
	" undertow drags you further to a watery doom.\n"+
	"%^RESET%^You struggle in futility for the surface, too encumbered to swim properly.");
	victim->cause_typed_damage(victim,0,roll_dice(1,6)+10,"piercing");
	broadcast_area("/d/islands/argentrock/shore", "%^BLUE%^Bubbles come to the "+
	"surface of the sea as someone is in the process of drowning.");
    call_out("suffocate",5,victim);
    return 1;
}
