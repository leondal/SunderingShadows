//Coded by Bane//
#include <std.h>
inherit MONSTER;
int flag = 0;
void create(){
    ::create();
    set_id(({"peasant","human","asgard peasant"}));
    set_name("asgard peasant");
    set_short("An Asgard peasant");
    set_long(
	"This feeble man is dressed in tattered clothing.  He wanders the "+
	"streets of Asgard doing his business, trying to make "+
	"a living.  He looks very weak and you feel kind of sorry for him."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(5,10);
    set_hp(50);
    set_overall_ac(10);
    set_exp(100);
    set_alignment(7);
    set_emotes(5,({"The peasant begs you for some money.","The peasant searches the ground for some change."}),0);
}
void init(){
    string race;
    ::init();
    if ((string)TP->query_vehicle_type() != "riding animal" ) {
      race = (string)TP->query_race();
    } else { 
      if (objectp(TP->query_current_rider()))
	if (!call_other((object)TP->query_current_rider(),"query_invis"))
	  race = call_other((object)TP->query_current_rider(),"query_race");
      if (!stringp(race))
	race = "horse";
    }

    if(wizardp(TP)) return;
    if(TP->query_invis()) return;
    if(race == "human" || race == "elf" || race == "half-elf" || 
       race == "dwarf" || race == "gnome" || race == "halfling" || 
       race == "horse") {
      if(interactive(TP)){
	      force_me("smile");
	   }
	 return;
    }
    force_me("scream for help");
    call_out("answer",5,TP);
    return;
}

int answer(object targ){
    if(!flag && objectp(targ) && present(targ)){
        tell_room(ETO,"A guard answers the peasants scream.");
        new("/d/laerad/mon/guard1")->move(ETO);
        new("/d/laerad/mon/guard1")->move(ETO);
	flag = 1;
        return 1;
    }
       tell_room(ETO,"No one answers the scream.");
}
void reset(){
        ::reset();
        flag = 0;
}
