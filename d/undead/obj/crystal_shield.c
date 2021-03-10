//updated by Circe 5/24/04
#include <std.h>
#include "../undead.h"

inherit CARMOR"shield";
int is_metal() { return 0; }
void create() 
{
    ::create();
    set_name("Crystalline Shield");
    set_id(({"shield","crystaline shield","crystalline shield","crystal shield"}));
    set_obvious_short("A shield of crystal");
    set_short("%^BOLD%^%^WHITE%^Crystalline Shield%^RESET%^");
    
    set_long("%^BOLD%^This is a shield that has been made out of "+
        "a flawless crystal, buffed and polished to a high shine.  "+
        "It is so reflective, you can literally see yourself in "+
        "its surface.  There are no facets, and the face of the "+
        "shield is completely smooth.  Two white leather straps "+
        "have been fitted to the back, allowing the shield to be "+
        "worn on one arm.  It is truly a work of art.");
      
    set_lore("Crystalline shields were once in fashion within the "+
        "courts of many lands.  Noble lords wore such shields as "+
        "they jousted, fancying the way the sunlight "+
        "glinted off of them and dazzled the ladies.  Sages believe "+
        "such shields have a much more pertinent purpose, however..."+
        "they speculate that such a shield could perhaps save "+
        "the wearer from a gaze attack.");

    set_property("lore difficulty",12);
    set_value(1500);
    set_property("enchantment", 3);
}
