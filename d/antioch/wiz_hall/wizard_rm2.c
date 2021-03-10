//  Created by Ignatius, for ShadowGate
//  Coded 13 02 95
//  Wizard Area - Public Board and access to Ignatius' office
//  As of 28 June 1995, access to Grolim's office, too

#include <std.h>
#include "/d/antioch/areadefs.h"
#include <config.h>
inherit "/std/vault";

string gro_last_knocker;
string query_gro_last_knocker();

void create() {
  object ob;
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no steal", 1);
  set_property("no fight", 1);
  set_short(
    "The Hall of Immortals - Antioch Outpost"
    );
  set_long(
@IGNATIUS

  The room you stand in is made of timber and stone.  Massive timbers hold 
tons of rock over your head, providing a cathedral like ceiling for this 
room.  The north and west walls are hewn from bare rock, and the east 
and south walls are crafted from a fine, dark wood.  The light in this 
chamber comes from large wooden chandeliers that hang high overhead.  They 
provide a soft, even glow to the room, and offer a comforting feeling to 
the room.
  A large oak door stands to the east, providing access to the office of 
the Bishop of Antioch, Ignatius.  If the door is locked, please feel free 
to knock.  If Ignatius is available, he will certainly come to answer your 
questions.
  Another door, this one made of pine, stands to the west.  Beyond, you are 
certain, lies the office of Grolim.  If you knock, he may answer.
  Up is a large staircase illuminated by a shimmering %^BLUE%^blue%^RESET%^ light.
IGNATIUS
);
  set_exits( ([
    "up": ANTIOCH+"wiz_hall/wizard_rm1",
    "west": ANTIOCH + "wiz_hall/gro_ofc",
    "east": ANTIOCH+"wiz_hall/ign_ofc"
  ]) );
  set_pre_exit_functions( ({"up"}), ({"go_up"}) );
  set_items ( ([
    "staircase":
      "A %^BLUE%^blue%^RESET%^ light illuminates the stairs leading up.",
    "walls":
      "The walls are made of stone and wood.  You feel as though you are "
      "in the Charu Mountain range.",
    ({"chandelier", "chandeliers"}):
      "These chandeliers provide light to the room."
  ]) );
  set_door("pine door", ANTIOCH + "wiz_hall/gro_ofc", "west",
           "grolimofficekey");
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({
      "board", "bulletin board"
      }) );
  ob->set_board_id("outer_antioch");
  ob->set_max_posts(30);
  ob->set_location(ANTIOCH+"wiz_hall/wizard_rm2");
  ob->set("short", "The Antioch Comment Board");
  ob->set("long",
          "This board is made for residents of Antioch, no matter how "
          "temporary, to post ideas and comments about the Realm.\n"
         );

}
void init(){
   ::init();
	add_action("knock","knock");
}

int go_up() {
  if(!wizardp(this_player())) {
  message("my_action",
          "You cannot penetrate the force of the blue light.\n",
          TP);
  message("other_action",
          Tn+" tries to go up the stairs, and is zapped by the force "
          "field.  Only wizards are allowed up.\n",
          environment(TP), TP);
    return 0;
  }
  message("my_action",
          "\n"
          "You penetrate the blue force field, and find that all manner "
          "of joy lies ahead.\nWelcome to Antioch, friend.\n",
          TP);
  message("other_action",
          "A booming voice fills the hall with a hollow sound.\n"+
          Tn+" has been assimilated.\nResistance is futile.\nWe are "
          "Antioch.  You will be made to serve us.\n",
          environment(TP), TP);
  return 1;
}

int knock(string str) {
 string doorname;
 if(!str) { notify_fail("Knock on <doorname> door.\n"); return 0;}
 if(sscanf(str,"on %s door",doorname) != 1){
  notify_fail("Knock on <doorname> door.\n");return 0;}
	
 switch(doorname){
      case "pine" :
  write("You knock of Grolim's pine door.");
  gro_last_knocker = Tn;
    if ( present ( "grolim", find_object ( ANTIOCH + "wiz_hall/ign_ofc" ))) {
    tell_object ( find_player ("grolim" ),
      Tn + "is knocking on your office door.\n");
      break;
               }
  write ( "He doesn't appear to be in..." );
  break;
        }
	return 1;
}
