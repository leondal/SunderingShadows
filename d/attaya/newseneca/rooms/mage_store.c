//Ethereal Wonders - spell shop for new Seneca's mage tower
//Run by an aasimar who struggles with his hatred for the 
//tiefling downstairs
//~Circe~ 1/9/08

#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_indoors(1);
   set_name("Ethereal Wonders, Seneca");
   set_short("%^YELLOW%^E%^WHITE%^t%^YELLOW%^h%^WHITE%^e%^YELLOW%^r"+
      "%^WHITE%^e%^YELLOW%^a%^WHITE%^l %^YELLOW%^W%^WHITE%^o"+
      "%^YELLOW%^n%^WHITE%^d%^YELLOW%^e%^WHITE%^r%^YELLOW%^s"+
      "%^WHITE%^, Seneca%^RESET%^");
   set_long(
      "%^YELLOW%^E%^WHITE%^t%^YELLOW%^h%^WHITE%^e%^YELLOW%^r"+
      "%^WHITE%^e%^YELLOW%^a%^WHITE%^l %^YELLOW%^W%^WHITE%^o"+
      "%^YELLOW%^n%^WHITE%^d%^YELLOW%^e%^WHITE%^r%^YELLOW%^s"+
      "%^WHITE%^, Seneca%^RESET%^\n"+
      "Stepping into this shop is much like stepping into a "+
      "small %^YELLOW%^golden %^WHITE%^h%^YELLOW%^e%^WHITE%^a"+
      "%^YELLOW%^v%^WHITE%^e%^YELLOW%^n%^RESET%^.  The walls "+
      "are painted a soft %^YELLOW%^yellow%^RESET%^, and most "+
      "every surface is covered in %^YELLOW%^gilt %^RESET%^"+
      "or %^YELLOW%^gold plating%^RESET%^.  All of the furniture "+
      "is made from the %^BOLD%^palest wood%^RESET%^, causing "+
      "it to %^BOLD%^gleam %^RESET%^with a soft light beneath "+
      "the %^YELLOW%^gilding%^RESET%^.  Elegant %^BOLD%^scroll"+
      "racks %^RESET%^line the walls, filled with all manner "+
      "of scrolls tied neatly with different %^BOLD%^%^RED%^c"+
      "%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^"+
      "s %^RESET%^of %^MAGENTA%^r%^BOLD%^i%^WHITE%^b%^GREEN%^b"+
      "%^BLACK%^o%^BLUE%^n%^CYAN%^s %^RESET%^to indicate their "+
      "school.  A %^YELLOW%^golden bookcase %^RESET%^stands "+
      "behind the %^BOLD%^marble counter %^RESET%^holding "+
      "%^ORANGE%^tomes %^RESET%^and %^ORANGE%^leather bags%^RESET%^ "+
      "while a %^YELLOW%^gold harp %^RESET%^plays idly from "+
      "the corner of the room.  Rather than having true "+
      "windows that look out upon the streets of Seneca, "+
      "the walls have been painted with arched %^CYAN%^windows%^RESET%^ "+
      "depicting animated scenes of an idyllic %^GREEN%^valley "+
      "%^RESET%^complete with %^MAGENTA%^wildflowers %^RESET%^"+
      "and a %^BOLD%^%^CYAN%^s%^BLUE%^p%^CYAN%^a%^BLUE%^r"+
      "%^CYAN%^k%^BLUE%^l%^CYAN%^i%^BLUE%^n%^CYAN%^g "+
      "river%^RESET%^."+
      "\n\n%^RESET%^<help shop> will give you help on how to use the shop.\n");
   set_smell("default","The crystal clean fragrance of water "+
      "mingled with pure jasmine fills the air.");
   set_listen("default","The roar of the waterfall is tempered "+
      "with the ethereal sound of a harp.");
   set_items(([
      ({"wall","walls"}) : "Much different from the walls of "+
         "the rest of the tower, the walls here seem to have "+
         "been stuccoed and then painted a %^YELLOW%^soft "+
         "yellow%^RESET%^.  At intervals along the northern wall, "+
         "three tall %^CYAN%^arched windows %^RESET%^have been "+
         "painted, all seeming to look down upon the same "+
         "lifelike %^GREEN%^river valley%^RESET%^.",
      "furniture" : "Several scrollracks are placed around the "+
         "walls of the room along with a thick white oak "+
         "bookcase.  A marble counter stands in front of the "+
         "bookcase, and a lovely golden harp has been enchanted "+
         "to play in the corner.",
      ({"scrollrack","scrollracks","racks","rack","scroll racks"}) :
         "Each scrollrack is made from slender shelves of %^BOLD%^"+
         "white oak %^RESET%^tilted so that the back rises above "+
         "the front, which is fitted with a rim.  The scrolls are "+
         "placed vertically on the rack to allow for easy access.",
      ({"scrolls","ribbons","colored ribbons","colors"}) : "Each "+
         "scroll placed upon the %^BOLD%^scrollracks %^RESET%^"+
         "has been tied with a %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o"+
         "%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^e%^WHITE%^d "+
         "%^RESET%^%^MAGENTA%^r%^BOLD%^i%^WHITE%^b%^GREEN%^b"+
         "%^BLACK%^o%^BLUE%^n %^RESET%^to identify its school.  "+
         "Though you cannot guess at his system, Godfrey clearly "+
         "has them carefully arranged for quick retrieval.",
      ({"bookcase","book case","golden bookcase","tomes","bags","leather bags"}) :
         "The %^YELLOW%^golden bookcase %^RESET%^behind the %^BOLD%^"+
         "marble counter %^RESET%^looks to have been made from "+
         "wood and covered with %^YELLOW%^gold plating%^RESET%^ "+
         "that grants it an almost blinding shine.  The lower "+
         "shelves are filled with %^ORANGE%^tomes %^RESET%^"+
         "of different shapes, sizes, and colors - all of which "+
         "have clearly seen some wear and tear and are likely "+
         "books waiting to be picked up by their owners.  "+
         "The top shelf holds brand new tomes in different "+
         "finishes, their covers glossy and clean (Godfrey "+
         "clearly has a fondness for white and gold, judging "+
         "from the selection).  On the shelf below, new "+
         "%^ORANGE%^leather bags %^RESET%^for storing "+
         "components are kept.",
      ({"counter","marble counter","marble","countertop"}) : 
         "%^BOLD%^%^WHITE%^Pristine white marble with delicate "+
         "veins of %^YELLOW%^gold %^WHITE%^and %^RESET%^"+
         "silver %^BOLD%^has been used for the counter in "+
         "the northern portion of the room.  It is kept "+
         "spotless and perfectly smooth, soft and cool "+
         "to the touch.",
      ({"harp","gold harp"}) : "%^ORANGE%^The %^YELLOW%^harp "+
         "%^RESET%^%^ORANGE%^in the northeastern corner of the "+
         "room is a magnificent construction of %^YELLOW%^gold"+
         "%^RESET%^%^ORANGE%^.  The triangular shape is full "+
         "of sweeping curves that hold the forty-five strings "+
         "strung across the body.  Seven pedals along the "+
         "floor complete the beautiful instrument, which has "+
         "been enchanted to create a heavenly music all on its "+
         "own.%^RESET%^",
      ({"window","windows","valley","wildflowers","river valley","river"}) :
         (:TO,"look_windows":)
   ]));
   set_exits( ([
      "west" : ROOMS"mage_landing3"
   ]));
}

