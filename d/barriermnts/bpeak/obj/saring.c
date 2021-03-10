#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^%^BLUE%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^%^CYAN%^e ring%^RESET%^");
   set_id(({"ring","sapphire ring"}));
   set_short("%^YELLOW%^A golden %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^%^BLUE%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^%^CYAN%^e %^YELLOW%^ring%^RESET%^");
   set_long("This small ring is designed with many small %^YELLOW%^g%^RESET%^"
"%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n threads%^RESET%^"
" looped around one another, creating a pattern of %^MAGENTA%^delicate"
" %^GREEN%^vines %^RESET%^that wrap around the wearers finger.  The"
" %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n"
" %^RESET%^%^GREEN%^vines %^RESET%^then reach up and spread into %^GREEN%^leaves"
" %^RESET%^that hold a %^YELLOW%^brilliant %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^a"
"%^BLUE%^p%^BOLD%^%^BLUE%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^%^CYAN%^e"
" %^RESET%^whose color resembles that of the %^BLUE%^depthless"
" %^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^e%^CYAN%^a."
"%^RESET%^\n");
   set_weight(2);
   set_value(1700);
   set_type("ring");
   set_limbs(({"right hand"}));
   set_size(2);
   set_property("enchantment",0);
   set_ac(0);
}
