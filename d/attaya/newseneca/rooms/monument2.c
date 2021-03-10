//monument2.c ~Circe~ 12/8/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

int count;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("A Grand Monument, Seneca");
   set_short("A Grand Monument, Seneca");
   set_property("light",3);
   set_long("%^BOLD%^%^WHITE%^A Grand Monument, Seneca%^RESET%^\n"+
      "%^GREEN%^This square garden is carpeted with lush, soft "+
      "%^BOLD%^grass%^RESET%^%^GREEN%^ that surrounds the magnificent "+
      "centerpiece, a %^BOLD%^%^WHITE%^marble statue%^RESET%^%^GREEN%^ of a lithe woman.  "+
      "Gently curved %^BOLD%^%^WHITE%^stone benches %^RESET%^%^GREEN%^are placed in each "+
      "ordinal corner, surrounded by vibrant %^ORANGE%^ora"+
      "%^YELLOW%^n%^RESET%^%^ORANGE%^ge bou%^YELLOW%^g%^RESET%^%^ORANGE%^"+
      "ain%^YELLOW%^v%^RESET%^%^ORANGE%^ill%^YELLOW%^e%^RESET%^%^ORANGE%^"+
      "a%^RESET%^%^GREEN%^.  Tended %^ORANGE%^orange trees %^GREEN%^grow between "+
      "the benches, their branches laden with juicy %^ORANGE%^oranges "+
      "%^GREEN%^no matter the season.  A thick square %^BOLD%^flowerbed "+
      "%^RESET%^%^GREEN%^surrounds the base of the statue, the %^BOLD%^ivy greenery "+
      "%^RESET%^%^GREEN%^interrupted with tiny, %^MAGENTA%^star-shaped "+
      "%^BOLD%^pink %^RESET%^%^MAGENTA%^flowers"+
      "%^GREEN%^.  A %^BOLD%^%^WHITE%^silver wind chime %^RESET%^%^GREEN%^hanging from a "+
      "low branch of one of the %^ORANGE%^orange trees%^GREEN%^ creates a "+
      "light %^CYAN%^melody%^GREEN%^ that adds to the peaceful spirit "+
      "of this garden.  To the south and west, you see the bustling "+
      "%^ORANGE%^co%^RED%^b%^ORANGE%^ble%^RESET%^s%^ORANGE%^to%^RED%^"+
      "n%^ORANGE%^e%^RESET%^%^GREEN%^ streets of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^, "+
      "while the beautiful %^ORANGE%^town square %^GREEN%^lies to "+
      "the southwest.  In all other directions, the view has been "+
      "obscured by a tall %^BOLD%^%^WHITE%^fence %^RESET%^%^GREEN%^lined with %^BOLD%^"+
      "hedges%^RESET%^%^GREEN%^.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"street","boulevard","cobblestone","cobblestones","thoroughfare"}) : 
         "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e streets%^RESET%^ "+
         "to the west and south and the town square to the southwest "+
         "are created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white arranged in zig-zagging patterns.",
      "grass" : "%^BOLD%^%^GREEN%^The grass here is soft and well-"+
         "groomed, quite unlike most of the beach grass growing "+
         "thoughout Seneca.  It is kept relatively short, and it "+
         "would likely be a great place for a picnic.%^RESET%^",
      ({"bench","benches","stone benches","stone bench"}) : "%^BOLD%^"+
         "%^WHITE%^In each of the ordinal corners, a curved stone "+
         "bench has been placed.  Each bench has smooth decorative "+
         "edges and would comfortably hold two people, though "+
         "the curve would make their knees touch, making it quite "+
         "cozy indeed.%^RESET%^",
      ({"bougainvillea","orange bougainvillea"}) : "%^GREEN%^Trained "+
         "into a ground cover, the bougainvillea has tiny, heart-shaped "+
         "%^BOLD%^leaves %^RESET%^%^GREEN%^with drip tips similar to "+
         "ivy leaves.  The plant is alive with clusters of small "+
         "%^ORANGE%^orange flowers %^GREEN%^that cascade over the "+
         "ground at the base of the %^RESET%^benches%^GREEN%^.%^RESET%^",
      ({"tree","trees","orange trees","orange tree"}) : "The orange "+
         "trees have small trunks that reach high into the air, their "+
         "flourishing boughs laden with oranges.  If you look close "+
         "enough, you may find an orange ripe enough to pick.",
      ({"flowerbed","greenery","ivy","ivy greenery","flowers","star flowers","star-shaped flowers"}) : 
         "%^ORANGE%^The square flowerbed is bound in natural stone "+
         "and filled with flowing %^GREEN%^greenery %^ORANGE%^with "+
         "leaves shaped liked %^GREEN%^ivy%^ORANGE%^.  Tiny "+
         "%^BOLD%^%^MAGENTA%^pink%^RESET%^%^ORANGE%^ flowers "+
         "shaped like stars are sprinkled throughout - looking "+
         "closely, you see they seem to be some sort of jasmine.%^RESET%^",
      ({"chime","wind chime","silver wind chime","chimes"}) : "%^BOLD%^"+
         "Creating a light tinkling melody, the wind chimes in the "+
         "trees are made simply from steel rods.  The rods are varying "+
         "lengths and widths, creating a variety of tones.  In the "+
         "center of the circle of rods hangs a steel charm in the "+
         "shape of a seagull in flight.%^RESET%^",
      ({"fence","hedge","hedges"}) : "Blending into the background "+
         "is the tall fence to the north and east.  The fence is "+
         "%^BOLD%^white%^RESET%^ and made of planks placed side-by-"+
         "side for privacy.  Growing in front of the fence are tall "+
         "%^GREEN%^hedges %^RESET%^that further add to the tranquil "+
         "atmosphere here, despite being so close to the bustling "+
         "center of Seneca."
   ]));
   set_exits(([
      "west" : ROOMS"skyline43",
      "south" : ROOMS"viento54",
      "southwest" : ROOMS"square"
   ]));
   count = 4;
}

void init(){
   ::init();
   add_action("pick_em","pick");
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
   if(!present("tiergaina statue")) new(OBJ"tier_statue")->move(TO);
   if(count < 4) count++;
}

int pick_em(string str){
   if(!str) return 0;
   if(str == "orange" || str == "oranges" || str == "an orange"){
      if(count < 1){
         tell_object(TP,"There don't seem to be any ripe oranges in reach.");
         return 1;
      }
      tell_object(TP,"%^GREEN%^You pick a ripe %^ORANGE%^orange "+
         "%^GREEN%^from a nearby tree.%^RESET%^");
      tell_room(TO,"%^ORANGE%^"+TPQCN+" picks a ripe %^ORANGE%^"+
         "orange%^GREEN%^ from a nearby tree.%^RESET%^",TP);
      new(OBJ"orange")->move(TP);
      count -= 1;
      return 1;
   }
   return 0;
}