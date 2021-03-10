//crushing hand for the Strength domain spell
//~Circe~ 5/4/08
#include <std.h>
#include <magic.h>

inherit WEAPONLESS;

object target;
int busy;

void create(){
   ::create();
   set_name("crushing hand");
   set_id(({"hand","crushing hand","giant hand"}));
   set_short("Crushing Hand");
   set_long("This large, disembodied hand seems almost the stuff "+
      "of nightmares.  Thankfully, there is a clean break just "+
      "the wrist, revealing nothing of the blood and sinew that "+
      "would appear to be inside.  The man-sized hand hovers in the "+
      "air, ready for its master's <command>.  The controller "+
      "may also <dismiss> the hand when it is no longer needed.");
   set_hd(1,8);
   set_hp(20);
   set_exp(1);
   set_stats("strength",10);
   set_stats("intelligence",7);
   set_stats("dexterity",18);
   set_race("conjuration");
   set_body_type("snake");
   add_limb("forearm","forearm",50,0,2);
   add_limb("wrist","base",0,0,0);
   add_limb("hand","wrist",0,0,0);
   remove_limb("head");
   remove_limb("mouth");
   remove_limb("tail");
   remove_limb("torso");
   set_attack_limbs(({"hand"}));
   set_hit_funcs((["hand":(:TO,"do_crush":)]));
   set_damage(1,1);
   set_attacks_num(1);
   set_base_damage_type("bludgeoning");
   set_gender("sexless");
   set_overall_ac(0);
   busy = 0;
}

int do_crush(object ob){
int strength;
   strength = TO->query_stats("strength");
   target = ob;
   if(objectp(target) && !busy){
      if((strength + random(6)) > (int)target->query_stats("strength")){
         tell_object(target,"%^RED%^The hand suddenly takes hold of you!%^RESET%^");
         tell_room(ETO,"%^RED%^The hand suddenly takes hold of "+target->QCN+"!%^RESET%^",target);
         busy = 1;
         call_out("crushing",1,target,1);
         return roll_dice(1,4);
      }
   }
   return roll_dice(2,4);
}

void crushing(object target,int round){
   if(!objectp(target)) return;
   if(!present(target,ETO)) return;
   while(round < 3){
      if(!objectp(target)) return;
      if(!objectp(TO)) return;
      if(!present(target,ETO)) return;
      tell_object(target,"%^BOLD%^%^RED%^You are crushed in the "+
         "grasp of the giant hand!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^RED%^"+target->QCN+" is crushed "+
         "in the grasp of the giant hand!%^RESET%^",target);
      target->do_damage("torso",roll_dice(4,4));
      target->set_tripped(1,"You are caught in the grip of the hand!");
      target->set_property("hand_tripped",1);
      if(target->query_hp() < 1)  return;
      if(objectp(target)) target->add_attacker(TO);
      if(objectp(target)) target->continue_attack();
      if(!objectp(target)) return;
      call_out("crushing",ROUND_LENGTH,target,round++);
      return;
   }
   tell_object(target,"%^ORANGE%^A rush of air fills your lungs "+
      "as the hand releases you!%^RESET%^");
   tell_room(ETO,"%^ORANGE%^"+target->QCN+" is suddenly released "+
      "by the hand!%^RESET%^",target);
   if(target->query_property("hand_tripped")){
      target->set_tripped(0);
      target->remove_property("hand_tripped");
      tell_object("target","%^BOLD%^%^BLUE%^You have been released by the hand!%^RESET%^");
   }
   busy = 0;
   return;
}

int isMagic(){ return 5; }