// path to the building

#include <std.h>
#include "../inherit/ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Narrow dirt path");
    set_short("%^ORANGE%^Narrow dirt path%^RESET%^");
    set_smell("default","Clean, fresh mountain air wafts on the breeze.");
    set_listen("default","Occasional gusts of wind whistle through the stones.");
    set_items(([
      ({"path","trail","pathway"}) : "%^GREEN%^The path is very narrow here, and only vaguely defined.  "
"It is little more than a trail of %^ORANGE%^dirt%^GREEN%^, winding further up into the "
"mountains%^RESET%^.",
      ({"tree","trees","pines","pinetrees"}) : "%^GREEN%^The %^BOLD%^trees%^RESET%^%^GREEN%^ have parted "
"here, no longer lining the edges of the pathway.  Several groups cluster together upon the rocky "
"slopes, thinning to only a few sparse pines as the path travels further upwards.",
      ({"brush","undergrowth","bushes"}) : "%^GREEN%^Thinned brush still covers the mountain slopes, "
"though it seems to be struggling to grow here.  Only scattered patches of %^RED%^holly%^GREEN%^ bushes "
"dot the rocky incline, mingled with a few vines of twisting %^WHITE%^ivy%^GREEN%^.%^RESET%^",
      ({"rocks","stones","rock","stone","boulder","boulders"}) : "%^BLACK%^%^BOLD%^Boulders "
"%^RESET%^%^GREEN%^of all sizes are strewn haphazardly across the mountain slopes, making any travel "
"away from the path very difficult.  A few small rocks have fallen onto the %^ORANGE%^path%^GREEN%^, "
"which has probably not been tended in quite some time.%^RESET%^",
    ]));
}
