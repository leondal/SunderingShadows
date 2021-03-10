#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long("This room has suffered the effects of damp and decay more than "
      "most in the house.  %^CYAN%^Mold %^RESET%^grows in patches on the floor, "
      "walls and ceiling.  There are many cobwebs, though even these appear to "
      "decay.  A large discolored copper boiler, dented, split and empty, "
      "stands under the window.  Stairs lead down into the %^BOLD%^%^BLACK%^"
      "darkness %^RESET%^of what you might suppose is a cellar.");
    set_smell("default","The smell of rot and decay is even stronger here.");
    set_exits(([
       "down" : HH_ROOMS+"cellar",
       "west" : HH_ROOMS+"kitchen"
    ] ));
    set_items(([
       ({"stairs", "cellar", "darkness" }): "You can probably go down there if "
         "you are feeling brave enough.",
       "mold" : "%^CYAN%^It is really thick in here, perhaps from the dampness "
         "coming up from the cellar.",
    ] ));
    hauntings();
    
}

void reset() {
  ::reset();
  if(!present("ghost")) {
    new("/d/deku/monster/gghost")->move(TO);
  }
  if(!present("skeleton")) {
    new("/d/deku/monster/skeleton")->move(TO);
    new("/d/deku/monster/skeleton")->move(TO);
  }
}

