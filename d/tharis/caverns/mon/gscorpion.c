//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"scorpion","giant scorpion"}));
    set_name("Giant Scorpion");
     set_short("A Giant Scorpion");
    set_long("This scorpion is huge! It measures almost 6 feet in length "+
	"and it looks fearsome. Its pincers wave back and forth searching "+
	"for prey, its tail cocked, ready to strike.");
    set_body_type("insectoid");
    set_race("scorpion");
    set_gender("male");
    set_size(2);
    set_hd(10,7);
    set_hp(170);
    set_overall_ac(3);
    set("aggressive",14);
    set_exp(1200);
    add_money("gold",random(100));
/*
    set_wielding_limbs(({"right hand","left hand","torso"}));
    new("/realms/bane/obj/scorclaw")->move(this_object());
    command("wield claw in right hand");
    new("/realms/bane/obj/scorclaw")->move(this_object());
    command("wield claw in left hand");
    new("/realms/bane/obj/scortail")->move(this_object());
    command("wield tail in torso");
*/
    add_limb("tail","abdomen",0,0,0);
    add_limb("right claw","right fore leg",0,0,0);
    add_limb("left claw","left fore leg",0,0,0);
    set_damage(2,6);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claw","left claw","tail"}));
    set_funcs(({"sting"}));
    set_func_chance(35);
}

void sting(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^%^RED%^The scorpion strikes suddenly, "+
         "stinging you with his tail!");
	tell_room(environment(targ),"%^BOLD%^%^RED%^The scorpion strikes "+
         ""+targ->QCN+" suddenly, stinging with his tail!",targ);
	targ->do_damage(targ->return_target_limb(),random(30)+20);
	targ->add_poisoning(5);
	return 1;
	} else {
	tell_object(targ,"%^RED%^The scorpion tries to sting you, but "+
         "you move just in time!");
	tell_room(environment(targ),"%^RED%^The scorpion tries to sting "+
         ""+targ->QCN+", but "+targ->QS+" moves just in time!",targ);
	return 1;
    }
}
