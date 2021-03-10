//adapted from the stonechip on Tonerra
//and now from Duel (Punkture) in Torm.

#include <std.h>
#include "../lgnoll.h"
inherit OBJECT;

int count;

void create(){
	::create();
	set_name("rake wound");
	set_id(({"wound","raked wound", "raked"}));
	set_short("%^RED%^Raked wound%^RESET%^");
	set_long("%^RED%^This is a vicious looking rake wound, "+
         "made by the claws of a wemic.  You might be "+
         "able to <staunch> the wound if you had a minute to "+
         "concentrate.%^RESET%^");
	set_value(0);
	set_weight(0);
	count=0;
	
}

int drop(){
   return 1;
}

int give(){
   return 1;
}
	
void init(){
   ::init();
   add_action("staunch","staunch");
   add_action("my_give","give");
   add_action("my_give","offer");
}

int staunch(){
   if(sizeof(TP->query_attackers()) > 0){
      tell_object(TP,"%^YELLOW%^You're a little busy right now?!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^RED%^You press your fist against the "+
      "wound to make it stop bleeding.");
   tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" presses "+TP->QP+" fist "+
      "against a wound to make it stop bleeding.",TP);
   TO->remove();
   return 1;
}

void hurt(object tp){
	int raked;
   if(!objectp(tp)){
      TO->remove();
      return;
   }
   if(tp->query_ghost()){
      TO->remove();
      return;
   }
//   raked = random(4)+3; altered to make the damage round based
//   for(i = 0;i<raked;i++){
	
   tell_object(tp,"%^BOLD%^%^RED%^You feel your blood seeping from your raked wound!");
   tell_room(EETO,"%^BOLD%^%^RED%^"+tp->QCN+" looks like "+tp->QS+" is losing a lot of blood!",tp);
   tp->do_damage(tp->return_target_limb(),roll_dice(1,4)+1);
   count++;
   if(count>roll_dice(4)+2){
      tell_object(tp,"%^RED%^The wound has stopped bleeding.");
      TO->remove();
      return 1;
   }
   call_out("hurt",random(4)+4,tp);
}

int my_give(string str){
   if(id(str)) return 1;
}
	
