//added check to see if the crypt keeper was there and toggle the trap off if he is not.  Circe 9/20/03
#include <std.h>
inherit VAULT;

#define SAVEROOM "/d/save/crypt18"
string *exp_grants;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  	set_name("The Crypt Keeper's Trap.");
    seteuid(getuid());
    exp_grants = ({});
    set_property("light", 0);
    set_property("indoors", 1);
    set_short("The Lair of the Crypt Keeper");
    set_long("%^BOLD%^%^BLACK%^You have finally made it to the %^RED%^Crypt Keeper!%^BOLD%^%^BLACK%^ The room that you now stand in is nothing more then a lair with %^RESET%^bones%^BOLD%^%^BLACK%^ of past adventurers scattered about the floor. Needless to say, this place is %^RESET%^%^CYAN%^unsettling%^BOLD%^%^BLACK%^, and if it wasn't for the fact that you need what the Crypt Keeper has to get out of here, YOU %^RED%^ABSOLUTELY%^BOLD%^%^BLACK%^ SHOULD NOT BE HERE!%^RESET%^\n");
    set_pre_exit_functions( ({"down"}),({"GoThroughDoor"}) );
    set_post_exit_functions( ({"down"}),({"exp_grant"}) );
    set_exits( ([
     "down" : "/d/koenig/town/crypt1",
     "up" : "/d/koenig/town/crypt17"
		 ]) );
  set_trap_functions(({"up"}),({"spearing_doorway"}),({"up"}));
}

void reset() {
  ::reset();
    if(!present("crypt keeper"))  {
	new("/d/koenig/town/mon/cryptkeeper.c")->move(this_object());
      }
}

int GoThroughDoor() {
  if(present("crypt keeper")) {
    write("%^BOLD%^%^RED%^The Crypt Keeper growls and blocks your passage!");
    return 0;
  }
  return 1;
}

int spearing_doorway() {
  	int spears, damage;
   if(present("crypt keeper")) {
      tell_object(TP,"%^BOLD%^%^RED%^As you try to escape the Crypt Keeper by returning "+
  		"the way you came...");
  	tell_object(TP,"%^BOLD%^%^RED%^He %^RESET%^%^RED%^cackles %^BOLD%^%^BLACK%^demonically%^BOLD%^%^RED%^ and reaches over "+
  		"and pulls a lever!");
  	tell_object(TP,"%^BOLD%^%^RED%^As you go to pass through the doorway, several %^RESET%^spears%^BOLD%^%^RED%^ appear...");
  	TP->force_me("emote gasps in agony!");
  	tell_room(ETP,"You see "+TPQCN+" attempting to escape the battle with the "+
  		"Crypt Keeper.", TP);
  	tell_room(ETP,"You see the Crypt Keeper reach over and pull a lever "+
  		"as "+TPQCN+" passes through the doorway to go back the way you all came...");
  	tell_room(ETP,"Suddenly spears shoot out along either side of the doorway "+
  		"impaling "+TPQCN+"!",TP);
  	tell_room(ETP,""+TPQCN+" gasps in agony and slowly unimpales themself and leaves.", TP);
  	tell_object(TP,"%^BOLD%^%^RED%^The Crypt Keeper cackles as you try to escape "+
  		"and are %^RESET%^%^RED%^impaled%^BOLD%^%^RED%^ on the spears!%^RESET%^");
  	spears = random(4)+1;
  	damage = random(15)+5;
  	TP->do_damage("torso",(damage*spears));
	TP->add_attacker(TO);
	TP->continue_attack();
     TP->remove_attacker(TO);
    if (!TP->query_ghost()) {
        return 0;
    } 
    else {
    tell_room(TO, TP->getParsableName()+" falls to the floor in a bloody heap as they expire from the treacherous trap.");
    return 1;
    }
  }
  else toggle_trap("up");
}

void exp_grant(){
//added so it won't be misleading about getting extra exp. each time *Styx* 8/2002
// added check for userp to try to avoid problems with snakes & critters *Styx* 12/11/02
    if(!userp(TP))  return;
    if(member_array("The crypt",TP->query_mini_quests()) != -1) {
      write("%^BOLD%^%^WHITE%^Lucky you to get out of here alive yet again.");
      return;
    }
    write("%^BOLD%^%^CYAN%^The gods look upon you with benevolence!");
    write("%^BOLD%^%^CYAN%^They grant you a reward for simply living through that adventure!!");
    tell_room(environment(TP),"%^BLUE%^ a faint blue haze surrounds "+TPQCN+" for a moment. Then it is gone.",TP);
    TP->set_mini_quest("The crypt",500000,"%^BOLD%^A treacherous passage through the Crypt keeper's domain");
    exp_grants += ({TPQCN});
}