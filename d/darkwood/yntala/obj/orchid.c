#include <std.h>
inherit OBJECT;

void create()
{
        ::create();
        set_name("%^GREEN%^wild %^MAGENTA%^or%^BOLD%^c%^RESET%^%^MAGENTA%^h%^BOLD%^i%^RESET%^%^MAGENTA%^d%^RESET%^");
        set_id(({"wild orchid","flower","orchid"}));
        set_short("%^RESET%^%^GREEN%^A large wild %^MAGENTA%^or%^BOLD%^c%^RESET%^%^MAGENTA%^h%^BOLD%^i%^RESET%^%^MAGENTA%^d%^RESET%^");
        set_long("%^RESET%^%^MAGENTA%^This large, wild %^BOLD%^orchid %^RESET%^%^MAGENTA%^is a deep purple in color with a slightly lighter colored tongue.  It's delicate petals emit a wonderful aroma. %^RESET%^");
        set_weight(1);
        set_value(20);
        set_cointype("silver");
}