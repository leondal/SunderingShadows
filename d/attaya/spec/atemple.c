#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
    ::create();
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^RESET%^%^BOLD%^%^BLACK%^A%^WHITE%^ncient %^BLACK%^Temp%^WHITE%^l%^BLACK%^e%^RESET%^%^BOLD%^%^BLACK%^ of the %^BOLD%^%^WHITE%^K%^BLACK%^in%^WHITE%^n%^BLACK%^esaruda%^RESET%^%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^A%^WHITE%^ncient %^BLACK%^Temp%^WHITE%^l%^BLACK%^e%^RESET%^%^BOLD%^%^BLACK%^ of the %^BOLD%^%^WHITE%^K%^BLACK%^in%^WHITE%^n%^BLACK%^esaruda%^RESET%^%^BOLD%^%^BLACK%^
");
    set_property("no teleport",1);
    set_climate("mountain");
    set_listen("default", "Screams echo through this hall");    
}

