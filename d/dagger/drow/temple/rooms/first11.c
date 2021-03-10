#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
void init() {
    ::init();
    add_action("drink_func","drink");
}
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",3);
    set_property("indoors",1);
   set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The aroma of goodness and purity fill the air."
    );
    set_listen("default","A slight singing fills your ears.");

    set_items(([
	"chamber":"%^CYAN%^You stand within a great chamber. "
	"A %^RESET%^stone fountain "
	"%^CYAN%^rests in the center of the chamber.%^RESET%^",
	"fountain":"%^CYAN%^The %^RESET%^"
        "fountain%^CYAN%^ bears three intertwining statues that spout "
        "%^BLUE%^water%^CYAN%^ into the basin of the fountain.%^RESET%^",
        "water":"%^BLUE%^The water looks clear and refreshing.%^RESET%^",
	"statues":"The statues spout water into the fountain.",
	"statue":"The statues spout water into the fountain.",
        "figures":"As you look upon the figures, one begins to speak to "
	"you...\n%^YELLOW%^Figure says: %^CYAN%^Merely drink from the "
	"fountain if you are of worth and purity will be "
	"granted!%^RESET%^"
    ]));
    set_exits(([
	"south": RPATH "first9"
	    ]));
}
string lng_fun(string str) {
	str = 
            "%^CYAN%^You stand within a large chamber. A %^RESET%^stone fountain "
	    "%^CYAN%^rests in the center of the chamber. The %^RESET%^"
	    "fountain%^CYAN%^ bears three intertwining statues that spout "
	    "%^BLUE%^water%^CYAN%^ into the basin of the fountain. "
	    "%^CYAN%^ ";
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presence of Grazzt."
	       "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
	str = 
            "%^CYAN%^Chamber of Purity.%^RESET%^";
    return str;
}
int drink_func(string str) {
    int poison;
    if(!str) {
	notify_fail("Drink what?");
	return 0;
    }
    if(str != "water") {
	notify_fail("Drink what?");
        return 0;
    }
    write(
	"%^YELLOW%^As you drink from the fountain, "
	"the statues turn towards you and sing!\n"
	"%^WHITE%^You feel your blood become purified!%^RESET%^"
    );
    say(
	"%^YELLOW%^As "+TPQCN+" drinks from the fountain, "
	"the statues turn towards "+TPQCN+" and "
	+TP->query_subjective()+" is surrounded in a bright light!"
	"%^RESET%^"
    ,TP);
    poison = (int)TP->query_poisoning();
    if(poison > 0) {
        TP->add_poisoning(-(poison));
    }
    return 1;
}
