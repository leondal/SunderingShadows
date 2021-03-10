//cath_foyer.c - entryway of the cathedral
//for new Seneca ~Circe~ 1/16/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Narthex of the Cathedral, Seneca");
   set_short("Narthex of the Cathedral, Seneca");
   set_long("%^BOLD%^Narthex of the Cathedral, Seneca%^RESET%^\n"+
      "Open to both the east and west, this foyer serves as the "+
      "entryway to the grand %^BOLD%^Cathedral%^RESET%^, open to "+
      "the public at all "+
      "times.  Slender %^BOLD%^silver columns %^RESET%^divide "+
      "the twin archways that lead outside, and looking closely, "+
      "you see that sliding panels have been cleverly hidden "+
      "inside the exterior walls so the church may be protected "+
      "in times of inclement %^CYAN%^weather %^RESET%^or invasion.  "+
      "The floor is tiled with %^ORANGE%^m%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^"+
      "r%^BOLD%^%^WHITE%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^e "+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^a"+
      "%^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^s %^RESET%^in shades "+
      "of %^ORANGE%^copper %^RESET%^and %^BOLD%^cream%^RESET%^ "+
      "that create a backdrop for the beautiful %^BOLD%^stone "+
      "font %^RESET%^standing upon a slender pedestal in the "+
      "center.  An %^ORANGE%^oaken door %^RESET%^in the southern "+
      "wall is banked on either side by elaborate %^ORANGE%^brass "+
      "candelabra %^RESET%^rising on smooth narrow stands to "+
      "spread fifteen %^BOLD%^pristine candles %^RESET%^in a "+
      "graceful crescent.  Northward is the grand entrance "+
      "into the lofty nave with its towering %^BOLD%^columns "+
      "%^RESET%^rimmed in %^YELLOW%^gold %^RESET%^and swooping "+
      "%^BOLD%^arches %^RESET%^rising to the vaulted ceiling "+
      "overhead.  The central aisle of the nave runs east and "+
      "west, causing the approach from the foyer to be at a "+
      "ninety degree angle.\n");
   set_exits(([
      "north" : ROOMS"cath_nave",
      "south" : ROOMS"cath_vestry",
      "west" : ROOMS"garden1",
      "east" : ROOMS"cath_yard"
   ]));
   set_smell("default","The clean scent of the ocean wafts in through the open archways.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"floor","diamonds","marble diamonds"}) : "An intricate "+
         "design covers the floor of the vestry.  Large marble "+
         "tiles cut into one-foot squares have been turned "+
         "diagonally and fitted point-to-point.  The rows "+
         "alternate %^ORANGE%^copper %^RESET%^and %^BOLD%^"+
         "cream%^RESET%^ so that, when viewed from an angle, the "+
         "floor appears to be a giant chessboard.",
      ({"column","columns"}) : "There are two types of columns "+
         "you can look at: the slender silver columns divide "+
         "the eastern and western entryways, and the marble "+
         "columns brace the entrance to the nave.",
      ({"silver columns","slender silver columns"}) : "%^BOLD%^"+
         "The fluted silver column in each entryway is slender "+
         "end elegant in design.  Each looks to have been carved "+
         "from stone and finished with %^RESET%^silver leaf%^BOLD%^"+
         "to give it additional sheen.  The columns support the "+
         "twin archways that grant entrance from the east and "+
         "west.%^RESET%^",
      ({"marble columns","towering columns","nave columns"}) :
         "The entrance to the nave is a giant archway supported "+
         "only by two towering %^BOLD%^marble columns%^RESET%^ "+
         "with their bases and capitals trimmed in %^YELLOW%^"+
         "gold%^RESET%^.  Each column is smooth and nearly soft "+
         "to the touch, the simplicity of the column itself "+
         "serving to heighten the decorative %^YELLOW%^attic "+
         "base %^RESET%^and %^YELLOW%^corinthian capital"+
         "%^RESET%^, each of which is carved from marble and "+
         "edged with %^YELLOW%^gold%^RESET%^.",
      ({"archway","archways"}) : "To the east, a paired archway "+
         "leads back out onto the %^BOLD%^white path %^RESET%^"+
         "that in turn leads to %^YELLOW%^Sol Boulevard%^RESET%^, "+
         "while a matching paired archway to the west leads into "+
         "the %^GREEN%^Cathedral gardens%^RESET%^.  An immense "+
         "archway to the east grants access to the breathtaking "+
         "%^BOLD%^nave%^RESET%^.",
      ({"panels","sliding panels"}) : "Looking closely, you can "+
         "see just the edge of the sliding panels in the twin "+
         "archways.  It seems they may be pulled close when "+
         "there is need, though the means to do so is not readily "+
         "apparent.  The panels seem to fit into grooves in the "+
         "center column which are deeper than the typical fluting "+
         "but cleverly hidden by it.",
      ({"font","stone font","holy water font","water font"}) :
         "A slender basin rises to support this beautiful font "+
         "containing %^CYAN%^holy water%^RESET%^.  Here, "+
         "monks and other faithful often bless themselves as a "+
         "sign of their dedication and contemplation before "+
         "journeying further into the Cathedral.",
      ({"candelabra","brass candelabra","candles","pristine candles"}) :
         "Impossibly thin stands made of brass rise gracefully "+
         "to support the crescent arches of fifteen candles.  "+
         "Each %^ORANGE%^brass candelabra %^RESET%^is ornate "+
         "in design, the light of the flawless %^BOLD%^white "+
         "candles %^RESET%^glinting off the myriad %^ORANGE%^"+
         "scrolling curves%^RESET%^.",
      "nave" : "The entrance to the nave lies to the north, "+
         "and it has been set at a right angle to this foyer.  "+
         "Peering through the archway, you can see that the "+
         "central aisle is lined on either side by huge "+
         "%^ORANGE%^wooden pews %^RESET%^polished until they "+
         "gleam."
   ]));
   set_door("door","/d/attaya/newseneca/rooms/cath_vestry","south",0);
   set_door_description("door","%^ORANGE%^The simple oaken door "+
      "to the south is stained a deep brown.  It is set with "+
      "burnished %^BOLD%^brass hinges %^RESET%^%^ORANGE%^and "+
      "a matching %^BOLD%^handle%^RESET%^%^ORANGE%^.%^RESET%^");
}
