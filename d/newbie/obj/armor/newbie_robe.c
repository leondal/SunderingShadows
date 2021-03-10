#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})
inherit "/d/common/obj/clothing/magerobe";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_id(({"robe", "pocket robe", "strange robe"}));
    set_short(myCol+"A strange quilted robe%^RESET%^");
    set_long(myCol+"This robe is made from a strange "+
    "and quilted fabric. You are unable to determine exactly what type of "+
    "cloth it was made from but it is exceedingly thick yet light weight. "+
    "It is long and flows down to nearly the feet of whoever is wearing it. "+
    "There also appear to be many pockets of various sizes lining the "+
    "inside of it and you realize that this is likely the reason for it "+
    "being so thick.%^RESET%^");
    set_value(0);       
}

int is_metal() { return 0; }

