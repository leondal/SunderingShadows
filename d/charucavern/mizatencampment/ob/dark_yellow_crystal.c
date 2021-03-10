#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("dark yellow crystal");
            
    set_id(({ "crystal", "dark yellow crystal", "yellow crystal" }));
            
    set_short("%^RESET%^%^YELLOW%^A dark yellow crystal%^RESET%^");
            
    set_long("%^RESET%^%^YELLOW%^This crystal is approximately a foot in length. "+
    "It is almost entirely cylindrical in appearance. It has various shades of "+
    "yellow throughout it, but most of them are quite dark. It appears very sturdy and "+
    "weighs much more than what you would think by simply observing it. There are "+
    "strange %^BOLD%^%^WHITE%^symbols%^RESET%^%^YELLOW%^ covering almost the "+
    "entire surface of it. The symbols make no sense and are in no "+
    "language that you ever encountered. In fact, you are unsure if they "+
    "ever had any meaning for anyone other than whoever put them there.%^RESET%^");
    
    set_property("lore difficulty", 14);
    
    set_lore("%^RESET%^%^YELLOW%^These crystals hail from the Mizat Encampment. "+
    "It is unknown where they originally came from but apparently they were "+
    "unearthed near a way-gate at the encampment. This particular crystal when "+
    "used to power the way-gate will take whoever enters it into a mysterious "+
    "cavern that those local to the encampment have taken to calling the '%^BOLD%^"+
    "%^CYAN%^Mystic Caves%^RESET%^%^YELLOW%^'.%^RESET%^");
    
    set_property("mizatwaygatepower", "mysticcaves");

	set_weight(10);
	set_value(5500);
}



