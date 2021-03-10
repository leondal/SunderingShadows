#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"bed2i";

void create() {
    ::create();
    set_long(
@KAYLA
Another dirty, decaying bedroom without furniture.  From the
doorway the floor in here does not look particularly safe.  Some
floorboards are missing while others appear to have suffered 
partial collapse.  Cobwebs festoon this completely abandoned 
bedroom.
KAYLA
    );
    set_exits(([ "north" : HH_ROOMS+"hall6" ] ));
    set_items(([
    ] ));
    hauntings();
}

void reset() {
  ::reset();
}
