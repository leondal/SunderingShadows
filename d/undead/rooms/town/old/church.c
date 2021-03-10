#include "../../undead.h"

inherit "/std/church";

void create() 
{
    ::create();
  
    set_name("The Church of Graez");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);

    set_short("Graez Church");
    set_long("%^BOLD%^%^RED%^You stand in the inner sanctum of the Graez Church.%^RESET%^\n"
        "The Order of Ximes runs the day to day services of the Church, as "
        "they are hand picked by the Arch Bishop, and ruler of this kingdom "
        "himself. It is a very elite group of men and women trained in the "
        "art of war just as well as they are trained in religion.");

    set_exits(([
        "north"     :TOWN+"room18",
        "west"      :TOWN+"room21"
	         ]));

    set_items(([
        "church"    : "The home of the elite Order of Ximes.",
	    "chamber"   : "People come here to pray for resurrection "
	                  "when they die.", 
             ]));
    
    set_listen("default", "You hear the faint sounds of chanting from the back of the church.");
    set_listen("chants", "In the dry, dry desert, ye shall fine the tomb of the master of "
        "the undead, Kartakass himself.");
    set_smell("default","The stale air bites at your nostrils.");
}

