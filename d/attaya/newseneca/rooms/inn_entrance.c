#include <std.h>
#include "../seneca.h"

inherit "/std/rquestroom";

void create(){
   object ob;
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_no_clean(1);
   set_property("light",2);
   set_name("Entryway of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Entryway of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Entryway of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "Designed with the comfort of weary travelers in mind, "+
      "this entry hall is filled with all the accoutrements of "+
      "a lounge.  Several light-framed %^CYAN%^sofas %^RESET%^"+
      "and %^BOLD%^%^MAGENTA%^chairs %^RESET%^have been "+
      "scattered about, crafted of %^YELLOW%^bamboo %^RESET%^"+
      "with %^ORANGE%^oak %^RESET%^accents and fitted with soft, "+
      "durable cushions in an array of bright, airy %^CYAN%^"+
      "c%^ORANGE%^o%^GREEN%^l%^YELLOW%^o%^MAGENTA%^r%^WHITE%^s"+
      "%^RESET%^.  Though the floor is crafted from locally "+
      "quarried %^BOLD%^stone%^RESET%^, it is covered with "+
      "several thin %^CYAN%^rugs %^RESET%^that provide a bit "+
      "of cushioning to tired feet.  Cheerful paintings of "+
      "%^BOLD%^%^BLUE%^beach scenes %^RESET%^grace the walls, "+
      "while decorative %^BOLD%^%^GREEN%^g%^BLUE%^l%^CYAN%^a"+
      "%^WHITE%^s%^GREEN%^s%^BLUE%^ g%^CYAN%^l%^WHITE%^o%^GREEN%^b"+
      "%^BLUE%^e%^CYAN%^s%^RESET%^ that seem to glow with a "+
      "light all their own hang from the ceiling at different "+
      "heights to provide soft illumination.  A doorway to the "+
      "south leads to the stables, and a central aisle "+
      "in the middle of the seating arrangement grants access "+
      "deeper into the inn, where a bakery, a bar, and "+
      "stairs leading to the rooms above are all visible.\n");
   set_smell("default","The light fragrance of the sea seems to linger here.");
   set_listen("default","Voices engaged in conversation reach your ears.");
   set_items(([
      ({"sofa","sofas","chair","chairs"}) : "Each of the couches "+
         "and chairs is lightly framed in %^YELLOW%^bamboo %^RESET%^"+
         "and set with %^ORANGE%^oaken armrests%^RESET%^, making them "+
         "sturdy.  They are fitted with brightly colored %^CYAN%^c"+
         "%^YELLOW%^u%^GREEN%^s%^WHITE%^h%^MAGENTA%^i%^RED%^o%^BLUE%^n"+
         "%^RESET%^%^ORANGE%^s %^RESET%^that add to the beachy "+
         "atmosphere of this inn.",
      ({"cushion","cushions"}) : "The cushions are fluffy, and each "+
         "is tied to the bamboo frame to prevent slipping.  Each "+
         "cushion is covered in a different fabric, some %^BOLD%^"+
         "s%^RED%^t%^YELLOW%^r%^GREEN%^i%^CYAN%^p%^BLUE%^e%^MAGENTA%^d"+
         "%^RESET%^, while some are simple different %^GREEN%^c"+
         "%^BOLD%^o%^RED%^l%^RESET%^%^ORANGE%^o%^MAGENTA%^r"+
         "%^CYAN%^s %^RESET%^of solids.",
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"rug","rugs"}) : "Each of the rugs is thin and hand-woven "+
         "right here in Seneca.  They feature an array of %^BOLD%^"+
         "s%^RED%^t%^YELLOW%^r%^GREEN%^i%^CYAN%^p%^BLUE%^e%^MAGENTA%^s"+
         "%^RESET%^ that mixes well with the colorful cushions of "+
         "the sofas and chairs.",
      ({"painting","paintings","scenes","beach scenes"}) : "Various "+
         "scenes of beach activity line the walls, from tranquil "+
         "paintings of the %^CYAN%^deep sea %^RESET%^lit by %^BOLD%^"+
         "moonlight%^RESET%^ to images of %^BOLD%^%^MAGENTA%^children %^RESET%^happily at "+
         "play in the %^YELLOW%^s%^WHITE%^a%^RESET%^n%^YELLOW%^d%^RESET%^.  They seem to have been chosen for their "+
         "subject matter rather than the skill of the artists, as "+
         "some are rather crudely done while others could almost "+
         "be called masterpieces.  Each one is framed in a simple "+
         "unfinished wooden frame left to silver in the elements.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      "bakery" : "The bakery is just visible to the "+
         "southwest.  The entrance is right beside the stairway "+
         "leading to the second floor.",
      "bar" : "A lively bar with a cozy stage is just visible "+
         "past the stairway to the west.",
      ({"stairs","stairway"}) : "A stairway tiled in the same "+
         "stone as the rest of the floor is visible to the "+
         "west.  It likely leads to the rooms for rent.",
   ]));
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board"}) );
   ob->set_short("Arcane Bulletin Board");
   ob->set_long("This simple corkboard is surrounded by a wooden "+
      "border painted vibrant purple.  All manner of notices are "+
      "found tacked here, along with a %^BOLD%^list%^RESET%^ of "+
      "quest items you could read.");
   ob->set_board_id("union_board");
   ob->set_max_posts(50);
   ob->set_location("/d/attaya/newseneca/rooms/inn_entrance");
   set_quest_daemon("/daemon/quests_high");
   set_exits(([
      "east" : ROOMS"skyline41",
      "south" : ROOMS"stable",
      "west" : ROOMS"inn_main"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/skyline41","east",0);
   set_door("stable door","/d/attaya/newseneca/rooms/stable","south",0,0);
   set_door_description("stable door","This small door leads through the "+
      "northern wall into the inn's entry hall, giving patrons easy "+
      "access to the comforts of the inn.");
   set_open("stable door",1);
}

  void init(){
    
  ::init();
    
  "/d/atoyatl/garus_locator_d.c"->initiate_garus_check(TO);
}
