#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/clothing/breeches";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("pair of breeches");
    set_id(({ "breeches", "strange breeches", "thick breeches", "pants" }));
    set_short(myCol+"A pair of thick breeches%^RESET%^");
    set_long(myCol+"These long and loose breeches are sewn from a thick and "+
    "unknown fabric. They are quite thick and appear to be several layers thick, "+
    "possible to confer some protection from the elements. There are reinforced "+
    "stitches through all of their seams, as if the crafter attempted to make sure "+
    "they would last for as long as possible.%^RESET%^");    
    set_value(0);
}
