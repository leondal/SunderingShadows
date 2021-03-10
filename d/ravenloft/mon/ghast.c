//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"ghast","Ghast"}));
    set_name("Ghast");
    set_short("A horrid Ghast");
    set_long(
	"This once human being stands before you, rotting skin falling "+
	"from its diseased body. Bones stick out from all over the "+
	"beast. The disfigured creatures tongue is long and tough, "+
	"its teeth and tails have become strong and sharp with its "+
	"undead transformation."
    );
    set_body_type("human");
    set_race("ghast");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_property("alignment adjustment",2);
    set_property("swamp",1);
    set_class("fighter");
    set_mlevel("fighter",9);
    set_hd(8,13);
    set_hp(77);
    set_exp(1100);
    set_overall_ac(0);
    set("aggressive",19);
    set_stats("strength",16);
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("slashing");
    set_attacks_num(3);
    set_damage(1,8);
    set_attack_bonus(5);
    set_hit_funcs( (["right hand":(:TO,"paralyze":),"left hand":(:TO,"paralyze":)]) );
    set_funcs(({"stench"}));
    set_func_chance(102);
}
void stench(object targ){
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^RED%^The Ghasts putred smell causes you to vomit!");
	tell_room(ETO,"%^BOLD%^RED%^The Ghasts putred smell causes "+targ->query_cap_name()+" to vomit!",targ);
	if(!targ->query_paralyzed()) targ->set_paralyzed(20,"You are still sick to your stomach.");
	set_func_chance(0);
	execute_attack();
	set_func_chance(102);
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Ghasts putred smell turns your stomach.");
    tell_room(ETO,"%^BOLD%^RED%^The Ghasts putred smell turns "+targ->query_cap_name()+" a little green.",targ);
    set_func_chance(0);
    execute_attack();
    set_func_chance(102);
    return 1;
}
void paralyze(object targ){
    if(targ->query_paralyzed()) return 1;
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Ghasts touch paralyzes you!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" stiffens at the touch of the Ghast!",targ);
	targ->set_paralyzed(70,"You are frozen stiff.");
	return 1;
    }
}
