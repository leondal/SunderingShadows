#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("scarlet wimple");
   set_id(({"shroud","wimple","scarlet wimple","layered wimple","layered scarlet wimple","shroud of the scarlet rose","Shroud of the Scarlet Rose"}));
   set_short("%^RESET%^%^GREEN%^Shroud of the %^BOLD%^%^RED%^Sc%^RESET%^%^RED%^a%^BOLD%^rl%^RESET%^%^RED%^e%^BOLD%^t %^RESET%^%^GREEN%^Rose%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^a layered sc%^BOLD%^ar%^RESET%^%^RED%^let wimple%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This wimple is much like a hood, designed to lie in layers about the wearer's "
"face and neck, and trail a short length down the back, leaving the face open to view.  The garment is made "
"from many folds of %^MAGENTA%^br%^RED%^oc%^MAGENTA%^ade silk %^GREEN%^in rich %^BOLD%^%^RED%^crim%^RESET%^"
"%^RED%^so%^BOLD%^n %^RESET%^%^GREEN%^hues, set about the face in thick opaque layers.  The remaining length "
"trails over the hair in %^CYAN%^translucent %^GREEN%^folds to allow limited visibility of the hairstyle "
"beneath.  The cloth itself is of a transparent silk base, dyed a deep shade of scarlet, and is patterned "
"entirely by raised, interwoven images of %^RED%^blossoming r%^BOLD%^o%^RESET%^%^RED%^ses %^GREEN%^with "
"verdant %^BOLD%^lea%^YELLOW%^v%^GREEN%^es %^RESET%^%^GREEN%^encircling their petals.  It is a very beautiful "
"piece, and probably designed by a master crafter, as anyone less skilled would surely ruin such %^MAGENTA%^"
"exquisite %^GREEN%^cloth as they worked.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("spell damage resistance",15);
   set_weight(2);
   set_value(0);
   set_lore("%^WHITE%^%^BOLD%^Wimples are generally only worn by women, particularly those of wealth and "
"status.  They come in many varieties, often set in elaborate folds, or supported by wire or wicker frames.  "
"Originally created to hide a woman's hair from view, later versions have evolved in a more 'fashionable' "
"designs commonly sewn with transparent silks or gauze, so as to better show off the ornate hairstyles often "
"favored by rich and affluent women.  The more austere styles are also prized among several priesthoods, "
"including that of Sune, for whom it is considered part of their ceremonial garb.%^RESET%^\n");
   set_property("lore difficulty",15);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun(){
   tell_room(EETO,"%^RED%^The wimple settles in soft layers around "+ETO->QCN+"'s face.%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^The wimple settles in comfortable layers around your face.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^RED%^"+ETOQCN+" unfolds the wimple from around "+ETO->QP+" face.%^RESET%^",ETO);
  tell_object(ETO,"%^RED%^You carefully remove the wimple's folds from around your face.%^RESET%^");
  return 1;
}