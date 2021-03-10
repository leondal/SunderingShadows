// Main Staircase -- Second Floor, Azha Keep
// Thorn@ShadowGate
// 12/19/95
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);    
	set_short("Main Staircase, Second Floor");
  set_long(
@AZHA
%^BOLD%^Second Floor Landing%^RESET%^
	You are looking at a stone staircase that appears to lead to the
first and third floors of the keep.  The walls are decorated with
scarlet hangings and tastefully scattered statues of ancient heroes. 
The stairs to the third level have two sets of stairs that come
together at the third floor landing.  These stairs are ornately
carved with images from Tsarvani history and mythology.  There
appears to be a passageway to the east.
AZHA
    );
	set_exits(([
	"up" : "/d/azha/fort/stair3",     
	"down" : "/d/azha/fort/stair1",     
	"east" : "/d/azha/fort/hall4",     
  ] ));     
	set_smell("default","A strong fragrance seems to be coming from upstairs.");
	set_items(([
		"hangings" : "These are silk wall hangings dyed scarlet, the color of Tsarven.",
		"statues" : "These statues seem almost lifelike and are armed in various fashions.",
		] ));
}
