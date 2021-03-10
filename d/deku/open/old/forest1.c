//minor change to description by Circe 1/2/04 to reflect
//planting by Marika in a plot run by Torm.
#include <std.h>

inherit "/d/deku/open/forest2i";

void create() {
    ::create();
    set_long("Somehow lush, beautiful trees grow thickly here in spite of the "
       "unnatural decay that seems to have overcome most of the island's "
       "forest.  They illuminate the area with vibrant colors.  The path ends, "
       "or perhaps begins, here at a temple.  Just off the path beside the "+
       "temple entrance, a newly planted %^BOLD%^%^RED%^cherry tree %^RESET%^"+
       "grows.");
    set_exits(([
      "temple":"/d/magic/temples/mielikki",
       "north" : "/d/deku/open/forest2i"
    ] ));
    set_items(([
       "forest" : "The forest looks very dark and dangerous to the north.  "
        "There appears to be smoke rising from the far northeast of the island.",
       ({"tree","cherry tree","cherry"}) : "The %^BOLD%^%^RED%^cherry tree "+
          "%^RESET%^growing beside the entrance to the temple seems small and "+
          "very young.  It has not been long planted there, although it is "+
          "obviously tended with care.  The dirt around it has been carefully "+
          "worked into a mound covering the roots, and the soil is a rich, "+
          "earthy brown.  The %^BOLD%^%^GREEN%^leaves %^RESET%^of the "+
          "%^BOLD%^%^RED%^cherry tree %^RESET%^rustle in the wind, revealing "+
          "colors of %^BOLD%^%^GREEN%^green %^RESET%^and %^BOLD%^silver%^RESET%^."
    ] ));
}
