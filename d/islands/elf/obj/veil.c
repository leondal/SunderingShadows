#include <std.h>
#include "../elf.h"
inherit "/d/common/obj/clothing/hat";

void create(){
   ::create();
   set_name("%^RESET%^%^MAGENTA%^mourners's veil");
   set_id(({"veil","Veil","dark veil",
   "mourner's veil","dancers veil"}));
   set_short("%^RESET%^%^MAGENTA%^mourner's veil%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^dark veil%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This hair piece appears to be a veil.  "+
   "It sits in the wearer's hair and drapes down, covering the wearer's"+
   " entire head.  It is made of a translucent "+
   "silky material.  The weaving is done is such a way as "+
   "to allow it to not block out completely but only slightly"+
   " mask the hair and face of the wearer.  It is colored a"+
   " deep purple and seems to glow with magic.%^RESET%^");

   set_property("enchantment",4);
   set_value(1045);
   set_lore("Cerilana was one of two half-elven children "+
"that were born from an elven princess and a human noble"+
" in an attempt to stop the conflict between the humans"+
" and the elves.  Both of their parents were killed by "+
"assassins and the older brother raised the younger "+
"sister.  He also tried to stop the slaughter.  When "+
"left all alone the woman who had no place in either "+
"world was consumed with despair.  She was said to have"+
" wandered off into the wilds to search for her brother"+
" years into his absence  but was never seen from again. ");
   set_property("lore difficulty",34);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_item_bonus("negative energy resistance",15);
   set_item_bonus("mental energy resistance",-1);
   set_item_bonus("charisma",1);
}

int wear_fun(){

   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" drapes the veil across "+ETO->QP+
   "face, clouding "+ETO->QP+" features from view.",ETO);

   tell_object(ETO,"%^MAGENTA%^You drape the veil across your face."+
   "  Thoughts of sorrow fill your mind like a loved one has just died.");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" unattaches the veil and reveals "+ETO->QP+
  "face and hair.",ETO);
  tell_object(ETO,"%^MAGENTA%^You remove the veil and uncover your face and hair.");
  return 1;
}
