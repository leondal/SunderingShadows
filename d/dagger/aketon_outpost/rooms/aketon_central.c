#include <std.h>
#include "../aketon_outpost.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("%^GREEN%^Central Platform of the Aketon Outpost");
   set_short("%^GREEN%^Central Platform of the Aketon Outpost");
   set_long("%^GREEN%^Central Platform of the Aketon Outpost%^RESET%^\n"+
      "%^ORANGE%^Snuggled against the massive trunk of the "+
      "giant %^RED%^redwood%^ORANGE%^, an %^BOLD%^%^WHITE%^"+
      "auroral platform %^RESET%^%^ORANGE%^made of smooth "+
      "%^BOLD%^%^WHITE%^opaque crystal %^RESET%^%^ORANGE%^"+
      "shaved impossibly thin lays across the branches.  "+
      "Five gracefully arched buildings which seem grown "+
      "from the same %^BOLD%^%^WHITE%^crystal %^RESET%^"+
      "%^ORANGE%^may be accessed from here, while a tiny "+
      "%^YELLOW%^stairway %^RESET%^%^ORANGE%^spirals around "+
      "the massive trunk, leading to an %^GREEN%^archer's "+
      "platform %^ORANGE%^above.  Narrow %^BOLD%^%^WHITE%^"+
      "pathways %^RESET%^%^ORANGE%^which lack rails or "+
      "supports lead to each of the buildings, and the "+
      "d%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^p%^RESET%^"+
      "%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^d %^BOLD%^"+
      "sunlight %^RESET%^%^ORANGE%^streaming through the "+
      "%^GREEN%^boughs %^ORANGE%^gives them the illusion "+
      "of transparency.%^RESET%^\n");
   set("night long","%^GREEN%^Central Platform of the Aketon Outpost%^RESET%^\n"+
      "%^BLUE%^Snuggled against the massive trunk of the "+
      "giant %^RED%^redwood%^BLUE%^, an %^BOLD%^%^WHITE%^"+
      "auroral platform %^RESET%^%^BLUE%^made of smooth "+
      "%^BOLD%^%^WHITE%^opaque crystal %^RESET%^%^BLUE%^"+
      "shaved impossibly thin lays across the branches.  "+
      "Five gracefully arched buildings which seem grown "+
      "from the same %^BOLD%^%^WHITE%^crystal %^RESET%^"+
      "%^BLUE%^may be accessed from here, while a tiny "+
      "%^YELLOW%^stairway %^RESET%^%^BLUE%^spirals around "+
      "the massive trunk, leading to an %^GREEN%^archer's "+
      "platform %^BLUE%^above.  Narrow %^BOLD%^%^WHITE%^"+
      "pathways %^RESET%^%^BLUE%^which lack rails or "+
      "supports lead to each of the buildings, and the "+
      "%^RESET%^d%^BOLD%^a%^RESET%^p%^BOLD%^p%^RESET%^"+
      "l%^BOLD%^e%^RESET%^d %^BOLD%^"+
      "moonlight %^RESET%^%^BLUE%^streaming through the "+
      "%^GREEN%^boughs %^BLUE%^gives them the illusion "+
      "of transparency.%^RESET%^\n");
   set_smell("default","Fresh woodland scents linger in the air.");
   set_listen("default","Songbirds sing among the rustle of leaves.");
   set_items(([
      ({"trees","canopy","forest","boughs"}) : "%^GREEN%^The forest "+
         "around you feels ancient.  Some of the trees are "+
         "bigger than any you have ever seen before!",
      ({"buildings","structure"}) : "%^BOLD%^Crafted out of "+
         "opaque crystal, the structures that are nestled in "+
         "the branches of the mighty redwood are of obvious "+
         "elven design.  Thin arches support the walls of the "+
         "structures, looking extremely fragile. Elegant "+
         "spires weave around, echoing a natural theme in "+
         "their form.",
      ({"pathways","pathway","path","paths"}) : "%^BOLD%^The "+
         "crystalline pathways seem very narrow, barely "+
         "wide enough for one person to cross.  They have no "+
         "rails or support, leaving one feeling exposed when "+
         "upon them.%^RESET%^",
      ({"stairway","stairs"}) : "The stairway looks to have "+
         "been grown from the tree itself, as each step is "+
         "covered in bark and looks almost to be a natural "+
         "protrusion.  The stairs spiral around the trunk, "+
         "leading to an archer's platform above.",
      ({"platform","archer's platform"}) : "Rather unlike the "+
         "crystalline creations on the main level, the archer's "+
         "platform is a five-foot-wide wooden band that encircles "+
         "the tree trunks, allowing a full view of the land "+
         "surrounding the outpost."
   ]));
   set_exits(([
      "south" : ROOMS"aketon_meeting",
      "southwest" : ROOMS"aketon_shrine",
      "northwest" : ROOMS"aketon_general",
      "northeast" : ROOMS"aketon_healer",
      "southeast" : ROOMS"aketon_inn",
      "up" : ROOMS"aketon_archer"
   ]));
   set_climb_exits(([
      "descend" : ({ROOMS"aketon_camp",20,6,100})
   ]));
} 
