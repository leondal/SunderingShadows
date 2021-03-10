#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("armband");
        set_id(({"armband","ruby armband"}));
        set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^armband%^RESET%^");
        set_long("%^BOLD%^%^RED%^This beautiful armband is crafted out of dazzling"
" rubies.  All the rubies are large and exquistely cut to maximize the reflection"
" of light.  A platinum setting holds each of the gems in place and links them"
" together in a gentle chain that wraps around the wearers upper arm a total of"
" three times.  Two long platinum strands drop three inches from the top of the"
" armband and end in two silver hands that each clasp a large ruby cut in a"
" teardrop shape.%^RESET%^\n");
        set_weight(2);
        set_value(1700);
        set_type("ring");
        set_limbs(({"right arm"}));
        set_size(2);
        set_property("enchantment",0);
}
