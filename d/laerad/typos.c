//Coded by Styx@Shadowgate for new bug reports board//
#include <std.h>
inherit ROOM;

void place_board()
{
    object ob;

    if (!objectp(present("typoboard"))) 
    {
     ob = new("std/bboard");
     ob->set_name("typoboard");
     ob->set_id( ({ "board", "typo reports board", "typoboard" }) );
     ob->set_board_id("typoboard");
     ob->set("short", "Typo Reports Board");
     ob->set("long", "A large board where mails about typos go for the "
           "wizzes to know where to look in the quest to eradicate them.\n");
     ob->set_max_posts(100);
     ob->set_ooc_board(1);
//this should restrict mortals from reading, viewing the index, or seeing how 
//many posts are unread (hopefully it will also prevent removing or editing)
//actually, the command itself also precludes any but avatars or wizzes reading
     ob->set_restricted_read();
     ob->set_location("/d/laerad/typos");
     ob->set_property("no steal",1);
     ob->move(TO);
  }
}

void create(){
    ::create();
    set_short("Typo Reports Room");
    set_long("%^BOLD%^YELLOW%^Typo Reports Room%^RESET%^\n"
      "This room houses the board mortals send their reports of typos to "
      "be corrected.  Please delete ones that were mistakes or you handled."
    );
    set_property("indoors",1);
    set_property("light",3);
    set_smell("default","A wonderful fragrance fills the room.");
    set_listen("default","Hopefully you find the room empty and quiet.");
    set_exits( ([
	"east":"/d/laerad/wizlounge",
    ]) );
   // place_board();
}

void reset() 
{
    ::reset();
    place_board();
}  

void init(){
    ::init();
    if(!wizardp(TP) && interactive(TP)){
	write("You aren't allowed in there mortal.");
	TP->move("/d/shadowgate/adv_main");
	return 1;
    }
}
