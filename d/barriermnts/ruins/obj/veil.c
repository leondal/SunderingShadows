#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("dancer's veil");
   set_id(({"veil","Veil","silken veil","translucent veil","dancer's veil","dancers veil"}));
   set_short("%^RESET%^%^MAGENTA%^da%^BOLD%^n%^RESET%^%^MAGENTA%^ce%^BLUE%^%^BOLD%^r%^RESET%^%^MAGENTA%^'s v%^CYAN%^e%^MAGENTA%^il%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^translucent veil%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^Sheer layers of silk form this semi-transparent veil, in soft pastel "
"shades of %^RESET%^%^CYAN%^cyan%^WHITE%^%^BOLD%^, %^RESET%^%^MAGENTA%^violet%^WHITE%^%^BOLD%^ and "
"%^BLUE%^blue%^WHITE%^.  It is designed to be worn across the lower face, concealing much of the "
"wearer's features, but leaving their eyes clearly visible.  Delicate, paper-thin tear-droplets of "
"%^ORANGE%^gold%^WHITE%^ run along the lower edge of the cloth, and matching %^ORANGE%^golden "
"beads%^WHITE%^ have been attached to each end of the veil, able to be linked together to hold the "
"garment upon the back of the wearer's head.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(2);
   set_property("enchantment",3);
   set_weight(2);
   set_value(1045);
   set_lore("%^WHITE%^%^BOLD%^Veils such as this are commonly worn by women of the Tsarven Empire.  This "
"particularly designed veil, however, was worn by the Selunite bardess Rhiannon, who was quite well "
"known for being far more capable than her demure appearance suggested.%^RESET%^\n");
   set_property("lore difficulty",14);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 17) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this item!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The veil doesn't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" drapes the veil across "+ETO->QP+" lower face, hiding much of "
+ETO->QP+" features from view.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^You drape the veil across your lower face and attach it carefully.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^CYAN%^"+ETOQCN+" unattaches the veil and reveals "+ETO->QP+" face.%^RESET%^",ETO);
  tell_object(ETO,"%^CYAN%^You unattach the veil and uncover your face.%^RESET%^");
  return 1;
}
