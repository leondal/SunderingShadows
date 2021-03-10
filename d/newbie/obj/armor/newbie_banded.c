#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})
inherit "/d/common/obj/armour/banded.c";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("suit of mineral banded armor");
    set_id(({"armor", "mineral armor", "banded", "mineral banded"}));
    set_short(myCol+"A suit of banded armor%^RESET%^");
    set_long(myCol+"This armor is composed of overlapping strips of a "+
    "mineral substance. The exact nature of the substance is unknown "+
    "but it seems quite durable and flexible in order to allow "+
    "for fairly easy movement. The strips are thick and wide, however, "+
    "and are padded on the inside in order to prevent chafing from "+
    "frequent wearing.%^RESET%^");
    set_value(0);
    set_ac(6);     
}

int is_metal() { return 0; }