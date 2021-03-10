//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
object stomach;
int stomach;
void create(){
    stomach = new("/d/laerad/mon/obj/s_stomach");
    ::create();
    set_id(({"sandling","Sandling"}));
    set_name("Sandling");
    set_short("A Sandling");
    set_long(
	"This strange creature appears to be an amorphous mass of moving, "+
	"sliding sand capable of creating color variances in order to blend "+
	"in better with their background."
    );
    set_body_type("human");
    set_race("sandling");
    set_gender("male");
    set_size(2);
    set_alignment(5);
    set_hd(5,10);
    set_hp(50);
    set_exp(650);
    set_overall_ac(2);
    set("aggressive","grab");
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_damage(2,8);
    set_invis();
}
void grab(){
    if(stomach->query_property("full")) return;
    if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")){
	tell_object(TP,"%^BOLD%^BLUE%^The Sand underneath you comes alive and engulfs you!");
	tell_room(ETO,"%^BOLD%^BLUE%^The Sand underneath "+TP->query_cap_name()+" comes alive and engulfs "+TP->query_objective()+"!",TP);
	TP->move(stomach);
	set_invis();
	force_me("kill "+TPQCN);
	return 1;
    }
    tell_object(TP,"%^BOLD%^BLUE%^The Sand underneath you comes alive and grabs at you unsuccessfully!");
    tell_room(ETO,"%^BOLD%^BLUE%^The Sand underneath "+TP->query_cap_name()+" comes alive and grabs at "+TP->query_objective()+" unsuccessfully!",TP);
    set_invis();
    force_me("kill "+TPQCN);
    return 1;
}
void die(object death){
    object *inven;
    int i, j;
    inven = all_inventory(stomach);
    i = sizeof(inven);
    if(i){
	for(j=0;j<i;j++){
	    inven[j]->move(ETO);
	    if(interactive(inven[j])){
		inven[j]->describe_current_room(1);
		add_attacker(inven[j]);
	    }
	}
	stomach->remove();
    }
    tell_room(ETO,"%^BOLD%^RED%^The Sandling dies and its inside's pour out of its stomach.");
    return ::die(death);
}
