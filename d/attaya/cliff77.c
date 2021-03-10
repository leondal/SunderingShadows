#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_short("%^BLUE%^%^BOLD%^Tomb of the lost girl");
    set_long("%^BLUE%^%^BOLD%^Tomb of the lost girl
%^RESET%^%^BOLD%^%^WHITE%^You come to a small pile of %^BLACK%^stones%^WHITE%^ at the end of the ledge. They lie in the shadows of a huge statue. The wind whips past you and you feel quite cold, yet you take a closer look. The stones are arranged by hand in a neat %^BLACK%^pile,%^WHITE%^ perhaps as a shallow unmarked grave. A thin layer of snow coats them. The sky around you is nothing but a light grey. You cannot see the %^BLUE%^oc%^CYAN%^e%^BLUE%^an%^WHITE%^ from here.");
    set_exits(([
                   "west":"/d/attaya/cliff76"
                   ]));
	
    set_smell("default", "A few snowflakes land upon you as you stand in the statue's shadow.");
    set_items(([
                   "stones" : "They make a neat pile just long enough to cover a small body.  They are most likely the coverstones for a shallow grave.",
                   "pile" : "The small pile of stones most likely mark a shallow unmarked grave in the shadows of the statue.",
                   "plaque" : "It is covered with ice, but still readable.",
                   "ocean" : "You cannot see it from here you idiot!"
                   ]));
}

void reset(){
	::reset();
    if(!present("statue"))
        new("/d/attaya/obj/statue2.c")->move(TO);
	
	
}
