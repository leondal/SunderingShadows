#include <std.h>
#include "../witchlair.h"
inherit OBJECT;

void create() {
 ::create();
 set_name("key");
 set_id(({"key","token","object","fetish","fetishkey"}));
 set_short("%^BOLD%^%^WHITE%^a strange m%^RESET%^e"
"%^BOLD%^%^BLACK%^t%^WHITE%^a%^RESET%^l%^BOLD%^-and-"
"%^RESET%^%^MAGENTA%^g%^BOLD%^%^MAGENTA%^e"
"%^RESET%^%^MAGENTA%^ms%^BOLD%^%^MAGENTA%^to"
"%^RESET%^%^MAGENTA%^ne %^BOLD%^%^WHITE%^fetish%^RESET%^");
 set_long("%^BOLD%^%^BLACK%^Shaped like a teardrop, the "
"object is four inches in length and quite heavy for its "
"size. It is made primarily of %^WHITE%^shining p%^RESET%^l"
"%^BOLD%^%^BLACK%^a%^WHITE%^t%^RESET%^i%^BOLD%^%^BLACK%^n"
"%^WHITE%^u%^RESET%^m%^BOLD%^%^BLACK%^, marbled with veins"
" and whorls of %^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^u"
"%^BLACK%^r%^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^l"
"%^RESET%^%^MAGENTA%^e ja%^BOLD%^%^BLACK%^s"
"%^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^e%^RESET%^"
"%^MAGENTA%^r%^BOLD%^%^BLACK%^. A faint %^GREEN%^gl"
"%^BLUE%^o%^GREEN%^w %^BLACK%^pulses through the jasper "
"segments erratically, much like a heart sending blood "
"throughout its body.%^RESET%^\n\n");
 set_weight(1);
 set_value(0);
}
