#include <std.h>
#include "../defs.h"
inherit "/std/pier";

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_property("teleport proof",-55); // likely passable by SC, but not by multis.
        set_name("A clearing in the forest");
        set_short("%^RESET%^%^ORANGE%^A clearing in the forest");
        set_long("%^GREEN%^The dense forest gives way to a small clearing, a %^CYAN%^bubbling spring %^GREEN%^at its center. Around the circumference of the "
"spring %^BOLD%^grass%^RESET%^%^GREEN%^ grows thick and plush. It spills away to the south in a small %^BOLD%^%^CYAN%^brook%^RESET%^%^GREEN%^, the meandering "
"flow giving this place a sense of calm. From the surrounding forest a thick %^WHITE%^mist%^GREEN%^ rises regardless of the weather. Almost palpable, it "
"doesn't seem to move with the wind, having a mind of its own.%^RESET%^");
        set_smell("default","%^RESET%^%^ORANGE%^The earthy scents of nature surround you.");
        set_listen("default","%^RESET%^%^ORANGE%^There is the occasional rustle or chirp of wildlife.");
        set_items(([
         "brook" : "Little more then the gentle trickle caused by the flow from the spring, it babbles away to the south.",
         "grass" : "Deep grass, fed by the rich water of the spring, grows plushy, offering a comfortable place to rest were "
"one so inclined. In its midst you notice a stone, flush to the ground.", 
         "stone" : (:TO,"stone_desc":),
        ]));
        set_exits(([
           "south" : ROOMS"elfpath005",
        ]));
        set_water_body("spring");
        new(OBJ+"spring")->move(TO);
}

string stone_desc() {
   if((int)TP->query_lang("elven") > 50 || (int)TP->query_skill("academics") > 25) return("A symbol is etched in the stone letting you know there is an elven sanctuary nearby.");
   return("There is a strange curling symbol etched in the stone.");
}