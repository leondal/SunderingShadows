

#include "/d/dagger/tonovi/short.h"


inherit VAULT;
object guard;
void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Southern path to Tonovi");
    set_long("%^RESET%^You are standing on the crest of one of the "
"taller hills. All around you are %^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^o"
"%^BOLD%^%^GREEN%^lli%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^g h%^RESET%^"
"%^GREEN%^ill%^BOLD%^%^GREEN%^s%^RESET%^. To the south and east you "
"see the walls %^BOLD%^%^BLACK%^caging%^RESET%^ in the plains. To the "
"northeast is a %^ORANGE%^lookout post%^RESET%^." );
    set_listen("default", "A cool breeze whispers across the plain");
    set_items( ([
        "hills" : "You are sorrounded by these great majestic green monsters.",
        "road" : "The new road here is just starting to get ruts in"+
                " it, as is burns an ominous scar across the plains.",
        "wall" : "The great wall around the plain is"+
                " supposed to keep invaders out, but it looks more "+
                "like it keeps the beauty in.",
        ({"lookout post", "post", "lookout"}) : "On the road "+
                "you can see a brick structure standing aside the road.",
      ]) );
    set_exits( ([
        "northeast" : RPATH "1path6",
        "southwest" : RPATH "1path4",]));
        
}