void reset(){
   ::reset();
   if(!present("godfrey"))
      find_object_or_load(MON"godfrey")->move(TO);
   switch(random(5)){
      case 0:  tell_room(TO,"%^ORANGE%^An eerie %^RED%^cackle "+
         "%^ORANGE%^fills the room and one of the %^YELLOW%^"+
         "scrollracks %^RESET%^%^ORANGE%^topples over.%^RESET%^");
         if(present("godfrey")){
            tell_room(TO,"%^MAGENTA%^Godfrey bellows%^RESET%^: "+
               "Curse you, you blasted little fiend!");
         }
         break;
      case 1:  tell_room(TO,"%^YELLOW%^The soothing music of "+
         "the harp swells to a grand symphony before fading "+
         "into the background once more.%^RESET%^");
         break;
      case 2:  tell_room(TO,"As if acting on some unheard command, "+
         "the %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o"+
         "%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^f%^WHITE%^u%^BLACK%^l "+
         "%^RESET%^%^MAGENTA%^r%^BOLD%^i%^WHITE%^b%^GREEN%^b"+
         "%^BLACK%^o%^BLUE%^n%^RED%^s %^RESET%^suddenly straighten "+
         "and tighten themselves on the scrolls.");
         break;
      case 3:  tell_room(TO,"%^ORANGE%^A broom materializes in "+
         "the center of the room and sweeps it carefully.  "+
         "Suddenly, it summons a dustpan, sweeps up any dirt, "+
         "vanishes in a %^BOLD%^%^WHITE%^POOF%^RESET%^%^ORANGE%^.%^RESET%^");
         break;
      default:  tell_room(TO,"%^BOLD%^%^BLACK%^The room suddenly "+
         "darkens with a flash of %^RESET%^smoke %^BOLD%^%^BLACK%^"+
         "and you hear an inane cackling before the light returns.%^RESET%^");
         break;
   }
}

