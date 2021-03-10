#include "../../newbie.h"
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("The Psicrystal");
	set_short("%^BOLD%^The Psicrystal%^RESET%^");
	set_long("%^BOLD%^The Psicrystal%^RESET%^\n"+
"The name of this small shop seems to say it all.  All around you are well-made, varnished %^ORANGE%^shelves %^RESET%^"
"supporting glass decanters and jars filled with various cut gems and crystals, all sparkling in the glow of brass "
"%^YELLOW%^lamps%^RESET%^.  Rather than using oil and fire, however, the lamps seem to be producing light of their own "
"accord.  A raised %^MAGENTA%^platform %^RESET%^near the rear of the shop supports a thick, round cushion colored a dusky "
"blue.  It seems that this cushion is the shopkeeper's preferred place from which to conduct business.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
	set_smell("default","A pleasing aroma of incense fills the air.");
	set_listen("default","The occasional sound of gems striking one another rises above the otherwise quiet of the store.");
	set_items( ([
        ({"components","store","counter","shelf","shelves","crystals","jars","decanters"}) : "%^ORANGE%^The crystals "
"sparkle in an endless array of colors, from the deepest blacks to iridescent pinks.  All of the gems are displayed in "
"clear containers for easy sorting and retrieval.%^RESET%^",
        ({"cushion","platform","raised platform"}) : "%^MAGENTA%^The cushion upon the platform is made from a plush dusky "
"blue material that looks very comfortable.  From here, the shopkeeper can often be seen waving a hand to call a "
"particular item to him through the air.%^RESET%^",
        ({"lamps","brass lamps"}) : "%^YELLOW%^The brass lamps feature slender, curving bodies.  They are placed on the "
"shelves throughout the store, and each produces a heatless 'flame' from its spout.%^RESET%^"
    ]) );
    set_exits(([
        "south" : MAINTOWN"psifoyer"
    ]) );
}

void reset(){
   ::reset();
   if(!present("nasir")) find_object_or_load(MON"nasir")->move(TO);
}