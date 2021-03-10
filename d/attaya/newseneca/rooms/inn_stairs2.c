//inn_stairs2.c by ~Circe~ 12/22/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Stairway of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "The %^ORANGE%^stairway%^RESET%^ winding upward through the %^BOLD%^%^MAGENTA%^"+
      "Tropical Breeze %^RESET%^features a bannister made of unfinished "+
      "%^BOLD%^driftwood%^RESET%^. Paintings of %^ORANGE%^beach %^RESET%^and "+
      "%^CYAN%^fishing %^RESET%^scenes are scattered here and there in the "+
      "soft %^BOLD%^glow %^RESET%^of decorative %^BOLD%^%^GREEN%^g%^BLUE%^l%^CYAN%^a"+
      "%^WHITE%^s%^GREEN%^s%^BLUE%^ g%^CYAN%^l%^WHITE%^o%^GREEN%^b"+
      "%^BLUE%^e%^CYAN%^s%^RESET%^ that dangle from the ceiling. Three doors open "
      "off of the landing here, to the east, south, and west.\n");
   set_smell("default","The light fragrance of the sea seems to linger here.");
   set_listen("default","The soft murmur of conversation rises from the floor below.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps. They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      ({"bannister","driftwood","driftwood bannister"}) : "The roughly finished "+
         "bannister is worn smooth in places from countless hands. It is "+
         "bleached white from the sun, echoing the floor tiles.",
      ({"painting","paintings","scene","scenes"}) : "Various scenes, from "+
         "painted shells to images of families on the beach, are placed "+
         "at random intervals along the wall, giving the hallway a "+
         "comfortable, welcoming feeling.",
      "doors" : "The bound oak doors that line the hallway have each been "
         "painted with a different flower: %^BOLD%^"
         "%^MAGENTA%^p%^WHITE%^ink-%^MAGENTA%^t%^WHITE%^ipped "
         "%^MAGENTA%^p%^WHITE%^lumeria%^RESET%^, %^BOLD%^%^BLUE%^b"
         "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
         "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
         "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^RESET%^, and %^MAGENTA%^"
         "purple bougainvillea%^RESET%^."
   ]));
   set_exits(([
      "down" : ROOMS"inn_stairs",
      "south" : ROOMS"inn_restroom",
      "east" : ROOMS"inn_plumeria",
      "west" : ROOMS"inn_orchid",
      "up" : ROOMS"inn_stairs3"
   ]));
   set_door("bougainvillea door","/d/attaya/newseneca/rooms/inn_restroom","south",0);
   set_door_description("bougainvillea door","The wooden door to the south "
      "has been decorated with a painting of %^MAGENTA%^purple bougainvillea%^RESET%^. "
      "The cluster of bougainvillea has tiny, heart-shaped %^GREEN%^leaves %^RESET%^"
      "with drip tips similar to %^GREEN%^ivy leaves%^RESET%^. Peeking from among the "
      "%^GREEN%^leaves %^RESET%^are groups of small %^MAGENTA%^purple flowers%^RESET%^. "
      "Painted in delicate script beneath the flowers is the word '%^CYAN%^Lavatory%^RESET%^'.");
   set_door("plumeria door","/d/attaya/newseneca/rooms/inn_plumeria","east",0);
   set_door_description("plumeria door","The wooden door to the east has been "
      "decorated with a painting of a %^BOLD%^"
      "%^MAGENTA%^p%^WHITE%^ink-%^MAGENTA%^t%^WHITE%^ipped "
      "%^MAGENTA%^p%^WHITE%^lumeria%^RESET%^. Each blossom features "
      "five rounded petals that are "
      "%^YELLOW%^yellow %^RESET%^in the center and fade to a "
      "flawless %^BOLD%^white %^RESET%^before ending with a %^BOLD%^%^MAGENTA%^pink "
      "edge %^RESET%^completely encircling the petal.");
   set_door("orchid door","/d/attaya/newseneca/rooms/inn_orchid","west",0);
   set_door_description("orchid door","The wooden door to the west "
      "has been decorated with a painting of two %^BOLD%^%^BLUE%^b"
      "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
      "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
      "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^ "
      "with their %^GREEN%^stems %^RESET%^crossed. Five wide, fanning "
      "petals of a %^BOLD%^%^BLUE%^radi%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^nt "
      "bl%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^e%^RESET%^ make up each pretty orchid.  The "
      "blue is broken by tiny %^BOLD%^white dots %^RESET%^that "
      "provide a pleasant contrast.");
}

