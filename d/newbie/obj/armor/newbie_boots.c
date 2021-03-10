#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/clothing/shoes";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("pair of thick leather boots");
    set_id(({ "boots", "thick leather boots", "thick boots", "leather boots" }));
    set_short(myCol+"A pair of thick leather boots%^RESET%^");
    set_long(myCol+"These thick leather boots have been crafted from "+
    "the hide of an unknown creature. They have been subjected to a tanning "+
    "process which has caused them to harden enough that they retain their form. "+
    "A thick cloth padding has been sewn into the inside of them to make them "+
    "more comfortable to wear. They are also shorter than typical boots, reaching "+
    "only slightly above the ankle of the wearer.%^RESET%^");
    set_value(0);
}
