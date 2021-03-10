#include <std.h>

inherit "/d/dagger/cave2/mon/weaponlesswonder.c";

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
      tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
      TP->set_invis();
    }
    call_out("kill_ob", 5, TP, 1);
}

void create() {
    object ob;
    ::create();
    set_name("Balor");
    set_id( ({"demon", "greater demon", "greater", "balor", "cavemon"}) );
    set_short("Balor of the pit");
    set_long(
      "Brought to the plane of mortals under his own power, this large red figure stands before you.  His great bat like wings are folded on his back, and his barbed tail is twitching behind him.  Two great pointed horns flow from his head, and his mouth is filled with great fangs.  The talons on his hands are covered in the blood of recent victims."
    );
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_hd(25,5);
    set_exp(7500);
    set_attack_bonus(6);
    set_max_hp(300+random(250));
    set_hp(query_max_hp());
    set_overall_ac(-7);
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("barbed tail", "barbed tail",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    add_limb("right talon", "right talon",50,1,3);
    add_limb("left talon", "left talon",50,1,3);
    set_attacks_num(4);
    set_attack_limbs( ({"barbed tail", "right talon", "left talon", "fangs", "right wing", "left wing"}) );
    set_base_damage_type("slashing");
    set_damage(3,5);
    set_property("swarm",1);
    set_stats("strength", 16);
    set("aggressive", 20);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(2500));
    add_money("silver", random(2500));
    set_funcs(({"pin", "tail", "scream"}));
    set_func_chance(50);
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
}

void scream(object targ) {

    tell_room(ETO, "%^MAGENTA%^The demon raises his arms and lets out a great battle cry!");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_object(targ, "%^MAGENTA%^The battle cry of the Demon freezes you in your tracks!  You are frozen in fear!");
      tell_room(ETO, "%^MAGETNA%^"+targ->query_cap_name()+" is frozen in fear!");
      targ->set_paralyzed(random(20)+15, "You are frozen in fear!");
    } else {
      tell_room(ETO, "%^MAGENTA%^The demon dives at you, preparing to feast upon your flesh.");
    }
}

void pin(object targ) {
    tell_room(ETO, "%^GREEN%^The demon dives at "+targ->query_cap_name()+" trying to slam "+targ->query_objective()+" to the ground!", targ);
    tell_object(targ, "%^GREEN%^The demon dives at you, trying to slam you to the ground!");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_room(ETO, "%^GREEN%^"+targ->query_cap_name()+" is grabbed by the demon and slammed to the ground knocking the breath out of "+targ->query_objective()+"!", targ);
      tell_object(targ, "%^GREEN%^The demon grabs you and slams you to the ground hard, knocking the breath out of you!");
      targ->set_paralyzed(random(20)+15, "The breath has been knocked out of you, you can't breathe!!");
      targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
      return 1;
    } else {
      tell_room(ETO, "%^GREEN%^"+targ->query_cap_name()+" dives out of the way of the demon!", targ);
      tell_object(targ, "%^GREEN%^You dive out of the way of the demon!");
      return 1;
    }
}

void tail(object targ) {
    tell_room(ETO, "%^CYAN%^The demon spins, trying to impale you upon his tail!");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_room(ETO, "%^CYAN%^The demon slams his tail into "+targ->query_cap_name()+"!\n "+targ->query_cap_name()+" is stuck upon the demon's tail! The demon thrashes his tail wildly, smashing "+targ->query_cap_name()+" against several walls, until "+targ->query_subjective()+" is flung free, to land in a crumpled heap in the corner of the room!", targ);
      tell_object(targ, "%^CYAN%^   The demon slams his tail into you, and you become painfully stuck upon it!  The demon thrashes its tail wildly, slamming you into several walls before you fly free to land in a heap in the corner!");
      targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
      targ->set_paralyzed(random(10)+5, "You lie in a beaten heap.");
      targ->add_poisoning(20);
      return 1;
    } else {
      tell_room(ETO, "%^CYAN%^You dive out of the way just in time, and the demon's tail slams into the wall!");
      return 1;
    }
}
void die(object obj) {
if(!random(4)){
		new("/d/dagger/cave2/obj/flame_whip.c")->move(TO);
    	}
    	::die(obj);
}
