#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})
inherit "/d/common/obj/armour/hide";

void create()
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
	::create();    
	set_name("hide armor from a scaly creature");
	set_short(myCol+"A suit of hide armor%^RESET%^");
	set_id(({"hide","armor","hide armor","armour", "scaly hide", "scaled armor"}));
	set_long(
	myCol+"This armor has been prepared from the thick hide of some scaly creature. "+
    "The exact nature of the creature is unknown, but there are bumps and bulbuous extrusions "+
    "all over it. It looks as if it has been double layered in order to offer more protection "+
    "and has undergone some type of tanning technique that has caused it to harden and "+
    "maintain its form.%^RESET%^");
	set_value(0);
}

int is_metal() { return 0; }