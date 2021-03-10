#include <std.h>
inherit NPC;


void struck(int damage, object weapon, object attacker, string limb) { 
  string message;
  if (objectp(TO)&& objectp(ETO)&& objectp(attacker)){
    if("daemon/saving_d"->saving_throw(TO,"rod_staff_wand",
                                   -1*((int)attacker->query_level()))
       && (!objectp(weapon)||!weapon->query_ethereal())){
    
      message = (string)attacker->QCN + "'s " ;
      if (objectp(weapon)){
        message+= weapon->query_name();
      } else{
        message += "blow";
      }
      message +=" %^RESET%^passes harmlessly through the " + query_short()
              + "'s %^CYAN%^insubstantial %^RESET%^body!";
      tell_room(ETO, message, TO);
      return;
    }
  }
  ::struck(damage,weapon,attacker,limb);
}
