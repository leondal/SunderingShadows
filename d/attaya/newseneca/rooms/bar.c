#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("The Salt Merchant, Seneca");
   set_short("%^BOLD%^%^BLUE%^The Salt Merchant, Seneca%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^The Salt Merchant, Seneca%^RESET%^\n"+
      "This tavern is filled with a raucous crowd at all times of the day "+
      "or night.  The %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand that covers so much of Seneca "+
      "is allowed to collect here, and it lies piled in the corners, only "+
      "swept away by the countless feet that meander toward the %^ORANGE%^"+
      "bar%^RESET%^.  The base of the bar itself is part of an old %^ORANGE%^"+
      "ship's hull%^RESET%^, complete with a few round %^CYAN%^portholes"+
      "%^RESET%^!  A %^ORANGE%^wooden countertop %^RESET%^has been placed atop "+
      "the hull, and it seems to stay %^CYAN%^soaked %^RESET%^with %^BOLD%^"+
      "alcohol %^RESET%^all the time.  Several mismatched %^ORANGE%^barstools "+
      "%^RESET%^stand in front of the bar, while small, round %^ORANGE%^tables "+
      "%^RESET%^are scattered around.  The %^BOLD%^%^BLUE%^walls %^RESET%^have "+
      "been painted %^BOLD%^%^BLUE%^blue %^RESET%^and are covered with all "+
      "types of %^BOLD%^nautical items %^RESET%^- from small %^YELLOW%^"+
      "hourglasses %^RESET%^and %^BOLD%^knotted rope %^RESET%^to %^BOLD%^nets %^RESET%^and "+
      "even an old %^BOLD%^%^BLACK%^pirate flag%^RESET%^.  No nautical tavern "+
      "would be complete without an %^BOLD%^%^BLACK%^anchor%^RESET%^, and "+
      "this bar is no exception - it is hanging behind the bar.  A %^BOLD%^%^BLUE%^"+
      "door %^RESET%^to the left of the bar leads into a back room of some "+
      "sort that often has people coming and going.\n");
   set_smell("default","The pungent stench of unwashed bodies is thankfully masked by the aroma of alcohol.");
   set_listen("default","Laughter and conversation makes it difficult to hear anything else.");
   set_items(([
      ({"crowd","people"}) : "The crowd here at the Salt Merchant is always "+
         "mixed lot.  You see sailors, merchants, tourists, members of the "+
         "guard...most everyone seems to stop by from time to time.  You "+
         "notice that many of them seemed to be grouped by kind at different "+
         "tables.",
      ({"sailor","sailors"}) : "A group of sailors fresh from the sea "+
         "is seated at a table in the corner, telling jokes and enjoying "+
         "their time on shore.",
      ({"merchant","merchants"}) : "You notice a few merchants meeting "+
         "with all manner of people in various places in the bar.  Most "+
         "of them are likely arranging to buy or transport cargo.",
      ({"tourist","tourists"}) : "The tourists seem to congregate in groups, "+
         "and look around with apprehension and excitement from their "+
         "tables.",
      ({"guard","members","members of the guard"}) : "Members of the guard "+
         "dressed in uniforms with the %^BOLD%^%^BLUE%^seal %^RESET%^of "+
         "Seneca typically sit in ones and twos at the bar after a long "+
         "day at work.",
      ({"sand","golden sand","piles"}) : "%^YELLOW%^G%^WHITE%^o%^RESET%^l"+
         "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand has piled in the corners and "+
         "seems to be allowed to remain there.  It's likely the place has "+
         "not been swept in years.  In the main pathways, the sand has "+
         "been pushed aside from the many customers as they walk to the bar.",
      ({"bar","hull","ship's hull","countertop"}) : "%^ORANGE%^An aged "+
         "ship's hull with a wooden countertop has been used as the bar.  "+
         "Judging from the size, it is clearly only a fraction of the hull, "+
         "but several %^CYAN%^portholes %^ORANGE%^are still attached, giving "+
         "it quite a nautical feel.%^RESET%^",
      ({"porthole","portholes"}) : "Each of the %^CYAN%^portholes %^RESET%^"+
         "features a %^ORANGE%^brass ring %^RESET%^with a thick, round "+
         "pane of %^CYAN%^glass %^RESET%^that can be opened to let in "+
         "air on a ship.  There are only three visible on the bar, each "+
         "about midway between the floor and countertop.",
      "alcohol" : "Alcohol seems to surround you here - in mugs, glasses, "+
         "and even spilled along the bar.",
      ({"barstool","barstools","stool","stools"}) : "Each of the stools by "+
         "the bar is wooden and about three feet tall.  That is where their "+
         "similarities ends, however, as each seems to be crafted in a "+
         "different way.",
      ({"table","tables","chair","chairs"}) : "Round tables with mismatched "+
         "chairs are scattered about the room.  Each looks to have been made "+
         "from weathered wood, likely taken from the wreckage of ships.",
      ({"wall","walls"}) : "%^BOLD%^%^BLUE%^The walls here are painted "+
         "blue, making the bar seem somewhat smaller and darker than it "+
         "really is.%^RESET%^",
      ({"equipment","nautical equipment"}) : "A wide array of gadgets and "+
         "pieces of ships have been placed upon the walls.  You see old "+
         "bits of rigging, pieces of driftwood, and dislodged portholes "+
         "among the other pieces of equipment.",
      ({"hourglass","hourglasses","rope","knotted rope"}) : "Not only useful "+
         "for telling time, the hourglass can also be used by clever captains "+
         "in conjunction with a knotted rope for telling the speed of a "+
         "ship.  Wonder how they do that...",
      ({"net","nets"}) : "Old netting of different thicknesses are spread "+
         "around the walls, providing decoration.  In some places, starfish "+
         "and shells have been 'captured' in the nets.",
      ({"flag","pirate flag"}) : "%^BOLD%^%^BLACK%^The black flag shows a "+
         "%^WHITE%^horned skeleton %^BLACK%^holding an %^RED%^hourglass "+
         "%^BLACK%^above crossed %^WHITE%^scimitars%^BLACK%^.%^RESET%^",
      "anchor" : "%^BOLD%^%^BLACK%^The iron anchor hanging above the bar "+
         "shows signs of %^RESET%^%^RED%^rust %^BOLD%^%^BLACK%^and "+
         "decay - likely the reason it is hanging here rather than off "+
         "a ship somewhere.%^RESET%^"
   ]));
   set_exits(([
      "north" : ROOMS"viento58",
      "south" : ROOMS"bar_cards"
   ]));
   set_door("bar door","/d/attaya/newseneca/rooms/viento58","north",0);
   set_door_description("bar door","%^BOLD%^%^BLUE%^Painted blue, the "+
      "door is fairly non-descript otherwise.  It is set within the "+
      "northern wall, and it is designed to swing both inward and "+
      "outward, allowing drunk patrons easy access to the street.%^RESET%^");
   set_door("door","/d/attaya/newseneca/rooms/bar_cards","south",0);
   set_door_description("door","%^BOLD%^%^BLUE%^Painted blue, the "+
      "door to the left of the bar nearly blends in with the wall.  "+
      "You cannot quite tell from here what goes on beyond it.%^RESET%^");
}

