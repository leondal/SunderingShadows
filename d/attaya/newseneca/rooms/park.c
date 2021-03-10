//park.c - public park
//for new Seneca ~Circe~ 12/17/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_name("Public Park, Seneca");
   set_short("Public Park, Seneca");
   set_long("%^BOLD%^Public Park, Seneca%^RESET%^\n"+
      "%^RESET%^%^GREEN%^Tall %^BOLD%^palm trees %^RESET%^%^GREEN%^"+
      "line the %^BOLD%^%^BLACK%^fence %^RESET%^%^GREEN%^surrounding "+
      "this peaceful little park, blocking much of the noise and "+
      "sights of the %^ORANGE%^co%^RED%^b%^ORANGE%^ble%^RESET%^s%^ORANGE%^to%^RED%^"+
      "n%^ORANGE%^e%^RESET%^%^GREEN%^ streets of the town beyond "+
      "the %^BOLD%^%^BLACK%^wrought iron gate%^RESET%^%^GREEN%^.  "+
      "Tall %^BOLD%^sea oats %^RESET%^%^GREEN%^tipped with %^ORANGE%^"+
      "golden grains %^GREEN%^wave lazily around the park, adding "+
      "their delicate %^MAGENTA%^music %^GREEN%^to the air.  "+
      "A circular %^RESET%^stone picnic table %^GREEN%^stands to "+
      "the west of a path strewn with %^RESET%^%^ORANGE%^p%^RESET%^e"+
      "%^ORANGE%^a gr%^GREEN%^a%^ORANGE%^v%^RESET%^e%^ORANGE%^l"+
      "%^GREEN%^, ready for a quiet meal in an intimate setting.  "+
      "A larger %^RESET%^rectangular picnic table %^GREEN%^is in "+
      "the southeastern corner of the park, just this side of the "+
      "%^BOLD%^%^BLACK%^iron fence %^RESET%^%^GREEN%^that separates "+
      "this public park from the church grounds.  Simple %^RESET%^"+
      "benches %^GREEN%^have been placed among the %^BOLD%^sea oats"+
      "%^RESET%^%^GREEN%^,providing quiet places for visitors to "+
      "relax.  The focal point of the park is the beautiful %^ORANGE%^"+
      "bronze statue %^GREEN%^set within a %^CYAN%^fountain %^GREEN%^"+
      "at the southern end.%^RESET%^\n");
   set_exits(([
      "north" : ROOMS"viento51"
   ]));
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"statue","fountain","bronze statue"}) : "%^CYAN%^The fountain "+
         "at the southern end features a %^RESET%^stone base %^CYAN%^"+
         "that rises about two feet in the air and is filled with "+
         "%^BOLD%^water%^RESET%^%^CYAN%^.  A stream of %^BOLD%^"+
         "%^WHITE%^crystal clear water %^RESET%^%^CYAN%^jets up "+
         "from the fountain's center and comes raining down upon "+
         "the bronze figures of a trio of %^ORANGE%^women%^CYAN%^.  "+
         "The women are depicted holding hands in mid-%^MAGENTA%^"+
         "dance%^CYAN%^, expressions of joy on their faces.  Their "+
         "hair whips about in the frenzy of their movements, bringing "+
         "life to the creation in %^ORANGE%^bronze%^CYAN%^.%^RESET%^",
      ({"fence","iron fence","wrought iron fence"}) : "%^BOLD%^"+
         "%^BLACK%^The iron picket fence has fleur-de-lis caps "+
         "and is set with %^RESET%^stone columns %^BOLD%^"+
         "%^BLACK%^at intervals.  An ornamental gate in the northern side "+
         "of the fence offers entry to the park.%^RESET%^",
      ({"street","boulevard","cobblestone","cobblestones","thoroughfare","streets"}) : 
         "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street%^RESET%^ "+
         "to the north is created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white, which are arranged to form a pattern of "+
         "zig-zagging lines.  The boulevard is well-crafted and was "+
         "carefully planned, allowing plenty of space for two wagons "+
         "side-by-side on each side of the grassy median.",
      ({"oats","sea oats","grains","golden grains"}) : "The sea "+
         "oats have been cultivated to grow here, and they thrive "+
         "within the %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
         "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand.  They are scattered "+
         "about to create a measure of shade and a feeling of "+
         "solitude.",
      ({"table","tables","picnic table","stone picnic table"}) : "The "+
         "picnic tables are set on either side of the narrow path.  "+
         "The circular one to the west has two narrow benches, "+
         "offering just enough room for two people to sit.  The "+
         "rectangular table to the east, however, looks as though "+
         "it could seat quite a few people at once.",
      ({"path","gravel path","pea gravel","pea gravel path"}) : 
         "The narrow path in the center of the park winds through "+
         "the sea oats.  It has been filled with pea gravel, "+
         "adding a touch of contrast.",
      ({"bench","benches","stone bench","stone benches"}) : "Each "+
         "of the benches has a stone top balanced upon dual carved "+
         "bases.  Several of them have been placed around the park, "+
         "and all of them are at least somewhat secluded thanks to "+
         "the towering sea oats."
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/viento51","north",0);
   set_door_description("gate","%^BOLD%^%^BLACK%^The wrought-iron "+
      "gate to the north leads through a matching fence onto a "+
      "bustling street.%^RESET%^");
}
