//inn_restroom.c by ~Circe~ 12/22/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Lavatory of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Lavatory of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Lavatory of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "Although simple, this little lavatory has been enhanced by magic. The %^BOLD%^%^GREEN%^g%^BLUE%^l%^CYAN%^a"+
      "%^WHITE%^s%^GREEN%^s%^BLUE%^ g%^CYAN%^l%^WHITE%^o%^GREEN%^b"+
      "%^BLUE%^e%^CYAN%^s%^RESET%^ lighting the inn are spaced at irregular intervals "
      "along the wall, providing ample illumination. A %^ORANGE%^claw-footed tub %^RESET%^dominates the "
      "space, offering room for a large human to stretch out and relax. The enchanted "
      "pipes can summon hot or cold water as desired - all one need do is turn the "
      "appropriately colored crystal handle. A %^ORANGE%^plush rug%^RESET%^ is spread out before the tub, "
      "protecting one's feet from the cold %^BOLD%^st%^RESET%^o%^BOLD%^ne floor%^RESET%^. In the northern part of the room, "
      "concealed behind a %^ORANGE%^painted screen%^RESET%^, is a small latrine. A series of %^BOLD%^driftwood "
      "shelves %^RESET%^house fluffy %^CYAN%^towels%^RESET%^, %^BOLD%^soaps%^RESET%^, "
      "%^BOLD%^%^MAGENTA%^shampoos%^RESET%^, and %^YELLOW%^scented oils%^RESET%^ for guests to use.\n");
   set_smell("default","The air is filled with the powerful fragrance of sandalwood and spice.");
   set_listen("default","The murmur of the inn is muffled by the thick wooden door.");
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
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      ({"tub","claw-footed tub","bathtub","bath tub"}) : "The porcelain tub "
         "stands on brass claw feet that keep it off the floor. The far end slopes "
         "gently, providing a comfortable place for one to recline. The faucet is "
         "braced by crystal handles - one %^RED%^red %^RESET%^and the other "
         "%^BLUE%^blue%^RESET%^. The former will produce hot water, while the "
         "latter will temper it with cold. If you choose, you could %^CYAN%^wash%^RESET%^ "
         "yourself in the tub.",
      ({"rug","plush rug"}) : "%^ORANGE%^The thick rug is woven from absorbent "
         "material in an array of %^CYAN%^c%^YELLOW%^o%^GREEN%^l%^MAGENTA%^o"
         "%^CYAN%^r%^RESET%^%^MAGENTA%^s%^RESET%^%^ORANGE%^. It covers much of "
         "the stone floor, providing a warm place for bare feet.%^RESET%^",
      ({"shelf","shelves","soap","soaps","shampoo","shampoos","oils","scented oils","towels","towel"}) :
         "The three shelves are carved from %^BOLD%^driftwood%^RESET%^, "
         "sanded smooth and varnished to a high shine. The top two hold mounds of "
         "fluffy %^MAGENTA%^towels%^RESET%^ while the lower shelf has a collection "
         "of bottles filled with fragrant scented oils and shampoos. Scattered among "
         "them are a few small dishes holding soaps of various shapes, colors, and scents.",
      ({"screen","painted screen"}) : "%^RESET%^%^ORANGE%^The screen is fashioned "
         "from four slender bamboo frames covered in stretched silk. A simple %^RESET%^"
         "beach scene %^ORANGE%^has been painted onto the smooth surface, depicting "
         "%^YELLOW%^sand dunes %^RESET%^%^ORANGE%^with waving %^GREEN%^sea oats %^ORANGE%^"
         "against a %^CYAN%^cloudless sky%^ORANGE%^. The screen separates the larger portion "
         "of the lavatory from the latrine.%^RESET%^",
      "latrine" : "Set atop a wooden stand is a porcelain chamberpot enchanted to whisk away waste."
   ]));
   set_exits(([
      "north" : ROOMS"inn_stairs2"
   ]));
   set_door("bougainvillea door","/d/attaya/newseneca/rooms/inn_stairs2","north",0);
   set_door_description("bougainvillea door","On this side, the door has been %^BOLD%^whitewashed "
      "%^RESET%^and distressed, allowing hints of the oak to shine through. The overall "
      "effect is rustic and charming, if one likes that sort of thing.");
}

void init(){
   ::init();
   add_action("wash_em","wash");
}

int wash_em(string str){
   if(!str){
      tell_object(TP,"You might want to try washing in the tub.");
      return 1;
   }
   if(str == "in tub" || str == "in the tub"){
      tell_object(TP,"Stretching out in the tub, you lather yourself with soap "
         "and rinse throughly. Ahh ... it feels good to get rid of all that grime.");
      tell_room(ETP,""+TPQCN+" washes "+TP->QO+"self in the tub.",TP);
      TP->set("long");
      return 1;
   }
   tell_object(TP,"You want to wash where? Try washing in the tub.");
   return 1;
}
