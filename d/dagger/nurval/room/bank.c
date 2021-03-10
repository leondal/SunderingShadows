#include <std.h>
#include "../tomb.h"

inherit BANK;

string getBankId(){ return "daggerdale";}

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("%^BOLD%^E%^ORANGE%^t%^RESET%^%^ORANGE%^e%^BOLD%^r%^WHITE%^nal C%^ORANGE%^o%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^n%^RESET%^");
    set_long("%^BOLD%^E%^ORANGE%^t%^RESET%^%^ORANGE%^e%^BOLD%^r%^WHITE%^nal C%^ORANGE%^o%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^n%^RESET%^
%^BOLD%^Made from pol%^BLACK%^ish%^WHITE%^ed ma%^BLACK%^rb%^WHITE%^le, the insides of this establishment give unusual contrast to everything that is %^BLACK%^o%^RESET%^%^BLUE%^ut%^BOLD%^%^BLACK%^side%^WHITE%^. %^RESET%^%^MAGENTA%^Exquisite %^RED%^carpets %^ORANGE%^flow %^BOLD%^%^WHITE%^on the floor from the entrance arch to the teller window. %^RESET%^%^GREEN%^Tapestries %^BOLD%^%^WHITE%^with images of far away lands and forgotten stories decorate walls on the sides. By the walls several comfortable %^RESET%^%^RED%^sofas %^BOLD%^%^WHITE%^and %^RESET%^%^RED%^chairs %^BOLD%^%^WHITE%^offer a place to rest and wait. The %^RESET%^%^ORANGE%^teller w%^BOLD%^i%^RESET%^%^ORANGE%^ndow %^BOLD%^%^WHITE%^is %^RESET%^%^ORANGE%^framed %^BOLD%^%^WHITE%^into %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n %^BOLD%^b%^RESET%^%^ORANGE%^a%^BOLD%^r%^RESET%^%^ORANGE%^s %^BOLD%^%^WHITE%^styled as plant vines. Golden chandeliers twelve feet above shine with diamond encrustation. The place is uncomfortably lavish.%^RESET%^

There is a %^ORANGE%^sign%^RESET%^ by the teller window.
  ");
    set_exits(([ "north":ROOMS+"/tomb1" ]));
    set_smell("default","The smell of oxidation of copper.");
    set_listen("default","The sounds of rustling coins fill your ears.");
    set_items(([
                   "sign":"A sign you can <read>.",
                   ]));
}
