//~Circe~ 1/2/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Courtyard of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Courtyard of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Courtyard of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "The smooth %^BOLD%^%^BLACK%^gray stone walls %^RESET%^of "+
      "this tower surround the most unlikely of sights - a "+
      "breathtaking %^BOLD%^%^CYAN%^waterfall %^RESET%^cascades "+
      "through the air, splashing into a %^BOLD%^%^CYAN%^g%^RESET%^"+
      "%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^t%^BOLD%^t%^RESET%^%^CYAN%^e"+
      "%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^g %^BOLD%^"+
      "pool%^RESET%^ shrouded with %^BOLD%^mist%^RESET%^.  The "+
      "%^BOLD%^%^CYAN%^waterfall %^RESET%^looks crystal clear on "+
      "first glance, but a closer look reveals all the colors of "+
      "the %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^i%^GREEN%^n"+
      "%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w %^RESET%^"+
      "coruscating within, adding their brilliance to the open "+
      "tower rising high above.  The source of the waterfall "+
      "is far out of sight from here - it seems to flow from "+
      "the very tip of the tower itself.  Encircling the %^CYAN%^"+
      "pool %^RESET%^in the floor are countless %^GREEN%^ferns "+
      "%^RESET%^and %^BOLD%^water flowers%^RESET%^, cultivating "+
      "the illusion of a %^GREEN%^hidden grotto%^RESET%^.  "+
      "%^RESET%^%^ORANGE%^Natural rock %^RESET%^has been shaped "+
      "by %^BOLD%^%^BLUE%^magic %^RESET%^to form several seats "+
      "that blend into the scenery, giving studious mages a "+
      "place to relax comfortably amid the serene landscape.  "+
      "The shifting of the %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^i"+
      "%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w "+
      "%^BOLD%^%^RED%^m%^RESET%^%^ORANGE%^i%^YELLOW%^s%^GREEN%^t"+
      "%^CYAN%^s%^RESET%^ reveals a %^CYAN%^glassteel spiral "+
      "staircase %^RESET%^in the northwestern portion of the room, "+
      "rising high overhead.  A partial ceiling twenty feet "+
      "high in the northwestern part of this chamber hints "+
      "at another room above.\n");
   set_smell("default","The crystal clean fragrance of water fills the air.");
   set_listen("default","The roar of the waterfall muffles all other sounds.");
   set_items(([
      ({"walls","wall","stone walls","gray stone walls"}) : "%^BOLD%^"+
         "%^BLACK%^The gray stone walls of the tower seem to blend "+
         "in to the background, masked by the brilliant waterfall and "+
         "lush foliage.%^RESET%^",
      ({"waterfall","water","falls","rainbow","rainbow falls"}) : (:TO,"rainbow_desc":),
      "mist" : "%^BOLD%^Rising into the area is a billowing "+
         "mist that sparkles with the colors of the %^RED%^r"+
         "%^RESET%^%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^CYAN%^b"+
         "%^BLUE%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ "+
         "and bathes the small %^CYAN%^pool%^WHITE%^.  "+
         "Unlike natural mists, it is not cool to the touch - "+
         "indeed, it proves impossible to feel at all!%^RESET%^",
      ({"pool","pool of water"}) : "Strangely, the pool of water "+
         "at the waterfall's base does not seem to grow, no "+
         "matter the volume of water pouring into it.  The "+
         "pool is edged with flourishing %^GREEN%^ferns %^RESET%^"+
         "and %^BOLD%^water flowers%^RESET%^, all adding to the "+
         "beautiful landscape here within the tower's walls.",
      ({"fern","ferns","flowers","water flowers"}) : "%^GREEN%^"+
         "The area around the pond has been filled with layers "+
         "of %^BOLD%^ferns %^RESET%^%^GREEN%^interspersed with "+
         "%^YELLOW%^lilies%^RESET%^%^GREEN%^, %^BOLD%^%^WHITE%^"+
         "lotus blossoms%^RESET%^%^GREEN%^, and %^MAGENTA%^"+
         "irises%^GREEN%^, all plants which typically need great "+
         "reserves of water.  The garden seems to be flourishing, "+
         "despite the obvious lack of natural water.%^RESET%^",
      ({"rock","natural rock","seats","seat"}) : "%^ORANGE%^The "+
         "landscape is dotted with several natural rocks that "+
         "have been shaped ever so slightly to become comfortable "+
         "seats.  A quick glance shows nothing but the rocks "+
         "themselves, but a second look shows that this portion "+
         "is just a bit too straight, that one curved just so - "+
         "all evidence of the touch of magic.%^RESET%^",
      ({"stairs","staircase","spiral staircase","glassteel spiral staircase","glassteel stairs"}) :
         "%^CYAN%^Spiralling tightly upon itself in the "+
         "northwestern reaches of the room is an elegant "+
         "%^BOLD%^glassteel staircase%^RESET%^%^CYAN%^.  Altered "+
         "by magic, glassteel becomes transparent, causing the "+
         "staircase to be virtually invisible.  Glints of light "+
         "off the edges and a faint %^BOLD%^blue tinge %^RESET%^"+
         "%^CYAN%^are the only indication the staircase is there.%^RESET%^",
      ({"ceiling","partial ceiling"}) : "High overhead in the "+
         "northeastern part of the room is a partial ceiling "+
         "made of the same %^BOLD%^%^BLACK%^gray stone %^RESET%^"+
         "as the walls.  Clearly, a room must be there, accessible "+
         "by the great glassteel staircase."
   ]));
   set_exits(([
      "south" : ROOMS"viento52",
      "up" : ROOMS"mage_landing1"
   ]));
   set_door("tower door","/d/attaya/newseneca/rooms/viento52","south",0,0);
   set_door_description("tower door","The smooth %^BOLD%^%^BLACK%^gray stone "+
      "walls %^RESET%^of the tower are broken by these arched %^ORANGE%^"+
      "double doors%^RESET%^.  Carved along the edges of the deep brown "+
      "wood are %^BOLD%^%^CYAN%^mystical runes %^RESET%^filled with "+
      "molten %^BOLD%^silver%^RESET%^.  Matching %^BOLD%^silver handles "+
      "%^RESET%^are mounted side-by-side to allow access to the street outside.");
}

