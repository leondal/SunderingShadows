#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
   ::create();
   set_name("Andaven's Eyepatch");
   set_id(({"eyepatch","patch", "andavens eyepatch","black eyepatch","eye"}));
   set_short("%^BOLD%^%^BLACK%^A%^BLUE%^n%^BLACK%^da%^BLUE%^v%^BLACK%^en's E%^BLUE%^y%^BLACK%^e%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A f%^RED%^i%^BLACK%^ne s%^YELLOW%^i%^BLACK%^lk%^YELLOW%^e%^BLACK%^n bla%^BLUE%^c%^BLACK%^k e%^BLUE%^"
   "y%^BLACK%^epa%^BLUE%^t%^BLACK%^ch%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This small %^BOLD%^%^MAGENTA%^ov%^CYAN%^a%^MAGENTA%^l%^BOLD%^%^BLACK%^ cloth is the perfect size for covering a human %^RESET%^%^RED%^eye"
   "%^BOLD%^%^BLACK%^. It is masterfully crafted from bla%^BLUE%^c%^BLACK%^k s%^YELLOW%^i%^BLACK%^lk with s%^RESET%^i%^BOLD%^%^BLACK%^lv"
   "%^RESET%^e%^BOLD%^%^BLACK%^r and %^RED%^red%^BLACK%^ stitching. The stitching is %^YELLOW%^%^magnificent%^BLACK%^"
   " in %^RESET%^%^MAGENTA%^design%^BOLD%^%^BLACK%^, which resembles"
   " an %^RESET%^%^RED%^e%^BOLD%^%^RED%^a%^RESET%^%^RED%^g%^BOLD%^%^RED%^l%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^w%^YELLOW%^i"
   "%^BOLD%^%^BLACK%^ng.\n");
   set_lore("%^BOLD%^%^BLACK%^Somewhere on a distant plane lies a house of Aasimar whose founder Andaven TanVell"
   " lost his sight in a war against a tiefling noble house. The house was on a downward spiral when the house mage"
   " was able to return partial sight to its leader through a magical eye patch. The house warriors all wear copies"
   " of this eye-patch, none having the magical abilities of the original, but still quite useful. This appears to be"
   " a copy, because the original is known to offer sight into different %^BOLD%^%^WHITE%^planes of existence%^BLACK%^.%^RESET%^\n");
   set_property("lore difficulty",30);
   set_size(2);
   set_value(5000);
   set_property("enchantment",4);
   set_item_bonus("wisdom",3);
   set_item_bonus("intelligence",3);
   set_item_bonus("sight bonus",3);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}


int check() {
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes start to shi%^BLUE%^mm%^BLACK%^er when "+ETO->QS+" places "+TO->query_short()+" %^BOLD%^BLACK%^over one of them.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You can see further and better than moments ago.%^RESET%^");
   ETO->add_temporary_feat("blindfight");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes quit shi%^BLUE%^mm%^BLACK%^ering when "+ETO->QS+" removes "+TO->query_short()+".%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The colors don't look as vibrant nor can you see as far.%^RESET%^");
   ETO->remove_temporary_feat("blindfight");
   return 1;
}
