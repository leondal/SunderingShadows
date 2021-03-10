//2014-04-28 Ergo: Nerfed value to 300 from 1700 because of an increase in drop chance
#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
      set_name("jade snake armband");
//This needs to be "jade snake armband" for the Riddle Quest
        set_id(({"armband","jade armband"}));
        set_short("%^RESET%^%^GREEN%^J%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^d%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^armband%^RESET%^");
        set_long("%^BOLD%^%^GREEN%^This armband is made out of"
" finely crafted %^RESET%^%^GREEN%^jade %^BOLD%^%^GREEN%^that"
" has been formed into a %^RESET%^%^GREEN%^s%^ORANGE%^n%^BOLD%^"
"%^GREEN%^a%^RESET%^%^ORANGE%^k%^GREEN%^e %^BOLD%^%^GREEN%^"
"whose body coils around the wearers arm three times before ending"
" in a smooth, serpentine head that rests just above the bicep."
"  Two small %^RED%^rubies %^GREEN%^mark the eyes of this fantastic"
" and life-like piece of work.%^RESET%^\n");
        set_lore("%^GREEN%^It is said that this armband was "+
           "made by the yuan-ti clan that came"
           " to these planes some time ago.  The armband is a "+
           "status symbol and marks them as part of the clan of "
           "Ingzelth.");
        set_weight(2);
        set_value(300);
        set_type("ring");
        set_limbs(({"right arm"}));
        set_size(2);
        set_property("enchantment",0);
}
