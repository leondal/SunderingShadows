#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	
	set_weight(0);
	set_value(100);
}

void set_my_type(string str, string MC) 
{
    if(!objectp(TO)) return;
    if(!stringp(str)) TO->remove();
    if(!stringp(MC)) MC = "%^BOLD%^%^RED%^";
    switch(random(2))
    {
        case 0:
            set_name("a tiny "+str+" rune fragment");
            
            set_id(({ "fragment", "rune fragment", str+" rune fragment", 
            str+" fragment", "saiderunefragment"+str, "mizatseekingshard" }));
            
            set_short(MC+"fragment of a "+str+" rune%^RESET%^");
            
            set_long(MC+"This is a tiny fragment from a "+str+" rune. "+
            "It is small enough to hold in the palm of your hand easily now. It still "+
            "gives off a slight aura but you suspect that is worth very little to most. "+
            "However, perhaps there is someone who might be interested in it.%^RESET%^");
            set_property("max mizat value", 1000);
            break;
        case 1:
            set_name("a sliver of a "+str+ " rune");
            
            set_id(({"sliver", "rune sliver", str+" rune sliver", 
            str+" sliver", "saiderunefragment"+str, "mizatseekingshard"}));
    
            set_short(MC+"sliver of a "+str+" rune%^RESET%^");
            
            set_long(MC+"This is a tiny sliver of a "+str+" rune. "+
            "It is small enough to hold in the palm of your hand easily now. It still "+
            "gives off a slight aura but you suspect that is worth very little to most. "+
            "However, perhaps there is someone who might be interested in it.%^RESET%^");
            set_property("max mizat value", 1000);
            break;
    }
    
}

