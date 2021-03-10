//updated by Circe 12/31/04 with new desc, etc.
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Tonovi General Store");
    set_name("Tonovi General Store");
/*    set_long(
   "This small, well organized general store is set up with general supplies that commoners need, not that the commoners of this area are able to afford them here, and the items most adventurers need to continue to succeed in their adventures."
    );
*/
    set_long("This small, well-organized store is set up with "+
       "%^ORANGE%^trade goods %^RESET%^often needed by commoners "+
       "in %^BOLD%^%^GREEN%^Tonovi %^RESET%^as well as %^ORANGE%^"+
       "supplies %^RESET%^in demand by adventurers and travelers.  "+
       "A clean stone counter made of %^BOLD%^%^BLACK%^glit%^WHITE%^"+
       "te%^BLACK%^ring gra%^WHITE%^n%^BLACK%^ite %^RESET%^stands "+
       "in the center of the room, the place where all transactions "+
       "are finalized.  Shallow %^ORANGE%^wooden shelves %^RESET%^"+
       "line the walls, supporting everything from %^BOLD%^sacks of "+
       "flour %^RESET%^to %^CYAN%^weapon sheaths %^RESET%^and "+
       "%^ORANGE%^climbing tools%^RESET%^.  A light %^CYAN%^haze "+
       "%^RESET%^of %^BOLD%^pipe smoke %^RESET%^hangs in the air of "+
       "the otherwise pristine shop.  The shop is lit by several "+
       "%^YELLOW%^oil lamps %^RESET%^placed around the room.\n");
    set_smell("default", "The smell of new metal and fresh "+
       "woodworking mingle with a slight hint of pipesmoke.");
    set_listen("default", "The bustle of the city and the cries of "+
       "the poor outside can barely reach your ears.");
    set_items(([
       ({"shelf","shelves"}): "The shallow shelves are made of sturdy "+
          "wood that still looks new.  They are lined with all manner "+
          "of items, all arranged neatly and within easy reach.",
       ({"woodwork","floor","walls"}) : "The store has work put into "+
          "its creation, with the wood crafted with great care and expense.",
       ({"light","lights"}) : "The oil lamps light the store well "+
          "and are shielded from drafts.",
       ({"counter","stone counter","granite","granite counter"}) : "%^BOLD%^"+
          "%^BLACK%^The black counter is made of glittering granite "+
          "with small deposits of quartz that shimmer in the light "+
          "of the oil lamps.  It stands about four feet high and is "+
          "somewhat narrow, allowing business to be conducted over "+
          "its top comfortably.",
       ({"flour","sacks","sacks of flour"}) : "%^BOLD%^Sacks of "+
          "flour and various other trade goods are kept in supply "+
          "for the commoners of the city.",
       ({"weapon sheaths","sheaths","climbing tools","supplies"}) : "The "+
          "supplies most commonly called for by travellers are kept on "+
          "the closest shelves, ready to be taken at a moment's "+
          "notice.  All look to be of very good quality."
    ]));
    set_exits(([
      "south" : RPATH "street8"
    ]));
}

void reset(){
::reset();
    if(!present("deleanek"))
      new(MPATH "deleanek")->move(TO);
}
