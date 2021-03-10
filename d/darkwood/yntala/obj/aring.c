#include <std.h>
inherit "/d/deku/armours/ring_p.c";

void create(){
::create();

        set_name("aquamarine ring of protection");
        set_id(({"ring","aquamarine ring","ring of protection"}));
        set_obvious_short("%^BOLD%^%^CYAN%^An aquamarine ring%^RESET%^");
      set_short("%^BOLD%^%^CYAN%^An %^RESET%^%^CYAN%^a%^GREEN%^q%^CYAN%^ua%^GREEN%^m%^CYAN%^ar%^GREEN%^i%^CYAN%^ne %^GREEN%^r%^CYAN%^i%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^g %^BOLD%^%^CYAN%^of protection%^RESET%^");
        set_long("%^RESET%^This little ring is made out of"
" %^BOLD%^%^WHITE%^s%^RESET%^h%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^"
"mm%^RESET%^e%^RESET%^r%^BOLD%^%^CYAN%^i%^RESET%^n%^BOLD%^"
"%^WHITE%^g %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^"
"%^WHITE%^ti%^RESET%^n%^BOLD%^%^BLACK%^u%^RESET%^m.  The crest"
" is inlaid with a large %^BOLD%^%^CYAN%^aquamarine %^RESET%^"
"whose %^BOLD%^%^WHITE%^magical %^RESET%^appearance seems to"
" constantly %^RESET%^change shape as though it were composed of"
" nothing but %^BOLD%^%^CYAN%^f%^RESET%^%^CYAN%^l%^RESET%^o"
"%^BOLD%^%^WHITE%^w%^RESET%^i%^CYAN%^n%^BOLD%^%^CYAN%^g %^BOLD%^"
"%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r."
"%^RESET%^\n");
      set_property("enchantment",random(2));
   set_wear((:TO,"do_wear":));
}

void init() {
   ::init();
   set_wear((:TO,"do_wear":));
}
