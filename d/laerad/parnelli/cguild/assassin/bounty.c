//shadows bounty.c

#include <std.h>

inherit "/std/bounty";

void create(){
	object ob;
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
	set_properties((["indoors":1,"light":2]));
//    set_property("no teleport", 1);  removing safe haven from guild halls *Styx*  4/6/03
	set_name("bounty office");
	
     set_short("A bounty office.");
	set("long",
@OLI
      %^BOLD%^%^YELLOW%^A duplicate of the Shadow Bounty Office
This fine room is paneled in oak and carries a dark atmosphere. Here
is where what law and good decides is attempted to be carried out. 
The legal and proper image is tainted a little by the knowledge that
here also the vindictive and weak and cowardly come to ask others to
deal with their problems. There is a sign on the wall beside a small.
grated window. Behind that window sits a small man on a stool waiting 
to take any money and complaints you may have. Taking all of the eastern
wall is the board with bounties posted.
OLI
	);
	set_exits(([
            "east":"/d/laerad/parnelli/cguild/assassin/aguild1"
		]));
	set_items(([
		"sign":"You really should read it for instructions",
		"board":"This will need to be read to get the list of bounties.",
		"list":"This will need to be read to get the list of bounties."
		]));
	
	set_smell("default","The smell of finished oak and a tint of leather linger in this room.");
	set_listen("default","You can hear so mutterings and such.");	
	ob = new(BBOARD);
	ob->set_name("board");
	ob->set_id(({"bounty board"}));
	ob->set_board_id("bounty");
	ob->set_max_posts(50);
     ob->set_location(base_name(TO));
   ob->set_short("The Shadow Bounty Board");
	ob->set_long("Please place any reasons, pleas or arguments here in addition to comments.");
}
