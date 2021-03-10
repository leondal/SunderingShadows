#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})
inherit "/d/common/obj/armour/bronze";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_id(({"plate", "mineral plate", "armor"}));
    set_short(myCol+"A suit of mineral plate armor%^RESET%^");
    set_long(myCol+"This is the most common version of plate armor. "+
    "It has been designed from plates rivited and interlocked to "+
    "cover much of the body of the wearer. This particular suit of armor is "+
    "composed from some strange mineral substance. It seems very sturdy and "+
    "is quite heavy though the exact nature of the substance is unknown. It is "+
    "padded on the inside in order to prevent chafing.%^RESET%^");
    set_value(0);       
}

int is_metal() { return 0; }

