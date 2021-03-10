//shore.c - Inherit for Loch Tearmann shore.  Circe 9/11/04
#include <std.h>
inherit "/std/pier";

void create() {
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_terrain(SHORE);
   set_travel(RUTTED_TRACK);
   set_name("A grassy shore"); 
   set_short("A grassy shore");
   set_long("%^GREEN%^Here on the grassy shores of %^BOLD%^%^BLUE%^"+
      "Loch Tearmann%^RESET%^%^GREEN%^, the ground is rather flat "+
      "and soft.  The %^YELLOW%^reeds %^RESET%^%^GREEN%^and %^BOLD%^"+
      "rushes %^RESET%^%^GREEN%^crowd the shore, and the bank rises "+
      "sharply beyond this small haven, making it rather secluded.  "+
      "The %^BLUE%^water %^GREEN%^laps the shore, and you can "+
      "see swimmers at times enjoying the cool mountain lake.  ");
   set_items(([
      ({"lake","water","loch","Loch Tearmann"}) : "%^BOLD%^%^BLUE%^"+
         "The cool water of the lake to the north laps against "+
         "the shore, choked by the reeds and rushes growing at the "+
         "edges.",
      ({"grass","shore","grassy shore","ground","shores"}) : "The "+
         "flat ground here is soft and covered with %^BOLD%^"+
         "%^GREEN%^lush grasses %^RESET%^that provide a comfortable "+
         "seat.  The area of the shore is not very wide, with the "+
         "outer edge rising sharply up a hill, and the lake's "+
         "reed-choked edges pulling in close.",
      ({"rushes","reeds"}) : "The lake is filled with rushes and "+
         "reeds, especially close to the shore.  The rushes are "+
         "those used as floor coverings in the town, while the "+
         "reeds are often combined with willow branches in making "+
         "the furniture.",
   ]));
   set_water_body("lake");
   set_max_fishing(6);
   set_chance(12);
   set_max_catch(8);
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","Occasional rustling noises rise from the undergrowth.");
}