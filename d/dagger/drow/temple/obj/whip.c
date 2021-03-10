#include <std.h>
//#include "/d/dagger/drow/temple/short.h"

//inherit "std/weapon";
// adjusting to be better balanced and available and inherit the common file per discussions with Circe and Cythera after a bug report *Styx* 8/2/05 

inherit "/d/common/obj/weapon/whip.c";

void create() {
   ::create();
   set_name("whip");
   set_id(({"drider whip","whip"}));
   set_short("%^RED%^drider whip%^RESET%^");
   set_long(
           "%^RED%^%^BOLD%^The drider whip is not like a normal whip.  It is "
           "composed of a light, web-like substance which breaks into multiple "
      "strands nearing its end.  This is clearly crafted by beings with powerful "
           "magical abilities for, by just looking at it, how it could ever be "
           "effective in combat is beyond your understanding.%^RESET%^"
           );
//   set_weight(10);
   set_value(300);
//   set_wc(1,6);   // all should come from the inherit now
//   set_large_wc(2,6);
//   set_size(2);
//   set_type("bludgeoning");
//   set_prof_type("whip");
   set_property("enchantment",3);  // increased from 1
   set_hit((:this_object(), "extra_hit":));
   set_wield((:this_object(), "extra_wield":));
}

int extra_hit(object ob) {
   int dam;
   dam = (random(5) + 1);
   if (interactive(ETO)) {
      if (random(20)) {  // raised from 15 now that evil rangers could dual wield it
         return 0;
      }
   } else {
      if(random(8) > 1) 
         return 0;
   }
   message("other_action",
           "%^RED%^The whip wielded by "+ETO->query_cap_name()+" wraps itself suddenly "
           "around "+ob->query_cap_name()+"'s legs and "
           +ob->query_subjective()+
           " falls to the ground!%^RESET%^"
           ,environment(ob),(({ETO, ob})));
   message("my_action",
           "%^RED%^The whip wielded by "+ETO->query_cap_name()+" wraps itself suddenly "
           +"around your legs and you trip to the ground!%^RESET%^" ,ob);
   // message for the wielder added by Lujke October 26 2005
   tell_object(ETO, "%^RED%^Your whip wraps itself suddenly around "+ob->query_cap_name()
          +"'s legs and " +ob->query_subjective()+" falls to the ground!%^RESET%^");
   // end of code added by Lujke
   ob->set_tripped(1+random(2),"You are still unravelling the whip "
                     "from your legs!");
   return dam;
}

int extra_wield() {
//   if((string)TP->query_race() != "drow" && (string)TP->query_race() != "drider") {
     if(!ALIGN->is_evil(TP) && interactive(TP)) {
//      write("%^RED%^You have not the knowledge to use this weapon!%^RESET%^" );
	write("%^BOLD%^%^BLACK%^The weapon dissolves into smoke in your hands!%^RESET%^" );
	remove();
 	return 0;
   }
   return 1;
}