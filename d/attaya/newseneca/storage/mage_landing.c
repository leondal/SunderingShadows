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
   set_name("Landing of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Landing of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Landing of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^, Seneca%^RESET%^\n"+
      "The slender %^CYAN%^glassteel staircase %^RESET%^spirals "+
      "to this landing.  A %^CYAN%^glassteel walkway %^RESET%^"+
      "leads to a room to the east, while the staircase itself "+
      "continues both up and down.  A graceful %^CYAN%^banister "+
      "%^RESET%^curves along the outside of the staircase, "+
      "protecting those who would climb, while a narrow pole "+
      "in the center provides the only visible means of support.  "+
      "To the southeast are the breathtaking %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^i"+
      "%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w "+
      "%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^a%^YELLOW%^l%^GREEN%^l"+
      "%^CYAN%^s%^RESET%^ that cascade down from the tower's "+
      "tip to fill the chamber below.\n");
   set_smell("default","The crystal clean fragrance of water fills the air.");
   set_listen("default","The roar of the waterfall muffles all other sounds.");
   set_items(([
      ({"staircase","spiral staircase","stairs","glassteel staircase"}) : 
         "%^CYAN%^Nearly transparent glassteel makes up this "+
         "beautiful staircase.  Seeming to be made of only thin "+
         "layers of glass, the staircase feels as thought it "+
         "could support any amount of weight.  The narrow stairs "+
         "spiral around a central pole, and the outer edge is "+
         "guarded by a banister.%^RESET%^",
      "banister" : "The banister is only about three inches thick, "+
         "causing some to feel uneasy, especially at the very "+
         "heights of the tower.",
      "walkway" : "The glassteel walkway leading to the east has "+
         "no rails of any kind.  It appears extremely thin, and "+
         "it looks as though the weight of a person might cause "+
         "it to crack.",
      ({"waterfall","water","falls","rainbow","rainbow falls"}) : (:TO,"rainbow_desc":)
   ]));
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
