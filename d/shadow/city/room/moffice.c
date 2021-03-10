//Modified by Diego 07/11/02//

#include <std.h>
inherit VAULT;

int BLUE;
object ob;

void create(){
	::create();
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_short("Office of the Magistrate");
	set_long(
		"       %^YELLOW%^Office of the Magistrate%^RESET%^\n"+
		"%^RESET%^This is the office of the Shadow Magistrate. It is here where people may"+
		" lodge legal complaints against others for wrong doings, and where the"+
		" accused may come to defend themselves against such accusations. "+
		"The room itself is panelled in dark, %^RESET%^%^ORANGE%^stain%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d oak%^RESET%^ and the ceiling "+
		"has been raised some twenty five feet high with ornate, "+
		"%^YELLOW%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^YELLOW%^nz%^RESET%^%^ORANGE%^e%^YELLOW%^d candelabras%^RESET%^ mounted high on the wall. A single, "+
		"%^ORANGE%^grand mahogany desk%^RESET%^ sits atop a raised dias at the far "+
		"end of the room with a single high backed chair behind it. "+
		"The floor is of polished wood with a single line of %^RESET%^%^RED%^dark "+
		"%^BOLD%^%^RED%^red%^RESET%^%^RED%^ carpet%^RESET%^ leading up to the dais. Stern-faced "+
		"portraits and plaster busts of past magistrates line this "+
		"intimidating aisle down which applicants to the Magistrate "+
		"must walk. There are several %^ORANGE%^shelves%^RESET%^ full of ledgers along "+
		"the wall behind the dais and above them sits a %^BOLD%^shield%^RESET%^ bearing "+
		"the city's coat of arms and the words '%^BOLD%^Per Justicum Ordinare%^RESET%^'."
	);
	set_smell("default","The room smells of candle smoke and wood "+
		"polish, overlayed with the aroma of fear.");
	set_listen("default","It is eerily quiet and any sound you make echoes off the walls.");
	set_items(([
		"sign" : "There is a sign here that you can read.",
    	"sign" : "There is a sign here, but is seems to have been vandalized.",
		"ink" : "There is ink here for lodging your complaints or writing down"+
			" your response.",
		"paper" : "There is paper here for you to write down your complaint or"+
                       " response to your accuser.",
		"desk" : "The imposing mahogany desk holds an orderly arrangement of "+
			"quills, blank parchment and a large black candlestick. There "+
                        "are a number of drawers and a freshly filled inkwell.",
		"floor" : "The wood is polished to an impressive sheen.",
		"carpet" : "The carpet is thick and soft deadening the footfalls of "+
			"those who approach the dais.",
		({"portaits","portrait"}) : "The stern, ungiving faces of "+
			"Jacob Caldera, Yuan-Kim and other forgotten past "+
			"magistrates stare down at you from the walls.",
		({"bust","busts"}) : "Some of the more notable past "+
			"magistrates have been commemorated here in sculpture.",
		({"shelves","shelf"}) : "The shelves are full of leather-bound ledgers.",
		({"ledgers","ledger"}) : "These are the records of past "+
			"crimes and sentences issued by the magistrates of "+
			"Shadow. Many were lost so the record is incomplete "+
			"and many of the ledgers are blank and waiting to be filled.",
		"walls" : "The walls have oil lamps attached to them for additional light.",
		({"candelabra","candleabras","lamps","oil lamps","lamp","oil lamp"}) : "The "+
			"light of the flames flickers and shines in the dull sheen of the bronze.",
		"ceiling" : "The ceiling is made of oak, matching the rest of the room.",
		"dais" : "The dais is raised four feet from the floor with three "+
			"steps leading up to the top of it.",
		({"drawer","drawers"}) : "There are 5 drawers in this desk, to "+
			"look at the individually you should look drawer 1, look drawer 2, etc..",
		"drawer 1" : "The drawer sticks slightly as you pull it out to find it is empty.",
		"drawer 2" : "The drawer sticks and then opens and reveals an "+
			"empty drawer save for a small notch of wood in the back corner.",
		"drawer 3" : "The drawer opens easily to reveal only dust inside.",
		"drawer 4" : "The drawer opens easily to show it emptiness save "+
			"for a small notch of wood in the back corner.",
		"drawer 5" : "The drawer opens with some difficulty to reveal only a "+
			"few bits of fluff."
	]));
	set_exits(([
	"south" : "/d/shadow/city/room/gallows",
   	"peephole" : "/d/shadow/room/city/secret/stefano/dark_space"
	]));

 	set_invis_exits(({"peephole"}));
   set_pre_exit_functions(({"peephole"}),({"nogo"}));

	set_search("floor","Along the edges of the room faint remnants "+
		"of dusty, muddy foot prints can just be made out.\n");
	set_search("ledgers","One of the red ledgers seems lighter than "+
		"the rest. A blue ledger seems to be a bit more used than the rest.\n");
	set_search("ledger","How do you search one one ledger?\n");
	set_search("dais","The dais is solidly built with the same "+
		"polished wood finish as the rest of the floor. It is quite "+
		"bare, other than the mahogany desk, which you can readily see.\n");
	set_search("desk","Up close, the desk looks virtually unused and "+
		"the drawers are closed.\n");
	BLUE = 0;
}
void init() {
  	::init();
  	add_action("move_em","move");
  	add_action("move_em","get");
  	add_action("move_em","take");
  	add_action("close_em","close");
  	add_action("press_em","press");
  	add_action("check_em","check");
}
int check_em(string str) {
	if(!str) {
   	tell_object(TP,"Check what?");
      return 1;
   }
  	if(str == "peephole"){
  		if(BLUE == 0){
  			tell_object(TP,"What peephole?\n");
  			return 1;
  		}
   	tell_object(TP,"You peek into the peephole and look into a dark room.\n");
      tell_room(ETP,""+TPQCN+" looks beside the blue ledger intently.\n",TP);
      tell_room(("/d/shadow/room/city/secret/stefano/dark_space"),"You hear "+
      	"a quiet scraping noise and then the darkness in the room is "+
      	"broken by a bit of light from a tiny hole in the south wall.\n",TP);
      TP->force_me("peer peephole 1");
    	return 1;
 	}
}
int nogo(){
	if(avatarp(TP)) return 1;
   if(interactive(TP))return 0;
}
int press_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Press what?");
      return 1;
   }
   if(str == "notch"){
   	tell_object(TP,"%^BOLD%^Press notch in which drawer?\n");
   	return 1;
   }
   if(str == "notch in drawer 2" || str == "notch in drawer 4"){
   	tell_object(TP,"%^BOLD%^You press the "+str+" and nothing happens.\n");
   	return 1;
   }
  	if(str == "notch in drawer 4 twice"){
  		if(member_array("down",TO->query_exits()) != -1) {
      	tell_object(TP,"%^BOLD%^You have already opened the trapdoor "+
      		"beneath the desk!.");
         return 1;
      }
     	tell_object(TP,"%^BOLD%^You hear a click and a trapdoor "+
     		"swings open beneath the desk.\n");
     	tell_room(ETP,"%^BOLD%^You hear a click.\n",TP);
     	tell_room("/d/shadow/room/city/secret/stefano/cellar","You "+
     		"hear a click and the trapdoor swings open.\n",TP);
      add_exit("/d/shadow/room/city/secret/stefano/cellar","down");
      ("/d/shadow/room/city/secret/stefano/cellar")->add_exit("/d/shadow/city/room/moffice","trapdoor");
		return 1;
	}
	if(str == "notch in drawer 4 thrice"){
  		if(member_array("down",TO->query_exits()) != -1) {
  			tell_object(TP,"%^BOLD%^You press the "+str+" "+
  				"and the trapdoor closes with a click.\n");
  			tell_room(ETP,"%^BOLD%^You hear a click.\n",TP);
  			tell_room("/d/shadow/room/city/secret/stefano/cellar","%^BOLD%^You "+
  				"hear a click and the exit up disappears.\n");
  			remove_exit("down");
  			("/d/shadow/room/city/secret/stefano/cellar")->remove_exit("trapdoor");
         return 1;
      }
 	}
 	if(str == "notch in drawer 1" || str == "notch in drawer 3" || "notch in drawer 5"){
   	tell_object(TP,"%^BOLD%^That would be ok if there was a "+str+", but "+
   		"there isn't one.\n");
   	return 1;
   }
	return 1;
}
int move_em(string str) {
	if(!str) {
   	tell_object(TP,"Move, get, or take what?");
      return 1;
   }
  	if(str == "red ledger"){
  		if(member_array("east",TO->query_exits()) != -1) {
      	tell_object(TP,"You have already done that!.");
         return 1;
      }
     	tell_object(TP,"As you attempt to move the red "+
     		"ledger from the shelf you hear a click and a "+
     		"section of the shelving swings back revealing "+
     		"a space behind the wall.\n");
     	tell_room(ETP,""+TPQCN+" moves one of the ledgers, you "+
     		"hear a click and a section of the shelving in the "+
     		"east wall swings open revealing an opening.\n",TP);
     	tell_room("/d/shadow/room/city/secret/stefano/dark_space","The "+
     		"wall suddenly opens.\n",TP);
      add_exit("/d/shadow/room/city/secret/stefano/dark_space","east");
      ("/d/shadow/room/city/secret/stefano/dark_space")->add_exit("/d/shadow/city/room/moffice","out");
	return 1;
	}
	if(str == "blue ledger"){
		if(BLUE == 1){
			tell_object(TP,"You have move the ledger back to its "+
				"original position, blocking the hole.\n");
			tell_room(ETP,""+TPQCN+" moves the blue ledger a bit.\n",TP);
			BLUE = 0;
			return 1;
		}
		tell_object(TP,"You move the blue ledger and reveal a small "+
			"peephole into another room.\n");
		tell_room(ETP,""+TPQCN+" moves the blue ledger a bit.\n",TP);
		BLUE = 1;
		return 1;
	}
}
int close_em(string str) {
 	if(!str) {
   	tell_object(TP,"Close what?");
      return 1;
   }
  	if(str == "shelf" || str == "shelves"){
  		if(member_array("east",TO->query_exits()) != -1) {
     		tell_object(TP,"You push the shelves closed.\n");
     		tell_room(ETP,""+TPQCN+" pushes the shelves closed.\n",TP);
     		remove_exit("east");
     		("/d/shadow/room/city/secret/stefano/dark_space")->remove_exit("out");
     		return 1;
     	}
     	tell_object(TP,"How can you close the shelves, they are not open!.");
		return 1;
	}
}

/*
void reset(){
    ::reset();
    if(!present("corpse"))
{
       ob = new("/d/shadow/mon/magis");
       ob->move(TO);
       ob->die();
       present("corpse")->remove_decay();
    }
}
*/
