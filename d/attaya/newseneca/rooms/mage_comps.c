//Impish Charms - comp shop for new Seneca's mage tower
//Run by a tiefling who likes to annoy the aasimar upstairs
//~Circe~ 1/8/08

#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_indoors(1);
   set_name("Impish Charms, Seneca");
   set_short("%^BOLD%^%^RED%^I%^BLACK%^m%^RED%^p%^BLACK%^"+
      "i%^RED%^s%^BLACK%^h %^RED%^C"+
      "%^BLACK%^h%^RED%^a%^BLACK%^r%^RED%^m%^BLACK%^s"+
      "%^WHITE%^, Seneca%^RESET%^");
   set_long(
      "%^BOLD%^%^RED%^I%^BLACK%^m%^RED%^p%^BLACK%^"+
      "i%^RED%^s%^BLACK%^h %^RED%^C"+
      "%^BLACK%^h%^RED%^a%^BLACK%^r%^RED%^m%^BLACK%^s"+
      "%^WHITE%^, Seneca%^RESET%^\n"+
      "Unlike many components shops, this large room is filled "+
      "with countless %^BOLD%^%^BLACK%^cages %^RESET%^on stands "+
      "in the southern area.  Here, live %^ORANGE%^monkeys"+
      "%^RESET%^, %^BOLD%^%^BLACK%^bats%^RESET%^, and other "+
      "small %^RED%^animals %^RESET%^are kept so the shopkeeper "+
      "may collect various parts needed for components.  Smaller "+
      "%^CYAN%^glassteel %^RESET%^crates resting on a shelf above "+
      "the floor are occupied by crawling %^BOLD%^%^BLACK%^"+
      "hairy spiders %^RESET%^and %^GREEN%^slithering snakes"+
      "%^RESET%^.  A massive %^ORANGE%^cabinet %^RESET%^filled "+
      "with drawers contains other supplies, such as dried "+
      "%^BOLD%^%^MAGENTA%^rose petals%^RESET%^, %^BOLD%^%^RED%^c"+
      "%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^"+
      "e%^RESET%^%^MAGENTA%^d %^BOLD%^s%^YELLOW%^a%^WHITE%^n"+
      "%^GREEN%^d%^RESET%^, and miniature models "+
      "of %^YELLOW%^hearing trumpets%^RESET%^, %^ORANGE%^bags"+
      "%^RESET%^, %^BOLD%^%^BLACK%^gloves%^RESET%^, and %^BOLD%^"+
      "shovels%^RESET%^.  A %^BOLD%^%^BLACK%^ma%^WHITE%^r"+
      "%^BLACK%^ble coun%^WHITE%^t%^BLACK%^ertop %^RESET%^"+
      "along the northern wall holds a %^ORANGE%^brass "+
      "balance scale %^RESET%^allowing %^BOLD%^%^BLACK%^Octavia%^RESET%^ to carefully "+
      "measure amounts and weigh the coins used in exchange.  "+
      "A plush %^MAGENTA%^velvet cushion %^RESET%^is perched "+
      "high overhead near the door, and it is here that %^BOLD%^%^RED%^Abayal%^RESET%^ "+
      "can often be found lounging when his services are not "+
      "required by his mistress.\n\n"+
      "%^RESET%^<help shop> will give you help on how to use the shop.\n");
   set_smell("default","The clean fragrance of the waterfall "+
      "does little to mask the odors from the cages.");
   set_listen("default","The roar of the waterfall can be heard "+
      "through the open doorway, contending with the noises of the animals.");
   set_items(([
      ({"cage","cages"}) : "%^BOLD%^%^BLACK%^The black bars "+
         "of the cages look smooth and glossy rather than "+
         "matte as iron typically does.  Each cage holds several "+
         "animals of the same type, and some of them look "+
         "quite crowded.  The cages are on slender stands and "+
         "are arranged throughout the southern part of the room.%^RESET%^",
      ({"monkey","monkeys"}) : "Several small monkeys ranging "+
         "in color from brown to gray are spread over a couple "+
         "of cages.  They peer out with intelligent eyes in "+
         "between random bouts of throwing things and screenching.",
      ({"bat","bats"}) : "Most of the bats are asleep, perched "+
         "upside-down.  Occasionally they will flutter their wings "+
         "and open their eerie %^BOLD%^%^RED%^red eyes%^RESET%^.",
      ({"animal","animals"}) : "Beside the bat and monkey cages, "+
         "other small animals are kept at times.  Sometimes you "+
         "see birds, others rats or hamsters, and sometimes "+
         "even more exotic creatures.",
      ({"crate","crates","glassteel crate","glassteel crates"}) :
         "Fashioned from %^CYAN%^glassteel %^RESET%^and "+
         "featuring mesh lids, these crates hold some of the "+
         "creepy-crawly critters that some people find loathesome."+
         "  The crates are kept upon a %^ORANGE%^wooden shelf "+
         "%^RESET%^several feet above the floor, and their lids "+
         "are sealed magically, preventing them from escaping.",
      ({"spider","spiders"}) : "Most of the spider are of the "+
         "huge, black, and hairy variety.  They are quite active "+
         "and make the crate appear to be writhing.",
      ({"snake","snakes"}) : "%^GREEN%^The slender snakes are "+
         "mostly harmless garter snakes used for various parts.  "+
         "A couple of smaller crates off to the right house "+
         "much more deadly varieties that are used for their fangs "+
         "and venom.%^RESET%^",
      ({"cabinet","drawers","supplies"}) : "The cabinet sits in the "+
         "northeastern corner of the room.  It has two large doors "+
         "that can be closed to further protect the goods within, "+
         "but they are often left open for easier access to the "+
         "drawers holding components.  A mixture of common "+
         "magical ingredients that have already been prepared and "+
         "are awaiting sale are contained within.",
      ({"countertop","marble countertop","counter"}) : "%^BOLD%^"+
         "%^BLACK%^The counter in the northern part of the room "+
         "is fitted with smooth black marble exquisite to touch.  "+
         "Not a scratch or gouge mars the surface, despite the "+
         "many transactions that must take place here.%^RESET%^",
      ({"scale","balance scale","brass scale","brass balance scale"}) :
         "%^ORANGE%^The brass scales have a central post that "+
         "supports a crossbeam which in turn holds a shallow "+
         "metal plate at each end.  Materials to be weighed "+
         "are placed on one of the plates, while weights are "+
         "placed on the other side until balance is achieved.%^RESET%^",
      ({"cushion","velvet cushion"}) : "A small wooden shelf "+
         "high upon the wall near the doorway is nearly concealed "+
         "by the %^MAGENTA%^velvet cushion%^RESET%^ it supports.  "+
         "The cushion seems made for a pet of some kind."
   ]));
   set_exits( ([
      "west" : ROOMS"mage_landing2"
   ]));
}

