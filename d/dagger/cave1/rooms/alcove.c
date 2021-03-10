#include <std.h>
inherit ROOM;
void init() {
    ::init();
    add_action("gem_func","insert");
}
void create (){
::create ();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
set_property ("light", 1);
set_property("indoors", 1);
set_property("no teleport",1);
set_short("caves");
set_long("This is a small cramped alcove south of the fur room,
There's a small statue of a spider here.");

set_smell("default", "The sharp odor of oil and furs tickles your your nose.");
set_listen("default", "You hear voices in the distance.");
set_items(([
"statue" : "It's an ugly spider statue with a missing red ruby eye.",
]));
set_exits( ([
"north" : "/d/dagger/cave1/rooms/entrance",
]) );
}
int gem_func(string str) {
    if(!str) {
	notify_fail("Insert what?");
	return 0;
    }
if(str != "gem") {
	notify_fail("Insert what?\n");
 	return 0;
    }
    if(!present("drow_gem",TP)) {
	notify_fail("insert what?\n");
	return 0;
    }
    write("%^RED%^Before you finish inserting the gem, you "
	"vanish in a flash of light!%^RESET%^");
    say("%^RED%^"+TPQCN+" vanishes in a flash of light!%^RESET%^"
    ,TP);
    TP->move_player("/d/dagger/cave1/rooms/room13.c");
    return 1;
}
