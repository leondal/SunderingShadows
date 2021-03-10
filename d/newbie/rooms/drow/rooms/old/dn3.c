#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"southwest" : DNROOMS+"dn2",
		"east" : DNROOMS+"dn4"
    	]));
    	
    	set_door("door",DNROOMS+"dn4","east","brass key");
    	set_locked("door",1,"lock");
     		(DNROOMS+"dn4")->set_locked("east room door",1,"lock");
    	set_door_description("door","The door is heavily made and is "+
    		"reinforced with iron bands.");
    	set_string("door","open","The door opens into a dark room.\n");

    	set_trap_functions(({"door"}),({"gas_em"}),({"pick"}));
}
int gas_em(string str){
	int poison;
	if(str!="lock"){
		return 0;
	}
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.\n%^BOLD%^%^GREEN%^You hear a hissing as a "+
		"cloud of sickly green gas issues from the lock.");
	tell_room(TO,"%^BOLD%^%^GREEN%^A sickly green mist issues from the lock!",TP);
      if((int)TP->query_stats("dexterity")>random(20)){
		tell_object(TP,"%^BOLD%^%^GREEN%^You manage to turn away and the spray misses "+
			"your face by inches.");
		tell_room(TO,""+TPQCN+" turns away from the spraying gas.",TP);
		return 0;
	}else{
		tell_room(TO,"%^BOLD%^%^GREEN%^The mist sprays directly into the face "+
			"of "+TPQCN+"!",TP);
		tell_object(TP,"%^BOLD%^%^GREEN%^The corrosive mist hits you right "+
			"in the face and starts burning into your skin and eyes "+
			"causing immense pain!");
		TP->set_blind(1);
		TP->do_damage("head",roll_dice(10,3));
		TP->add_attacker(TO);
		TP->continue_attack();
     		TP->remove_attacker(TO);
    	}
    	if (TP->query_ghost()) {
        	return 1;
    	}else if((int)TP->query_stats("constitution")>random(20)){
      	tell_object(TP,"You get a whiff of the deadly vapor, but hopefully not "+
      		"enough to cause you permanent damage.");
      	return 1;
      }else{
      	poison = roll_dice(15,5);
      	tell_object(TP,"You breathe in the gas deeply and begin to cough.");
      	tell_room(TO,""+TPQCN+" coughs and gags as the gas works its way "+
      		"into "+TP->query_possessive()+" lungs\n",TP);
		TP->add_poisoning(poison);
		TP->setPoisoner(TO);
		return 1;
	}
}
