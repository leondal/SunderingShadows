//mirror of shadows bounty.  Coppied and changed a bit to make useful in Juran.

#include <std.h>
#include "../juran.h"

inherit "/std/bounty";

void create(){
	object ob;
	::create();
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
	set_properties((["indoors":1,"light":-2]));
	set_name("bounty office");
	
	set_short("The Juran Bounty office");
	set_long(
@DIEGO
	%^BOLD%^%^YELLOW%^The Juran Bounty office%^RESET%^
This fine room is paneled in old oak and carries a dark atmosphere. Here
is where people who cannot take care of things themselves come for help. 
The legal and proper image is tainted a little by the knowledge that
here also the vindictive and weak and cowardly come to ask others to
deal with their problems. There is a sign on the wall beside a small,
grated window. Behind that window sits a small goblin on a stool waiting 
to take any money and complaints you may have. Taking all of the western
wall is the board with bounties posted.  There is a curtain in the north 
wall leading back into the inn.
DIEGO
	);
	set_exits(([
		"curtain":JROOMS+"inn"
	]));
	set_items(([
		"sign":"You really should read it for instructions",
		"board":"This will need to be read to get the list of bounties.",
		"list":"This will need to be read to get the list of bounties."
	]));
	
	set_smell("default","The smell of finished oak and a tint of leather "+
		"linger in this room.");
        set_listen("default","You can hear so mutterings and such.");
}
