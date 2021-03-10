//monument1.c ~Circe~ 12/10/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

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
      "centerpiece, a %^BOLD%^%^WHITE%^marble statue%^RESET%^%^GREEN%^ "+
      "of a stoic monk.  Ringing the statue is a large %^ORANGE%^s%^RED%^"+
      "t%^ORANGE%^on%^RESET%^e %^ORANGE%^bo%^RED%^r%^ORANGE%^der%^GREEN%^, "+
      "oval in shape, that has been filled with %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand%^GREEN%^, combining with the "+
      "detail of the statue to make it seem as if the monk is simply "+
      "resting here for a moment before continuing on his way.  Small "+
      "%^BOLD%^trees%^RESET%^%^GREEN%^ with %^RED%^reddish leaves %^GREEN%^"+
      "are spread throughout this garden, filling the air with their "+
      "light, fresh fragrance.  There are no benches here, but small "+
      "square %^RESET%^stones %^GREEN%^inscribed with %^CYAN%^runes "+
      "%^GREEN%^are spread across the ground, and the grass is certainly "+
      "soft enough for a comfortable seat.  The tall %^BOLD%^%^WHITE%^"+
      "fence%^RESET%^%^GREEN%^ bounding the northern and western ends "+
      "of the garden have been lined with %^BOLD%^hedges%^RESET%^"+
      "%^GREEN%^.  The elements of the garden blend to generate a "+
      "sense of %^MAGENTA%^reverence%^GREEN%^ and %^CYAN%^honor%^GREEN%^.%^RESET%^\n");
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
         "to the east and south and the town square to the southeast "+
         "are created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white arranged in zig-zagging patterns.",
      "grass" : "%^BOLD%^%^GREEN%^The grass here is soft and well-"+
         "groomed, quite unlike most of the beach grass growing "+
         "thoughout Seneca.  It is kept relatively short, and it "+
         "would likely be a great place for a picnic.%^RESET%^",
      ({"tree","trees","orange trees","orange tree"}) : "The orange "+
         "trees have small trunks that reach high into the air, their "+
         "flourishing boughs laden with oranges.  If you look close "+
         "enough, you may find an orange ripe enough to pick.",
      ({"fence","hedge","hedges"}) : "Blending into the background "+
         "is the tall fence to the north and west.  The fence is "+
         "%^BOLD%^white%^RESET%^ and made of planks placed side-by-"+
         "side for privacy.  Growing in front of the fence are tall "+
         "%^GREEN%^hedges %^RESET%^that further add to the tranquil "+
         "atmosphere here, despite being so close to the bustling "+
         "center of Seneca.",
      ({"border","stone border","oval border"}) : "The oval border "+
         "has been crafted from the same smooth %^ORANGE%^s%^RED%^"+
         "t%^ORANGE%^on%^RESET%^e as the cobblestone streets.  "+
         "Much like the edge of a flowerbed, it contains the "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n sand to keep it from spilling into the grass.",
      ({"sand","golden sand"}) : "The soft %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
         "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand that covers much of "+
         "Seneca is gathered here and made a fitting part of the monument "+
         "honoring Seneca's Altherian monks.",
      ({"tree","trees","leaves","reddish leaves"}) : "%^GREEN%^The "+
         "trees spread around the garden are small but feature "+
         "beautiful spreading boughs full of %^ORANGE%^r%^RED%^e"+
         "%^ORANGE%^d%^RED%^d%^ORANGE%^i%^RED%^s%^ORANGE%^h "+
         "%^RED%^leaves%^GREEN%^, each a delicate beauty with "+
         "five slender points.%^RESET%^",
      ({"stones","square stones","stone","runes"}) : "Each of the "+
         "stones is rather like a paving stone, large and flat.  "+
         "The top of each ahs been carved with a different rune, "+
         "though you cannot seem to tell the meanings."
   ]));
   set_exits(([
      "east" : ROOMS"skyline43",
      "south" : ROOMS"viento53",
      "southeast" : ROOMS"square"
   ]));
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
   if(!present("monk statue")) new(OBJ"monk_statue")->move(TO);
}