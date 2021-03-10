#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("bright pink crystal");
            
    set_id(({ "crystal", "bright pink crystal", "pink crystal" }));
            
    set_short("%^BOLD%^%^MAGENTA%^A bright pink crystal%^RESET%^");
            
    set_long("%^BOLD%^%^MAGENTA%^This crystal is approximately a foot in length. "+
    "It is almost entirely cylindrical in appearance. There are some darker "+
    "specks of %^RESET%^%^MAGENTA%^pink%^BOLD%^%^MAGENTA%^ throughout it but "+
    "mostly it is a brilliant and almost blinding hue. It weighs more than you "+
    "would anticipate by just looking at it and seems sturdy enough that dropping "+
    "it would likely do no major damage.%^RESET%^");
    
    set_property("lore difficulty", 10);
    
    set_lore("%^BOLD%^%^MAGENTA%^This crystal was created by one of the Crystal Merchants at the "+
    "Mizat Encampment in order to allow much quicker trips to the surface. "+
    "Whenever used to power the way-gate at the encampment this crystal will take "+
    "whoever enters it up to the Charu Mountains, very quickly.%^RESET%^");
    
    set_property("mizatwaygatepower", "surface");

	set_weight(4);
	set_value(2500);
}



