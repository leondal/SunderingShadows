#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_long(::query_long()+" %^RESET%^%^GREEN%^A small %^YELLOW%^plaque%^RESET%^%^GREEN%^ has been installed at the edge of the path here.%^RESET%^");
  set("night long",::query("night long")+" %^RESET%^%^BLUE%^A small %^YELLOW%^plaque%^RESET%^%^BLUE%^ has been installed at the edge of the path here.%^RESET%^");
  set_exits(([
  "west":TCITY+"c108",
  "east":TCITY+"c106",
  ]));
  add_item("plaque",({"%^YELLOW%^There is a small golden plaque here.%^RESET%^","%^BOLD%^%^WHITE%^In memory of wise king Erik, may he rest in peace evermore.\n%^BOLD%^%^WHITE%^In gratitude to those who restored his legacy: %^BOLD%^%^WHITE%^Trillet, Erynion, Verbannon, Jysibyll, and Luur.%^RESET%^","common"}));
}
