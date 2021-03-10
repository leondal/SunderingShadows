#include <std.h>
inherit ROOM;

int is_virtual() { return 1; }

void create() {
 ::create();
set_indoors(0);
 set_light(2);
 set_short("%^GREEN%^Mystic jungle%^RESET%^");
 set_long(
@MELNMARN
%^BOLD%^%^GREEN%^Your within a strange mystical jungle. The plants and trees
here grow densly about you and are intertwined above you forming a 
tropical rooftop. The thickness of the jungle has formed narrow cavern
like trails twisting their way through the jungle. A glowing portal
is shimmering in the center of the trail's dead end.%^RESET%^
MELNMARN
 );
 set_exits(([
	"south":"/d/tharis/barrow/virtual/level1/2,1.level1",
	"portal":"/d/tharis/barrow/rooms/chamber1.c"
]));
set_smell("default","You smell jungle odors of unknown types.");
set_listen("default","You hear an uncanny silence. There seems to be no life "
	"here.");
set_search("default",(: TO,"search_it" :) );
}
void search_it(string str){
if(str == "default")
write(
@DEFAULT
Searching around the jungle casually, you see the
plants, vines and trees the jungle. Nothing 
really jumps out and catches your eye. 
DEFAULT
);
}
