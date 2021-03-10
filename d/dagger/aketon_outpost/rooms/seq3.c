#include <std.h>
#include "../aketon_outpost.h"
inherit "/d/dagger/aketon_outpost/rooms/aketon_sequoia_inh.c";
        void create(){ 
        ::create();
 set_long(::query_long()+"%^GREEN%^An opening is worked into the tree here.  "+
"The large opening provides access to the shopkeeper, and his wares.  "+
"Inside a crowded collection of rope, pouches, and other useful tools"+
" fill the shop.  Everything looks as if it has been neatly organized,"+
" even if there is a plethora of items.  Decorating"+
" the entrance of the shop is a %^BOLD%^%^CYAN%^crystal%^RESET%^%^GREEN%^"+
" awning.\n");
 add_item(({"opening","shop"}),"%^ORANGE%^The opening to the shop"+
" has been magically shaped out of the tree, keeping it healthy and intact."+
"  The shop is crowded with tools, rope, sacks, and other useful objects for "+
"everyday life.  Though crowded, everything has been meticulously laid out in order."+
"  Tucked against the counter two quivers full of flight arrows, and a long bow"+
" can be seen.");
add_item(({"awning","crystal awning"}),"%^BOLD%^%^CYAN%^Woven from strands of crystal,"+
" this awning takes the apperance of a fine lattice weave.  The delicate looking"+
" awning doesn't look as if it would protect that well from the elements.  Hinged"+
" arms support the crystal awning up.  It would see that in times of warfare, the"+
" awning can be closed.  The lattice deign of the awning then becomes a series of"+
" archer's windows, allowing the elves to fire on their enemies below.");
        set_exits(([ "down" : ROOMS"seq2",
                         "up" : ROOMS"arch2",
                        ]));
}
