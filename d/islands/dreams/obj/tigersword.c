//updated to current code and to remove old gods ~Circe~ 9/22/19

#include <std.h>
inherit "/d/common/obj/weapon/katana";

void create(){
   ::create();
   set_name("Tiger Katana");
   set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^ Katana%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A large katana with an adamantium blade%^RESET%^");
   set_id(({"sword","katana sword","katana","tiger katana"}));
   set_long("%^YELLOW%^The katana has a large hilt that can be gripped with two hands by a humanoid. The hilt is made out of some type of %^WHITE%^bone%^YELLOW%^ that has been carved into the likeness of a %^RESET%^%^ORANGE%^leaping t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^, but is still smooth enough to comfortably grip. A square-cut %^RESET%^%^ORANGE%^topaz%^YELLOW%^ is embedded in the bottom of the pommel. The curved blade itself is forged from adamantium, tapering to a point and sharpened on both sides.  It is a very fine weapon with perfect balance.%^RESET%^");
   set_property("enchantment",3);
   set_item_bonus("perception",2);
   set_lore("Seeming to hail from a distant land, the Tiger Katana is a weapon that many have desired to posses but few have found themselves worthy of the blade.  The katana is said to house the spirit of a great tiger who will aid the worthy wielder of the blade.  The katana caused a massive battle of power when it first was found in the forests of Deku.  Rulers wished to posses the katana, using it as a sign of their right to rule, as did the faiths of Nilith and the Faceless One.  The faiths of Kreysneothosies and Jarmila tried to locate the sword, wishing to use it to further aid their battle against the darkness.  The blade was finally cast into the planes by a priestess of Kismet named Sarafina.  Sarafina wished to keep the katana out of the hands of mortals, seeing how the quest for it drove many of her friends and enemies into a craze to possess it. - The Tiger Katana: The History and Legends of the Fabled Blade - Naarick the Cobalt Mage");
   set_property("lore difficulty",18);
   set_value(2900);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme(){
   tell_object(ETO,"%^ORANGE%^%^You feel the spirit of the tiger heighten your senses.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" seems to come alive as "+ETO->QS+" grips the strange hilt of the sword.%^RESET%^",ETO);
   return 1;
}

int removeme(){
   tell_object(ETO,"%^ORANGE%^The spirit of the tiger departs as you release the hilt.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^%^"+ETOQCN+" sighs softly as "+ETO->QS+" releases "+ETO->QP+" hold of the sword.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   if(!random(20)){
      tell_object(ETO,"%^YELLOW%^You feel the spirit of the tiger possess you! With its agility and strength, you score a series of vicious attacks against "+targ->QCN+" before it leaves you.%^RESET%^");
      tell_object(targ,"%^YELLOW%^"+ETOQCN+" roars and begins to furiously attack you so quickly and viciously you can't block "+ETO->QO+"!%^RESET%^");
      tell_room(EETO,"%^YELLOW%^"+ETOQCN+" roars loudly and scores a series of vicious quick strikes on "+targ->QCN+".%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(3)+5);
      targ->do_damage("torso",random(2)+4);
      ETO->execute_attack();
      return 1;
   }
   if(!random(15)){
      tell_object(ETO,"%^BOLD%^%^BLACK%^The world appears to slow down for a moment and you easily strike through "+targ->QCN+"'s slow defense.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" moves with preternatural speed to strike you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" moves with preternatural speed to strike "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(5)+3);
      return 1;
   }
   if(!random(8)){
      tell_object(ETO,"%^RED%^%^BOLD%^Your sword slices cleanly through "+targ->QCN+", drawing blood.%^RESET%^");
      tell_object(targ,"%^RED%^%^BOLD%^"+ETOQCN+"'s sword slices cleanly through your flesh, drawing blood.%^RESET%^");
      tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+"'s sword slices cleanly through "+targ->QCN+", drawing blood.%^RESET%^",({ETO,targ}));
      ETO->set_property("magic",1);
      targ->do_damage("torso",random(8)+2);
      ETO->set_property("magic",-1);
      return 1;
   }
}
