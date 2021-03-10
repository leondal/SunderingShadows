#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inherit.c";

void create() {
 set_short("%^RESET%^%^BLUE%^Entrance to a %^CYAN%^misty "
"%^BLUE%^grove%^RESET%^");
 ::create();
 set_long("%^RESET%^%^BLUE%^Entrance to a %^CYAN%^misty "
"%^BLUE%^grove%^RESET%^\n\n"
"%^RESET%^%^BLUE%^Soon as you pass the archway, the %^CYAN%^"
"fog %^BLUE%^grows denser, thick enough that you can barely "
"see inches in front of your face. Despite this, you still "
"feel the presence of the trees you saw through the arch... "
"and can't help wondering just what could be stalking among "
"their branches. Whorls of the mist twist and curl across "
"the ground around your feet, almost as though directed by "
"some unseen force. An almost tangible feel of %^RED%^malice "
"%^BLUE%^hangs in the air here, made only more unsettling by "
"the echoed sound of breathing from somewhere in the mist.");
TO->add_item(({"arch","archway"}),"%^BOLD%^%^BLACK%^Carved from dark"
" gray stone, it is perhaps ten feet in height, and a bit over half "
"that in width. The stone is rather simple, with little decoration "
"beyond a series of strange, clawmark-like runes carved into the apex "
"of the arch. Peering through the arch yields a very strange sight: "
"instead of this dark grove, an overgrown %^RESET%^%^GREEN%^marsh"
"%^BOLD%^%^BLACK%^.%^RESET%^");
 set_exits(([
  "north":"/d/dagger/marsh/witchlair/rooms/grove3",
  "northwest":"/d/dagger/marsh/witchlair/rooms/grove2",
  "northeast":"/d/dagger/marsh/witchlair/rooms/grove4",
  "archway":"/d/dagger/marsh/witchlair/rooms/archway",
 ]));
}
