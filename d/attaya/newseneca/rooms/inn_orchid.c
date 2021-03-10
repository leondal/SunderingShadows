//inn_orchid.c by ~Circe~ 12/22/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Guest Room of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Guest Room of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Guest Room of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "%^RESET%^%^CYAN%^This room has been furnished with opulence for two in mind. The "
      "wide, four-poster bed is covered in rich %^BOLD%^%^WHITE%^cr%^RESET%^e%^BOLD%^am "
      "s%^RESET%^i%^BOLD%^lks %^RESET%^%^CYAN%^delicately embroidered with %^BOLD%^%^BLUE%^b"
      "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
      "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
      "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^%^CYAN%^. "
      "%^BOLD%^%^WHITE%^Pillows %^RESET%^%^CYAN%^edged in %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^are "
      "piled high on the bed, offering supreme comfort. A %^ORANGE%^mahogany chest "
      "%^RESET%^%^CYAN%^covered with a %^BOLD%^%^WHITE%^cr%^RESET%^e%^BOLD%^am%^RESET%^-%^BOLD%^co"
      "%^RESET%^l%^BOLD%^or%^RESET%^e%^BOLD%^d silk cushion %^RESET%^%^CYAN%^stands at "
      "the foot of the bed, empty for guests to use. A small, coordinating %^ORANGE%^table%^RESET%^%^CYAN%^ "
      "braced by two %^ORANGE%^chairs %^RESET%^%^CYAN%^is in the southwestern corner of the room, offering an "
      "intimate dining space. Suspended from the ceiling over the table is an "
      "artfully arranged collection of candles of different shapes and sizes, all "
      "in a soothing %^BOLD%^%^WHITE%^cr%^RESET%^e%^BOLD%^am%^RESET%^%^CYAN%^. The warm glow from "
      "the candles casts flickering shadows around the room, most unlike the globes "
      "that light the rest of the inn. A wooden stand beside the table holds a %^BOLD%^%^WHITE%^silver "
      "bucket %^RESET%^%^CYAN%^that may be filled with %^BOLD%^ice %^RESET%^%^CYAN%^to "
      "chill a bottle of wine. A dark %^ORANGE%^wooden vanity %^CYAN%^on the eastern wall "
      "features a delicate %^BOLD%^%^WHITE%^mirror %^RESET%^%^CYAN%^one might use when "
      "seated upon the matching %^BOLD%^%^WHITE%^padded bench%^RESET%^%^CYAN%^. Across the room is a "
      "wide, arched %^BOLD%^window %^RESET%^%^CYAN%^framing a serene view of the rooftops of "
      "%^YELLOW%^Seneca %^RESET%^%^CYAN%^and the clear %^BOLD%^blue sky%^RESET%^%^CYAN%^. Vases of %^BOLD%^"
      "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
      "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^%^CYAN%^ "
      "placed around the room complete the lavish atmosphere.%^RESET%^\n");
   set_smell("default","The light fragrance of the sea is nearly obscured by the scent of orchids.");
   set_listen("default","The soft hum of the city rises from the streets.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"candle","candles"}) : "A square %^ORANGE%^bronze frame %^RESET%^suspended from "
         "thin %^ORANGE%^bronze wires %^RESET%^hangs over the table, supporting an "
         "array of %^BOLD%^%^WHITE%^cr%^RESET%^e%^BOLD%^am%^RESET%^-%^BOLD%^co"
         "%^RESET%^l%^BOLD%^or%^RESET%^e%^BOLD%^d candles%^RESET%^ of various sizes.",
      ({"bed","four-poster bed"}) : "%^RESET%^%^ORANGE%^The bed is made of mahogany, "
         "carved in simple, clean lines. The rich, dark wood has been polished until "
         "it gleams, and the eye is drawn to the luxurious %^BOLD%^%^WHITE%^cr"
         "%^RESET%^e%^BOLD%^am%^RESET%^-%^BOLD%^co"
         "%^RESET%^l%^BOLD%^or%^RESET%^e%^BOLD%^d silk %^RESET%^%^ORANGE%^bed linens.",
      ({"linens","sheets","sheet","silks"}) : "The silks are smooth to the touch "
         "and shimmer faintly in the light. A true artist has embroidered delicate %^BOLD%^%^BLUE%^b"
         "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
         "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
         "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^BOLD%^%^BLUE%^s%^RESET%^ along the edges.",
      ({"pillow","pillows"}) : "The pillows are crafted from a variety of rich materials "
         "- silk, velvet, and even corduroy - and edged in blue. Some are embroidered with "
         "orchids or simple designs that enhance the plethora of shapes and textures.",
      ({"chest","mahogany chest","cushion"}) : "The mahogany chest is plain but well-made, "
         "and the padded top offers extra seating if needed.",
      ({"table","chair","chairs"}) : "Slender legs carved of dark wood "
         "support the stone top of the square bistro table. The chairs are fashioned "
         "from mahogany and fitted with %^CYAN%^blue silk cushions%^RESET%^.",
      ({"stand","wooden stand","wood stand","bucket","silver bucket","ice bucket"}) : 
         "The simple wooden frame standing beside the table holds a polished silver "
         "bucket that may be filled with ice. Closer inspection reveals a small "
         "drawer that holds a corkscrew for your convenience.",
      ({"vanity","bench","mirror","wooden vanity","padded bench"}) : "Elegant in "
         "its simplicity, the wooden vanity is crafted with clean lines. The mirror "
         "is an oval of silvered glass supported by slender curved arms. The piece is "
         "finished with a padded bench designed for comfort.",
      ({"window","arched window","view","rooftops","sky"}) : "%^RESET%^%^CYAN%^The window "
         "in the western wall opens onto a quieter view of Seneca. In the distance, you "
         "can see the unique rooftop of the bank, constructed from panels of glass set in wood.",
      ({"orchid","orchids","vases","vase"}) : "Placed here and there around the "
         "room are slender vases holding the %^BOLD%^%^BLUE%^b"
         "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
         "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
         "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^BOLD%^%^BLUE%^s %^RESET%^that make "
         "this room distinct. Five wide, fanning "
         "petals of a %^BOLD%^%^BLUE%^radi%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^nt "
         "bl%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^e%^RESET%^ make up each pretty orchid.  The "
         "blue is broken by tiny %^BOLD%^white dots %^RESET%^that "
         "provide a pleasant contrast."
   ]));
   set_exits(([
      "east" : ROOMS"inn_stairs2",
   ]));
   set_door("orchid door","/d/attaya/newseneca/rooms/inn_stairs2","east",0);
}

