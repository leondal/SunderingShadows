//Jeweler for Tabor.  Circe 6/1/04

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_property("indoors",1);
  set_light(2);
  set_name("Cornelia's Crystal Creations");
  set_short("Cornelia's Crystal Creations");
  set_long(
@TABOR
%^BOLD%^Cornelia's Crystal Creations, Tabor%^RESET%^
%^BOLD%^%^BLUE%^This airy shop has a front made almost entirely 
of %^CYAN%^glass%^BLUE%^!  The floor-to-ceiling windows are covered in 
widely-spaced %^YELLOW%^sun-catchers %^BLUE%^that produce a %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w %^BOLD%^%^BLUE%^of colors 
on the opposite wall.  %^CYAN%^Glass cases %^BLUE%^are spaced evenly around 
the walls, all holding some of Cornelia's most prized creations.  
Strangely, several bunches of %^RESET%^%^ORANGE%^dried herbs %^BOLD%^%^BLUE%^tied with %^MAGENTA%^colorful 
ribbons %^BLUE%^also hang from various places, providing an unusual,
though not distasteful, decoration.  A low %^RESET%^%^ORANGE%^wooden table %^BOLD%^%^BLUE%^sits 
in the back of the room, covering in small hammers, chisels, 
twine, and various other implements used in jewelling.  A short 
%^RESET%^%^ORANGE%^stool %^BOLD%^%^BLUE%^stands just behind it.
TABOR
    );
  set_exits(([
    "south" : ROOMDIR+"gwy4",
  ]));
  set_listen("default","You hear the muffled sounds of the large town outside.");
  set_smell("default","A clean, light fragrance is in the air.");
  set_items(([
     ({"windows","window","front"}) : "%^BOLD%^%^CYAN%^The windows "+
        "at the front of the store are glass from floor to ceiling.  "+
        "Gnomish craftmanship has clearly been at work here, as even "+
        "the door itself is made of glass!  Suncatchers have been "+
        "placed around the glass, and they send their brilliant "+
        "%^BLUE%^c%^RED%^o%^MAGENTA%^l%^YELLOW%^o%^GREEN%^r%^WHITE%^s "+
        "%^CYAN%^dancing around the shop.",
     ({"suncatcher","sun catcher","suncatchers","sun catchers"}) : "These "+
        "bright creations range from simple %^BOLD%^prisms %^RESET%^"+
        "suspended on thin wires to elaborate %^YELLOW%^crystal "+
        "%^RED%^m%^RESET%^%^ORANGE%^o%^YELLOW%^s%^GREEN%^a%^CYAN%^i"+
        "%^BLUE%^c%^RESET%^%^MAGENTA%^s%^RESET%^.  Each one catches "+
        "the %^YELLOW%^light%^RESET%^ and sends it dancing around "+
        "the shop, sometimes making it seem quite chaotic on a bright "+
        "day.",
     ({"cases","glass cases","case"}) : "Cornelia's wares are displayed "+
        "in glass cases placed neatly around the room.  Clearly, some "+
        "of these pieces are not for sale but are displayed to show "+
        "Cornelia's handiwork.",
     ({"herbs","bunches","bunches of herbs","dried herbs"}) : "Several "+
        "bunchs of dried herbs have been tied with colorful ribbons "+
        "and hung at various location around the room.  They do "+
        "not detract from the decor, but they do seem a little "+
        "out of place, given the vivacity of the room.",
     ({"table","hammer","chisels","twine","implements"}) : "The "+
        "low table in the back is covered in implements of jeweling.  "+
        "Most sit neatly in their own cases or hang from custom-made "+
        "racks.  Clearly some of the more unusual tools are of "+
        "gnomish construction - and even a gnome might have to "+
        "guess at their use.",
     "stool" : "A small, sturdy stool upon which Cornelia sits "+
        "to do her work."
  ]));
}

void reset(){
	::reset();
      if(!present("cornelia") && !query_night()){
         new(MONDIR+"cornelia")->move(TO);
      }
}
