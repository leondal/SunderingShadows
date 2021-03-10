//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

object seized;

void breakout(object ob);
nosave int BEAT, heartcount;

void create()
{
      ::create();
  	set_name("giant crocodile");
  	set_id(({"croc","crocodile","giant croc","monster", "giant crocodile"}));
  	set_short("%^BOLD%^%^GREEN%^giant %^RESET%^%^GREEN%^crocodile");
  	set_long("%^BOLD%^%^GREEN%^A giant %^RESET%^grocodile %^BOLD%^%^GREEN%^"
             +" with huge, %^BOLD%^%^WHITE%^spikey teeth%^BOLD%^%^GREEN%^ and"
             +" malevolent %^BOLD%^%^RED%^red eyes%^BOLD%^%^GREEN%^.\n");
  	set_race("lizard");
  	set_body_type("quadruped");


	set_class("fighter");
	set_mlevel("fighter",55);
	level = 55;
	set_guild_level("fighter",55);
   	set_hp(random(2000)+800 + random(800));
	set_max_level(49);
	set_property("swarm",1);
  	set_overall_ac(-66);
      set_size(3);
      add_attack_bonus(69);
      set_property("magic",1);
      set_monster_feats(({
        "damage resistance",
    }));



    set_stats("strength",25);
    set_stats("dexterity",22);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",25);
    set_stats("charisma",5);
    set_attacks_num(5);
    set_damage(8,12);
    set_base_damage_type("piercing");
    add_limb("teeth", "head", 0, 0, 0);
    set_attack_limbs(({"teeth"}));
    set("aggressive", 30);
    set_alignment(4);
    set_property("full attacks",1);
    set_funcs(({"seize"}));
    set_func_chance(25);
    set_emotes(10,({
            "%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^croc%^BOLD%^%^GREEN%^"
           +" dives to attack from below",

            "%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^croc%^BOLD%^%^GREEN%^"
           +" gapes its mouth wide open, displaying rows of%^RESET%^"
           +" w%^BOLD%^%^WHITE%^i%^RESET%^cked teeth%^BOLD%^%^GREEN%^.",
    }),1);
    seized = 0;
    set_property("no random treasure", 1);
    set_new_exp(50, "normal");
    BEAT = 0;
    heartcount = 0;
    check_my_heart();
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

void spin(int count){
  if (!objectp(seized)){seized = 0; return;}
  if (!objectp(ETO)){ return;}
  if (!present(seized, ETO)){ breakout(seized); return;}
  if (!seized->query_paralyzed()){ return;}
  count --;
  if  (count <1){
    breakout(seized);
    return;
  }
  tell_object(seized, "%^BOLD%^%^GREEN%^The " + TO->QCN + "%^BOLD%^%^GREEN%^spins suddenly,"
                    +" with one of your limbs locked firmly in its mouth, nearly %^BOLD%^"
                    +"%^RED%^ripping%^BOLD%^%^GREEN%^ it off and leaving you damaged and"
                    +" disoriented.");
  tell_room(ETO, TO->QCN + "%^BOLD%^%^GREEN%^ spins suddenly with one of " + (string)seized->QCN
                 +"'s %^BOLD%^%^GREEN%^ limbs in its mouth, trying to rip it off.", seized);
  seized->do_damage(100+random(100));
  call_out("spin", 2, count);
}

void breakout(object ob){
  if (!objectp(ob)) { return;}
  tell_object(ob, "You manage to break free from the croc's jaws");
  tell_room(ETO, (string)ob->QCN + "%^RESET%^ manages to break free of the croc's jaws!", ob);
  ob->set_paralyzed(0);
  seized = 0;
}

void seize(object targ){
  object room;
  room = ETO;
  if (seized !=0){return;}
  if (!objectp(targ)||!objectp(room)) { return; }
  tell_object(targ, TO->QCN + "%^BOLD%^%^GREEN%^ grabs you in its mouth and holds tight.");
  tell_room(room, TO->QCN + "%^BOLD%^%^GREEN%^ seizes " + targ->QCN
                 +"%^BOLD%^%^GREEN%^ in its mouth and holds tight.", targ);
  targ->set_paralyzed(roll_dice(1, 4) * 8, "You are locked in the powerful jaws of the %^GREEN%^crocodile%^RESET%^.");
  seized = targ;
  call_out("spin", 2, 3 + random(3));
}

void die(mixed ob)
{
  if (objectp(seized)){
    breakout(seized);
  }
  ::die(ob);
}
