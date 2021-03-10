#include <std.h>

inherit "/d/common/obj/weapon/longsword";

void create(){
   ::create();
   set_name("stag beetle antler");
   set_id(({"antler","beetle antler","stag beetle antler","sword","long sword","longsword"}));
   set_short("%^RESET%^%^ORANGE%^stag beetle antler%^RESET%^");
   set_long("%^ORANGE%^This unusual weapon seems crafted straight from "+
      "the body part of an insect!  It is the length and general "+
      "shape of a longsword, and its balance makes it almost "+
      "as easy to use.  The hilt of the weapon is made from the "+
      "joint where it attached to the body, while the blade has "+
      "been left with the naturally sharp, somewhat jagged edge.%^RESET%^");
   set_lore("This particular sword was taken from the mandible "+
      "of a giant stag beetle.  Judging from the size of the "+
      "sword, the insect must have been enormous!  You "+
      "recall having heard that giant insects had been reported "+
      "in the Ekibi Caverns near the meadowlands.");
   set_value(18);
   set_hit((:TO,"hitme":));
}

int hitme(object targ){
   if(!random(15)){
      tell_object(ETO,"%^ORANGE%^You draw back the blade, "+
         "tearing "+targ->QCN+"'s flesh with the serrated "+
         "edge!");
      tell_object(targ,"%^ORANGE%^You hear a hiss as "+ETOQCN+" "+
         "draws back "+ETO->QP+" blade, tearing your flesh "+
         "with the serrated edge!");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" draws back the blade, "+
         "tearing "+targ->QCN+"'s flesh with the serrated "+
         "edge!",({ETO,targ}));
      return random(3)+1;
   }
   return 1;
}