//Octothorpe (2/6/17)
//Three Coins Inn Restaurant
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Three Coins Patio, Three Coins Inn, Shadow");
   set_short("%^BOLD%^%^WHITE%^Three Coins Patio, Three Coins "+
      "Inn, Shadow%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Three Coins Patio, Three Coins "+
      "Inn, Shadow\n"+
      "%^BOLD%^%^WHITE%^The view up here is truly %^CYAN%^breathtaking "+
      "%^WHITE%^as it stretches over the city and, on a clear day, "+
      "off into the %^RESET%^%^CYAN%^i%^BOLD%^%^GREEN%^n%^BLUE%^f"+
      "%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^n%^GREEN%^it%^BLUE%^e "+
      "%^RESET%^%^CYAN%^s%^BOLD%^%^BLUE%^e%^GREEN%^a %^WHITE%^in the "+
      "distance. A low, %^GREEN%^i%^RESET%^%^GREEN%^v%^BOLD%^y-e%^RESET%^"+
      "nt%^GREEN%^a%^BOLD%^ngl%^RESET%^e%^BOLD%^%^GREEN%^d %^WHITE%^"+
      "wall is all that stands between you and the far, far drop to "+
      "the ground below. The patio is narrow but provides a comfortable "+
      "lounging area complete with %^BLACK%^private booths%^WHITE%^. In "+
      "the center of each table burns a small ring of %^RED%^fi%^BLACK%^"+
      "r%^RED%^e%^WHITE%^, providing light and warmth when it is needed. "+
      "%^GREEN%^Rugs %^WHITE%^break up the space and add an element of "+
      "design to the tiled floor.\n"+
      "%^RESET%^%^GREEN%^Some strange mass of plants has"+
      " grown off to one corner.  It looks like a booth of"+
      " some sorts with a table in it.   How the plants were"+
      " made to grow in such a way seems odd.");
   set_smell("default","%^CYAN%^The %^WHITE%^enticing %^CYAN%^smell of "+
      "food makes your mouth water.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^Soft piano music provides a "+
      "pleasant backdrop to the %^RESET%^susurration %^BOLD%^%^CYAN%^of "+
      "conversations.%^RESET%^");
   set_items(([
      "view" : "%^RESET%^%^CYAN%^Standing at one of the city's highest "+
         "points, the rooftops and roads below seem quite %^BOLD%^"+
         "serene%^RESET%^%^CYAN%^. From here, you can watch the city go "+
         "about its daily business, and off in the distance you can just "+
         "make out where the %^BOLD%^%^BLUE%^v%^RESET%^%^GREEN%^a"+
         "%^CYAN%^s%^BOLD%^%^BLUE%^t bl%^RESET%^%^GREEN%^u%^BOLD%^"+
         "%^BLUE%^e s%^RESET%^%^GREEN%^e%^BOLD%^%^BLUE%^a %^RESET%^"+
         "%^CYAN%^meets the horizon.%^RESET%^",
      "wall" : "%^RESET%^%^CYAN%^The %^BOLD%^%^BLACK%^stone wall "+
         "%^RESET%^%^CYAN%^is wide enough that a particularly daring "+
         "soul might sit on it. But it's quite a far drop to the ground "+
         "below. %^BOLD%^%^GREEN%^Ivy %^RESET%^%^CYAN%^creeps along the "+
         "old rocks, covered in %^WHITE%^small white blossoms"+
         "%^CYAN%^.%^RESET%^",
      ({"tables","booths","fire","fire pit"}) : "%^RESET%^%^CYAN%^Each "+
         "table is cut from a heavy slab of %^BOLD%^%^BLACK%^black "+
         "granite%^RESET%^%^CYAN%^, and in the middle of each table is "+
         "dug a ring-shaped trench. The ring is filled with %^BOLD%^"+
         "%^BLACK%^oil-coated stones%^RESET%^%^CYAN%^, and then set "+
         "%^BOLD%^%^RED%^alig%^RESET%^%^RED%^h%^BOLD%^t %^RESET%^"+
         "%^CYAN%^to %^BOLD%^%^BLACK%^smolder%^RESET%^%^CYAN%^. It makes "+
         "for an interesting - if not slightly dangerous - "+
         "centerpiece.%^RESET%^",
      ({"rugs","floor","tiles"}) : "%^RESET%^%^CYAN%^Each table is "+
         "divided into its own section by the rug beneath it. The rugs "+
         "are muted, %^ORANGE%^neutral %^CYAN%^shades, their borders "+
         "that of %^BOLD%^%^WHITE%^i%^ORANGE%^n%^RESET%^%^ORANGE%^t"+
         "%^BOLD%^e%^WHITE%^rlo%^ORANGE%^c%^RESET%^%^ORANGE%^k%^BOLD%^"+
         "i%^WHITE%^ng r%^ORANGE%^i%^RESET%^%^ORANGE%^n%^BOLD%^g"+
         "%^WHITE%^s%^RESET%^%^CYAN%^. Small square marble tiles, "+
         "%^BOLD%^%^BLACK%^darkly colored%^RESET%^%^CYAN%^, add a "+
         "nice touch to the patio floor.%^RESET%^",
      ({"plants","booth"}) : "The plants growing almost seem"+
      " like a shelter of some sort.  A person or two could "+
      "hide in here and have a private meal.  The owner looked"+
      " to have added a small table an a couple of chairs "+
      "with that in mind."     
   ]));
   set_exits(([
      "south" : ROOMS"3coinsrest"
   ]));
   set_door("glass door",ROOMS"3coinsrest","south",0,0);
   set_door_description("copper door","%^RESET%^This %^BOLD%^glass "+
      "door %^RESET%^leads inside to the restaurant.");
}    
