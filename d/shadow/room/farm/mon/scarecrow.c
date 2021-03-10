#include <std.h>
inherit WEAPONLESS;

void create() {
  object obj;
  ::create();
  set_name("scarecrow");
  set_id(({"golem","scarecrow","scare crow"}));
  set_short("a clumsy scarecrow");
  set_long("This scarecrow is made of a wooden frame bound together "+
     "with hemp rope.  It has been given a rough hemp shirt stuffed "+
     "with straw to give it a more human shape.  It wears pants of "+
     "deep blue hemp, tied with a rope belt and stuffed with straw "+
     "into well-worn boots.  Instead of the typical pumpkin head, this "+
     "one has been given a muslin bag filled with sawdust.  Its "+
     "eyes and expression have been painted on, giving it a permanent "+
     "smile.");
  set_gender("neuter");
  set_race("scarecrow");
  set_body_type("human");
  set_alignment(9);
  set_hd(10,2);
  set_stats("strength",19);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_stats("charisma",8);
  set_property("swarm",1);
  add_money("gold",random(150));
  set_overall_ac(-2);
  set_hp(100+random(30));
  set_exp(800);
  set_max_level(12);
  set_attack_limbs(({"right hand","left hand"}));
  set_damage(1,6);
  set_attacks_num(2);
  set_speed(40);
  set_nogo(({"/d/shadow/room/farm/room/path2"}));
  set_funcs(({"stare"}));
  set_func_chance(8);
  set_emotes(3,({
     "The scarecrow wanders about the farm with a rake in hand.",
     "The scarecrow pulls a few weeds from the ground.",
     "The scarecrow scatters feed for the chickens."
  }),0);
  obj = new("/d/antioch/valley/obj/rope_belt");
  if(random(4)) obj->set_property("monsterweapon",1);
  obj->move(TO);
  command("wear belt");
}

int stare(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(TO)) return 0;
   if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",0)) {
      tell_object(targ,"%^BOLD%^%^BLUE%^The scarecrow fixes you with its "+
         "lifeless gaze!");
      tell_room(ETO,"%^BOLD%^%^BLUE%^The scarecrow fixes its lifeless "+
         "gaze on "+targ->QCN+"!",targ);
      targ->set_paralyzed(10+random(6),"You are dazed by the look of "+
         "the scarecrow!");
      return 1;
   }
   tell_object(targ,"%^CYAN%^The scarecrow turns its gaze on you, but "+
      "you resist its power!");
   tell_room(ETO,"%^CYAN%^The scarecrow gazes at "+targ->QCN+", but "+
      ""+targ->QS+" resists!",targ);
   return 1;
}