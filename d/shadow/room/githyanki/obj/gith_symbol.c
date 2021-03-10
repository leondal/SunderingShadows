//Githyanki Holy Symbol - Githyanki Fortress - LoKi - 07-02-2008

#include <std.h>
#include "../githyanki.h"
inherit OBJECT;

void create(){
    ::create();
    set_name("gith symbol");
    set_id(({"symbol","githyanki symbol","gith symbol","medallion","black medallion","small black medallion"}));
    set_short("%^BLACK%^%^BOLD%^small black medallion%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^This symbol has been cra"+
"fted from %^RESET%^%^WHITE%^iron%^RESET%^%^BOLD%^%^BLACK%^. It "+
"hangs from a thin chain and is decorated with a symbol of a %^RESET%^"+
"%^MAGENTA%^f%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ve hea"+
"%^RESET%^%^WHITE%^d%^RESET%^%^MAGENTA%^ed d%^RESET%^%^WHITE%^r%^RESET%^"+
"%^MAGENTA%^ag%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^n%^RESET%^"+
"%^BOLD%^%^BLACK%^. It glows with an almost malign light%^RESET%^");
    set_weight(2);
    set_value(50);
}










