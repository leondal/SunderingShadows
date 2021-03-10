#include <std.h>
#include "../aketon_outpost.h"
inherit "/d/dagger/aketon_outpost/rooms/aketon_sequoia_inh.c";
        void create(){ 
        ::create();
 set_long(::query_long()+"%^GREEN%^An opening is worked into the tree here.  "+
"The large opening provides access to the blacksmith, and his wares.  "+
"Inside a spartian workspace has been laid out, with everything in neat"+
" order.  Billets of metal are arranged in crystalline bins.  Decorating"+
" the entrance of the shop is a %^BOLD%^%^CYAN%^crystal%^RESET%^%^GREEN%^"+
" awning.\n");
 add_item(({"opening","blacksmith"}),"%^ORANGE%^The opening to the blacksmith"+
" has been magically shaped out of the tree, keeping it healthy and intact."+
"  The shop is laid out in a clean style, with everything neatly in its place."+
" On the ledge that faces outward, samples of the wares for sale have been laid."+
"  Tucked against the counter two quivers full of flight arrows, and a long bow"+
" can be seen. An intricate looking forge lays against the back wall of the shop."+
"  The forge is fueled by a magical cold fire, that provides no smoke or damage "+
"to the tree.");
add_item(({"awning","crystal awning"}),"%^BOLD%^%^CYAN%^Woven from strands of crystal,"+
" this awning takes the apperance of a fine lattice weave.  The delicate looking"+
" awning doesn't look as if it would protect that well from the elements.  Hinged"+
" arms support the crystal awning up.  It would see that in times of warfare, the"+
" awning can be closed.  The lattice deign of the awning then becomes a series of"+
" archer's windows, allowing the elves to fire on their enemies below.");
        set_exits(([ "southwest" : ROOMS"aketon_central",
                         "up" : ROOMS"seq2",
                        ]));
}
