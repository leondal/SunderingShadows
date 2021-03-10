#include <std.h>
#include "../spriggan.h"

inherit CROOM;

void pick_critters();

void create(){
   pick_critters();
   set_repop(25);
   ::create();
   set_name("A sandy shore");
   set_short("%^RESET%^%^ORANGE%^A sandy shore%^RESET%^");
   set_terrain(BEACH);
   set_travel(FOOT_PATH);
   set_indoors(0);
   set_property("light",3);
   set_long("%^RESET%^%^ORANGE%^This narrow stretch of %^YELLOW%^sandy "
      "beach %^RESET%^%^ORANGE%^is situated between a %^GREEN%^serene "
      "%^CYAN%^bl%^GREEN%^u%^CYAN%^e%^GREEN%^-%^CYAN%^gre%^GREEN%^en "
      "%^CYAN%^sea %^ORANGE%^and the %^BOLD%^%^BLACK%^rocky sides %^RESET%^"
      "%^ORANGE%^of a flat-topped %^RESET%^mountain %^ORANGE%^rising "
      "sharply inland.  The shore is decorated with a scattering of "
      "broken %^RESET%^s%^BOLD%^e%^RESET%^a%^CYAN%^s%^RESET%^h%^BOLD%^e"
      "%^RESET%^l%^BOLD%^l%^RESET%^s %^ORANGE%^that lend a sheen of "+
      "%^BOLD%^%^WHITE%^iri%^RESET%^de%^BOLD%^scence %^RESET%^%^ORANGE%^"
      "to the sand.  The interior of the island looks to be covered "
      "with lush %^GREEN%^tropical plants %^ORANGE%^and verdant %^BOLD%^"
      "%^GREEN%^trees%^RESET%^%^ORANGE%^.  It seems as though the "
      "jungle would be impossible to reach from here without some sort "
      "of path.%^RESET%^\n");
   set_items(([
      ({"sea","ocean","water"}) : "%^CYAN%^The sparkling waters of the "
         "sea are a soothing blue-green, and they seem to be teeming "
         "with sealife.%^RESET%^",
      ({"mountain","sides","slopes","rocky sides"}) : "Butting close against "
         "the shore, the rocky slopes of the mountain are a deep gray "
         "in color, dusted with brown.  They seem to offer no handholds "
         "or ready means up.  The top of the mountain itself looks to "
         "be flattened, rather like a dormant volcano.",
      ({"shells","seashells","broken seashells","broken shells"}) : "The "
         "shells have been pounded by the surf and lend a dusting of "
         "sparkling black, gray, and white powder to the otherwise "
         "light-colored sand.  Occasionally, larger pieces and even whole "
         "shells wash ashore.",
      ({"trees","plants","verdant trees","lush plants","tropical plants","interior"}) : 
         "%^GREEN%^The inner portion of the island is covered with tall, "
         "flourishing trees as far as the eye can see.  The jungle is rather "
         "thick, not allowing the gaze to penetrate far.  Below the trees, "
         "%^MAGENTA%^m%^BOLD%^u%^RED%^l%^YELLOW%^t%^GREEN%^i%^CYAN%^-"
         "%^GREEN%^c%^YELLOW%^o%^RED%^l%^MAGENTA%^o%^RESET%^%^MAGENTA%^r"
         "%^CYAN%^e%^BOLD%^d %^RESET%^%^GREEN%^flowers brighten the "
         "landscape.%^RESET%^"
   ]));
   set_search("default","There seems to be nothing of interest here.");
   set_listen("default","You hear the waves crashing against the shore.");
   set_smell("default","The light scent of salt and seaweed hangs in the air.");
}

void reset(){
   ::reset();
   switch(random(5)){
      case 0:  tell_room(TO,"%^BOLD%^%^CYAN%^A large wave crashes "
                  "against the shore.%^RESET%^");
               break;
      case 1:  tell_room(TO,"%^BOLD%^A cool breeze stirs, bringing "
                  "relief from the heat of the sun.%^RESET%^");
               break;
      case 2:  tell_room(TO,"%^ORANGE%^A group of gulls suddenly takes "
                  "flight from the shore.%^RESET%^");
               break;
      case 3:  tell_room(TO,"%^MAGENTA%^The strange call of a bird "
                  "floats on the breeze from farther inland.%^RESET%^");
               break;
      case 4:  tell_room(TO,"%^BOLD%^%^RED%^A loud BANG suddenly "
                  "reverberates from somewhere on the island.%^RESET%^");
               break;
   }
   if(!random(12) && !present("seashell")){
      tell_room(TO,"%^CYAN%^A wave gently washes ashore, leaving "
         "behind a small %^BOLD%^treasure%^RESET%^%^CYAN%^.");
      new(SOBJ"seashell")->move(TO);
   }
}

void pick_critters() {
      switch(random(9)){
         case 0..1:   set_monsters(({SMON"crab"}),({1}));
                   break;
         case 2..3:   set_monsters(({SMON"seagull"}),({1}));
                   break;
         default: tell_room(TO,"No critters this time.");
                   break;
      }
}