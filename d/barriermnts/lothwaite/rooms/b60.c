#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_name("An impressive chamber");
   set_short("%^YELLOW%^An impressive chamber%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",2);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^BOLD%^%^BLUE%^This impressive chamber is circular and "+
      "carved straight from the %^BOLD%^%^BLACK%^deep gray stone %^BLUE%^"+
      "of the mountain itself.  The %^BLACK%^walls %^BLUE%^are perfectly "+
      "smooth and shot through with %^BOLD%^%^BLACK%^v"+
      "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^BLUE%^of %^BOLD%^"+
      "%^BLACK%^black %^BLUE%^and %^YELLOW%^gold%^BLUE%^, which "+
      "%^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e"+
      "%^RESET%^r %^BOLD%^%^BLUE%^in the %^YELLOW%^light %^BLUE%^of "+
      "innumerable %^RESET%^%^ORANGE%^torches%^BOLD%^%^BLUE%^ that "+
      "climb all the way up the wall.  The %^BLACK%^ceiling %^BLUE%^"+
      "is a large, %^RESET%^%^ORANGE%^onion-shaped dome %^BOLD%^"+
      "%^BLUE%^whose stone windows have been painted to look like "+
      "the %^RESET%^%^CYAN%^sky%^BOLD%^%^BLUE%^!  The only exit from "+
      "this circular chamber is the doorway to the west, which stands "+
      "open.  Dominating the center of the room is an exquisite "+
      "%^RESET%^statue %^BOLD%^%^BLUE%^carved of flawless %^WHITE%^"+
      "ivory%^BLUE%^.  Countless piles of %^YELLOW%^gold %^BLUE%^"+
      "and precious treasures surround the statue, clearly an indication "+
      "of the fallen king's esteem among his people.%^RESET%^\n");
   set_items(([
      ({"chamber","passageway","passageways","hallways","hallway"}) : "The "+
         "doorway to the west opens into a wide passageway that is "+
         "somewhat narrower than this chamber.",
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of the "+
         "caverns are flawlessly smooth and seem to emit a coldness all "+
         "their own.  They are shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
      ({"torch","torches","torchlight"}) : "%^YELLOW%^Unlike most torches, "+
         "these are not made of simple wood with fuel-soaked cloth.  Instead, "+
         "each torch has been formed from solid gold and set with %^BLUE%^"+
         "sapphires %^YELLOW%^and %^CYAN%^diamonds%^YELLOW%^.  Strangely, "+
         "you notice no source of fuel that would explain the burning of "+
         "any of the torches.",
      ({"dome","ceiling","ceilings","onion dome","domes"}) : (:TO,"dome_desc":),
      ({"statue","ivory statue"}) : "%^BOLD%^%^WHITE%^In the exact "+
         "center of the room stands a massive ivory statue.  It rises "+
         "well over 20 feet tall, making you realize exactly how high "+
         "the ceiling overhead must be.  The statue is carved in the "+
         "highly detailed likeness of a proud firbolg %^RESET%^%^RED%^"+
         "warrior%^BOLD%^%^WHITE%^.  The firbolg is standing with his "+
         "chin held high, a massive %^CYAN%^sword %^WHITE%^sheathed "+
         "across his back.  He wears a %^RESET%^%^ORANGE%^leather skirt "+
         "%^BOLD%^%^WHITE%^with a matching %^RESET%^%^ORANGE%^"+
         "breastplate,%^BOLD%^%^WHITE%^and his feet are shod with simple "+
         "%^RESET%^%^ORANGE%^leather shoes%^BOLD%^%^WHITE%^.  Even his "+
         "hair has been colored the beautiful %^RESET%^%^RED%^au"+
         "%^ORANGE%^b%^RED%^urn %^BOLD%^%^WHITE%^it must once have "+
         "been.  His %^BLUE%^blue eyes %^WHITE%^look on with "+
         "confidence and wisdom, and all seems in place.  All, that is, "+
         "save for the indention around his waist, where something is "+
         "clearly missing.",
      ({"treasure","gold","piles","treasures"}) : (:TO,"treasure_desc":)
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The cool breath of a tomb is the only smell in the air.");
   set_exits(([
      "west" : PATHEXIT"b59",
   ]));
}

int dome_desc(){
   if(query_night()){
      return("%^BLUE%^The dome is painted to look like the "+
         "night sky, with %^BOLD%^%^WHITE%^stars %^RESET%^%^BLUE%^"+
         "endlessly %^BOLD%^%^WHITE%^t%^RESET%^w%^BOLD%^i%^RESET%^n"+
         "%^BOLD%^k%^RESET%^l%^BOLD%^i%^RESET%^n%^BOLD%^g %^RESET%^"+
         "%^BLUE%^above.  Occasionally, a lone %^YELLOW%^shooting "+
         "star %^RESET%^%^BLUE%^streaks across the lonely painted "+
         "heavens, and all seems peaceful within this tomb.");
   }
   return("%^CYAN%^The dome is painted the quiet, tranquil azure "+
      "of the midday sky.  %^BOLD%^%^WHITE%^Puffy clouds %^RESET%^"+
      "%^CYAN%^float lazily by, though they send no shadows when "+
      "they cross the painted %^YELLOW%^sun%^RESET%^%^CYAN%^.  "+
      "Every once in awhile, a lone %^RED%^hawk %^CYAN%^wheels and "+
      "turns in the sky, before disappearing at the edge of the "+
      "window.");
}

int treasure_desc(){
   string tmp;
   switch(random(6)){
      case 0:  tmp = "%^YELLOW%^Piles of gold and %^WHITE%^platinum "+
                  "%^YELLOW%^coins are heaped at the feet of the "+
                  "great statue.";
               break;
      case 1:  tmp = "Your eyes fall upon an %^BOLD%^ivory drinking "+
                  "horn %^RESET%^fitted with an impressive %^YELLOW%^"+
                  "golden band%^RESET%^.  Scattered %^BOLD%^%^RED%^"+
                  "chips of rubies %^RESET%^heighten its beauty - "+
                  "and its worth!";
               break;
      case 2:  tmp = "%^ORANGE%^Halfway buried beneath the glittering "+
                  "coins is a beautifully carved wooden statue of "+
                  "a %^BOLD%^%^WHITE%^pegasus %^RESET%^%^ORANGE%^in "+
                  "flight.  His eyes glitter with %^BOLD%^%^BLUE%^"+
                  "sapphires%^RESET%^%^ORANGE%^, and his wings are "+
                  "tipped in %^RESET%^silver%^ORANGE%^.";
               break;
      case 3:  tmp = "%^BOLD%^%^GREEN%^An emerald the size of your "+
                  "fist catches your eye.  It rests just at the base "+
                  "of the statue.";
               break;
      case 4:  tmp = "None of the treasure seems quite so regal or "+
                  "impressive as the lifelike statue in the center "+
                  "of the room.  Somehow, it draws your attention "+
                  "away from the piles of wealth upon the floor.";
               break;
      default:  tmp = "%^BOLD%^%^BLACK%^A fantastic necklace of "+
                  "black pearls has been left among the treasures.  "+
                  "Something about its appearance suggests it "+
                  "probably belonged to someone who cared about "+
                  "the king a great deal on a personal level.";
               break;
   }
   return tmp;
}

void reset(){
   ::reset();
   if((!present("firbolg king"))){
      new(MON"ghostking")->move(TO);
   }
}