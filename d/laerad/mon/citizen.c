#include <std.h>
inherit MONSTER;
int flag=0;
void create(){
    ::create();
    set_id(({"citizen","human","asgard citizen"}));
    set_name("asgard citizen");
    set_short("An Asgard citizen");
    set_long(
	"This is a fine citizen of the city Asgard.  He is dressed in casual "+
	"clothing, perhaps on his way to work.  He does not look strong but "+
	"yet he walks around with no fear, knowing that the kings guards "+
	"will protect him and this fine city."
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
    set_emotes(5,({"%^MAGENTA%^Asgard citizen says%^RESET%^: Good day my friend.","The Citizen tips his hat to you."}),0);
}
void init(){
    string race;
    ::init();
    race = (string)TP->query_race();
    if(wizardp(TP)) return;
   if(TP->query_invis()) return;
    if(race == "human" || race == "elf" || race == "half-elf" || 
       race == "dwarf" || race == "gnome" || race == "halfling" || 
       race == "horse") {
       return;
    }
	if(interactive(TP)){
	  force_me("smile");
	  return;
    }
    force_me("say GUARDS! GUARDS!");
    call_out("answer",5,TP);
    return;
}
int answer(object targ){
     if(present(targ) && !flag){
        tell_room(ETO,"A guard answers the citizens scream.");
        new("/d/laerad/mon/guard1")->move(ETP);
    new("/d/laerad/mon/guard1")->move(ETP);
        return 1;
    }
       tell_room(ETO,"No one answers the scream.");
}

void reset(){
        ::reset();
        flag = 0;
}
