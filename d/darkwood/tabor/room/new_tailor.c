//New tailor for Tabor.  Circe 4/26/05

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_property("indoors",1);
  set_light(2);
  set_name("Clothing by Kelsey");
  set_short("Clothing by Kelsey");
  set_long(
@TABOR
%^BOLD%^Clothing by Kelsey, Tabor%^RESET%^
%^ORANGE%^This quaint shop is small, but well-cared-for.  It features a
few %^YELLOW%^homey touches%^RESET%^%^ORANGE%^, namely small %^CYAN%^vases of flowers %^ORANGE%^and a few 
%^BOLD%^%^WHITE%^hand-stitched pieces%^RESET%^%^ORANGE%^.  Simple %^YELLOW%^forms %^RESET%^%^ORANGE%^are placed around the 
room, sporting finished items and products in the works.  Each 
item in the store is neatly folded and placed on %^YELLOW%^shelves%^RESET%^%^ORANGE%^, with 
a few hanging for display.  It seems the owner tries to keep a 
variety of items and colors available along with making a 
sampling of different sizes.  A long %^RESET%^table %^ORANGE%^runs the length 
of the room, and it has been placed discreetly in the back 
to provide a work area with %^BOLD%^%^WHITE%^scissors%^RESET%^%^ORANGE%^, %^YELLOW%^threads%^RESET%^%^ORANGE%^, and a variety 
of %^MAGENTA%^dyes%^ORANGE%^.  No stool is in sight, as it seems the owner must 
keep herself rather busy.
TABOR
    );
  set_exits(([
    "west" : ROOMDIR+"math3",
  ]));
  set_listen("default","You hear the muffled sounds of the large town outside.");
  set_smell("default","A clean, light fragrance is in the air.");
  set_items(([
      ({"vases","vase","flowers","vases of flowers","flowers"}) : "The "+
         "vases are hand-made and glazed in light shades of green.  They "+
         "hold bouquets of wildflowers that add their pleasant fragrance "+
         "to the shop.",
      ({"pieces","hand-stitched pieces"}) : "The framed pieces show "+
         "expert needlework.  All of them show various faeries set "+
         "amongst beautifully worked flowers.",
      ({"forms","mannequin","mannequins"}) : "The wooden forms are "+
         "roughly the size and shape of a human torso.  They have "+
         "been planed and sanded so as to not snag clothing, and "+
         "they give a decent idea as to the way an article of "+
         "clothing will look when worn.",
      ({"clothes","clothing","items","shelves"}) : "The clothes are of wonderful "+
         "quality and show a variety of items and colors.  They are "+
         "folded neatly on shelves all around the store.",
      ({"table","scissors","dyes","threads"}) : "The dyes, threads, "+
         "and scissors are neatly arranged on the table, within "+
         "easy reach of the seamstress as she works.  She clearly "+
         "treats each item well, putting it carefully away when "+
         "she has finished."
  ]));
}

void reset(){
	::reset();
      if(!present("kelsey") && !query_night()){
         new(MONDIR+"kelsey")->move(TO);
      }
}
