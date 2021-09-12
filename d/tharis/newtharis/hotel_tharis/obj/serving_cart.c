// Chernobog (1/25/21)
// Tonovi Hotel

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"cart","serving cart","servingcart"}));
	set_name("serving cart");
	set_short("%^BOLD%^%^BLACK%^A c%^RESET%^o%^BOLD%^ver%^RESET%^e%^BOLD%^%^BLACK%^d "+
        "serving %^RESET%^%^ORANGE%^cart%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This two-tiered %^ORANGE%^cart %^CYAN%^is overflowing "+
        "with various %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^ver%^RESET%^e%^BOLD%^%^BLACK%^"+
        "d d%^RESET%^i%^BOLD%^sh%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^. "+
        "%^MAGENTA%^E%^BOLD%^n%^RESET%^%^MAGENTA%^t%^BOLD%^i%^WHITE%^c%^MAGENTA%^i"+
        "%^RESET%^%^MAGENTA%^n%^BOLD%^g %^RESET%^%^CYAN%^smells hint at all the "+
        "offerings prepared and ready, with a %^BOLD%^menu %^RESET%^%^CYAN%^displayed "+
        "at one corner listing everything available.%^RESET%^");
	set_weight(1000000);
	set_value(0);
	set_property("no animate",1);
}

