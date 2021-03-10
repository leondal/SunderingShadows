#include <std.h>
inherit "/d/common/obj/armour/leather_plate.c";

#define COLORS ({"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^ORANGE%^orange%^RESET%^",\
"%^YELLOW%^yellow%^RESET%^",\
"%^RED%^red%^RESET%^",\
"%^GREEN%^green%^RESET%^",\
"%^BOLD%^%^BLUE%^blue%^RESET%^",\
"%^BOLD%^%^MAGENTA%^pink%^RESET%^",\
"%^MAGENTA%^purple%^RESET%^",\
"%^RESET%^gray%^RESET%^",\
"%^BOLD%^%^CYAN%^light blue%^RESET%^"})
void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
   	set_short("%^RESET%^%^CYAN%^A %^RESET%^"+COLOR+" %^CYAN%^leather breastplate%^RESET%^");
     	set_long("%^CYAN%^This breastplate is made of tanned leather that is still "+
       "rather supple and fits close to the wearer's body, moving with "+
       "him.  For added protection, metal rivets, dyed "+COLOR+" %^CYAN%^to match the "+
       ""+COLOR+" %^CYAN%^leather, have been added at intervals so as not to hamper "+
       "movement.  The breastplate is often a prime choice for "+
       "those concerned with appearances who do not like to be "+
       "seen in a full suit of armor.%^RESET%^\n");
	set_property("enchantment",1);
	set_value(130);
}
