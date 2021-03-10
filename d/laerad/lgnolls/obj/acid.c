//adapted from the stonechip on Tonerra
//and now from Duel (Punkture) in Torm.

#include <std.h>
#include "../lgnoll.h"
inherit OBJECT;

int count;

void create(){
	::create();
	set_name("acid arrow");
	set_id(({"acid","acid arrow", "acid burn"}));
	set_short("%^RED%^acid arrow%^RESET%^");
	set_long("%^BOLD%^%^GREEN%^This acid arrow is embedded in your body! You should %^RESET%^%^ORANGE%^'extract'%^BOLD%^%^GREEN%^ that really fast!%^RESET%^");
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
   add_action("extract","extract");
   add_action("my_give","give");
   add_action("my_give","offer");
}

int extract(){
   if(sizeof(TP->query_attackers()) > 0){
      tell_object(TP,"%^YELLOW%^You're a little busy right now?!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^RED%^You pull the arrow out of your body, stopping the burning.");
   tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" pulls the arrow "+
      "out of "+TP->QP+" body",TP);
   TO->remove();
   return 1;
}

void hurt(object targi){
	int i,burn;
   if(!objectp(targi)){
      TO->remove();
      return;
   }
   if(targi->query_ghost()){
      TO->remove();
      return;
   }
//   burn = random(3)+1;
//   for(i = 0;i<burn;i++){
   tell_object(targi,"%^BOLD%^%^GREEN%^You feel the %^ORANGE%^a%^GREEN%^c%^ORANGE%^i%^GREEN%^d %^RED%^b%^ORANGE%^u%^RED%^r%^ORANGE%^n%^RED%^i%^ORANGE%^n%^RED%^g %^GREEN%^in your wound!");
   tell_room(EETO,targi->QCN+"'s %^BOLD%^%^GREEN%^wound s%^RED%^i%^ORANGE%^zz%^GREEN%^l%^RED%^e%^GREEN%^s as the %^ORANGE%^a%^GREEN%^c%^ORANGE%^i%^GREEN%^d continues to b%^RED%^u%^GREEN%^rn!",targi);
   targi->do_damage(targi->return_target_limb(),roll_dice(1,5)+5);
   count++;
   if(count>roll_dice(1,3)+1){
      tell_object(targi,"%^GREEN%^The %^BOLD%^acid%^RESET%^%^GREEN%^ finally stops burning.");
      TO->remove();
      return 1;
   }
   call_out("hurt",random(4)+4,targi);
}


int my_give(string str){
   if(id(str)) return 1;
}
	
