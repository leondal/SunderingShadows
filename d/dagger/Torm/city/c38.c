#include <std.h>
// #include "../tormdefs.h"

#define GHOUSE "/d/player_houses/girruuth/"
#define TCITY "/d/dagger/Torm/city/"

// inherit BAR;  converting to Girruuth's armor & weapons repair shop *Styx* 12/02

inherit VAULT;

int set;

void create()   {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("GiGi's entrance");
  set_short("GiGi's entrance");
  set_long( (: TO, "ldesc" :)  );
  set_smell("default", "The scent of recently burned incense helps mask the stable smells from the west.");
  set_listen("default", "Sounds from outside and adjoining rooms echo off the floor and walls.");
  set_search("default", "The large sign over the shop door catches your eye.");
  set_search("large sign", "Looking carefully, you can see the darkened but sharp edge of an axe head behind it.  However, you can't see any way to get to it.");
  set_exits(([
        "north": GHOUSE+"shop",
	"south":TCITY+"c37",
	"west" : TCITY+"c26",
  ]));
  set_door("shop door", GHOUSE+"shop", "north", "gir_key");
//  set_locked("shop door",1,"lock");
  lock_difficulty("shop door",-50, "lock");
  set_trap_functions(({"shop door"}),({"axe_me"}),({"pick"}));
  set = 1;
//  set_open("shop door", 0);  handled in reset
  "/d/player_houses/girruuth/shop"->set_open("door", 0);
  set_door("stable door", TCITY+"c26", "west", "gir_key");
  set_open("stable door", 0);
  set_door("door",TCITY+"c37","south");
// set_open("door", 0);  this is set by the other side
  set_items( ([
	({"wall", "walls"}): "The shop walls are made of stone and wood and look quite sturdy.",
	({"cobblestones", "stones", "floor"}): "Upon closer inspection, the %^BOLD%^%^GREEN%^emerald colored stones %^RESET%^appear to form letters and symbols.",
	({"symbols", "letters"}): "The emerald colored stones form the letters %^BOLD%^%^GREEN%^Gigi's %^RESET%^.  The symbols are on either side of the letters and are of an %^BOLD%^%^GREEN%^axe and shield%^RESET%^.",
	"sign" : "There is a large sign and a small sign, which are you looking at?",
        "large sign" : "This sign hangs over the doorway to the north.  It proclaims the place as %^BOLD%^%^GREEN%^Gigi's %^RESET%^.  It also has a very nicely crafted carving of an %^BOLD%^axe in front of a shield %^RESET%^at slight angle to the right.",
	"small sign": "It hangs over the door to the west and has a %^BOLD%^%^BLACK%^carving of a magnificent black stallion %^RESET%^with the word '%^ORANGE%^Stables%^RESET%^' artfully burned into the wood below it.",
	({"benches", "padded benches", "bench"}): "Each bench is over seven ft. long and padded with thick, %^BLUE%^dark blue cushions %^RESET%^that invite visitors to sit while waiting.",
   ]) );
}

void reset() {
   ::reset(); 
   if(query_night() == 1) {
      set_open("shop door",0);
// added a clerk so it can make sense to leave open 24/7 *Styx*  3/24/03
//      set_locked("shop door",1, "lock");
      "/d/player_houses/girruuth/shop"->set_open("shop door", 0);
/* probably best to leave evidence of a break-in until reboot, not using this atm
      if(!random(3) && !trapped("shop door"))  {
	toggle_trap("shop door");
      	set = 1;
      }
*/
   }
   else {
      set_open("shop door",0);
      set_locked("shop door",0);
      "/d/player_houses/girruuth/shop"->set_open("shop door",0);
   }
}

void init() {
   ::init();
   add_action("sit_bench", "sit");
   add_action("arm_trap", "arm");
}

int sit_bench(string str) {
   if(!str) {
     tell_object(TP,"The benches look like the most comfortable place to sit here.");
     tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     return 1;
   }
   if(str == "bench" || str == "benches") {
      tell_object(TP,"You sit on the bench and find the cushions quite comfortable.");
      tell_room(ETP,""+TPQCN+" takes a seat on one of the benches.",TP);
      return 1;
   }
   return 0;
}

