#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/misc/pouch";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("strange corded belt");
    set_id(({ "belt","corded belt", "strange corded belt"}));
    set_short(myCol+"A strange corded belt%^RESET%^");
    set_long(myCol+"This belt is made from a strange fabric, the "+
    "exact nature of which you are not able to determine. There are several "+
    "strands of the fabric that have been woven together tightly to create the "+
    "appearance of a braid. You realize that it has a small pocket in between "+
    "some of the strands of fabric. The opening of the pocket faces the inside and "+
    "you are unsure of how much could actually fit inside of it.%^RESET%^");
    set_value(0);
}
