//cath_nave.c - main worship area of the cathedral
//for new Seneca ~Circe~ 1/17/08
#include <std.h>
#include "../seneca.h"

inherit "/std/church";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Nave of the Cathedral, Seneca");
   set_short("Nave of the Cathedral, Seneca");
   set_long("%^BOLD%^Nave of the Cathedral, Seneca%^RESET%^\n"+
      "The vaulted ceilings of the nave are supported by high-"+
      "reaching %^BOLD%^stone arches%^RESET%^, breathtaking in "+
      "their simplicity.  The gleaming floor is crafted from "+
      "%^ORANGE%^m%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^"+
      "r%^BOLD%^%^WHITE%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^e "+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^a"+
      "%^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^s %^RESET%^in shades "+
      "of %^ORANGE%^copper %^RESET%^and %^BOLD%^cream%^RESET%^ "+
      "that lend their soft radiance to the polished %^ORANGE%^"+
      "wooden pews %^RESET%^lining the central aisle, which runs "+
      "west to east.  Each of the pews has a %^BOLD%^cream"+
      "-colored pad %^RESET%^that matches the kneeler attached "+
      "to the pew in front of it, though the pads seem too thin "+
      "to provide much comfort.  Approaching the eastern end, "+
      "the pews give way to a series of long, narrow steps that "+
      "lead to a %^BOLD%^dais%^RESET%^ housing the %^ORANGE%^"+
      "altar %^RESET%^draped in exquisite %^YELLOW%^g%^RESET%^"+
      "%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e"+
      "%^RESET%^%^ORANGE%^n %^YELLOW%^c%^RESET%^%^ORANGE%^l"+
      "%^YELLOW%^o%^RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^ "+
      "braced on either side by graceful %^ORANGE%^brass "+
      "candelabra%^RESET%^.  The eastern and western walls "+
      "upon the dais are fitted with rows of %^ORANGE%^chairs%^RESET%^ "+
      "whose tall backs extend over the heads of their occupants, "+
      "revealing carved images of crowns.  An exquisite %^YELLOW%^"+
      "altar screen %^RESET%^rises at the far end of the dais, "+
      "its golden surface carved into panels and gilded, towering "+
      "high overhead to convey a sense of vastness.  A quiet "+
      "attitude of solemnity ensconces the nave, encouraging "+
      "respect in all who enter.\n");
   set_exits(([
      "east" : ROOMS"cath_chancel",
      "south" : ROOMS"cath_foyer"
   ]));
   set_invis_exits(({"east"}));
   set_pre_exit_functions(({"east"}),({"panel"}));
   set_smell("default","The clean scent of the ocean is heightened "+
      "by the pungent fragrance of incense.");
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
      ({"arch","arches","stone arches"}) : "The smooth stone of "+
         "the arches rise from thick columns staggered along the "+
         "northern and southern walls.  Each archway curves up "+
         "to support the ceiling, highlighting the impressive "+
         "height.",
      ({"column","columns"}) : "Columns march along the northern "+
         "and southern walls, their bases and capitals trimmed in %^YELLOW%^"+
         "gold%^RESET%^.  Each column is smooth and nearly soft "+
         "to the touch, the simplicity of the column itself "+
         "serving to heighten the decorative %^YELLOW%^attic "+
         "base %^RESET%^and %^YELLOW%^corinthian capital"+
         "%^RESET%^, each of which is carved from marble and "+
         "edged with %^YELLOW%^gold%^RESET%^.",
      ({"candelabra","brass candelabra","candles","pristine candles"}) :
         "Impossibly thin stands made of brass rise gracefully "+
         "to support the crescent arches of fifteen candles.  "+
         "Each %^ORANGE%^brass candelabra %^RESET%^is ornate "+
         "in design, the light of the flawless %^BOLD%^white "+
         "candles %^RESET%^glinting off the myriad %^ORANGE%^"+
         "scrolling curves%^RESET%^.",
      ({"pew","pews","wooden pews","kneeler","kneelers","pad","pads"}) :
         "%^ORANGE%^Each of the wooden pews has been well-cared-"+
         "for.  They are carved from large pieces of wood and "+
         "have straight backs, their rigidity broken only by "+
         "the thin %^BOLD%^%^WHITE%^cream pads %^RESET%^%^ORANGE%^"+
         "that line them.  Each of the pews has a sectioned "+
         "kneeler that may be pulled down from the bench before "+
         "it.%^RESET%^",
      ({"steps","dais"}) : "The steps are narrow but as long as "+
         "the nave is wide, running from northern to southern "+
         "walls.  A series of three of them rise to the square "+
         "dais that holds the altar.",
      ({"altar","cloth","altar cloth","golden cloth"}) : 
         "Unlike many marble altars, this one has been carved from "+
         "a single block of wood.  The size of the tree that must "+
         "have borne such a massive trunk is staggering.  The "+
         "altar is rectangular in shape and only lightly carved, "+
         "though it is polished to a high shine and draped with an "+
         "incredible altar cloth of gold.",
      ({"chair","chairs","rows","rows of chairs"}) : "The chairs "+
         "upon the dais are narrow and feature slender arms and "+
         "tall, carved backs.  Both the northern and southern wall "+
         "feature a row of six, each row angled so that the outer"+
         "most is against the wall, while the innermost is nearly "+
         "in line with the edge of the altar, allowing whoever "+
         "sits in these chairs to see the proceedings.",
      ({"screen","altar screen"}) : "The wooden altar screen "+
         "in the eastern end is simply gorgeous.  Its smooth "+
         "facade has been carved into slender panels and decorated "+
         "with guilding, creating a gleaming backdrop for the "+
         "ceremonies that take place here.  Upon closer "+
         "inspection, you realize the center panel is actually a "+
         "working door that allows you to move east."
   ]));
/*
   set_door("door","/d/attaya/newseneca/rooms/cath_chancel","east",0);
   set_door_description("door","This is elaborate and stuff.");
Change this to cheat since doors don't work with churches.  East will be a hidden exit, and when you go east, it will emote that you push open the panel and go through.
*/
}

int panel(){
   tell_object(TP,"You push the center panel of the altar screen, "+
      "and it opens, allowing you to go into the room beyond.");
   tell_room(TO,""+TPQCN+" pushes the center panel of the altar "+
      "screen and moves through it as it opens.",TP);
   tell_room("/d/attaya/newseneca/rooms/cath_chancel","The small "+
      "central panel of the altar screen opens and "+TPQCN+" "+
      "emerges.",TP);
   return 1;
}
