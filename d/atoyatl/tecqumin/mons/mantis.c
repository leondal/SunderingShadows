//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

object seized;
nosave int BEAT, heartcount;
void breakout(object ob);


void create()
{
      ::create();
  	set_name("giant mantis");
      set_property("not random monster", 1);
  	set_id(({"mantis","preying mantis","giant mantis","giant preying mantis"}));
  	set_short("%^BOLD%^%^GREEN%^giant pr%^RESET%^%^GREEN%^e%^BOLD%^y%^RESET%^"
        +"%^GREEN%^i%^BOLD%^ng m%^RESET%^%^GREEN%^a%^BOLD%^nt%^RESET%^%^GREEN%^"
        +"i%^BOLD%^s");
  	set_long("%^BOLD%^%^GREEN%^This fearsome creature is about%^RESET%^ twenty"
        +" feet %^BOLD%^%^GREEN%^in length, and rears up to%^RESET%^ eight feet"
        +" %^BOLD%^%^GREEN%^high when it chooses. Its distinctively triangular"
        +" %^RESET%^%^GREEN%^insectoid %^BOLD%^head features multiple eyes,"
        +" antennae and powerful%^RESET%^%^GREEN%^ mandibles%^BOLD%^, which it"
        +" uses to bite and chew on its prey. Its primary means of attack,"
        +" however, are the formiddable forearms with which it is able to grab"
        +" and seize victims.");
    set_race("insect");
    set_body_type("quadruped");


	set_class("fighter");
	set_mlevel("fighter",55);
	level = 55;
	set_guild_level("fighter",55);
	set_max_level(49);
	set_property("swarm",1);
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "sunder",
        "daze",
    }));



    set_level(55);
    set_class("fighter");
    set_mlevel("fighter", 55);
    set_max_hp(4000);
    set_hp(query_max_hp());
    set_exp(7000);
    set_property("swarm", 1);
    set_overall_ac(-71);
    set_size(3);
    add_attack_bonus(71);
    set_stats("strength",18);
    set_stats("dexterity",12);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",21);
    set_stats("charisma",5);
    set_attacks_num(7);
    set_damage(3,9);
    set_base_damage_type("piercing");
    set_fake_limbs(({"torso", "thorax", "head",
      "front leg", "back leg",
      "left forearm", "right forearm"}));
    set_attack_limbs(({"mandibles", "left forearm", "right forearm"}));
    set("aggressive", 30);
      set_new_exp(level, "normal");
  	set_overall_ac(-65);
      set_size(2);
      add_attack_bonus(65);
  	set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"seize", "sunder", "rush", "seize", "seize"}));
      set_func_chance(25);
  	set_emotes(10,({

            "%^BOLD%^%^GREEN%^The mantis brings its spiked forelimbs"
           +" together, as if in %^RESET%^prayer%^BOLD%^%^GREEN%^. ",

            "%^BOLD%^%^GREEN%^The mantis %^RESET%^chitters%^BOLD%^%^GREEN%^"
           +" angrily.",

            "%^BOLD%^%^GREEN%^The mantis dances back and raises its"
           +" forelimbs high in a threatening posture, its wings fanning"
           +" out behind it to make it look enormous.",

            "%^BOLD%^%^GREEN%^The mantis lets out an angry %^RESET%^hiss",
    	}),1);
  	set_emotes(10,({
            "%^BOLD%^%^GREEN%^The mantis brings its spiked forelimbs"
           +" together, as if in %^RESET%^prayer%^BOLD%^%^GREEN%^. ",
            "%^GREEN%^The mantis tilts its head to one side, curiously.",
		"%^BOLD%^%^GREEN%^The mantis goes very still, but sways like a"
           +"%^RESET%^%^GREEN%^ leaf%^BOLD%^%^GREEN%^ in the wind.",
            "%^GREEN%^The mantis takes a few steps backwards"

    	}),0);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
      set_skill("perception", 70);
}
void init()
{
  ::init();
}

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

void check_my_heart()
{
    if (heartcount>300){
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

void sunder(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("sunder " + who);
}

void rush(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("rush " + who);
}


void munch(int count){
  if (!objectp(seized)){seized = 0; return;}
  if (!objectp(ETO)){ return;}
  if (!present(seized, ETO)){ breakout(seized); return;}
  if (!seized->query_paralyzed()){ return;}
  count --;
  if  (count <1){
    breakout(seized);
    return;
  }
  tell_object(seized, "%^BOLD%^%^GREEN%^The " + TO->QCN
                     +"%^BOLD%^%^GREEN%^ drags you close and"
                     +" %^RESET%^munches %^BOLD%^%^GREEN%^on your head,"
                     +" chewing with its %^RESET%^powerful mandibles"
                     +"%^BOLD%^%^GREEN%^.");
  tell_room(ETO, TO->QCN + "%^BOLD%^%^GREEN%^ drags " + seized->QCN
                 +"%^BOLD%^%^GREEN%^ close and %^RESET%^munches"
                 +" %^BOLD%^%^GREEN%^on " + seized->QP +" head, grinding"
                 +" away with its powerful mandibles.", seized);
  seized->do_damage(275+random(225));
  call_out("munch", 2, count);
}

void breakout(object ob){
  if (!objectp(ob)) { return;}
  tell_object(ob, "You manage to break free of the preying mantis's grasp");
  tell_room(ETO, (string)ob->QCN + "%^RESET%^ manages to break free of the preying mantis's grasp!", ob);
  ob->set_paralyzed(0);
  seized = 0;
}

void seize(object targ){
  object room;
  room = ETO;
  if (seized !=0){return;}
  if (!objectp(targ)||!objectp(room)) { return; }
  tell_object(targ, TO->QCN + "%^BOLD%^%^GREEN%^ seizes you in the"
                 +" unyielding grip of its %^RESET%^spiked%^BOLD%^%^GREEN%^"
                 +" forelegs.");
  tell_room(room, TO->QCN + "%^BOLD%^%^GREEN%^ seizes " + targ->QCN
                 +"%^BOLD%^%^GREEN%^ in the unyielding grip of its"
                 +" %^RESET%^spiked%^BOLD%^%^GREEN%^ forelegs.", targ);
  targ->set_paralyzed(30, "You"
                 +" are in the deadly grip of a %^BOLD%^%^GREEN%^giant"
                 +" praying mantis!%^RESET%^");
  seized = targ;
  call_out("munch", 2, 3 + random(3));
}
