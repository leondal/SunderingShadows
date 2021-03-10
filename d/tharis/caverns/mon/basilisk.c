//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"basilisk","Basilisk","greater basilisk"}));
    set_name("Greater Basilisk");
    set_short("A Greater Basilisk");
    set_long(
	"A reptilian monster with eight legs, this beast stands fearlessly "+
	"before you. Its skin is a dull brown but its eyes glow a deadly "+
	"%^BOLD%^%^GREEN%^green%^RESET%^%^CYAN%^. It moves slowly "+
      "around the area looking for some "+
	"foolish adventures that happen to stumble into its lair."
    );
    set_body_type("reptile");
    set_race("basilisk");
    set_gender("male");
    set_size(2);
    set_hd(15,3);
    set_hp(random(50)+150);
    set_exp(7000);
    set_overall_ac(2);
    set("aggressive",16);
    add_money("gold",random(500)+500);
    add_money("silver",random(300)+200);
    add_money("copper",random(250)+100);
/*    set_wielding_limbs(({"head","right hand","left hand"}));
    new("/realms/bane/obj/basclaw")->move(this_object());
    command("wield claw in right hand");
    new("/realms/bane/obj/basclaw")->move(this_object());
    command("wield claw in left hand");
    new("/realms/bane/obj/basteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("right claws","right foreleg",0,0,0);
    add_limb("left claws","left foreleg",0,0,0);
    add_limb("teeth","head",0,0,0);
    set_damage(2,6);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claws","left claws","teeth"}));
    set_funcs(({"gaze","breath"}));
    set_func_chance(35);
}
void gaze(object targ){
    if(!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",0)){
	tell_object(targ, "%^BOLD%^BLUE%^The Basilisk gazes into your eyes and turns you into stone!");
	tell_room(environment(targ),"%^BOLD%^BLUE%^The Basilisk looks at "+targ->query_cap_name()+" and turns "+targ->query_objective()+" into stone!",targ);
	targ->do_damage(targ->return_target_limb(),75);
	targ->set_paralyzed(50);
	if(strsrch("paralysis",targ->query_property("strength"))!=-1);
	return 1;
	} else {
	tell_object(targ,"%^BOLD%^BLUE%^The Basilisk gazes towards you but you avert your eyes just in time!");
	tell_room(environment(targ),"%^BOLD%^BLUE%^The Basilisk gazes towards "+targ->query_cap_name()+" but "+targ->query_subjective()+" averts "+targ->query_possessive()+" eyes just in time!",targ);
	return 1;
    }
}
void breath(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^GREEN%^The Basilisk envelops you in a cloud of poisonous gas!");
	tell_room(environment(targ),"%^BOLD%^GREEN%^The Basilisk breathes a cloud of poisonous gas enveloping "+targ->query_cap_name()+"!",targ);
	targ->do_damage(targ->return_target_limb(),50);
	targ->add_poisoning(10);
	return 1;
	} else {
	tell_object(targ,"%^BOLD%^GREEN%^The Basilisk breathes a cloud of poisonous gas at you but you dive aside just in time!");
	tell_room(environment(targ),"%^BOLD%^GREEN%^The Basilisk breathes a cloud of poisonous gas at "+targ->query_cap_name()+" but "+targ->query_subjective()+" dives aside just in time!",targ);
	return 1;
    }
}
