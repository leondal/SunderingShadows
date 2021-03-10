#include <std.h>

inherit "/std/quest_room.c";

void create(){
	::create();
	
   set_short("Camp of the great trainer");
	set_long(
@OLI
	%^BOLD%^%^GREEN%^The training camp of the masters%^RESET%^
This is the camp of one of the great specialists in the realms. The 
maker of this camp can train anyone to do anything. The tent is lit 
by a dancing fire in the middle. The area is littered with small 
items of various specialties.
OLI
	);
	set_smell("default","The smell of cooking mixes with oils and tars.");
	set_listen("default","The fire crackles and the area dances.");
	set_property("Specialist",1);
    set_property("no teleport",1);
	set_property("indoors",1);
	set_property("training",1);
	set_light(2);
}

string query_long(string str){
	string hold;
	
	hold = :: query_long(str);
	if(stringp(player))
            hold += "%^BOLD%^The trainer waits for "+capitalize(player)+".";
	return hold;
}
