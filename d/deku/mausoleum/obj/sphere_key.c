#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("a smooth hollow sphere");
    set_id(({ "sphere", "hollow sphere", "smooth sphere", "empty sphere",
    "mausoleum_of_the_damned_sphere_keyxxx71"}));
    
    set_short("an empty hollow sphere");    
    
    set_long("%^BOLD%^%^CYAN%^This small sphere is completely smooth on the "+
    "outside. It seems quite thin and you are able to see through it, though "+
    "the material that composes it is slightly translucent. You are not sure "+
    "what purpose that it could have originally had, but it seems mundane now."+
    "%^RESET%^");
    
    set_lore("There are no rumors about this sphere, but you are able to "+
    "ascertain that it is most likely some type of key. You are not sure what "+
    "such an object would unlock though.");
    
    set_property("lore difficulty", 15);
    
    set_weight(1);
    set_value(0);
}

