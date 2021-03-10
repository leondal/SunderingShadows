#include <std.h>

inherit ROOM;

int locked,open;

int is_virtual() { return 1; }


void create() {
 ::create();
set_indoors(0);
 set_light(2);
 set_short("%^GREEN%^Mystic jungle");
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
	"north":"/d/tharis/barrow/virtual/level1/1,1.level1",
	"east":"/d/tharis/barrow/virtual/level1/1,0.level1"

]));
set_smell("default","You smell jungle air.");
set_listen("default","You hear a dead silence.");
}
