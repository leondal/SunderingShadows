//updated by ~Circe~ 10/14/19 to current code and to remove references to old gods
#include <std.h>
inherit "/d/common/obj/weapon/trident.c";

void create(){
   ::create();
   set_name("red coral trident");
   set_short("%^BOLD%^%^WHITE%^Trident of the %^RED%^R%^RESET%^%^RED%^e%^BOLD%^d%^RESET%^%^RED%^ B%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^e%^RESET%^");
   set_obvious_short("%^BOLD%^%^RED%^A red coral trident%^RESET%^");
   set_id(({"trident","coral trident","red coral trident","fork"}));
   set_long("%^RED%^Crafted from %^BOLD%^red coral%^RESET%^%^RED%^, this three pronged trident has been magically hardened.  %^BOLD%^Red coral%^RESET%^%^RED%^ barbs jut out from the outer prongs, allowing the trident to rip apart flesh and armor. Rising up higher than the outer prongs, the center prong tapers to a fine point.  The %^BOLD%^red coral%^RESET%^%^RED%^ has been knitted and fused together creating a long shaft.%^RESET%^"); 
   set_lore("Crafted for the pirate Manxean the Red, the Trident of the Red Brine is a cruel and sadistic weapon.  Magically formed from red coral, the trident pays homage to Manxean's love of the sea.  Enchanted with a deadly thirst for blood, the trident's magical properties seem to be tied to the red fluid.  Many who managed to survive Manxean's raids on ships around Torm speak of his cold laughter as his trident drank in the victim's blood, leaving them a dry and empty husk.  The fate of Manxean is unknown.  Some legends say that his favored trident turned on him one day and drained him dry. - Ships and Sails: A History of Famous Pirates - Gwendor Jankel");
   set_property("lore difficulty",15);
   set_value(2000);
   set_property("enchantment",3);
   set_hit((:TO,"hitme":));
   set_wield("%^RED%^You can feel the power within the trident as you grip it.%^RESET%^");
}

int hitme(object targ){
   if(!random(10)){
      tell_object(ETO,"%^RED%^You feel the tines sink deeply into "+targ->QCN+"'s flesh.%^RESET%^");
      tell_object(targ,"%^RED%^"+ETOQCN+" sinks "+ETO->QP+" trident deeply into your flesh.%^RESET%^");
      tell_room(EETO,"%^RED%^"+ETO->QCN+" sinks "+ETO->QP+" trident deeply into "+targ->QCN+"'s flesh.%^RESET%^",({ETO,targ}));
      set_property("magic",1);
     	targ->do_damage("torso",random(4)+6);
      remove_property("magic");
      return 1;
   }
   if(!random(18)){
      tell_object(ETO,"%^BOLD%^%^RED%^The tips of the tines glow white hot as begins to extract blood from "+targ->QCN+".  The trident pulses in your grasp as it drinks in the red fluid.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^RED%^Your heartbeats faster as your blood answers the call of "+ETOQCN+"'s trident.  Your blood begins to flow out of your body and into "+ETOQCN+"'s trident.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+targ->QCN+" howls in pain as blood flows from "+targ->QP+" body into "+ETOQCN+"'s trident.%^RESET%^",({ETO,targ}));
      set_property("magic",1);
      targ->do_damage("torso",random(10)+10);
     	remove_property("magic");
      return 1;
   }
}