void look_windows(){
string tmp;
   switch(random(4)){
      case 0:  tmp = "As you watch the magical painting, a "+
         "%^RED%^hawk %^RESET%^wheels lazily in the sky.";
         break;
      case 1:  tmp = "As you gaze at the mystical windows, "+
         "a sudden %^BOLD%^%^CYAN%^brisk wind%^RESET%^ rises, "+
         "sending the %^MAGENTA%^w%^BOLD%^i%^CYAN%^l%^WHITE%^d"+
         "%^YELLOW%^f%^GREEN%^l%^RED%^o%^MAGENTA%^w%^BLUE%^e%^RESET%^"+
         "%^ORANGE%^r%^MAGENTA%^s%^RESET%^ dancing."; break;
      case 2:  tmp = "Watching the windows, you catch sight "+
         "of the tell-tale %^BOLD%^glint %^RESET%^of a small "+
         "school of fish swimming in the %^BOLD%^%^BLUE%^"+
         "river%^RESET%^."; break;
      default: tmp = "Studying the painted windows, you "+
         "see the %^GREEN%^grasses %^RESET%^bend in a "+
         "line, much as if some small creature were "+
         "running through them."; break;
   }
   return("Each of the three windows is painted in such a way "+
      "as to look outlined in %^BOLD%^stone%^RESET%^ and to "+
      "appear to be looking onto a %^GREEN%^river valley%^RESET%^.  "+
      "The %^BOLD%^painting %^RESET%^has been enchanted to move "+
      "of its own accord, making the %^GREEN%^tall grasses %^RESET%^"+
      "wave in an imaginary %^CYAN%^wind%^RESET%^.  The %^BOLD%^"+
      "%^BLUE%^river %^RESET%^winding through the valley in the "+
      "center window %^BOLD%^%^CYAN%^s%^BLUE%^p%^CYAN%^a%^BLUE%^r"+
      "%^CYAN%^k%^BLUE%^l%^CYAN%^e%^BLUE%^s%^RESET%^ with the "+
      "changing light that mimics day and night.  Rising in the "+
      "background of each of the windows are towering %^BOLD%^"+
      "%^BLACK%^mountains %^RESET%^with %^BOLD%^snow-capped peaks "+
      "%^RESET%^that guard the lush %^GREEN%^valley %^RESET%^"+
      "brimming with %^MAGENTA%^w%^BOLD%^i%^CYAN%^l%^WHITE%^d"+
      "%^YELLOW%^f%^GREEN%^l%^RED%^o%^MAGENTA%^w%^BLUE%^e%^RESET%^"+
      "%^ORANGE%^r%^MAGENTA%^s%^RESET%^.\n\n"+tmp+"");
}