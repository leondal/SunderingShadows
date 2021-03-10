#include <std.h>
#include "../lgnoll.h"

inherit WEAPONLESS;




void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
      tell_room(ETO, "%^RESET%^YELLOW%^The golem starts to move in your direction .. It can see you!");
      TP->set_invis();
    }
    call_out("kill_ob", 5, TP, 1);

	}

void create() {
   object ob;
    ::create();
    set_name("golem");
    set_id( ({"golem", "granite golem", "granite", "Golem"}) );
    set_short("%^RESET%^%^ORANGE%^gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^te g%^BOLD%^%^CYAN%^o%^RESET%^%^ORANGE%^l%^BOLD%^%^CYAN%^e%^RESET%^%^ORANGE%^m%^RESET%^");
    set_long("%^ORANGE%^This g%^BOLD%^%^CYAN%^o%^RESET%^%^ORANGE%^l%^BOLD%^%^CYAN%^e%^RESET%^%^ORANGE%^m seem "+
	"to have materialized out of the walls of this chamber. It has been created of exactly the same gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^CYAN%^e %^RESET%^%^ORANGE%^as "+
	"the walls. It moves on two short gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^CYAN%^e "+
	"%^RESET%^%^ORANGE%^pillars for legs, and has two enormous clubs for arms. The limbs seem to flow a few inches from the "+
	"massive boulder that makes up its torso, like some magical force keeps the limbs connected to the rest of the body. "+
	"A smaller boulder hovers just above the torso, with %^BOLD%^%^BLACK%^two black sockets for e%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^es%^RESET%^%^ORANGE%^. "+
	"Otherwise, it is made purely of gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^CYAN%^e%^RESET%^%^ORANGE%^.%^RESET%^");
    set_race("construct");
    set_body_type("human");
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 28);
    set_hd(28,5);
    set_exp(5500);
    set_attack_bonus(6);
    set_max_hp(400+random(350));
    set_hp(query_max_hp());
    set_overall_ac(-17);
    set_attacks_num(4);
    set_attack_limbs( ({"right stone fist", "left stone fist"}) );
    set_base_damage_type("bludgeoning");
    set_damage(8,4);
    set_property("swarm",1);
    set_stats("strength", 18);
    set("aggressive", 20);
    set_mob_magic_resistance("average");
	set_property("damage resistance", 10);
    set_alignment(7);
    add_money("gold", random(4500));
    add_money("platinum", random(1500));
    set_funcs(({"blow", "ball"}));
    set_func_chance(35);
   if(!random(2)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("living stone");
     ob->move(TO);
	
   }
}

void blow(object targ) {

    tell_room(ETO, "%^MAGENTA%^The Granite Golem raises his arms and brings them down on "+targ->QCN+" in a mighty blow!",targ);
	tell_object(targ,"%^MAGENTA%^The Granite Golem raises its arms as it towers over you, bringing them down in a massive blow!");
    if(!"/daemon/saving_throw_d"->do_save(targ,-1,"reflex")) {
      tell_object(targ, "%^RED%^The Granite Golem crushes you beneath its powerful arms!");
      tell_room(ETO, "%^RED%^"+targ->query_cap_name()+" is crushed by the golem's powerful arms.");
      targ->set_paralyzed(random(5)+15,"Ow ... That hurt! You are seeing white dots everywhere.");
	  targ->do_damage(targ->return_target_limb(),roll_dice(5,10)+5);
    return 1;} else {
      tell_room(ETO, "%^MAGENTA%^"+targ->QCN+" jumps aside at the last second, avoiding the golem's massive blow!",targ);
	  tell_object(targ,"%^MAGENTA%^You manage to jump aside, just as the golem's massive limbs crash into the floor!");
    return 1;}
}

void ball(object targ) {
	int bolts,i;
	
	object *ebils;
//	tell_object(targ,"ETO is "+base_name(ETO)+" and bumptarg is "+base_name(targ)+".");
	tell_room(ETO,"%^GREEN%^The golem rolls itself up into a 6 foot ball and rolls towards you!",targ);
	ebils = TO->query_attackers();	    	
	tell_object(targ,"%^GREEN%^The golem rolls itself up into a 6 foot ball and rolls towards you!");
	if(!sizeof(ebils)){ return 10;}
	bolts = roll_dice(1,6)+2;
	for(i = 0;i<bolts;i++) {
	targ = ebils[random(sizeof(ebils))];
	tell_object(targ, "%^ORANGE%^The ball is coming at you .. Jump!");

	  if(!"/daemon/saving_throw_d"->do_save(targ,-1,"reflex")) {
      tell_room(ETO, "%^GREEN%^"+targ->QCN+" is run over by the granite ball!",targ);
      tell_object(targ,"%^GREEN%^You are run over by the massive granite ball!");
      targ->do_damage(targ->return_target_limb(),roll_dice(2,10));
      
	} else {
     tell_room(ETO, "%^ORANGE%^"+targ->QCN+" dives out of the way of the granite ball!", targ);
     tell_object(targ, "%^GREEN%^You dive out of the way of the granite ball!");
	}
	}
    return 1;}

void die(object obj) {
    tell_room(ETO, "%^BLACK%^%^BOLD%^The golem stops moving for a second, before crumbling to dust.%^RESET%^");
if(!random(4)){
		new(OBJ"graniterobes")->move(TO);
    	}
    	::die(obj);
}
