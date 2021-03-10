#include "chaos.h"

inherit VAULT;
int search;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A strange room");
    set_long( 
@MELNMARN
%^BOLD%^You are in a very strange room.%^RESET%^
Looking around the room, you see some strange devices.
In the center of the room, you see a painting on the floor.
It is a painting of a sun.
MELNMARN
    );
    set_exits( ([
	"south" : CHAOSDIR+"floor3"
        ]) );
    set_door("north door",CHAOSDIR+"floor3","south",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");
    set_search("default","You find a loose stone in the center of the painted sun.");
    set_search("stone",(:TO,"search_fun":));
    search = 0;
}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
    add_action("push_it","push");
}

void search_fun(string str){
	if(!str) return;
	write("You notice the stone moves easily. Makes you wonder what would happen if you pushed on it.");
	add_action("push_it","push");
	search = 1;
}
int push_it(string str){
	if(!str) return notify_fail("Push what?\n");
	if(str != "stone") return notify_fail("You can not push the "+str+"!\n");
	write("You push on the stone, and feel the floor under you move.");
	write("You notice the painted sun's surface has risen six inches above the floor.");
	remove_action("push_it","push");
	return 1;
}
