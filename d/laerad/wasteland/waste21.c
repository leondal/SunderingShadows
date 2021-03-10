#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
	set_long(TO->query_long()+"%^BOLD%^%^BLACK%^A large %^RESET%^%^ORANGE%^wooden palisade wall %^BOLD%^%^BLACK%^has been raised to the west. 15 feet tall and too well made to climb.\n");
    add_item("wall","The wall is tall and made from quality wood. Clearly not from around here! and from the looks of it. raised recently");
	set_long(
      "%^ORANGE%^A sandy wasteland shore\n "
       "You are on a barren shore alongside the %^CYAN%^Sa%^BOLD%^"
	   "%^WHITE%^a%^RESET%^%^CYAN%^krune S%^BOLD%^%^WHITE%^e%^RESET%^"
	   "%^CYAN%^a%^ORANGE%^.  The earth appears cracked and dead with "
	   "no vegetation other than an occasional unusually large cactus.  "
	   "A wicked wind bites at your face, blowing sand into your eyes.  "
	   "Here and there a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^"
	   "spews from a new fissure in the ground.  The lifeless wasteland "
	   "continues for what seems like leagues towards the east.\n "
    );
	add_item("wall","The wall is tall and made from quality wood. Clearly not from around here! and from the looks of it. raised recently");
    set_exits( ([
        "east":"/d/laerad/wasteland/waste30",
        //"west":"/d/laerad/wasteland/waste8",
        "south":"/d/laerad/wasteland/waste22"
    ]) );
}
