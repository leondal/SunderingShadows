//coded by ~Circe~ 4/6/05
#include <std.h>

inherit "/d/common/obj/weapon/battle_axe";

void create(){
   ::create();
   set_name("woodsman's axe");
   set_id(({"axe","woodsmans's axe","weathered axe","wood axe"}));
   set_obvious_short("weathered wood axe");
   set_short("%^RESET%^%^ORANGE%^Woodsman's Axe%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This weathered axe features "+
      "a single wedge-shaped head perfect for splitting wood, "+
      "though it could likely split armor just as easily.  "+
      "The axe head was once well-oiled and still holds a "+
      "biting edge.  The handle is made of stout oak reinforced "+
      "in a few places with iron bands somehow kept free of "+
      "rust.%^RESET%^");
   set_lore("Although it was once just a normal woodsman's tool, "+
      "this particular axe was enchanted by a member of the "+
      "Gnomish Experimentors' League, evident by the rune "+
      "burned into the butt of the axe.  Your studies show "+
      "that the axe was meant to chop wood on its own, though "+
      "the enchantment seems somewhat fitful.  It might perhaps "+
      "work occasionally, but not often enough to depend upon.");
   set_value(25);
   set_property("enchantment",random(2));
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hitme":));
}

int wieldme(){
   tell_object(ETO,"%^YELLOW%^You feel a bit like a woodsman "+
      "as you heft the axe, finding it heavier than you expected.");
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" looks strangely like "+
      "a woodsman as "+ETO->QS+" lifts the axe.",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(targ)) return 1;
   if(!objectp(ETO)) return 1;
   if(!random(11)){
      tell_object(ETO,"%^ORANGE%^The axe suddenly seems to have "+
         "a life of its own, striking out at "+targ->QCN+" "+
         "uncontrollably!");
      tell_object(targ,"%^ORANGE%^"+ETOQCN+" looks shocked as "+
         ""+ETO->QS+" tries to control the axe while its "+
         "keen edge bites into your flesh!");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" looks shocked as "+
         ""+ETO->QS+" tries to control the axe while its "+
         "keen edge bites into "+targ->QCN+"'s flesh!",({ETO,targ}));
      return roll_dice(1,8);
   }
}