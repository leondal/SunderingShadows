#include <std.h>
#include "../ogres.h"

inherit WEAPONLESS;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
      tell_room(ETO, "%^RESET%^RED%^The Balor glares in your direction. Power flares "+
"as it pulls you violently from your hiding.");
      TP->set_invis();
    }
    call_out("kill_ob", 5, TP, 1);
}

void create() {
    object ob;
    ::create();
    set_name("Balor");
    set_id( ({"demon", "greater demon", "greater", "balor", "cavemon",
"greater balor demon", "balor"}) );
    set_short("%^RESET%^%^RED%^Greater Balor Demon%^RESET%^");
    set_long(
      "%^RESET%^%^BOLD%^%^BLACK%^This demon towers at an impressive thirty feet "+
"tall. Its whole humanoid body is covered in a %^RESET%^%^RED%^fine red fur "+
"%^RESET%^%^BOLD%^%^BLACK%^and a m%^RESET%^%^MAGENTA%^a%^RESET%^%^BOLD%^%^BLACK%^"+
"lign %^RESET%^%^MAGENTA%^a%^RESET%^%^BOLD%^%^BLACK%^ura seems to linger around it."+
" Giant bl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ck leat%^RESET%^%^WHITE%^h"+
"%^RESET%^%^BOLD%^%^BLACK%^ery wi%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^BLACK%^gs "+
"extend from it's back and two horns rise above it's head. Its face is vaugely bull"+
" like, with horns extending at the side of each of its jaws. %^RESET%^%^ORANGE%^M"+
"%^RESET%^%^WHITE%^a%^RESET%^%^ORANGE%^ssive te%^RESET%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
"th %^RESET%^%^BOLD%^%^BLACK%^fill an impressively large maw. The only clothing it "+
"wears is a %^RESET%^%^ORANGE%^dark l%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^"+
"ather l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^in clo%^RESET%^%^BOLD%^%^BLACK%^"+
"t%^RESET%^%^ORANGE%^h %^RESET%^%^BOLD%^%^BLACK%^made of the skin from some unknown "+
"animal. In its hands it grips a %^RESET%^%^BOLD%^%^RED%^wh%^RESET%^%^RED%^i%^RESET%^"+
"%^BOLD%^%^RED%^p %^RESET%^%^BOLD%^%^BLACK%^made from %^RESET%^%^BOLD%^%^RED%^p%^RESET%^"+
"%^YELLOW%^u%^RESET%^%^BOLD%^%^RED%^re fla%^RESET%^%^YELLOW%^m%^RESET%^%^BOLD%^%^RED%^e"+
"%^RESET%^%^BOLD%^%^BLACK%^.%^RESET%^"
    );
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 28);
    set_hd(28,5);
    set_max_level(25);
    set_attack_bonus(6);
    set_max_hp(400+random(250));
    set_hp(query_max_hp());
    set_overall_ac(-17);
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("barbed tail", "barbed tail",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    add_limb("right talon", "right talon",50,1,3);
    add_limb("left talon", "left talon",50,1,3);
    set_attacks_num(4);
    set_attack_limbs( ({"barbed tail", "right talon", "left talon", "fangs",
"right wing", "left wing"}) );
    set_base_damage_type("slashing");
    set_damage(5,7);
    set_property("swarm",1);
    set_stats("strength", 18);
   set("aggressive", 25);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(4500));
    add_money("silver", random(4500));
    set_funcs(({"pin", "tail", "scream"}));
    set_func_chance(50);
   if(!random(10)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
    set_resistance("electricity",10);
    set_resistance("acid",5);
    set_resistance("cold",5);
    set_resistance("fire",5);
}

void scream(object targ) {

    tell_room(ETO, "%^MAGENTA%^The demon raises his arms and lets out a great battle cry!");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_object(targ, "%^MAGENTA%^The battle cry of the Demon freezes you in your tracks!  You are frozen in fear!");
      tell_room(ETO, "%^MAGENTA%^"+targ->query_cap_name()+" is frozen in fear!");
      "/std/effect/status/panicked"->apply_effect(targ,roll_dice(1,6));
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
      "/std/diseases/diseases/demon_fever"->infect(targ, query_level());
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
      targ->set_paralyzed(roll_dice(1,2)*8, "You lie in a beaten heap.");
      targ->add_poisoning(20);
      return 1;
    } else {
      tell_room(ETO, "%^CYAN%^You dive out of the way just in time, and the demon's tail slams into the wall!");
      return 1;
    }
}
void die(object obj) {
    tell_room(EETO, "%^RED%^%^BOLD%^There is a blinding flash of light as the demon escapes back to the abyss...%^RESET%^");
if(!random(4)){
		new("/d/dagger/cave2/obj/flame_whip.c")->move(TO);
    	}
    	::die(obj);
}
