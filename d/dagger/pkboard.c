// made this board used for posting (only) by mortals via avatarmail command
// *Styx* 6/2002

#include <std.h>
inherit ROOM;

void place_board()
{
   object obj;
   int max;
   if(!present("pkmail board")) 
   {
	obj = new("std/bboard");
	obj->set_name("pkmail board");
	obj->set_id(({"board", "bulletin board","pkmail board"}));
	obj->set_board_id("pk_board");
	max = 200;
        obj->set_max_posts(max);
	obj->set_short("The PK Mail Discussion Board");
        obj->set_long("A large board for the pkmail players submit.  "
           "It is meant to facilitate the immortal discussions of possible "
           "additional consequences to either attacker or victim and esp. "
	   "review of effect on plots.  %^YELLOW%^Max posts are "
	   +max+"%^RESET%^ so please convert them to notes "
	   "on the players in a timely fashion and then delete and/or combine "
	   "them once they are handled.");
	obj->set_location("/d/dagger/pkboard.c");
        obj->set_ooc_board(1);
       	obj->set_restricted_read();
       	set_long("Wanted posters abound in here and you can almost hear the screams "
	 "of the victims.  Thankfully they usually drown out the player whining or "
	 "at least the entertainment factor of the accounts helps you ignore it.\n"  
	 "Please note that the max posts for the board are:  "
	 "%^YELLOW%^"+max+"%^RESET%^.  Please review this "
	 "description periodically as the number may change."
       	);
   }
    
}
void create() 
{
	::create();
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",2);
	set_short("PK Mail Board Room");
//	set_long("The description should load in reset so it can get the max posts count.");
	set_smell("default","You can almost smell fresh blood and singed bodies.");
	set_listen("default","You imagine hearing the clash of weapons and blasts of spells.");
	set_exits(([
	"west" : "/d/dagger/avaboard2",
	]));
    //place_board();
}

void reset() 
{
    ::reset();
    place_board();
}   