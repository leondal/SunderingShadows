#include <std.h>

inherit "/d/deku/forest/forest2i";

void create() {
    ::create();

/* change back to let it use the inherit desc. after moving Mielikki's temple
    set_long("Somehow lush, beautiful trees grow thickly here "+
    "in spite of the unnatural decay that seems to have overcome "+
    "most of the island's forest.  One tree here stands out from "+
    "amongst the others, seeming to radiate an almost tangible "+
    "aura of life, and you think that from this tree all the others "+
    "draw their life.  The tree is what has come to be known as a "+
    "%^RED%^cherry tree%^RESET%^ and it stands proud and vibrant.  "+
    "The entire area is illuminated with hues of %^GREEN%^greens"+
    "%^RESET%^, %^MAGENTA%^browns%^RESET%^, %^RED%^reds%^RESET%^, "+
    "and %^YELLOW%^yellows%^RESET%^, colors of life which most of "+
    "this land so desperately lacks.  In the middle of all the "+
    "trees, just south of the %^RED%^cherry%^RESET%^, is a temple.");
*/
    set_exits(([
//      "temple":"/d/magic/temples/mielikki_entrance",
       "north" : "/d/deku/forest/forest2i"
    ] ));
    set_items(([
       "forest" : "The forest looks very dark and dangerous to the north.  "
        "There appears to be smoke rising from the far northeast of the island.",
    ] ));
}
