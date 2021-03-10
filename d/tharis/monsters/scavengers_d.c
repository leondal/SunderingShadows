//scavenger_d.c

#include <std.h>
#define BASE "/d/tharis/forest/"
#define ROOMS ({"good4","evil4","forest71","forest77","forest117","forest120","forest127","forest134","forest102","forest135"})
#define SIZE 10
#define SCAVENGER "/d/tharis/monsters/scavenger"

inherit DAEMON;

object *scavengers;

void clean_up() { return 0;}

void create(){
	::create();
// disabling them for a few days to see if bugs go away
// *Styx*  5/15/02
    scavengers = allocate(SIZE);
    call_out("placeem",20);
}

void placeem(){
	object ob;
	int i;
	
		
	for(i = 0;i < SIZE;i++){
		if(!find_object(BASE+ROOMS[i]))
			continue;
		if(!objectp(scavengers[i])){
			ob = new(SCAVENGER);
			ob->move(BASE+ROOMS[i]);
			scavengers[i] = ob;
		}
	}
	call_out("placeem",20);
}
	
