//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("torture chamber");
   set_short("torture chamber");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"As your eyes adjust to the darkness you realize "+
   	"you've entered the torture chamber of Loviatar's "+
   	"clergy.  Devices of torture fill the musty and dark "+
   	"room.  A stretching rack sits in the center of the "+
   	"room along with a metal chair covered with spikes.  "+
   	"In the corner sits a small cage-like box and along "+
   	"the wall is a cross with leather straps.  Manacles "+
   	"line the walls and a brazier of burning coals glows dimly "+
   	"in the corner.  A large vat is positioned against the far "+
   	"wall  with a space for a fire to be built underneath it.  "+
            "A vent for the smoke leads up to somewhere unseen.  A large "+
   	"variety of whips and floggers line the walls, as well as metal "+
   	"pokers and oddly shaped utensils of unspeakable uses.  Off to "+
   	"one side, a pair of metal boots appear to have been solidly "+
   	"affixed to the floor."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The is musty and smells faintly of stale "+
   	"blood and bodily wastes.");
   set_listen("default","Sounds of suffering fill the air.");
   set_items(([
   	({"stretching rack","rack"}) : "This is a typical rack "+
   		"bound with leather straps and large wheels.  The "+
   		"surface of the rack is covered with many sharp metal spikes.\n",
   	"chair" : "This is where the victims would be placed for "+
   		"questioning.  It has straps to hold the victim in place "+
   		"and the sitting surface is lined with mithril barbs.\n",
   	"cross" : "This device is made of oak and seems quite sturdy.  "+
   		"The leather straps can be used to hold a person in place "+
   		"while being tortured.  The wood is indelibly stained with "+
   		"the blood of many victims.\n",
   	"box" : "This is another of the torture devices in the room.  "+
   		"The small box leaves little room for a victim to move, let "+
   		"alone breathe, and the floor and roof are lined with small spikes.\n",
   	"boots" : "These odd items appear to be made in two halves with "+
   		"thick leather bindings which would allow them to be fastened "+
   		"shut around a person's feet.  They appear to come in "+
   		"one-size-fits-all and are unlikely to be very comfortable, "+
   		"but then it doesn't appear that the victim would be expected "+
   		"to walk very far.  There are small funnelled inlets on either "+
   		"side of the boots whose purposes can only be guessed at.  On "+
   		"the average human the boots would probably reach to mid-calf.\n",
   	"vat" : "The vat looks large enough for a human, or a slightly "+
   		"larger humanoid, to stand in.  The vat is filled with a "+
   		"thick, viscous liquid.  There is a space beneath the vat "+
   		"and it looks like a fire has been built there before.  "+
   		"There is, also, a vent above the vat to carry smoke away.\n",
   	"liquid" : "The liquid appears to be oil.\n",
   	"vent" : "Glancing up at the vent you wonder whether it might "+
   		"offer some kind or reprieve, or escape, to the victim of "+
   		"the chamber.  However, you notice a small metal grate "+
   		"blocking the vent to prevent this eventuality.\n",
   	"grate" : "The grate appears to be solid, offering no chance of "+
   		"escape even if you could reach it.\n"
  	]));
   set_exits(([
	]));
}
void init() {
  	::init();
  	add_action("search_em","search");
}
void reset(){
	::reset();
//        if(!present("urgoth"))new(GAB+"urgoth")->move(TO);
//        if(!present("victim"))new(GAB+"victim")->move(TO);
}
int search_em(string str) {
 	if(!str) {
   	tell_object(TP,"Search what?");
      return 1;
   }
  	if(str == "ceiling"){
   	if(member_array("up",TO->query_exits()) != -1) {
      	tell_object(TP,"The trapdoor in the ceiling has already been found!");
         return 1;
     	}
     	tell_object(TP,"You look over the ceiling carefully and discover "+
     		"a thin rectangular crevice outlining a trapdoor. \n");
     	tell_room(ETP,""+TPQCN+" discovers a trapdoor in the ceiling.\n",TP);
      add_exit(GAB+"gath_room","up");
    	(GAB+"gath_room")->add_exit(GAB+"gath_room","down");

    	(GAB+"gath_room")->set_door("trapdoor",GAB+"tor_cham","down","loviatar_holy_symbol");
    	(GAB+"gath_room")->set_locked("trapdoor",0,"lock");
     	set_locked("trapdoor",0,"lock");
    	(GAB+"gath_room")->set_door_description("trapdoor","This is a simple wooden "+
   		"trapdoor in the floor.\n");
    	(GAB+"gath_room")->set_string("trapdoor","open","You lift the door open.\n");

    	set_door("trapdoor",GAB+"gath_room","up","loviatar_holy_symbol");
    	set_door_description("trapdoor","This is a simple wooden "+
   		"trapdoor in the ceiling.\n");
    	set_string("trapdoor","open","You push the "+
    			"trapdoor up to open it into the gathering room.\n");
     	return 1;
     	}
}
