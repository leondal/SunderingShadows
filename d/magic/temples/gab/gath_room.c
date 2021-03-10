//Coded by Diego//
// Updated by Lujke 20 October 2005 Iron door removed due to conflict
// with trapdoor trap

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void blasting(object tp, int num);

void create(){
	::create();
	set_name("gathering room");
   set_short("gathering room");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This seems to be a gathering room of sorts and it is "+
   	"quite plain.  A bare %^RESET%^%^ORANGE%^wooden table "+
   	"%^BOLD%^%^BLACK%^sits in the middle of the room and is "+
   	"surrounded by %^RESET%^%^ORANGE%^wooden chairs%^BOLD%^%^BLACK%^.  "+
   	"A large part of the floor is covered by an intricately "+
   	"woven rug that is patterned with deep shades of "+
   	"%^RESET%^%^GREEN%^green %^BOLD%^%^BLACK%^and "+
   	"%^RED%^crimson %^BLACK%^and lined in %^YELLOW%^gold%^BLACK%^.  "+
   	"Sputtering torches are spaced evenly on the walls casting "+
   	"light and shadows around the room."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","You smell the faint aroma of incense.");
   set_listen("default","The anguished cries seem louder and closer now.");
   set_items(([
        "table" : "The wooden table appears clean and unused.\n",
   	"rug" : "The rug is by far the most ornate decoration "+
   		"in the room.  It appears almost awkward in the bare room.\n"
  	]));
   set_exits(([
		"east" : GAB+"alcove"
	]));

	set_search("rug","The rug looks very beautiful and expensive "+
		"and upon closer examination looks like it has been moved recently.\n");

// Iron door removed by Lujke 20 October 2005
//  	set_door("iron door",GAB+"alcove","east","loviatar_holy_symbol");
//   set_door_description("iron door","This door is made of iron and is "+
//   	"large.  Heavy and able to take much damage before opening if "+
//   	"barred, the door open and move with the lightest touch.\n");
//   set_string("iron door","open","The door swings open with the lightest "+
//   	"touch temple proper.\n");
//	set_open("iron door",1);
}
void init(){
   ::init();
   add_action("lift_em","lift");
   add_action("lift_em","move");
  	add_action("cover_em","cover");
   add_action("disarm_em","knock");
}
int lift_em(string str) {
   if(!str) {
   	tell_object(TP,"Lift what?");
      return 1;
   }
  	if(str == "rug"){
  		if(member_array("down",TO->query_exits()) != -1) {
      	tell_object(TP,"The rug has already been lifted out "+
      		"of the way and the trapdoor has already been uncovered!");
         return 1;
     	}
    	tell_object(TP,"You lift the rug out of the way and find it "+
    		"was covering a trapdoor.\n");
     	tell_room(TO,""+TPQCN+" lifts the rug and uncovers a trapdoor.\n",TP);
      add_exit(GAB+"tor_cham","down");
		(GAB+"tor_cham")->add_exit(GAB+"gath_room","up");

   	set_door("trapdoor",GAB+"tor_cham","down","loviatar_holy_symbol");
   	set_door_description("trapdoor","This is a simple wooden "+
   		"trapdoor in the floor.\n");
   	set_string("trapdoor","open","You lift the door open.\n");
   	set_locked("trapdoor",0,"lock");
			(GAB+"tor_cham")->set_locked("door",0,"lock");

    	(GAB+"tor_cham")->set_door("trapdoor",GAB+"gath_room","up","loviatar_holy_symbol");
    	(GAB+"tor_cham")->set_door_description("trapdoor","This is a simple wooden "+
   		"trapdoor in the ceiling.\n");
    	(GAB+"tor_cham")->set_string("trapdoor","open","You push the "+
    			"trapdoor up to open it into the gathering room.\n");

		set_trap_functions(({"trapdoor"}),({"blast_em"}),({"open"}));

		return 1;
	}
}
int cover_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Cover what?\n");
      return 1;
   }
  	if(str == "trapdoor"){
  		if(member_array("down",TO->query_exits()) != -1) {
     		tell_object(TP,"%^BOLD%^You pull the rug back into place "+
     			"covering the trapdoor.\n");
     		tell_room(TO,"%^BOLD%^"+TPQCN+" replaces the rug hiding "+
     			"the trapdoor once more.\n",TP);
     		remove_exit("down");
     		(GAB+"tor_cham")->remove_exit("up");
     	}else{
     		tell_object(TP,"The trapdoor is already covered!");
     	}
     	return 1;
   }
}
int blast_em(){
	if(interactive(TP)){
  		if(member_array("down",TO->query_exits()) != -1) {
			tell_object(TP,"%^BOLD%^%^YELLOW%^You pull open the trapdoor "+
				"and are surprised at the clicking noise that follows "+
				"closely behind that action!\n");
			tell_room(ETP,"You hear an ominous clicking sound "+
				"as "+TPQCN+" opens the trapdoor.\n",TP);
      	blasting(TP,0);
 		}else tell_object(TP,"What trapdoor?");
 	}
	return 1;
}
void blasting(object tp,int num){
	switch(num){
   	case(0):
   		tell_object(TP,"%^YELLOW%^Energy crackles and forms in the "+
      		"threshold of the trapdoor.\n");
         tell_room(ETP,"%^YELLOW%^You hear the sound of energy crackling.\n",TP);
      	TP->set_paralyzed(5000,"%^BOLD%^%^RED%^You can't do that "+
      		"right now your being electrocuted!");
        	break;
     	case(1):
     		tell_object(TP,"%^YELLOW%^You feel static electricity "+
     			"building and crawling over your skin.\n");
         tell_room(ETP,"%^YELLOW%^"+TPQCN+" stands paralyzed as "+
         	"energy crawls over "+TP->query_possessive()+" skin.\n",TP);
         break;
    	case(2):
    		tell_object(TP,"%^YELLOW%^Suddenly the building energy "+
         	"reaches critical mass and explodes with a tremendous "+
				"%^BOLD%^%^RED%^BANG%^YELLOW%^ slamming you backward "+
				"into the wall!!!\n");
			tell_room(ETP,"%^BOLD%^%^RED%^"+
				"The energy suddenly explodes with a "+
				"loud %^YELLOW%^BANG %^RED%^"+
				"sending "+TPQCN+" flying head over heels backward "+
				"into the wall!\n",TP);
         TP->set_paralyzed(0);
			TP->do_damage("torso",roll_dice(2,10)+20);
			TP->add_attacker(TO);
			TP->continue_attack();
         break;
    	case(3):
    		tell_object(TP,"%^YELLOW%^You land in a heap at the base "+
    			"of the wall.\n");
        	tell_room(ETP,"%^CYAN%^"+TPQCN+" lands in a dishevelled heap! \n",TP);
			return;
	}
   num++;
   call_out("blasting",0,tp,num);
   return;
}
int disarm_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^%^CYAN%^Knock on what?");
      return 1;
   }
  	if(str == "trapdoor twice" || str == "on trapdoor twice"){
  		if(member_array("down",TO->query_exits()) != -1) {
   		tell_object(TP,"%^BOLD%^You rap on the trapdoor twice and "+
   			"it swings open.\n%^RESET%^");
      	tell_room(ETP,"%^BOLD%^"+TPQCN+" raps soundly on the "+
      		"trapdoor twice and the trapdoor swings open.\n%^RESET%^",TP);
     		toggle_trap("trapdoor");

    		set_open("trapdoor",1);
     		(GAB+"tor_cham")->set_open("trapdoor",1);
     		tell_room(GAB+"tor_cham","The trapdoor swings open.\n");
 		}else tell_object(TP,"What trapdoor?");
 	}
 	if(str == "trapdoor" || str == "on trapdoor"){
 		tell_object(TP,"You rap on the trapdoor and possibly hurt "+
 			"your knuckles, but no one seems to be answering your knock.\n");
 		tell_room(ETP,""+TPQCN+" raps on the trapdoor.\n");
 	}
	return 1;
}
