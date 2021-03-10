//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"dragonnel","Dragonnel"}));
    set_name("Dragonnel");
    set_short("A Dragonnel");
    set_long("The Dragonnel stands 24 feet tall, its huge wings stretched out before you. "+
	"Very similar to a dragon, the Dragonnel has 4 legs, wings, and "+
	"a long tail. Its body is a glossy black and it has a deep red "+
	"underbelly. Wicked looking maroon spines run down its back. "+
	"It stares at you with its pale violet eyes."
    );
    set_body_type("dragon");
    set_race("dragonnel");
    set_gender("male");
    set_size(3);
    set_hd(9,4);
    set_hp(random(60)+34);
    set_overall_ac(2);
    set("aggressive",13);
    add_money("gold", random(100)+200);
    set_property("swarm",1);
    set_exp(2000);
/*
    set_wielding_limbs(({"head","right foreclaw","left foreclaw"}));
    new("/realms/bane/obj/drlclaw")->move(this_object());
    command("wield claw in right foreclaw");
    new("/realms/bane/obj/drlclaw")->move(this_object());
    command("wield claw in left foreclaw");
    new("/realms/bane/obj/drlteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("teeth","head",0,0,0);
    set_damage(3,6);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right foreclaw","left foreclaw","teeth"}));
    set_funcs(({"slap"}));
    set_func_chance(25);
}
int slap(object targ){
    tell_object(targ,"%^BOLD%^RED%^The Dragonnel whips its tail around and slaps you with it!");
    tell_room(environment(targ),"%^BOLD%^RED%^The Dragonnel whips its tail around and slaps "+targ->QCN+" with it!",targ);
    targ->do_damage(return_target_limb(),random(20)+10);
}
