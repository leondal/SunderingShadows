
#include <std.h>

inherit "/d/dagger/cave2/mon/weaponlesswonder.c";

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
	tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
	TP->set_invis();
	kill_ob(TP,1);
    }
}

void create() {
    object ob;
    ::create();
    set_name("Nalfshnee");
    set_id( ({"demon", "lesser demon", "common demon", "nalfshnee", "cavemon"}) );
    set_short("Nalfeshnee the Goat demon");
    set_long(
      "Nalfeshnee is a large ugly demon, standing on two cloven hoves, the lower half of his body being that of a goat.  Large leather wings raise out of his back, and two great clawed hands reach out to rip you apart."
    );
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hd(20,3);
    set_attack_bonus(3);
    set_exp(3500);
    set_max_hp(200+random(150));
    set_hp(query_max_hp());
    set_overall_ac(-5);
    set_wielding_limbs(({"right hand", "left hand"}) );
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("barbed tail", "barbed tail",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    add_limb("right talon", "right talon",50,1,3);
    add_limb("left talon", "left talon",50,1,3);
    set_attacks_num(2);
    set_attack_limbs( ({"barbed tail", "right talon", "left talon", "fangs", "right wing", "left wing"}) );
    set_base_damage_type("slashing");
    set_damage(3,3);
    set_property("swarm",1);
    set_stats("strength", 25);
    set("aggressive", 20);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(2500));
    add_money("silver", random(2500));
    set_func_chance(0);
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
}
