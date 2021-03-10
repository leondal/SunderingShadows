// Multi board room for planning changes for character classes.

#include <std.h>

inherit ROOM;

object myboard;
string whichboard;



int switch_board(string str) {
  string temp;
  if (!objectp(myboard))
    myboard = present("bulletin board");
  if (!objectp(myboard))
    myboard=new("/std/bboard");

  myboard->set_name("board");
  str=lower_case(str);
  switch (str) {
  case "thief":
  case "bard":
  case "assassin":
  case "mage":
    temp = "plan_"+str+"";
    myboard->set_id( ({ "board", "bulletin board", temp }) );
    myboard->force_reset_board_id(temp);
    temp = "The "+capitalize(str)+" Classes Planning board";
    myboard->set_short(temp);
    temp = "A board for ideas and discussions about "+str+" class issues.";
    myboard->set_long(temp);
    whichboard = str;
    break;
  default:
    myboard->set_id( ({ "board", "bulletin board", "plan_general" }) );
    myboard->force_reset_board_id("plan_general");
    myboard->set("short", "The General Classes Planning board");
    myboard->set("long", "A board for ideas and discussions about general class issues..");
    whichboard="general";
    break;
  }
  myboard->set_max_posts(20);
  myboard->set_location("/d/dagger/planroom.c");
  return 1;
}

void create(){
  ::create();
  set_properties((["light":2,"indoors":1,"no attack":1]));
  set_property("no teleport",1);
  set_short("Immortal Planning Room.");
  set_long(
@GARRETT
%^BOLD%^%^BLUE%^You find yourself floating high in the sky, with the world miles below you.  The azure blue sky is bright and cheerful, just like a perfect summer day.  %^WHITE%^Fluffy white clouds%^BLUE%^ move with the gentle breeze that billows through.  Off in the distance there %^BLACK%^storm clouds%^BLUE%^ gather.  Flashes of %^CYAN%^lightning%^BLUE%^ can be seen in the %^BLACK%^storm gray clouds%^BLUE%^.  A wooden board hangs in air, with a bright %^RED%^red%^BLUE%^ switch on it.
GARRETT
);
  set_items(([
//	      ({"flip","switch"}) : "This switch, Garrett hopes, you will be able to 'flip' to a different class's board."
  ]));
  set_exits(([
        "out":"/d/dagger/avalounge",
	"north":"/d/dagger/avalounge",
        "guildhall" : "/d/dagger/gboard",
        "aketon" : "/d/dagger/aketon/path/path11",
        "nwps":"/realms/mercutio/rooms/boardroom",
  ]));

  set_smell("default","You smell grease of well-oiled machinery.");
  set_listen("default","The clicking of gears and the counting of punched
cards echoes in the distance.");
  myboard= new("std/bboard");
  myboard->set_name("board");
//  switch_board("general");
}

void reset(){
  object ob;
  ::reset();
 if (!objectp(present("new avatar board"))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "new avatar board" }) );
    ob->set_board_id("sg_3_0_board");
    ob->set("short", "Shadowgate 3.0 event board");
    ob->set("long", "A large board where the avatars of the realm may post.");
    ob->set_max_posts(100);
    ob->set_location("/d/dagger/planroom");
//added by Styx 6/02 just in case a mortal ends up in the room
    ob->set_restricted_read();
    ob->set_ooc_board(1);
  }
}

void init() {
  ::init();

  if (avatarp(TP)) {
    add_action("flip","flip");
    add_action("flip","switch");
  }
  if (!avatarp(TP)) add_action("nono","",1);
}
int nono(string str) {
  if (member_array(query_verb(),({"switch","read","edit","post"})) == -1)
    return 0;
  write("I'm sorry, Dave, I can't let you do that.");
  return 1;
}


int flip(string str) {
  if (stringp(str) &&
     (member_array(str,({"general","thief","bard","assassin","mage"})) != -1)){
    switch_board(str);
    message("my_environment",TPQCN+" changes the board to the "+whichboard+" to read that one.", ETP ,  TP );
    message("my_action", "You change the board to the "+whichboard+", and notice the board looks like "+myboard->query_short()+".",TP);
    return 1;
  } else {
    switch (whichboard) {
    case "general":
      switch_board("assassin");
      break;
    case "assassin":
      switch_board("bard");
      break;
    case "bard":
      switch_board("mage");
      break;
    case "mage":
      switch_board("thief");
      break;
    case "thief":
    default:
      switch_board("general");
      break;
    }
    message("my_action", "You change the board to the "+whichboard+", and notice the board looks like  "+myboard->query_short()+".\n",({TP}));
    message("my_environment",TPQCN+" changes the board to the "+whichboard+" to read that one.",({ ETP }), ({ TP }));
    return 1;
  }    
}

string query_long(string temp) {
  string holder;
  object tempboard;
  int iter;
//  string * idlist = ({ "plan_general", "plan_assassin", "plan_bard", "plan_mage", "plan_thief" }) ;
#define IDLIST ({ "plan_general", "plan_assassin", "plan_bard", "plan_mage", "plan_thief" })
#define BOARDS ({ "general", "assassin", "bard", "mage", "thief" })

  holder = ::query_long(temp);
  return holder;
  /*tempboard->new("/std/bboard.c");
  for (iter = 0; iter < sizeof(IDLIST) ; iter ++) {
  tempboard->reset_board_id(IDLIST[iter]);
  tempboard->set_short(BOARDS[iter]+": ");
  holder += tempboard->display_new(BOARDS[iter]);
  }
  tempboard->remove();
  return holder;*/
}
