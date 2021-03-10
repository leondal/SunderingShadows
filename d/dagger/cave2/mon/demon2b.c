
#include <std.h>

inherit "/d/dagger/cave2/mon/weaponlesswonder.c";
object ob;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
      tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
      TP->set_invis();
      kill_ob(TP, 1);
    }
}

	void create() {
	    ::create();
	    set_name("Marlith");
	    set_id( ({"demon", "lesser demon", "common demon", "marlith", "cavemon"}) );
	    set_short("Marlith the charmer");
	    set_long(
	      "You stare into the eyes of the most beautiful woman you've ever seen.  Well, at least from the waist up.\n\n   Marlith is a demon.  From the waist up, she is one of the most beautiful women you've ever seen. At her waist the illusion vanishes (as do her legs) into the coils of the tail of a great snake that replace her legs.  Another problem is her six arms, all holding big nasty weapons to rip you apart, but hey, nobody's perfect."
	    );
	    set_race("demon");
	    set_body_type("human");
	    remove_limb("left hand");
	    remove_limb("right foot");
	    remove_limb("right leg");
	    remove_limb("left foot");
	    remove_limb("left leg");
	    remove_limb("right arm");
	    remove_limb("right hand");
	    remove_limb("left arm");
	    add_limb("tail", "torso", 0, 0, 0);
	    add_limb("upper right arm", "torso", 0, 0, 0);
	    add_limb("upper right hand", "torso", 0, 0, 0);
	    add_limb("upper left arm", "torso", 0, 0, 0);
	    add_limb("upper left hand", "torso", 0, 0, 0);
	    add_limb("middle right arm", "torso", 0, 0, 0);
	    add_limb("middle right hand", "torso", 0, 0, 0);
	    add_limb("middle left arm", "torso", 0, 0, 0);
	    add_limb("middle left hand", "torso", 0, 0, 0);
	    add_limb("lower right arm", "torso", 0, 0, 0);
	    add_limb("lower right hand", "torso", 0, 0, 0);
	    add_limb("lower left arm", "torso", 0, 0, 0);
	    add_limb("lower left hand", "torso", 0, 0, 0);
	    set_wielding_limbs( ({"upper right hand", "upper left hand", "middle right hand", "middle left hand", "lower right hand", "lower left hand"}) );
	    set_gender("female");
	    set_size(2);
	    set_class("ranger");
	    set_mlevel("ranger", 18);
	    set_hd(18,1);
	    set_mob_magic_resistance("average");
	    set_attack_bonus(3);
	    set_exp(3500);
	    set_max_hp(150+random(150));
	    set_hp(query_max_hp());
	    set_overall_ac(-5);
	    set_property("swarm",1);
	    set_property("full attacks", 1);
	    set_stats("strength", 15);
	    set("aggressive", 20);
	    set_mob_magic_resistance("average");
	    set_alignment(9);
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->set_short("A beaten scimitar");
	    ob->move(TO);
	    command("wield fork in upper right hand");
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->set_short("A shining longsword");
	    ob->move(TO);
	    command("wield fork");
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->set_short("A glowing claymore");
	    ob->move(TO);
	    command("wield fork");
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->set_short("A red rapier");
	    ob->move(TO);
	    command("wield fork");
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->set_short("A shortsword");
	    ob->move(TO);
	    command("wield fork");
	    ob = new("/d/dagger/cave2/obj/demonfork.c");
	    ob->set_property("monsterweapon", 1);
	    ob->move(TO);
	    command("wield fork");
	    add_money("gold", random(1000));
	    add_money("silver", random(2500));
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
	}