void init(){
   ::init();
   add_action("touch_em","touch");
}

int touch_em(string str){
   if(str != "water" && str != "waterfall") return 0;
   tell_object(TP,"%^BOLD%^You reach out and attempt to touch "+
      "the %^RED%^w%^YELLOW%^a%^GREEN%^t%^CYAN%^e%^BLUE%^r"+
      "%^CYAN%^f%^GREEN%^a%^YELLOW%^l%^RED%^l %^WHITE%^only to "+
      "see it vanish into a %^CYAN%^mist %^WHITE%^around your "+
      "hand.  As soon as you pull your hand away, the falls "+
      "resume their normal course.%^RESET%^");
   tell_room(TO,"%^BOLD%^"+TPQCN+" %^BOLD%^%^WHITE%^reaches "+
      "out and attempts to touch "+
      "the %^RED%^w%^YELLOW%^a%^GREEN%^t%^CYAN%^e%^BLUE%^r"+
      "%^CYAN%^f%^GREEN%^a%^YELLOW%^l%^RED%^l %^WHITE%^only to "+
      "see it vanish into a %^CYAN%^mist %^WHITE%^around "+TP->QP+" "+
      "hand.  As soon as "+TP->QS+" pulls "+TP->QP+" hand away, the falls "+
      "resume their normal course.%^RESET%^",TP);
   return 1;
}

void rainbow_desc(){
string color, tmp;
   switch(random(10)){
      case 0: color = "%^BOLD%^%^RED%^red"; break;
      case 1: color = "%^RESET%^%^ORANGE%^orange";  break;
      case 2: color = "%^YELLOW%^yellow"; break;
      case 3: color = "%^BOLD%^%^GREEN%^green"; break;
      case 4: color = "%^BOLD%^%^CYAN%^blue"; break;
      case 5: color = "%^BOLD%^%^BLUE%^indigo"; break;
      case 6: color = "%^RESET%^%^MAGENTA%^violet"; break;
      case 7: color = "%^BOLD%^%^MAGENTA%^pink"; break;
      case 8: color = "%^BOLD%^%^WHITE%^silver"; break;
      default: color = "%^BOLD%^i%^RED%^r%^GREEN%^i%^CYAN%^d"+
         "%^YELLOW%^e%^MAGENTA%^s%^BLUE%^c%^WHITE%^e%^RESET%^"+
         "%^MAGENTA%^n%^YELLOW%^t"; break;
   }
   switch(random(4)){
      case 0: tmp = "Glancing over the %^CYAN%^waterfall%^RESET%^, "+
         ""+color+" vapor %^RESET%^catches your eye."; break;
      case 1: tmp = "The %^CYAN%^waterfall %^RESET%^pulses with "+
         ""+color+" light%^RESET%^ as you watch before fading "+
         "back to its transparent beauty."; break;
      case 2: tmp = "A %^BOLD%^g%^RESET%^l%^BOLD%^i%^RESET%^m"+
         "%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g "+
         ""+color+" mist %^RESET%^sparkles in the air."; break;
      default: tmp = "The entire %^CYAN%^waterfall %^RESET%^"+
         "glows with a "+color+" radiance %^RESET%^for a long "+
         "moment before returning to its normal state."; break;
   }
   return("The %^CYAN%^waterfall%^RESET%^ rises high overhead, "+
      "reaching far out of sight.  It seems to begin somewhere "+
      "at the top of the tower itself.  "+tmp+"");
}