void reset(){
   ::reset();
   if(!present("octavia")){ find_object_or_load(MON"octavia")->move(TO); }
   switch(random(6)){
      case 0:  tell_room(TO,"%^ORANGE%^A monkey rattles the bars "+
         "of its cage, calling out noisily.%^RESET%^");
         break;
      case 1:  tell_room(TO,"%^BOLD%^%^BLACK%^One of the bats "+
         "flutters its leathery wings and blinks its %^RED%^"+
         "eyes%^BLACK%^.%^RESET%^");
         break;
      case 2:  tell_room(TO,"%^GREEN%^A slithering snake moves "+
         "silently over a %^ORANGE%^rock %^GREEN%^in its cage.%^RESET%^");
         break;
      case 3:  tell_room(TO,"%^BOLD%^%^BLACK%^A large, hairy "+
         "%^RESET%^spider%^BOLD%^%^BLACK%^ jumps at the glass of "+
         "its cage and emits an audible hiss.%^RESET%^");
         break;
      case 4:  tell_room(TO,"%^YELLOW%^The clink of coins can be "+
         "heard as the scale seems to adjust of its own accord.%^RESET%^");
         break;
      case 5:  tell_room(TO,"%^CYAN%^A breeze blowing through the "+
         "room lifts a small quantity of %^BOLD%^%^RED%^c"+
         "%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^"+
         "e%^RESET%^%^MAGENTA%^d %^BOLD%^s%^YELLOW%^a%^WHITE%^n"+
         "%^GREEN%^d%^RESET%^%^CYAN%^ into the air.%^RESET%^");
         break;
      default:  tell_room(TO,"%^BOLD%^An open drawer suddenly "+
         "closes itself, hiding its contents.%^RESET%^");
         break;
   }
}