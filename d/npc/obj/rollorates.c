#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"rate sheet"}) );
    set_name("rate sheet");
    set("short", "rate sheet");
    set_long(
@THORN
%^CYAN%^Tailor services rendered by Rollo Taylor, master tailor.
%^RESET%^
%^RED%^BOLD%^alter %^RESET%^<item>.......%^BOLD%^10%^RESET%^ gold per size
%^RED%^BOLD%^design %^RESET%^<item>......%^BOLD%^100%^RESET%^ gold base + price of item to be customized

Since designing a custom piece of clothing requires the best materials,
Master Taylor insists that he only work with items he sells.  These 
items can be dyed and embroidered to your order!

robe...............%^BOLD%^15%^RESET%^ gold    banner.............%^BOLD%^5%^RESET%^ gold
cloak..............%^BOLD%^10%^RESET%^ gold    tabard.............%^BOLD%^10%^RESET%^ gold
silk robe..........%^BOLD%^150%^RESET%^ gold   silk cloak.........%^BOLD%^100%^RESET%^ gold

%^BOLD%^YELLOW%^Quality is our catchword!%^RESET%^
THORN
    );
    set_weight(0);
    set_value(0);
}

