#include <std.h>
#include "../bpeak.h"
inherit MONSTER;
string emoteMessage;


object obj;
void create (){

::create ();
   set_name("Galhyon");
   set_id(({"giant","Galhyon","galhyon","hill giant","Hill Giant","Hill giant"}));
   set_short("%^RESET%^%^ORANGE%^A massive hill giant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This giant stands nearly ten and a half feet tall,"
" even with his massive shoulders haunched.  He has dark brown hair that is"
" shaggily cut and matches his ruddy skin tone.  His overly bushy eyebrows set low"
" on his large forehead, shadowing his dark brown eyes.  His face looks as though"
" it is pulled into a constant frown and his jowels hang low.  His hairy arms look"
" almost uproportionally long and end in very large hands.  He wears several layers"
" of dirty hide armor, alot of it still has tufts of fur attached in odd places here"
" and there.%^RESET%^");
   set_race("giant");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(25,2);
   set_overall_ac(-7);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",19);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_stats("charisma",7);
   set_exp(10000);
   set_alignment(9);
   set_hp(random(250)+300);
   set_max_hp(query_hp()); 
   add_search_path("/cmds/fighter"); 
   set_max_level(35);
   set_property("full attacks",1);
   set_func_chance(55);
   set_funcs(({"bodyslam","kick","roll","eyepoke","headbutt","earbox","frustration","overedge"}));
   set("aggressive","aggfunc");
   set_money("gold",random(1500));
   set_money("silver",random(500));
   set_money("copper",random(50));
   set_money("electrum",random(200));
   new(OBJD+"wcloak1")->move(TO);
   command("wear cloak");
   new(OBJD+"gclub")->move(TO);
   command("wield club");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(50);
   set_property("add kits",30);
   obj=new("/d/deku/armours/ring_p.c");
   obj->set_property("enchantment",2);
   obj->move(TO);
   command("wear ring");
     set_emotes(1, ({"%^RESET%^ The giant greedily tears at his food, chewing loudly.",
"%^RESET%^%^ORANGE%^Galhyon swings his club around in the air, grunting as he does.%^RESET%^"}), 0);
    set_property("not random monster", 1);
}
int aggfunc() {
   force_me("emoteat "+TPQN+ " turns to $N and raises his club above his head.");
   force_me("speech grunt");
   force_me("say %^ORANGE%^Me kill you now!");
   call_out("force_me",1,"rush "+TPQN+ "");
}
void bodyslam(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant leaps into the air and throws himself at "+target->query_cap_name()+"!%^RESET%^",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant leaps into the air and flies towards you in what looks like a lopsided swan dive.  Your life flashes before your eyes as the force of impact knocks the wind out of you!%^RESET%^");
   target->set_tripped(3,"You are still trying to catch your breath.");
   return roll_dice(2,10)+5;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant leaps into the air and flies towards "+target->query_cap_name()+", but misses "+target->query_objective()+"!",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The hill giant leaps into the air and flies at you, but misses!%^RESET%^");
   return 1;
}
void kick(object target) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^The giant grunts loudly as he kicks "+target->query_cap_name()+" in the shins!%^RESET%^",target);
   tell_object(target, "%^BOLD%^%^BLACK%^The giant grunts loudly as he kicks you in the shins!%^RESET%^");
   target->do_damage("torso",roll_dice(2,8));
}
void roll(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant throws himself onto the ground and starts rolling towards "+target->query_cap_name()+"!  He rolls right into "+target->query_objective()+", knocking "+target->query_objective()+" off of "+target->query_possessive()+" feet!%^RESET%^",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant throws himself onto the ground and barrels into you, knocking you off of your feet!%^RESET%^");
   target->set_tripped(3,"Damn, you just got run over by a giant... And you want to get up already!?");
   return roll_dice(2,8)+2;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant throws himself onto the ground and rolls right past "+target->query_cap_name()+" before quickly jumping back to his feet!",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant throws himelf onto the ground and rolls right past you before quickly jumping back to his feet!%^RESET%^");
   return 1;
}
void eyepoke(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant reaches out with his stubby fingers and pokes "+target->query_cap_name()+" in the eyes!%^RESET%^",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant reaches out with his stubby fingers and pokes you in the eyes!%^RESET%^");
   target->set_temporary_blinded(3,"You're still trying to figure out if you have eyes anymore!");
   return roll_dice(1,8)+2;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^ORANGE%^"+target->query_cap_name()+" quickly turns away as the giant stabs at "+target->query_possessive()+" eyes with his fingers!",target);
   tell_object(target, "%^RESET%^%^ORANGE%^You quickly turn away as the giant reaches for your eyes with his stubby fingers!%^RESET%^");
   return 1;
}
void heabutt(object target) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^As the giant headbutts "+target->query_cap_name()+"%^RESET%^ %^RESET%^sweat %^BOLD%^%^BLACK%^flies everywhere!%^RESET%^",target);
   tell_object(target, "%^BOLD%^%^BLACK%^The giant headbutts you ferociously, splattering his %^RESET%^sweat %^BOLD%^%^BLACK%^all over you!%^RESET%^");
   target->do_damage("torso",roll_dice(2,10));
}
void earbox(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   force_me("unwield club");
   force_me("Unwield club 2");
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant unwields his club and brings both hands up on either side of "+target->query_cap_name()+"'s ears, boxing them with tremendous force!%^RESET%^",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant unwields his club and claps his hands over your head, effectively boxing your ears like they've never been boxed before!%^RESET%^");
   force_me("wield club");
   force_me("wield club 2");
   target->set_tripped(3,"Your head is ringing.");
   return roll_dice(2,10)+5;
   return 1;
   }
   force_me("unwield club");
   force_me("unwield club 2");
   tell_room(ETO,"%^RESET%^%^ORANGE%^The giant unwields his club and "+target->query_cap_name()+" ducks just as the giant claps his hands over "+target->query_possessive()+" head!",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The giant unwields his club and you manage to duck just as he claps his hands together over your head!%^RESET%^");
   force_me("wield club");
   force_me("wield club 2");
   return 1;
}
void frustration(object target) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^The giant screams in frustration and grabs a rock!");
   if(!present("stone",TO)){
      new("/d/deku/misc/stones")->move(TO);
   }
   force_me("unwield club");
   force_me("unwield club 2");
   force_me("wield stone");
   tell_room(ETO,"%^BOLD%^%^BLACK%^The giant smashes the %^RESET%^stone %^BOLD%^%^BLACK%^over "+target->query_cap_name()+"'s head!%^RESET%^",target);
   tell_object(target, "%^BOLD%^%^BLACK%^The giant smashes the %^RESET%^stone %^BOLD%^%^BLACK%^over your head!%^RESET%^");
   target->do_damage("torso",roll_dice(2,10));
   force_me("unwield stone");
   force_me("wield club");
   force_me("wield club 2");
}
void overedge(object target){
   if((random(23)-5) >target->query_stats("dexterity")){
   tell_room((ETO),"%^RESET%^%^RED%^The hill giant grabs "+target->query_cap_name()+" and visciously hurls "+target->query_objective()+" over the edge of the cliff!",target);
   tell_object(target, "%^RESET%^%^RED%^The hill giant grabs you and hurls you over the edge of the cliff!");
      if (!TO->query_ghost()){
      target->move_player(INRMS+"bcliff");
      }
   }
      tell_room((ETO),"%^RESET%^%^RED%^The hill giant grabs "+target->query_cap_name()+" and visciously hurls "+target->query_objective()+" over the edge of the cliff, but "+target->query_subjective()+" catches "+target->query_objective()+"self on the ledge and climbs back up!",target);
   tell_object(target, "%^RESET%^%^RED%^The hill giant grabs you and hurls you towards the edge of the cliff. You catch yourself on the ledge and scramble back up!");
}
void receive_message(string msg_type,string msg){
   ::receive_message(msg_type,msg);
   if(msg_type == "emote"){
      if(present("wolf",ETO)) {
         if(strsrch(msg,"%^RESET%^%^ORANGE%^begs the giant for some food%^RESET%^.") != -1) {
            emoteMessage="emote takes another bite of his food and then throws the wolf the bone.";
         return;
        }
         if(strsrch(msg,"whines at the giants feet.") != -1) {
            emoteMessage="emote takes another bite of his food and then throws the wolf the bone.";
         return;
        }
         if(strsrch(msg,"'s hair stands on end as he snarls at the giant.") != -1) {
            emoteMessage="emote %^BOLD%^%^BLACK%^kicks the wolf hard, sending it whimpering to a corner.%^RESET%^";
         return;
        }
      return ;
      }
   return ;
   }
}      
void heart_beat(){
   ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   if(emoteMessage){
      force_me(emoteMessage);
      emoteMessage=0;
   return;
   }
   /*if(query_hp()<250  && present("vial",TO)){
   command("open vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   }*/
   if(present("wolf",environment(TO))) {
      if(sizeof(TO->query_attackers()) == 0) {
         switch(random(100)){
            case 0:
               force_me("emote beats the wolf severely with his club.");
            break ;
           case 1..99:
         break ;
         }    
      }
   }
}




