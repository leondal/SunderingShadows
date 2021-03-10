//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"scarecrow","Scarecrow"}));
    set_name("Scarecrow");
    set_short("A frightful Scarecrow");
    set_long(
	"The scarecrow's body is made up of cut wood and he sits "+
	"on a large stake in the ground. Its limbs are bound "+
	"together with hemp rope and covered in tattered rags, "+
	"grass and straw. A hollow gourd with a face carved into "+
	"it serves as its head. The wind rocks it slowly back and "+
	"forth on its support."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(5,20);
    set_hp(60);
    set_attack_bonus(6);
    set_exp(1800);
    set_overall_ac(5);
    set("aggressive",15);
    set_property("swarm",1);
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_damage(1,6);
    set_funcs(({"gaze"}));
    set_func_chance(35);
}
void gaze(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^GREEN%^The Scarecrow gazes into your eyes hypnotizing you!");
	tell_room(ETO,"%^BOLD%^GREEN%^The Scarecrow gazes into "+targ->query_cap_name()+"'s eyes!",targ);
	tell_room(ETO,""+targ->query_cap_name()+"'s body goes limp.",targ);
	targ->set_paralyzed(200,"You stare off into space.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The Scarecrow gazes into your eyes but you resist its charm!");
    tell_room(ETO,"%^BOLD%^GREEN%^The Scarecrow gazes into "+targ->query_cap_name()+"'s eyes but "+targ->query_subjective()+" resists its charm!",targ);
    return 1;
}
