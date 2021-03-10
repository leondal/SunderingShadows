#include <std.h>
inherit OBJECT;

void create()
{
        ::create();
        set_name("%^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s%^RESET%^");
        set_id(({"wildflowers","flowers","bouquet"}));
        set_short("%^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s%^RESET%^");
        set_long("%^RESET%^%^GREEN%^This is a lovely %^BOLD%^%^GREEN%^bouquet %^RESET%^%^GREEN%^of %^BOLD%^%^GREEN%^fresh %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^RESET%^%^GREEN%^consisting of all the %^BOLD%^%^CYAN%^b%^YELLOW%^r%^WHITE%^ig%^YELLOW%^h%^CYAN%^t %^RESET%^%^GREEN%^colors of %^YELLOW%^ye%^RESET%^%^ORANGE%^ll%^YELLOW%^ow d%^RESET%^%^ORANGE%^a%^YELLOW%^i%^RESET%^%^ORANGE%^s%^YELLOW%^i%^RESET%^%^ORANGE%^e%^YELLOW%^s, %^BLUE%^b%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e f%^CYAN%^o%^BOLD%^%^CYAN%^r%^BLUE%^g%^RESET%^%^CYAN%^e%^BLUE%^t-%^BOLD%^%^BLUE%^me-%^RESET%^%^BLUE%^n%^BOLD%^%^CYAN%^o%^BLUE%^t%^RESET%^%^CYAN%^s, %^RESET%^%^GREEN%^%^and %^RED%^wild %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^%^RED%^r%^BOLD%^%^RED%^o%^RESET%^%^MAGENTA%^s%^BOLD%^%^RED%^e%^RESET%^%^RED%^s, %^GREEN%^with %^BOLD%^%^GREEN%^green i%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y %^RESET%^%^GREEN%^%^lacing through it all%^RESET%^.");
        set_weight(1);
        set_value(20);
        set_cointype("silver");
}