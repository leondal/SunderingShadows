//adapted from the stonechip on Tonerra

#include <std.h>

inherit OBJECT;

int count;

void create(){
	::create();
	set_name("puncture wound");
	set_id(({"wound","puncture wound"}));
	set_short("%^RED%^Puncture wound%^RESET%^");
	set_long("%^RED%^This is a vicious looking puncture wound, "+
         "apparently made by some piercing weapon.  You might be "+
         "able to <staunch> the wound if you had a minute to "+
         "concentrate.%^RESET%^");
	set_value(0);
	set_weight(0);
	count = 0;
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
      tell_object(TP,"%^YELLOW%^You're a little busy trying to "+
         "defend yourself right now!");
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
   if(!objectp(tp)){
      TO->remove();
      return;
   }
   if(tp->query_ghost()){
      TO->remove();
      return;
   }
   tell_object(tp,"%^BOLD%^%^RED%^You feel your wound sting "+
      "as you lose more blood!");
   tell_room(environment(tp),"%^BOLD%^%^RED%^"+tp->QCN+" looks weak "+
         "and pale!",tp);
   tp->do_damage("torso",roll_dice(1,4));
   count += 1;
   if(count>4){
      tell_object(tp,"%^RED%^The wound has stopped bleeding.");
      TO->remove();
      return 1;
   }
   call_out("hurt",random(4)+4,tp);
}

int my_give(string str){
   if(id(str)) return 1;
}
	
