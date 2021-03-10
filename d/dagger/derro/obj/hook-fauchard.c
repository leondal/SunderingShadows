//updated to inherit a common weapon and use current coding standards ~Circe~ 7/30/19

#include <std.h>
inherit "/d/common/obj/weapon/fauchard.c";

void create(){
   ::create();
   set_id(({"polearm","pole arm","hook-fauchard","hook","fauchard"}));
   set_name("hook-fauchard");
   set_short("hook-fauchard");
   set_long("This is a six-foot-long polearm that can be used to impale and then drag opponents off balance with its hooks.  The haft is crafted from sturdy oak while the blade and hook are tempered steel.");
   set_lore("This weapon is favored by the derro in the Dagger region. Known for their tricks in combat, the derro make excellent use of these polearms, but few others have mastered them to the same degree.");
   set_property("enchantment",2);
   set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
   int dam;
   ob = ETO->query_current_attacker();
   if(!objectp(ob))return 1;
   if(random(25)>2)  return 1;   
   tell_object(ETO,"%^BOLD%^%^WHITE%^You impale "+ob->QCN+" and then drag "+ob->QO+" off balance with the hook!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" impales "+ob->QCN+" with "+ETO->QP+" hooked polearm and then pulls "+ob->QO+" off ballance!%^RESET%^",({ETO,ob}));
   tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->QCN+" impales you with "+ETO->QP+" hooked polearm and then pulls you off your feet!%^RESET%^");
   ob->set_tripped(1,"%^BOLD%^%^WHITE%^You are struggling to your feet!%^RESET%^");
   return(random(5)+1);
}
