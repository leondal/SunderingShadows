// Chernobog (6/3/21)
// Random Quills

#include <std.h>
inherit OBJECT;

#define FEATHERS ({"%^BOLD%^%^BLACK%^rav%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^RESET%^w%^ORANGE%^l%^WHITE%^",\
"%^BOLD%^%^BLUE%^b%^BLACK%^l%^BLUE%^ue%^WHITE%^j%^BLUE%^a%^WHITE%^y%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^RESET%^s%^BOLD%^%^BLACK%^t%^WHITE%^r%^RESET%^i%^BOLD%^c%^RESET%^h",\
"%^BOLD%^%^BLUE%^p%^CYAN%^e%^GREEN%^a%^RESET%^%^GREEN%^c%^BOLD%^o%^ORANGE%^c%^GREEN%^k%^RESET%^",\
"%^BOLD%^%^RED%^c%^WHITE%^a%^RED%^rd%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^a%^BOLD%^l%^RESET%^",\
"%^RESET%^%^ORANGE%^t%^BOLD%^%^RED%^u%^RESET%^%^ORANGE%^r%^BOLD%^k%^BLACK%^e%^ORANGE%^y%^RESET%^",\
"%^RESET%^%^ORANGE%^e%^BOLD%^a%^RESET%^%^ORANGE%^g%^BOLD%^l%^WHITE%^e%^RESET%^",\
"%^BOLD%^%^WHITE%^d%^BLACK%^o%^WHITE%^v%^RESET%^e",\
"%^RESET%^%^RED%^h%^BOLD%^um%^GREEN%^m%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^n%^GREEN%^g%^RESET%^%^GREEN%^b%^BOLD%^i%^RESET%^%^GREEN%^r%^BOLD%^d%^RESET%^"})

void create(){
    string feather;
    ::create();
    feather = FEATHERS[random(sizeof(FEATHERS))];
    set_name("quill");
    set_id(({"quill","writing quill",""+feather+" quill"}));
    set_short("%^RESET%^%^CYAN%^A "+feather+"%^RESET%^%^CYAN%^-feather writing quill%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This is a feather from a "+feather+"%^RESET%^%^CYAN%^, affixed with a channeled %^BOLD%^%^WHITE%^m%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^l %^RESET%^t%^BOLD%^%^BLACK%^i%^RESET%^p %^CYAN%^for use in calligraphy.%^WHITE%^");
    set_weight(1);
    set_value(100);
    set_item_bonus("academics",1);
}

