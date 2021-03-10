// A track through the forest
// Thorn@ShadowGate
// 000829
// Alamut
// forest8.c

#include <std.h>

inherit ROOM;

void create() {
  	room::create();
    set_light(2);
    set_short("At the foot of Mount Alamut");
  	set_long(
@DAI
%^BOLD%^At the foot of Mount Alamut%^RESET%^
You are on a paved road at the foot of what you realize is a high
plateau.  Here you can see that the rock face now seems to curve
slightly to the west, indicating that you are now at its easternmost 
point.  The road you are on follows this curve closely, except for
a patch where it avoids a bit of a rock fall.  The cliff face is 
much less sheer here and you can see a number of little ledges and 
rough edges jutting out.  Above, you still see the omnipresent 
caves and ledges above you at great height.

The road continues to the northwest and the southwest.
DAI
    );
    set_exits(([
			"northwest" : "forest9",
			"southwest" : "forest7"
  	] ));
  	set_listen("default","You hear the wind moaning around the high rock wall.");
    set_climb_exits((["climb":({ "8level2",4,6,500})]));
    set_fall_desc(
@FALL
You fall down about 100 feet. You land on some rocks, and other
debris. Pain racks your body.
FALL
    );

 }

void reset(){
	::reset();
}
