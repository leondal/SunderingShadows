#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/armour/greaves";

void create()
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("mineral greaves");
    set_id(({ "greaves", "strange mineral greaves", "mineral greaves" }));
    set_short(myCol+"A pair of mineral greaves%^RESET%^");
    set_long(myCol+"These greaves have been crafted from some "+
    "strange substance. It appears to be some type of mineral, though "+
    "it is unlike anything you have ever seen. They have been forged so that they "+
    "fit tight against the shin and calves. Thankfully there is a "+
    "thick padding attached to the insides of them.%^RESET%^");
    set_value(0);    
}

int is_metal() { return 0; }