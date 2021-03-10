//  /d/dragon/town/coder.c
//d/dragon/town/coder.c

#include <std.h>
#include <objects.h>

object ob;
  inherit ROOM;

  string *allow;
     
void create() {
    ::create();
    set_light(2);
set_indoors(1);
  
allow=({"hern","grayhawk","amazon","atmos","diana","tristan","sin","thorn","melnmarn","arius","crystal","styx","garrett","grendel","dinji"});
  set_short("A private coding room");
  set_property("no teleport",1);
    set_long(
@HERN
  This room was designed for the coding staff of Dragon and only them.
There are many tools around the room, including artifacts from days
past.  One that catches your eye is a DragonLance as a reminder of
our purpose here.  A large marble table sits in the middle of the room.
HERN
    );
    set_exits(([
  "up" : "/d/dragon/town/square"
    ] ));
set_items( ([ "table" : "This is an unbreakable table made of marble.  Around it are seats.  One has your name on it.",
"dragonlance" : "This is a footsmans lance, about 8' long these lances were used in the great war.  Twenty are belived to remain.  This is one." ]));
  ob = new("/std/bboard");
  ob->set_name("board");
  ob->set_id(({"board","comment board","sanctuary board"}));
  ob->set_board_id("sanctuary");
  ob->set_max_posts(30);
  ob->set_edit_ok(({"grayhawk","hern"}));
  ob->set_location("/d/dragon/town/coder");
  ob->set_short("%^BOLD%^%^GREEN%^Sanctuary's Comment Board");
  ob->set_long("Wizards and coders post their comments and ideas concerning\n"+
               "the realm of Dragon.  Yo can post suggestions, or any ideas\n"+
               "about the realm of Dragon.\n");
}
	void init()
{
	      ::init();
  if(interactive(TP) && member_array(TPQN,allow)==-1)
     {
   TP->move("/d/dragon/town/square");
  tell_object(TP,"This room is for the Dragon coding staff, please do not disturb.  \n");
     }else{
  tell_room(environment(TP),TPQCN +" enters the confrence room.",TP);
              }

}