void reset() {
    object ob;
  ::reset();
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("salt_merchant");
        ob->move(TO);
    }
    if(!present("barkeep")){
      find_object_or_load(MON"jericho")->move(TO);
    }
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str){
   object obj,obj2;
   int i;
   string *names;
   if(str == "list" && obj2 = present("dartboard")) {
      names = obj2->query_mastery_list();
      if(sizeof(names) < 1){
         write("%^BOLD%^No one has yet mastered darts at this bar!\n"+
            "Will you be the first?");
         return 1;
      }else{
         write("The following individuals are recognized as having "+
            "mastered the game of darts.");
         for(i = 0;i < sizeof(names);i++) {
            tell_object(TP,"%^BOLD%^%^CYAN%^"+(i+1)+" %^BOLD%^%^WHITE%^- "+
               "%^BLUE%^"+capitalize(names[i])+"%^RESET%^\n");
         }
      }
      return 1;
   }
   if(!present("barkeep")) {
      write("The bartender doesn't seem to be here to show you the menu.");
      return 1;
   }
   obj = present("barkeep");
   if(str == "menu") {
      if(!TP->query_invis()) tell_room(TO,""+TPQCN+" reads over the menu.",TP);
      message("Ninfo","The menu is on a small sign on the bar, and it "+
         "lists these items:\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^-------------------------%^CYAN%^# %^WHITE%^Highballs %^CYAN%^#%^BLUE%^------------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^YELLOW%^Seneca %^RESET%^%^MAGENTA%^Su%^BOLD%^nr%^RED%^is%^YELLOW%^e%^RESET%^        \t\t"+
         ""+(int)obj->get_price("seneca sunrise")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^CYAN%^Sea Breeze%^RESET%^        \t\t"+
         ""+(int)obj->get_price("sea breeze")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^MAGENTA%^Ambrosia%^RESET%^        \t\t"+
         ""+(int)obj->get_price("ambrosia")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^BLACK%^Belladonna%^RESET%^        \t\t"+
         ""+(int)obj->get_price("belladonna")+" silver pieces\n",TP);
      message("Ninfo","\t%^ORANGE%^Bellini%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("bellini")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^-------------------------%^CYAN%^# %^WHITE%^Shooters %^CYAN%^#%^BLUE%^-------------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^BOLD%^Salty Dog%^RESET%^        \t\t"+
         ""+(int)obj->get_price("salty dog")+" silver pieces\n",TP);
      message("Ninfo","\t%^ORANGE%^Butterball%^RESET%^        \t\t"+
         ""+(int)obj->get_price("butterball")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Seneca %^BLACK%^Dust%^RESET%^        \t\t"+
         ""+(int)obj->get_price("seneca dust")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^BLACK%^Beshaba's %^RED%^Kiss%^RESET%^        \t\t"+
         ""+(int)obj->get_price("beshaba's kiss")+" silver pieces\n",TP);
      message("Ninfo","\t%^ORANGE%^Prairie %^YELLOW%^F%^RED%^i%^RESET%^%^ORANGE%^r%^YELLOW%^e%^RESET%^        \t\t"+
         ""+(int)obj->get_price("prairie fire")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Three Priests%^RESET%^        \t\t"+
         ""+(int)obj->get_price("three priests")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^RED%^Oyster Shooter%^RESET%^        \t\t"+
         ""+(int)obj->get_price("oyster shooter")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^---------------------------%^CYAN%^# %^WHITE%^Ales %^CYAN%^#%^BLUE%^---------------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^ORANGE%^Attaya Ale%^RESET%^        \t\t"+
         ""+(int)obj->get_price("attaya ale")+" silver pieces\n",TP);
      message("Ninfo","\t%^MAGENTA%^Bruiser%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("bruiser")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^Mercenary's Milk%^RESET%^        \t"+
         ""+(int)obj->get_price("mercenary's milk")+" silver pieces\n",TP);
      message("Ninfo","\t%^CYAN%^Seafarer's Slop%^RESET%^        \t\t"+
         ""+(int)obj->get_price("seafarer's slop")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^---------------------------%^CYAN%^# %^WHITE%^Shots %^CYAN%^#%^BLUE%^--------------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^BOLD%^Vodka%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("vodka")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^GREEN%^Tequila%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("tequila")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^Rum%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("rum")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^MAGENTA%^Brandy%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("brandy")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^Gin%^RESET%^        \t\t\t"+
         ""+(int)obj->get_price("gin")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^-------------------%^CYAN%^# %^WHITE%^Non-Alcoholic Drinks %^CYAN%^#%^BLUE%^-------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^CYAN%^Briny Deep%^RESET%^        \t\t"+
         ""+(int)obj->get_price("briny deep")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^Coconut Milk%^RESET%^        \t\t"+
         ""+(int)obj->get_price("coconut milk")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^MAGENTA%^Pomegranate Juice%^RESET%^        \t"+
         ""+(int)obj->get_price("pomegranate juice")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^---------------------------%^CYAN%^# %^WHITE%^Foods %^CYAN%^#%^BLUE%^--------------------------%^CYAN%^#\n",TP);
      message("Ninfo","\t%^ORANGE%^Shrimp Empanadas%^RESET%^        \t"+
         ""+(int)obj->get_price("shrimp empanadas")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Fish Cakes%^RESET%^        \t\t"+
         ""+(int)obj->get_price("fish cakes")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^Rag Pudding%^RESET%^        \t\t"+
         ""+(int)obj->get_price("rag pudding")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Fisherman's %^MAGENTA%^P%^WHITE%^a%^YELLOW%^e%^WHITE%^l%^MAGENTA%^l%^YELLOW%^a%^RESET%^        \t"+
         ""+(int)obj->get_price("fisherman's paella")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^#%^BLUE%^--------------------------------------------------------------%^CYAN%^#\n",TP);
      message("Ninfo","<buy item_name> gets you the food or drink.\n",TP);
      return 1;
   }
}
