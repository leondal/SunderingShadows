//Changed by Circe 12/7/03.  It was set to give a message to the player
//and room using TP if they were a ghost, but that was stopping the 
//death sequence and leaving people stuck as ghosts.  I removed 
//it to hopefully stop the bugs.
//Coded by Diego//

#include <std.h>
#include "../juran.h"

inherit VAULT;

void create(){
 	::create();
   set_name("cellar");
	set_short("cellar");
	set_long(
  		"%^RESET%^%^CYAN%^"+
		"The cellar still looks like a cellar oddly enough.  Time and the "+
		"ruination of the buildings upstairs has done little to change this "+
		"place.  Crates are stacked up in the southern section of the room.  "+
		"Something has definitely been taking up residence in the "+
		"place, but what is anyone's guess.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",1);
	set_property("light",-3);
  	set_terrain(STONE_BUILDING);
  	set_travel(PAVED_ROAD);
	set_smell("default","The smell of decay and rotted wood fills the air.");
	set_listen("default","Aside from the wind blowing through the room upstairs it is "+
		"as quiet as death here.");
	set_items(([
     	({"wall","walls"}) : "Some of the wall is made from stones and "+
     		"brick and other parts of the walls are made from compacted "+
     		"dirt.  Roots from the plants above have bored through the "+
     		"dirt sections.\n",
     	({"crates","crate"}) : "The crates are old and moldy.  They "+
     		"look to have been here for a very long time and are stacked "+
     		"haphazardly.  The crates are empty.\n",
		({"stair","stairs"}) : "The stairs are made from stone and are "+
			"part of the wall.  They lead up to the ruined building above.\n"
  	]));

	set_search("crates","The crates are empty and there are scratches "+
		"on the floor at the base of the boxes.\n");
	set_search("scratches","The scratches look to have been caused by "+
		"the moving of the crates.\n");

  	set_exits(([
  		"up" : JROOMS+"rb2"
  	]));

	set_trap_functions(({"south"}),({"gas_em"}),({"south"}));
}
void init() {
  	::init();
  	add_action("move_em","move");
  	add_action("disarm_em","snap");
}
int move_em(string str) {
   if(!str) {
   	tell_object(TP,"%^BOLD%^Move what?");
      return 1;
   }
  	if(str == "crates"){
  	  	if(member_array("south",TO->query_exits()) != -1) {
        	tell_object(TP,"%^BOLD%^You move the crates and close "+
        		"an opening to the south.\n");
     		tell_room(ETP,"%^BOLD%^"+TPQCN+" moves the crates and closes "+
     			"an opening in the south.\n",TP);
        	remove_exit("south");
        	tell_room("/d/player_houses/saradin/rooms/hallway","%^BOLD%^The "+
        		"opening in the north is suddenly closed.\n");
        	("/d/player_houses/saradin/rooms/hallway")->remove_exit("north");
         return 1;
      }
     	tell_object(TP,"%^BOLD%^You move the crates and open an exit to the south.\n");
     	tell_room(ETP,"%^BOLD%^"+TPQCN+" moves the crates and reveals an "+
     		"opening in the south wall.\n",TP);
      add_exit("/d/player_houses/saradin/rooms/hallway","south");
      tell_room("/d/player_houses/saradin/rooms/hallway","%^BOLD%^An opening "+
      	"in the north wall opens up.\n");
      ("/d/player_houses/saradin/rooms/hallway")->
      		add_exit("/d/shadow/juran/city/rb2d","north");
		return 1;
	}
	return 1;
}

