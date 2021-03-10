//Coded by Bane//
#include <std.h>
inherit TOWNSMAN;
void create(){
    ::create();
    set_id(({"shaman","healer","zargoth","zargoth the shaman"}));
    set_name("zargoth");
    set_short("Zargoth the Shaman");
    set_long(
	"Zargoth is dressed in a large leather and chainmail suit of armor.  "+
	"He sits in this hut healing the wounded and enjoying it immensely."
    );
    set_race("troll");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_hd(19,2);
    set_hp(154);
    set_overall_ac(0);
    set_exp(2000);
    set_alignment(9);
    set("aggressive",0);
   set_nwp("healing",15);
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
        if((string)TP->query_race() == "human" || (string)TP->query_race() ==
"elf"
|| (string)TP->query_race() == "half-elf" || (string)TP->query_race() ==
"dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() ==
"halfling" || (string)TP->query_race() == "horse"){
	tell_room(ETO,"Zargoth bolts out the back door!");
	TO->remove();
	return 1;
    }
    return 1;
}
void heart_beat(){
    ::heart_beat();
    if(TP->query_hp() < 153){
        TP->add_hp(2);
        return 1;
    }
}
