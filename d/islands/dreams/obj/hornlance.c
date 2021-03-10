//updated to current code and to remove references to old gods ~Circe~ 9/22/19

#include <std.h>
inherit "/d/common/obj/weapon/mhlance.c";

void create(){
   ::create();
   set_name("horn lance");
   set_short("%^BOLD%^%^WHITE%^A%^YELLOW%^l%^WHITE%^i%^YELLOW%^c%^WHITE%^o%^YELLOW%^r%^WHITE%^n%^YELLOW%^ Lance%^RESET%^");
   set_obvious_short("A golden horn lance%^RESET%^");
   set_id(({"lance","golden lance","horn lance","unicorn lance"}));
   set_long("%^YELLOW%^This lance is 15 foot in length and has been crafted from %^WHITE%^ivory%^YELLOW%^ to look like a larger version of a unicorn's horn. It spirals to a sharp point, with ridges instead of perfectly smooth spirals, like that of a real horn.  The alicorn lance is set on a gold handle.%^RESET%^");
   set_lore("As a symbol of purity and virtue, the unicorn has long been used by many nobles as an icon.  Certain members of the faithful of Nim'navanon deeply cherishe the unicorn as a symbol of their deity.  It is then not unusual for knights and warriors of virtue would seek to draw upon the unicorn in the creation of weapons and arms.  The Alicorn Lance was created for a paladin of Lysara, Lady Isabella Dominquean.  Lady Isabella utilized the unicorn as her own personalsymbol to the point she is often refered to as The Silver Unicorn. The Alicorn Lance was passed down through her bloodline until her great-great-grandson Duke Ramazl Dominquean.  Sadly while on a quest for the Silverstar Harp Duke Ramazl vanished after setting sail for the island of Deku from Torm - A History of Nobels Houses of the North: Volume 7 - Marvesha Blackwood");
   set_property("lore difficulty",11);
   set_value(2000);
   set_property("enchantment",random(2)+3);
   set_item_bonus("sight bonus",3);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme(){
   tell_object(ETO,"%^YELLOW%^The horn lance is truly a marvel to behold.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^The lance almost seems to glow as "+ETOQCN+" wields it.%^RESET%^",ETO);
   return 1;
}

int removeme(){
   tell_object(ETO,"%^BOLD%^You put the lance aside for gentler activities.%^RESET%^");
   tell_room(EETO,"%^BOLD%^The faint glow around the lance ceases as "+ETOQCN+" releases it.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   int x;
   if(!objectp(ETO)) return 0;
   if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle())){
      ETO->force_me("drop lance");
      return 0;
   }
   if(!random(10)){
      tell_object(ETO,"%^BOLD%^The lance pierces through "+targ->QCN+"'s defenses!%^RESET%^");
      tell_object(targ,"%^BOLD%^"+ETOQCN+"'s lance pierces through your defenses!%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s lance pierces through "+targ->QCN+"'s defenses!%^RESET%^",({ETO,targ}));
      set_property("magic",1);
      targ->do_damage("torso",random(5)+10);
      remove_property("magic");
      return 1;
   }
   if(!random(30)){
      tell_object(ETO,"%^YELLOW%^The lance's glow increases and you feel revitalized.%^RESET%^");
      tell_room(EETO,"%^YELLOW%^The glow around "+ETOQCN+"'s lance increases and "+ETO->QS+" looks refreshed.%^RESET%^",ETO);
      ETO->do_damage("torso",-(random(10)+20));
      return 1;
   }
}
