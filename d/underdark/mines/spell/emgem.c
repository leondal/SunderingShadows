//Octothorpe (12/23/08)
//Underdark Mining Caverns, Dragon Scale Cloak Gem Mob
//Based on Faithful Phantom Guardians mobs
///d/magic/mon/pbat.c

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/d/magic/mon/pbat.c";

void create(){
   ::create();
   set_name("emerald gem");
   set_short("%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l"+
      "%^RESET%^%^GREEN%^d g%^BOLD%^e%^RESET%^%^GREEN%^m%^RESET%^");
   set_id(({"emgem"}));
   set_long("%^BOLD%^%^GREEN%^This construct is a faceted, man-sized "+
      "%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l"+
      "%^RESET%^%^GREEN%^d%^BOLD%^, that is floating a few inches "+
      "off of the ground.%^RESET%^");
   set_race("emerald");
   set_gender("neuter");
   set_attacks_num(0);
   set_body_type("junk");
}

//Borrowing wail from Geonslu
///d/islands/tonerra/mon/edragon.c
void die(object targ){
   object obj;
   int i;
   object *inven;
   object *live;
   targ = ETO->query_current_attacker();

   inven = all_living(ETO);
   live = filter_array(inven, "is_non_immortal",
FILTERS_D);

   if(!objectp(targ)){
      tell_room(ETO,"%^BOLD%^The %^RESET%^%^GREEN%^em%^BOLD%^er"+
         "%^RESET%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d%^BOLD%^"+
         "%^BOLD%^%^GREEN%^shield flickers and fades away.%^RESET%^",TO);
      TO->move("/d/shadowgate/void");
      TO->remove();
   }
   for(i=0;i<sizeof(live);i++){
      if(!objectp(live[i])) continue;
      tell_room(ETO,"%^BOLD%^The %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^"+
         "a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d %^RESET%^%^BOLD%^shatters "+
         "and lets out a loud, keening wail.%^RESET%^",TO);
      if(!live[i]->query_property("wail immune")){
         tell_object(live[i],"%^BOLD%^The keening wail strikes you down, "+
            "shaking your soul.%^RESET%^\n");
         live[i]->do_damage("torso",roll_dice(24,4)/2+6);
      }
      if(!"/daemon/saving_throw_d"->fort_save(inven[i],-14)){
         live[i]->set_paralyzed(( roll_dice(1,12))*8,"%^BOLD%^The "+
            "ringing in your head won't stop!%^RESET%^");
      } else{
         live[i]->add_attack_bonus(-1);
      }
      if(live[i]->query_property("wail immune")){
         remove_property("wail immune");
      }
   }
   ::die();
}
