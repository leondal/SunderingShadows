//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"turtle","dragon","dragon turtle"}));
    set_name("Dragon Turtle");
    set_short("A Dragon Turtle");
    set_long(
	"A massive looking turtle stands before you. Over 30 feet long "+
	"this creature look fearsome. Its shell is a bright green and "+
	"the rest of its body is a dull brown. Golden spines run around "+
	"the length of its shell, connected by a dark green webbing. "+
	"The Turtle gazes at you lazily, perhaps thinking you are no "+
	"threat to the likes of him."
    );
    set_body_type("dragon");
    set_race("dragon turtle");
    set_gender("male");
    set_size(2);
    set_stats("strength",15);
    set_hd(14,1);
    set_hp(random(120)+50);
    set("aggressive",1);
    set_overall_ac(0);
    set_exp(13000);
    add_money("gold",random(1500)+3000);
    add_money("silver",random(1000)+2500);
    add_money("platinum",random(50)+50);
/*    set_wielding_limbs(({"head","right foreclaw","left foreclaw"}));
    new("/realms/bane/obj/drtclaw")->move(this_object());
    command("wield claw in right foreclaw");
    new("/realms/bane/obj/drtclaw")->move(this_object());
    command("wield claw in left foreclaw");
    new("/realms/bane/obj/drtteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("mouth","head",0,0,0);
    remove_limb("right wing");
    remove_limb("left wing");
    set_damage(5,6);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right foreleg","left foreleg","mouth"}));
    set_funcs(({"breath"}));
   set_func_chance(30);
}
int breath(object targ){
    string dam;
    if("/daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	dam = "singes";
	} else {
	dam = "scalds";
    }
    tell_object(targ,"%^BOLD%^WHITE%^The Dragon Turtle breaths a cone of steam at you and "+dam+" you badly!");
    tell_room(environment(targ),"%^BOLD%^WHITE%^The Dragon Turtle breaths a cone of steam at "+targ->QCN+" and "+dam+" "+targ->QO+" badly!",targ);
    if(dam == "scalds"){
	targ->do_damage("torso",roll_dice(20,6));
	} else {
	targ->do_damage("torso",((roll_dice(20,6))/2));
    }
    return 1;
}
