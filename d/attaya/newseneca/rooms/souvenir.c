#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("Driftwood");
   set_short("%^RESET%^%^ORANGE%^Driftwood%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Driftwood, Seneca%^RESET%^\n"+
      "Fashioned from sun-bleached %^ORANGE%^timber%^RESET%^, "+
      "this tiny shop features many open %^CYAN%^windows %^RESET%^"+
      "designed to let in the %^YELLOW%^sun %^RESET%^and "+
      "%^CYAN%^ocean breeze%^RESET%^.  The %^CYAN%^windows "+
      "%^RESET%^have no glass, instead featuring %^BOLD%^"+
      "whitewashed wooden shutters %^RESET%^that have been "+
      "stenciled with a border of %^GREEN%^palm trees %^RESET%^"+
      "and %^BOLD%^%^BLACK%^birds %^RESET%^in flight.  %^YELLOW%^"+
      "G%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n %^BOLD%^"+
      "sand %^RESET%^continually blows in through the doorway and "+
      "windows, adding a fine layer to all within the shop.  "+
      "The store seems crammed full, with trinkets and pretty "+
      "little ornaments sprouting up from %^ORANGE%^stands%^RESET%^"+
      ", hanging from the %^BOLD%^ceiling%^RESET%^, and lying on "+
      "the %^BOLD%^countertops%^RESET%^.  The floor has been "+
      "left as simply planed boards, worn smooth by the sand and "+
      "the feet of many customers.\n");
   set_smell("default","The clean scent of the ocean wafts in through the windows.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      "floor" : "The shopkeeper has apparently given up on sweeping the "+
         "floor.  Despite the overall cleanliness of the shop, a light "+
         "of sand covers the smooth wooden floor planks.",
      ({"window","windows","shutters"}) : "%^BOLD%^Several wide windows "+
         "grace the walls of the shop, not giving much of a view, but "+
         "allowing the sounds, smells, and lights of Seneca to penetrate "+
         "its interior.  The wooden shutters "+
         "are fashioned at the top with hinges so that they may be dropped "+
         "down to protect the store in times of stormy weather.  They "+
         "are propped up with wooden poles, and the shutters themselves "+
         "feature pretty stenciling of beach scenes - %^BOLD%^%^BLACK%^"+
         "birds %^WHITE%^fly on the %^CYAN%^breeze %^WHITE%^above the "+
         "%^RESET%^%^ORANGE%^peaceful shore %^BOLD%^%^WHITE%^%^featuring "+
         "%^RESET%^%^GREEN%^palm trees%^BOLD%^%^WHITE%^.",
      ({"sand","golden sand"}) : "A fine layer of sand covers most "+
         "sufaces in the shop, thinning where people often walk and "+
         "building up in the corners.",
      ({"stand","stands"}) : "Stands are often found in the shop, "+
         "holding flimsy little umbrellas for those of delicate "+
         "constitution who cannot take the sun and heat of the "+
         "streets of Seneca.",
      "ceiling" : "The ceiling is not much to look at - a simple "+
         "whitewashed affair.  Hanging from it are several "+
         "macrame plant hangers embellished with shells.  "+
         "%^GREEN%^Flourishing plants %^RESET%^have been placed "+
         "in them, adding a bit of greenery to the place.",
      ({"counter","countertop","countertops","counters"}) : "Like "+
         "the rest of the shop, the countertops are fashioned "+
         "from simple planed wood which seems to have been white"+
         "washed at some time.  Various trinkets are scattered "+
         "across their top, adding to the clutter of the shop.",
      ({"trinket","trinkets","ornament","ornaments"}) : (:TO,"look_trinkets":)
   ]));
   set_exits(([
      "west" : ROOMS"souveniryard"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/souveniryard","west",0);
   set_door_description("door","%^GREEN%^The door to the shop is "+
      "fashioned from several planks placed vertically and "+
      "reinforced with two horizontal boards.  It has been painted "+
      "a subdued green and seems rather worn from the sand.%^RESET%^");
}

void reset(){
   ::reset();
   if(!present("tarolina")){
      new(MON"tarolina")->move(TO);
   }
}


void look_trinkets(){
   switch(random(10)){
      case 0:  tell_object(TP,"Your eyes light upon an interesting "+
         "creation - a dozen small conch shells in %^BOLD%^%^RED%^"+
         "v%^MAGENTA%^i%^WHITE%^b%^CYAN%^r%^BLUE%^a%^MAGENTA%^n%^RED%^"+
         "t %^RESET%^colors have been arranged upon 'stems' and placed "+
         "in a %^BOLD%^crystal vase %^RESET%^to make a bouquet of roses.");
      break;
      case 1:  tell_object(TP,"%^ORANGE%^A small wicker basket on one "+
         "of the counters holds countless small %^RESET%^sand dollars "+
         "%^ORANGE%^in different natural colors.%^RESET%^");
      break;
      case 2:  tell_object(TP,"%^ORANGE%^A collection of dried %^YELLOW%^"+
         "sand dollars %^RESET%^%^ORANGE%^has been carefully displayed "+
         "upon a white cloth on the countertop, allowing the unusual "+
         "specimens of %^BOLD%^%^RED%^scarlet%^RESET%^%^ORANGE%^, "+
         "%^MAGENTA%^purple%^ORANGE%^, and %^BOLD%^%^BLUE%^blue "+
         "%^RESET%^%^ORANGE%^to shine.%^RESET%^");
      break;
      case 3:  tell_object(TP,"You see a %^ORANGE%^barrel %^RESET%^"+
         "of common seashells - often sold by the handful.  At a "+
         "glance, you see %^BOLD%^%^MAGENTA%^conch shells%^RESET%^, "+
         "%^ORANGE%^clam shells%^RESET%^, %^BOLD%^white scallop shells"+
         "%^RESET%^, %^BOLD%^%^MAGENTA%^pink %^RESET%^and %^BOLD%^"+
         "%^GREEN%^green %^RESET%^sea urchin shells, and little "+
         "ring top cowrie shells.");
      break;
      case 4:  tell_object(TP,"You catch sight of a small rack of "+
         "%^ORANGE%^leather necklaces%^RESET%^, each bearing a "+
         "single %^BOLD%^shark's tooth%^RESET%^.");
      break;
      case 5:  tell_object(TP,"Atop a small table in a corner is a "+
         "tower of jars.  Each jar is filled with layers of "+
         "%^MAGENTA%^p%^BOLD%^%^BLUE%^a%^GREEN%^i%^RED%^n%^CYAN%^t"+
         "%^YELLOW%^e%^RESET%^%^ORANGE%^d sand%^RESET%^, the settling "+
         "and thickness of each layer making each one truly unique.");
      break;
      case 6:  tell_object(TP,"A small %^YELLOW%^treasure chest "+
         "%^RESET%^has been filled with %^YELLOW%^gold chains "+
         "%^RESET%^of different "+
         "lengths - some meant to be bracelets, some necklaces, and "+
         "still others anklets.  Each one holds a tiny %^CYAN%^"+
         "vial %^RESET%^of %^BOLD%^%^BLUE%^ocean water%^RESET%^.");
      break;
      case 7:  tell_object(TP,"On a %^ORANGE%^wooden board %^RESET%^"+
         "fitted with pegs, pairs of earrings are on display.  Each "+
         "pair is made from matching shells, though their slight "+
         "variations cause them to be flawed in some eyes - all "+
         "the more perfect in others.");
      break;
      case 8:  tell_object(TP,"You gaze around at various interesting "+
         "pieces of %^ORANGE%^driftwood %^RESET%^that can be found "+
         "around the shop.  The shop's namesake, each one has been "+
         "mounted and given a name.");
      break;
      case 9:  tell_object(TP,"Your eyes land upon the pride of "+
         "%^ORANGE%^Driftwood's %^RESET%^owner, a fantastic "+
         "ship in a bottle that is nearly as big as the owner "+
         "herself.  The ship is immaculate in every detail, and "+
         "the bottle is kept highly polished, sitting upon the "+
         "center of the counter in a place of honor.");
      break;
      default: tell_object(TP,"Hmm...you shouldn't see this message.  "+
         "Mail Circe and let her know she messed something up.");
      break;
   }
   tell_room(TO,""+TPQCN+" looks around at the various trinkets in the shop.",TP);
   return;
}