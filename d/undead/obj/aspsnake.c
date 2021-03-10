//Essy: Nov 2016
//adapted from the stonechip on Tonerra
//and now from Duel (Punkture) in Torm.

#include <std.h>
#include "../undead.h";
inherit OBJECT;

int count;

void create(){
	::create();
	set_name("asp snake");
	set_id(({"snake","asp snake", "asp"}));
	set_short("%^BOLD%^%^GREEN%^biting asp snake%^RESET%^");
	set_long("%^BOLD%^%^GREEN%^The asp snake is coiling and biting you!%^RESET%^");
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
   
   add_action("my_give","give");
   add_action("my_give","offer");
}


void hurt(object targi){
	int i,bite;
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
   tell_object(targi,"%^BOLD%^%^GREEN%^The asp snake quirms and bites!");
   tell_room(EETO,targi->QCN+"%^BOLD%^%^GREEN%^ is trying to prevent an asp snake from squirming under his clothes!",targi);
   targi->do_damage(targi->return_target_limb(),roll_dice(2,5)+5);
   count++;
   if(count>roll_dice(1,3)+2){
      tell_object(targi,"%^GREEN%^You finally manages to pry the asp snake off you!.");
	  tell_room(EETO,targi->QCN+" %^GREEN%^manages to remove the squirming asp snake ",targi);
      TO->remove();
      return 1;
   }
   call_out("hurt",random(4)+4,targi);
}


int my_give(string str){
   if(id(str)) return 1;
}
	
