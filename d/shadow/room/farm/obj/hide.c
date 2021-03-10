#include <std.h>
inherit "/d/common/obj/armour/hide.c";

#define COLORS ({"%^BOLD%^%^BLACK%^wolf%^RESET%^",\
"%^YELLOW%^sp%^RESET%^%^ORANGE%^o%^BOLD%^tted lion%^RESET%^",\
"%^ORANGE%^ch%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^et%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^h%^RESET%^",\
"%^RED%^boar%^RESET%^",\
"%^GREEN%^weasel%^RESET%^",\
"%^BOLD%^%^RED%^salamander%^RESET%^",\
"%^BOLD%^%^GREEN%^frog%^RESET%^",\
"%^RED%^blood hawk%^RESET%^",\
"%^BOLD%^%^BLUE%^newt%^RESET%^",\
"%^BOLD%^%^GREEN%^lizard%^RESET%^",\
"%^ORANGE%^antelope%^RESET%^",\
"%^BLUE%^hyena%^RESET%^",\
"%^BLUE%^bear%^RESET%^",\
"%^YELLOW%^osquip%^RESET%^",\
"%^GREEN%^muskrat%^RESET%^",\
"%^YELLOW%^blink dog%^RESET%^",\
"%^RED%^peryton%^RESET%^"})
void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
      set_id(({"hide","breastplate","hide breastplate","armor","armour"}));
   	set_short("%^BOLD%^%^WHITE%^A %^RESET%^"+COLOR+" %^BOLD%^%^WHITE%^hide breastplate%^RESET%^");
     	set_long("%^BOLD%^This breastplate has been prepared from the"+
		" thick hide of a%^RESET%^ "+COLOR+"%^BOLD%^%^WHITE%^ and"+
        " has been double layered for protection.  The hide has been boiled to"+
        " toughen it, which also makes it stiff and harder to move in. %^RESET%^\n");
	set_property("enchantment",1);
	set_value(150);
}
