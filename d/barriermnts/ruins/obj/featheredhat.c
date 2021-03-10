#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("feathered hat");
   set_id(({"Hat","hat","feathered hat"}));
   set_short("%^BLUE%^%^BOLD%^f%^RESET%^%^BLUE%^ea%^BOLD%^th%^RESET%^%^BLUE%^er%^BOLD%^ed %^RESET%^%^BLUE%^ha%^BOLD%^t%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^long-feathered hat%^RESET%^");
   set_long("%^GREEN%^This flamboyant hat is made of some sort of %^ORANGE%^pale, tanned "
"leather%^GREEN%^, with a cap portion to cover the head and a wide brim to shade the wearer's face.  At "
"the back, one section of the brim has been folded up over itself, and a long "
"%^BLUE%^%^BOLD%^sapphire-blue%^RESET%^%^GREEN%^ feather has been stuck onto one side.  Underneath, the "
"cap-like portion of the hat is lined with %^BLACK%^%^BOLD%^thicker leather%^RESET%^%^GREEN%^, which "
"would obviously protect the head far better than a normal hat.%^RESET%^\n");
   set_type("leather");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(2);
   set_property("enchantment",2);
   set_weight(4);
   set_value(80);
   set_lore("%^WHITE%^%^BOLD%^This could be anyone's hat really, but a story comes to your mind of a "
"rogue known only to history as Eylean.  Many stories tell of the rogue who was recognizable by his "
"distinctive hat, though the stories fade at a certain point; noone seems to know what happened to "
"him.%^RESET%^\n");
   set_property("lore difficulty",15);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
}

int wear_fun(){
   tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETO->QCN+" sets the feathered hat upon "+ETO->QP+" head, and tilts "
"it to one side.%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^%^BOLD%^You set the feathered hat upon your head, and tilt it to one "
"side.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" removes "+ETO->QP+" feathered hat with a "
"flourish.%^RESET%^",ETO);
  tell_object(ETO,"%^BLUE%^%^BOLD%^You remove the feathered hat with a flourish.%^RESET%^");
  return 1;
}
