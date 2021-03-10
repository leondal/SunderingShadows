//Coded by Bane//
#include <std.h>
inherit TOWNSMAN;
void create(){
    ::create();
   set_nwp("healing", 20);
    set_id(({"silvermoon","healer","silvermoon the healer"}));
    set_name("silvermoon");
    set_short("Silvermoon the Healer");
    set_long(
	"Silvermoon is clothed in flowing robes of many colors.  She sits "+
	"in this store healing any wounded adventurers for a small fee.  "+
	"She smiles happily hoping she can help you."
    );
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_size(2);
    set_hd(19,2);
    set_hp(154);
    set_overall_ac(0);
    set_exp(500);
    set_alignment(1);
    set("aggressive",0);
}

void init(){
    string race;
    ::init();
    race = (string)TP->query_race();
    if(TP->query_true_invis())  return 1;
    if(race == "human" || race == "elf" || race == "half-elf" || race == "dwarf" || race == "gnome" || race == "halfling" || race == "horse"){
        return 1;
    }
    tell_room(ETO,"Silvermoon screams and runs out her back door.");
    TO->remove();
    return 1;
}