/*
int gas_em(string str){
	int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);
   if(TP->query_true_invis()) return 0;

	tell_object(TP,"%^BOLD%^You start to move south and you "+
		"hear a barely audible click.\n");
	tell_room(ETP,"%^BOLD%^%^GREEN%^A glowing grey-green noxious "+
		"vapor hisses out suddenly and rapidly fills the cellar!  "+
		"Breathing the gas is unavoidable!\n%^RESET%^");
	tell_room(ETP,"%^BOLD%^GREEN%^The gas burns your eyes, nose, and "+
		"mouth.  You feel like it is burning at your skin.\n%^RESET%^");

  	for(i=0;i<j;i++) {
   	   if(!objectp(inven[i])) continue;
         if(inven[i] == TO) continue;
         if(inven[i] == TP) continue;
         if(inven[i]->query_true_invis()) continue;
         if((int)inven[i]->query_stats("constitution")>random(21)){
			tell_object(inven[i],"%^BOLD%^%^GREEN%^You cough and gasp, "+
				"but lasting effects of the gas leave as the gas dissipates.\n%^RESET%^");
  			inven[i]->do_damage("torso",random(10)+10);
		}else{
			tell_object(inven[i],"%^BOLD%^%^GREEN%^You cough and gasp "+
				"as the gas burns into your eyes and seeps into your blood.\n%^RESET%^");
			inven[i]->set_blind(1);
  			inven[i]->do_damage("torso",random(20)+20);
		}
	  inven[i]->add_attacker(TO);
	  inven[i]->continue_attack();
	  if(objectp(inven[i])) {	
			inven[i]->remove_attacker(TO);
        } 
  	}
  	TP->do_damage("torso",random(20)+20);
	TP->add_attacker(TO);
	TP->continue_attack();  		
        tell_player(TP,"%^BOLD%^%^GREEN%^The gas causes you to gasp and pant for breath as it is strangled from your body.");
        tell_object(ETO,"%^BOLD%^%^GREEN%^The gas causes "+TP->query_cap_name()+" to writhe on the ground, as the breath is strangled from their body by the choking, ichorous gas.",TP);
      }

      if((int)TP->query_stats("constitution")>random(21)){
		tell_object(TP,"%^BOLD%^%^GREEN%^You cough and gasp, "+
			"but lasting effects of the gas leave as the gas dissipates.\n%^RESET%^");
	}else{
		tell_object(TP,"%^BOLD%^%^GREEN%^You cough and gasp "+
			"as the gas burns into your eyes and seeps into your blood.\n%^RESET%^");
		TP->set_blind(1);
	}
	return 0;
}
Taken out and recoded by Circe to hopefully stop bugs 12/7/03
*/

int gas_em(object targ)
{
   int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);
   if(TP->query_true_invis()) return 0;

   tell_object(TP,"%^BOLD%^You start to move south, and you "+
		"hear a barely audible click.\n"+
            "%^BOLD%^%^GREEN%^A glowing grey-green noxious "+
		"vapor hisses out suddenly and rapidly fills the cellar!  "+
		"Breathing the gas is unavoidable!");
   tell_room(ETP,"%^BOLD%^%^GREEN%^As "+TPQCN+" moves south, a glowing grey-green noxious "+
		"vapor hisses out suddenly and rapidly fills the cellar!  "+
		"Breathing the gas is unavoidable!",TP);
   for(i=0;i<j;i++) {
      if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i] == TP) continue;
      if(inven[i]->query_true_invis()) continue;  
      if(!"daemon/saving_d"->saving_throw(inven[i],"paralyzation_poison_death")) {
         tell_object(inven[i],"%^BOLD%^%^GREEN%^You cough and gasp "+
				"as the gas burns into your eyes and seeps into your blood.");
 	  inven[i]->set_blind(1);
        inven[i]->do_damage("torso",random(20)+20);
	  inven[i]->add_attacker(TO);
	  inven[i]->continue_attack();
	  if(objectp(inven[i])) {	
			inven[i]->remove_attacker(TO); 
	  }
      }
      else {
         tell_object(inven[i],"%^BOLD%^%^GREEN%^You cough and gasp, "+
				"but lasting effects of the gas leave as the gas dissipates.");
        inven[i]->do_damage("torso",random(10)+10);
	  inven[i]->add_attacker(TO);
	  inven[i]->continue_attack();
	  if(objectp(inven[i])) {	
			inven[i]->remove_attacker(TO); 
	  }
      }
   }
   if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")) {
      tell_object(TP,"%^BOLD%^%^GREEN%^You cough and gasp "+
			"as the gas burns into your eyes and seeps into your blood.");
	TP->set_blind(1);
      TP->do_damage("torso",random(20)+20);
      TP->add_attacker(TO);
      TP->continue_attack();
	  if(objectp(TP)) {
	     TP->remove_attacker(TO);
	  }
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^GREEN%^You cough and gasp, "+
	"but lasting effects of the gas leave as the gas dissipates.");
   TP->do_damage("torso",random(10)+10);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) {
		TP->remove_attacker(TO);
   }
   if(objectp(TP)){
   return 0;
   }
   return 1;
}

int disarm_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^%^CYAN%^You snap your fingers, you sure are cool!");
      return 1;
   }
  	if(str == "fingers twice" || str == "twice"){
   	tell_object(TP,"%^BOLD%^You snap your fingers twice and hear "+
   		"another answering click.\n%^RESET%^");
   	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" snaps "+
   		""+TP->query_possessive()+" fingers twice and an answering click is heard.",TP);
		toggle_trap("south");
		return 1;
 	}
}

void reset(){
	::reset();
   if(!trapped("south"))toggle_trap("south");
}
