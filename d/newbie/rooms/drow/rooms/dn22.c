#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"northeast" : DNROOMS+"dn21",
		"northwest" : DNROOMS+"dn23"
    	]));

	set_trap_functions(({"northeast"}),({"drop_em"}),({"northeast"}));
}
int drop_em(string str){
   if(!interactive(TP) && ( (string)TP->query_race() == "kobold" || (string)TP->query_race() == "hobgoblin") ) return 1;
	TP->set_paralyzed(5000,"You are unable to do that!");
	tell_object(TP,"You move northeast and feel the floor give way beneath you.\n");
	tell_room(ETO,""+TPQCN+" yelps!\n");
	tell_room(TO,"pitches forward!",TP);
	if((int)TP->query_stats("dexterity")>random(25)){
         tell_room(TO,""+TPQCN+" leaves to the northeast!\n",TP);
		TP->move_player(DNROOMS+ "dn21");
		tell_object(TP,"You avoid falling into the dark pit.\n");
	}else{
		tell_room(TO,""+TPQCN+" screams and disappears to the northeast!\n",TP);
		TP->move_player(DNROOMS+"pit1");
		tell_object(TP,"%^BOLD%^%^RED%^You tumble into a dark pit\n!");
		TP->do_damage("torso",roll_dice(2,10));
// added attacker stuff to prevent bugs if it kills them
	        TP->add_attacker(TO);
	        TP->continue_attack();
	        TP->remove_attacker(TO);
		tell_object(TP,"%^BOLD%^%^RED%^You come to a sudden painful stop at the "+
			"bottom of the pit\n!");
		tell_room((DNROOMS+"pit1"),"%^BOLD%^%^MAGENTA%^"+TPQCN+" lands with a thud"+
			"!\n",TP);
      	tell_room((DNROOMS+"pit1"),""+TPQCN+" %^BOLD%^%^MAGENTA%^groans\n",TP);
	}
	TP->set_paralyzed(0);
	return 1;
}
