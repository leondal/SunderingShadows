#include <std.h>
#include "../drownew.h"

inherit CAVERN;

/* changing to have inherit handle it with CROOM controls *Styx*  3/20/03
void reset() {
        ::reset();
        if(present("drowf") || present("drowt")) return;
        if(!random(10)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(15)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(15)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(20)) {
            new(DNMONS+"ndrowt")->move(TO);
            return;
        }
        if(!random(25)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
}
*/

void create(){
::create();
  	set_exits(([
		"north" : DNROOMS+"dn9",
		"northeast" : DNROOMS+"dn10",
		"east" : DNROOMS+"dn12",
		"southeast" : DNROOMS+"dn15",
		"southwest" : DNROOMS+"dn21",
		"northwest" : DNROOMS+"dn8"
    	]));

	set_trap_functions(({"southwest"}),({"drop_em"}),({"southwest"}));
}
int drop_em(string str){
   if(!interactive(TP) && (string)TP->query_race() == "drow") return 1;
	TP->set_paralyzed(5000,"You are unable to do that!");
	tell_object(TP,"You move southwest and feel the floor give way beneath you.\n");
	tell_room(ETO,""+TPQCN+" yelps!\n");
	tell_room(TO,""+TPQCN+" pitches forward!",TP);
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,""+TPQCN+" leaves to the southwest!\n",TP);
		TP->move(DNROOMS+ "dn21");
		tell_object(TP,"You barely avoid falling into the dark pit.\n");
	}else{
		tell_room(TO,""+TPQCN+" screams and disappears to the southwest!\n",TP);
		TP->move(DNROOMS+"pit1");
		tell_object(TP,"%^BOLD%^%^RED%^You tumble into a dark pit\n!");
		TP->do_damage("torso",roll_dice(2,10));
// added attacker stuff to prevent bugs if it kills them
	        TP->add_attacker(TO);
	        TP->continue_attack();
	        TP->remove_attacker(TO);
		tell_object(TP,"%^BOLD%^%^RED%^You come to a sudden painful stop at the "+
			"bottom of the pit!\n");
		tell_room((DNROOMS+"pit1"),"%^BOLD%^%^MAGENTA%^"+TPQCN+" lands with a thud"+
			"!\n",TP);
      	tell_room((DNROOMS+"pit1"),""+TPQCN+" %^BOLD%^%^MAGENTA%^groans.\n",TP);
	}
	TP->set_paralyzed(0);
	return 1;
}