int axe_me(string str) {
   if(interactive(TP)) {
	toggle_trap("lock");
	tell_object(TP,"%^YELLOW%^As you attempt to pick the lock you hear an "
	   "ominous click and then the sound of something sliding above the door!");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" bends down to the lock and then "
	   "gasps as a click sounds from it.  Immediately you hear something "
	   "sliding above the door!",TP);
	TP->force_me("emote gulps!");
//     	TP->set_paralyzed(50,"You are too busy dodging logs!");
	if((int)TP->query_stats("dexterity") > random(25)) {
	   tell_object(TP,"%^BOLD%^%^CYAN%^You scramble to get away from the "
		"door but the huge axe head still catches your arm.");
	   tell_room(ETP,"%^RED%^A huge double bladed axe head swings down "
		"from behind the sign over the door and grazes "+TPQCN+" as "
		+TP->query_subjective()+" scrambles frantically away from "
		"the door!\n",TP);
	  TP->do_damage("torso",roll_dice(4,10));
	}else{
 	   tell_room(ETP,"%^RED%^A huge double bladed axe head swings down "
		"from behind the sign over the door.  It swings back and "
		"forth, cutting "+TPQCN+" deeply across "
		+TP->query_possessive()+" arm, chest, and neck as "
		+TP->query_subjective()+" fails to scramble clear!\n",TP);
	tell_object(TP,"%^BOLD%^%^RED%^A huge double bladed axe head swings "
		"down from behind the sign.  It slashes you deeply across "
		"the chest, arm, and neck as it swings back and forth "
		"before you can roll out of the way!");
	TP->do_damage("torso",roll_dice(6,10));
	TP->do_damage("torso",roll_dice(4,10));
	TP->do_damage("torso",roll_dice(8,8));
	}
	TP->add_attacker(TO);
	TP->continue_attack();
	TP->remove_attacker(TO);
       	set = 0;
	add_item("axe head", "%^BOLD%^%^RED%^A huge, double bladed, bloodied "
		 "axe head that dangles from behind the sign above the door.");
       	return 1;
   }
}

void arm_trap(string str) {
   if(str != "trap") return;
//   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   tell_object(TP,"You carefully re-position the axe behind the large sign.");
   tell_room(ETP,TPQCN+" carefully re-positions an axe head behind the large "
	"sign over the shop door.", TP);
   TP->set_paralyzed(10,"You are too busy re-setting the trap!");
   if(!random(50)) {
	tell_object(TP,"%^BOLD%^%^RED%^Something goes awry and the axe head "
	   "falls onto your arm!");
	tell_room(ETP,"%^RED%^Something seems to go awry and the axe head "
	   "falls on "+TPQCN+"'s arm.",TP);
	TP->do_damage("torso",roll_dice(3,10));
	TP->add_attacker(TO);
	TP->continue_attack();
  	TP->remove_attacker(TO);
	return;
   }
   if(!trapped("shop door"))  toggle_trap("shop door", "pick", "lock");
   set = 1;
   remove_item("axe head");
   return;
}

string ldesc() {
   if(!set) {
      return("This is the entrance to a shop that seems to cater to numerous "
"needs.  A %^GREEN%^large sign %^RESET%^hangs over the main door to the north "
"and a %^BOLD%^%^RED%^huge, double bladed, bloody axe head%^RESET%^ dangles "
"from it.  Something has obviously not gone well for someone here recently.  "
"A %^ORANGE%^small sign %^RESET%^hangs over the door to the stables to the west."
"  The floor here is made of carefully placed %^BOLD%^cobblestones%^RESET%^.  "
"The stones are several different colors and have been carefully placed and "
"smoothed over.  A few %^BOLD%^%^BLUE%^nicely padded benches %^RESET%^sit "
"along the walls for those who might gather or wait here.\n");
   } else {
      return("This is the entrance to a shop that seems to cater to numerous "
"needs.  A %^GREEN%^large sign %^RESET%^hangs over the main door to the north.  "
"A %^ORANGE%^small sign %^RESET%^hangs over the door to the stables to the west."
"  The floor here is made of carefully placed %^BOLD%^cobblestones%^RESET%^.  "
"The stones are several different colors and have been carefully placed and "
"smoothed over.  A few %^BOLD%^%^BLUE%^nicely padded benches %^RESET%^sit "
"along the walls for those who might gather or wait here.\n");
   }
}

/* was this before the change

  set_long("What remains of the Sailor's Pit bar is clearly being remodeled.  "
	"The splintered tables and other furnishings have been piled into a corner.  "
	"The grimy wooden plank floors are even worse from the dust of the new stonework "
	"filtering in through the opening cut into the western wall.  The walls "
	"look a little cleaner in spots behind where the old tapestries used to "
	"hang, but overall it looks like there is still much work to be done."
  );
  set_short("The sailor's pit");
  set_door("door",TCITY+"c37","south","masterkey");
  set_long(
    "  You can't say this is the cleanest eating place you've ever been in but it certainly does look like the people here don't care who they feed as long as gold is involed before hand."
    "  The battered tables are complimented by splintery chairs that look like they've seen better days."
   "  The floor is rather dirty and the walls are covered in rather tacky paintings in a desperate attempt to make the establishment look a bit more respectable."
  );
   set_items(([
   "tables" : "The tables are very battered and scratched, survivors of the bar fights that you imagine must take place in here given the diverse crowd. There are a couple of empty ones, although they have yet to be cleaned off.",
   "chairs" : "The chairs are battered as well and some look as though they are ready to collapse at any moment.",
   "floor" : "The floor is covered in dirt and grime, and every now and then a bit of blood that hasn't been cleaned up from the latest brawl.",
   ({"wall","walls","paintings"}) : "Some rather tacky paintings have been hung on the walls in a desperate (and unsuccessful) attempt to make the place look a bit more respectable. You notice one of a typical pirate, one of a mermaid, and one of a large treasure chest at the bottom of the sea guarded by a gigantic squid.",
   ]));
  set_exits(([
  "south":TCITY+"c37",
  ]));
  set_open("door",1);
}

void reset(){
  ::reset();
  if(!present("waitstaff")) {
     new(MON+"barkeep3")->move(TO);
  }
}
*/