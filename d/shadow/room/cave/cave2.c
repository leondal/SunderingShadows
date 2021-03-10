//cave2.c
#include "../cave.h"

inherit CAVERAT;

void set_rope(int rope);

int rope_present;

void create(){
    ::create();
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^\n"+
      "These wide %^BOLD%^%^BLUE%^caverns %^RESET%^seem to have "+
      "been naturally carved.  Strange "+
      "%^ORANGE%^striations %^RESET%^and variations in color "+
      "along the %^GREEN%^walls %^RESET%^suggest that "+
      "an %^BLUE%^underground river %^RESET%^was the origination "+
      "of these %^BOLD%^tunnels%^RESET%^.  The "+
      "%^CYAN%^air %^RESET%^is damp, heavy, and quite cool here "+
      "in the darkness.  The %^BOLD%^%^BLACK%^floors "+
      "%^RESET%^are worn completely smooth and are covered with "+
      "a light film of "+
      "%^ORANGE%^dirt %^RESET%^and %^GREEN%^debris %^RESET%^made "+
      "sticky from the occasional streams which still "+
      "flow through here during heavy rainfalls.  There is a "+
      "large hole in the ceiling of this cavern, and "+
      "an aged %^ORANGE%^rope %^RESET%^dangles from above."+
      "\n"
    );
    add_item("rope","This knotted rope hangs from the cavern above, "+
      "but seems old and rotted.  You would "+
      "probably need your own tools or fantastic skills to climb out of the cavern.");
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_exits((["west" : CAVEDIR+"cave3"]));
    set_climb_exits((["climb":({ CAVEDIR+"cave1",10,6,100})]));
    set_fall_desc(
@FALL
You fall down about 50 feet. You land on some rocks and other
debris. Pain racks your body.
FALL
);
}
/*
void init(){
    ::init();
    do_random_encounters(({MONDIR+"rat"}),30,5);
}
*/
