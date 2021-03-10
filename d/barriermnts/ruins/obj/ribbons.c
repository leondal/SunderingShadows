#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("ribbons");
   set_short("%^RESET%^%^CYAN%^si%^BLUE%^lke%^MAGENTA%^n ha%^CYAN%^ir r%^BLUE%^ibb%^MAGENTA%^ons%^RESET%^");
   set_id(({"ribbons","hair ribbons","silken ribbons","silken hair ribbons","silk ribbons"}));
   set_long("%^WHITE%^%^BOLD%^These are nothing more than slender strands of silk, of various lengths "
"and dyed a variety of %^RESET%^%^CYAN%^co%^BLUE%^lou%^MAGENTA%^rs%^WHITE%^%^BOLD%^.  They can be used "
"to tie back long hair, though they really aren't much more than ornamental.%^RESET%^\n");
   set_weight(1);
   set_value(20);
   set_ac(0);
   set_type("ring");
   set_limbs(({"head"}));
   set_lore("%^WHITE%^%^BOLD%^Ribbons such as these are commonplace hair decorations worn by women of "
"all ages, made from cloth of all types.  They can be worn for merely appearances, or for the more "
"constructive purpose of holding long hair away from the face.%^RESET%^");
   set_property("lore difficulty",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^CYAN%^You tie your hair back with the silken ribbons.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" ties "+ETO->QP+" hair back with the silken "
"ribbons.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^CYAN%^You pull the ribbons out, letting your hair fall free.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" slips the ribbons out of "+ETO->QP+" hair.%^RESET%^",ETO);
   return 1;
}
