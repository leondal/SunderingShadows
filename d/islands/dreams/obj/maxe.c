//updated to current code and to remove references to old gods ~Circe~ 9/21/19
#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";

void create(){
   ::create();
   set_name("mercury battle axe");
   set_short("%^BOLD%^%^WHITE%^M%^CYAN%^e%^WHITE%^r%^CYAN%^c%^WHITE%^u%^CYAN%^r%^WHITE%^y Battle Axe%^RESET%^");
   set_obvious_short("%^BOLD%^A %^BLUE%^bluish%^WHITE%^ crystal battle axe%^RESET%^");
   set_id(({"axe","mercury axe","battle axe","mercury battle axe","crystal axe","crystal battle axe"}));
   set_long("%^BOLD%^This battle axe seems to be made out %^CYAN%^crystal%^WHITE%^ filled with %^RESET%^mercury%^BOLD%^. The metal is constantly moving and shifting within the crystal casing. The hilt is made out of a %^CYAN%^bluish%^WHITE%^ steel, and on the very bottom of the handle a %^YELLOW%^lightning bolt %^WHITE%^has been engraved.%^RESET%^");
   set_property("enchantment",4);
   set_lore("The Mercury Battle Axe's creating is tied to a dwarven hero by the name of Jardaik Goldhelm, of Kinaro.  Carrying the blessing of his clan with him as Jardaik set out in the world, this axe was said to have been be an ancient clan treasure.  Jardaik cut his way through the infestation of drow and orcs that plagued the city of Daggerdale during its infancy, helping the humans to establish a firm hold withing the wild north.  Jardaik, a loyal follower of Tempus was the one who demonstrated to the faith the importance of establishing a temple complex in the battle torn North. - Axes, Hammers and Ale: An Overview of Famous Dwarves - Brooks Chipmunkcheeks");
   set_property("lore difficulty",13);
   set_value(3500);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hitme":));
}

int wieldme(){
   tell_object(ETO,"%^YELLOW%^A slight jolt goes through your arm as you grip the handle of the axe.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" looks startled for a moment as "+ETO->QS+" grips the hilt of the crystal axe.%^RESET%^",ETO);
   ETO->do_damage("torso",1);
   return 1;
}

int removeme(){
   tell_object(ETO,"%^BOLD%^You release the axe but can still feel a faint tingling in your palms.%^RESET%^");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" unwields "+ETO->QP+" crystal axe.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   if(!random(8)){
      tell_object(ETO,"%^BOLD%^You feel a tingle in your arm as you strike "+targ->QCN+".%^RESET%^");
      tell_object(targ,"%^BOLD%^"+ETOQCN+" strikes you so hard you feel a slight tingle from the wound.%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" strikes "+targ->QCN+" fiercely.%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(4)+4);
   }
   if(!random(12)){
      tell_object(ETO,"%^BOLD%^%^CYAN%^You slice cleanly through "+targ->QCN+"'s flesh with your axe.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" slices cleanly through your flesh with "+ETO->QP+" axe!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" slices cleanly through "+targ->QCN+"'s flesh with "+ETO->QP+" axe!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(5)+4);
      ETO->execute_attack();
     	return 1;
   }
   if(!random(16)){
      tell_object(ETO,"%^YELLOW%^Electricity arcs from your axe as you hit "+targ->QCN+", showering "+targ->QO+" in sparks!%^RESET%^");
      tell_object(targ,"%^YELLOW%^Electricy crackles around "+ETOQCN+"'s axe, showering you in sparks!%^RESET%^");
      tell_room(EETO,"%^YELLOW%^Electricy arcs from "+ETOQCN+"'s axe to "+targ->QCN+", showering "+targ->QO+" in sparks!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(5)+9);
      return 1;
   }
}
