//Coded by Bane//
#include <std.h>
inherit MONSTER;
int flag;
void create(){
    ::create();
    set_id(({"vendor","human","asgard vendor"}));
    set_name("street vendor");
    set_short("A street vendor");
    set_long(
	"This is your typical Asgardian street vendor.  He is dressed in a "+
	"fine cloak and stands around in the central market square trying "+
	"anything to anyone.  He is a fairly small man and doesnt look like "+
	"he could hold much of a fight."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(8,11);
    set_hp(75);
    set_overall_ac(10);
  flag = 0;
    set_exp(500);
    set_alignment(5);
    set_emotes(7,({"%^MAGENTA%^Vendor says%^RESET%^: How are you doing this fine day my friend?","The street vendor holds open his cloak showing numerous small wares.","The street vendor brushes some dirt from his breeches."}),0);
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
   if(TP->query_invis()) return 1;
        if((string)TP->query_race() == "human" || (string)TP->query_race() ==
"elf"
|| (string)TP->query_race() == "half-elf" || (string)TP->query_race() ==
"dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() ==
"halfling" || (string)TP->query_race() == "horse"){
	return 1;
    }
    force_me("scream for help");
    call_out("answer",5,TP);
    return 1;
}
int answer(object targ){
   if(!objectp(targ)){
      tell_room(ETO,"No one answers the scream.");
     return 1;
   }
     if(present(targ) && !flag){
	tell_room(ETO,"A guard answers the vendors scream.");
	new("/d/laerad/mon/guard1")->move(ETP);
    new("/d/laerad/mon/guard1")->move(ETP);
	flag = 1;
	return 1;
    }
       tell_room(ETO,"No one answers the scream.");
}
void reset(){
	::reset();
	flag = 0;
}
