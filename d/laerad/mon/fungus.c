#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"fungus","plant"}));
    set_name("Fungus");
    set_short("A Fungus");
    set_long("The algae like fungus resembles a fibrous blob of decomposing "+
	", milk-colored matter with capped fungi growing out of it.");
    set_body_type("fungus");
    set_race("fungus");
    set_gender("male");
    set_size(2);
    set_hd(7,7);
    set_hp(77);
    set_exp(1000);
    set_overall_ac(3);
    set("aggressive",0);
    set_property("strength","fire");
    set_stats("strength",20);
    set_property("no rush",1);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_damage(1,10);
    set_funcs(({"spores"}));
    set_func_chance(20);
}
void spores(object targ){
    int hp;
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^GREEN%^The fungus sprays you with its spores and you start choking horribly!");
	tell_room(ETO,"%^BOLD%^GREEN%^"+targ->query_cap_name()+" is sprayed with some spores from the fungus and starts choking horribly!",targ);
	hp = ((int)targ->query_hp() - 1);
	targ->do_damage(targ->return_target_limb(),hp);
	return 1;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The fungus sprays you with its spores causing you to cough alot!");
    tell_room(ETO,"%^BOLD%^GREEN%^"+targ->query_cap_name()+" is sprayed with some spores from the fungus and starts to cough alot!",targ);
    targ->do_damage(targ->return_target_limb(),roll_dice(5,4));
    return 1;
}
