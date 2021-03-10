#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
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
    set_exits( ([
        "east":"/d/laerad/wasteland/waste21",
        "southwest":"/d/laerad/wasteland/waste7",
        "south":"/d/laerad/wasteland/waste20"
    ]) );
}
