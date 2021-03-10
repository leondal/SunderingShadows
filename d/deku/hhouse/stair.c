#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";

void create() {
    ::create();
    set_long(
@KAYLA
The stairs creak ominously as you ascend but they are safe enough. 
At the top you reach the gallery which is at the north and west
end of the hall.  To east and west the corridor appears to 
stretch the full width of the house with doors leading off it to
the south.  Opposite the western portion of the gallery is another
corridor leading north.
KAYLA
    );
    set_exits(([
       "down" : HH_ROOMS+"entrance",
       "west" : HH_ROOMS+"hall7",
       "east" : HH_ROOMS+"hall5"
    ] ));
    set_items(([
       "stairs" : "The stairs look safe enough and unlikely to collapse from "
           "normal loads."
    ] ));
    hauntings();
}
