//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"spider"}));
    set_name("Whisper Spider");
    set_short("A Whisper Spider");
    set_long(
	"This Spider has a large plump abdomen, multiple eyes, and four "
	"pairs of segmented legs. Its body is covered with short, black "
 	"bristles. Two gray stripes run the length of its back. Its eyes "
	"are bright red. The creature moves incredibly fast for a 15 foot "
	"long spider."
    );
    set_body_type("arachnid");
    set_race("spider");
    set_gender("male");
    set_size(3);
	set_hd(24,16);
	set_hp(100);
    set_exp(2100);
    set_overall_ac(3);
    set("aggressive",19);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(2,6);
    set_hit_funcs((["head":(:TO,"poison":)]));
    set_funcs(({"web"}));
    set_func_chance(20);
}
void poison(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^RED%^The Spider's poison binds you tight!");
	tell_room(ETO,"%^BOLD%^RED%^The Spider sinks its jaws into "+targ->query_cap_name()+" binding "+targ->query_objective()+" tight!",targ);
	targ->set_paralyzed(90,"The poison holds you still.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Spider's poison stiffens you a bit!");
    tell_room(ETO,"%^BOLD%^RED%^The Spider sinks its jaws into "+targ->query_cap_name()+" shaking "+targ->query_objective()+" up a bit!",targ);
    return 1;
}
void web(object targ){
    tell_object(targ,"%^BOLD%^BLUE%^The Spider fires a strand of web at you!");
    tell_room(ETO,"%^BOLD%^BLUE%^The Spider fires a strand of web at "+targ->query_cap_name()+"!",targ);
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	tell_object(targ,"\n%^BOLD%^BLUE%^You get caught in the Spider's web!");
	tell_room(ETO,"\n%^BOLD%^BLUE%^"+targ->query_cap_name()+" gets caught in the Spider's web!",targ);
	targ->set_paralyzed(70,"You are stuck in the Spider's web.");
	return 1;
    }
    tell_object(targ,"\n%^BOLD%^BLUE%^The strand of web flies past you!");
    tell_room(ETO,"\n%^BOLD%^BLUE%^The strand of web flies past "+targ->query_cap_name()+"!",targ);
    return 1;
}
