#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
	set_long( ::query_long()+"

It looks like you could %^YELLOW%^<climb>%^BOLD%^%^BLACK%^ back up to the %^WHITE%^dock%^BLACK%^.
");
    set_smell("default","You smell salty sea water.");
    set_listen("default","The ocean crashes against the rocks.");
    set_items( ([ 
        ({"rocks","shore"}):"The rocks are black and slick from sea water.",
        ({"sea"}):"The sea looks dark and mysterious.",
		({"dock"}):"You could climb back up to the dock.  It won't be easy.",
       ({"forest"}):"The thick forest looms above.",
        ]) );
   set_exits( (["southwest":SHO+"shore2"]) );
   set_climb_exits((["climb":({"/d/shadow/virtual/sea/argentrock.dock.c",20,roll_dice(10,8),100})]));

}

