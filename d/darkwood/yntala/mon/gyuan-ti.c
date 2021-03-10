#include <std.h>
#include "../yntala.h"
inherit MONSTER;

   void create (){
   object ob;
   ::create ();
      set_name("Ghost of Yuan-ti Halfblood");
      set_id(({"yuan-ti","Yuan-TI","Yuan-ti","yuan-ti halfblood","halfblood","yuan ti","Yuan TI","yuan TI","Yuan Ti","ghost","undead"}));
      set_short("A translucent Yuan-ti");
      set_long("%^RESET%^This shimmering, human-like creature is much like its living, pureblood counterparts with the"
" exception that its head resembles that of a snake, complete with long fangs, forked tongue and dark, slanted eyes."
"  It is slightly thinner than the other yuan-ti and its hands, arms, legs and body are covered in gleaming, white"
" scales that mimic the look of a diamondback rattlesnake.  It's image constantly shifts and fades into and out of"
" view.");
      set_race("undead");
      set_gender("female");
      set_body_type("human");
      set_overall_ac(-3);
      set_size(2);
      set_hd(18,2);
      set_stats("intelligence",18);
      set_stats("strength",18);
      set_stats("wisdom",18);
      set_stats("dexterity",18);
      set_stats("constitution",13);
      set_stats("charisma",16);
      set_money("gold",random(300)+121);
      set_money("silver",random(100)+23);
      set_money("copper",random(50)+175);
      set_money("electrum",random(75)+50);
      set_money("platinum",random(50)+31);
      set_class("ranger");
    set_exp(2800);
      set_max_level(15);
    set_hp(random(200)+100);
      set_max_hp(query_hp());  
      set_alignment(9);
      set_property("full attacks",1);
      set_mlevel("ranger",18);
      set("aggressive","aggfunc");
      set_func_chance(30);
      set_funcs(({"kiss","regen","shriek","whirlit"}));
      new(OBJD+"gdagger.c")->move(TO);
      command("wield dagger");
      ob = new(OBJD+"gdagger.c");
      ob->move(TO);
      ob->set_property("monsterweapon",1);
      command("wield dagger");
	 set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl"
   }));
}
int aggfunc() {
   force_me("emote shrieks!");
   force_me("kill "+TPQN+ "");
}
void kiss(object target){
   tell_room(ETO,"%^RESET%^%^BOLD%^The Yuan-ti ghost wraps both of its hands around "+target->query_cap_name()+"'s head and kisses "+target->query_objective()+" deeply!",target);
   tell_object(target, "%^RESET%^%^BOLD%^The Yuan-ti ghost wraps two cold hands around your head and pulls you into a deep, sucking kiss that feels like she is sucking the very life out of you!");
   target->do_damage("torso",roll_dice(2,10));
   target->set_paralyzed(15,"%^BOLD%^You are still reeling from the kiss!");
}
void regen(object target){
   tell_room(ETO,"%^RESET%^%^BOLD%^The Yuan-ti ghost glows brightly for a moment and seems to be sucking in energy from around it!");
   if((int)TO->query_hp() < TO->query_max_hp()) {
      TO->do_damage("torso",-1*(random(20)+20));
   }
   return;
}
void shriek(object target){
   tell_room(ETO,"%^RESET%^%^BOLD%^The ghost takes in a deep breath and lunges for "+target->query_cap_name()+"!  She pulls "+target->query_objective()+" close and lets loose an ear shattering shriek right in "+target->query_possessive()+" ear!",target);
   tell_object(target, "%^RESET%^%^BOLD%^The ghost takes in a deep breath and lunges for you!  She pulls you in close and lets loose an ear shattering shriek right in your ear!");
   target->set_paralyzed(30,"%^BOLD%^You ears are still ringing!");
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}
