//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Scepter of the Healer

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/weapon";

create() {
    ::create();
   set_id ( ({
    "sceptre", "large sceptre"
    }) );
   set_name("sceptre");
   set_short("A sceptre");
   set_long(
        "You examine a well made sceptre.  It seems to work well as a club, "
        "based on the blood stains at the large end.  Isn't it odd that there "
        "are no marks on it, though?\n"
   );
   set_weight( 3 );
    set_size(2);
    set_wc(1,6);
   set_value(30);
    set_large_wc(1,3);
   set_type("blunt");
   set_prof_type("mace");
}
