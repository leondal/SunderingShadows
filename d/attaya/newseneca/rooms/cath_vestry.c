//cath_vestry.c - vestry of the cathedral
//for new Seneca ~Circe~ 1/15/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Vestry of the Cathedral, Seneca");
   set_short("Vestry of the Cathedral, Seneca");
   set_long("%^BOLD%^Vestry of the Cathedral, Seneca%^RESET%^\n"+
      "This square room is designed as both a meeting and storage "+
      "area for the monks of the %^BOLD%^Cathedral%^RESET%^.  "+
      "Just to the west of the %^ORANGE%^door%^RESET%^ from the "+
      "foyer is a narrow %^BOLD%^white marble stairway %^RESET%^that "+
      "leads into the basement while the floor of the vestry itself is "+
      "tiled with %^ORANGE%^m%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^"+
      "r%^BOLD%^%^WHITE%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^e "+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^a"+
      "%^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^s %^RESET%^in shades "+
      "of %^ORANGE%^copper %^RESET%^and %^BOLD%^cream%^RESET%^.  "+
      "The entire western wall is lined with a %^ORANGE%^wooden "+
      "wardrobe %^RESET%^that houses the %^BOLD%^ceremonial "+
      "robes %^RESET%^used by the monks in more solemn occasions.  "+
      "An ancient large oval %^RED%^redwood table%^RESET%^ has "+
      "been placed in the southern part of the room, surrounded "+
      "by much newer %^RED%^redwood chairs%^RESET%^.  Gracing "+
      "most of the southern wall from floor to ceiling is an "+
      "opulent %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^ that sheds multi-colored light "+
      "on the room, creating a dazzling sense of awe.  "+
      "All along the eastern wall, %^ORANGE%^"+
      "brass sconces %^RESET%^hold %^BOLD%^candles %^RESET%^"+
      "to provide illumination for the monks at work, their "+
      "line unbroken save by the door in the center of the wall.  "+
      "Completing the room's furnishings, a tall %^ORANGE%^"+
      "cabinet%^RESET%^ stands in the northeastern corner, "+
      "likely holding %^CYAN%^incense %^RESET%^and other "+
      "supplies.\n");
   set_exits(([
      "east" : ROOMS"cath_tower1",
      "north" : ROOMS"cath_foyer",
      "down" : ROOMS"cath_basement"
   ]));
   set_smell("default","The clean scent of the ocean wafts in through the windows.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"stairs","stairway","white stairway","white marble stairway","marble stairway"}) :
         "Leading down into the darkened basement, the white "+
         "marble stairway is rather narrow and looks to have "+
         "been carved for both function and beauty, much like the "+
         "rest of the cathedral.  In the recesses of the basement, "+
         "many of the monks live and study, spending out their "+
         "entire lives in the warrens below.",
      ({"floor","diamonds","marble diamonds"}) : "An intricate "+
         "design covers the floor of the vestry.  Large marble "+
         "tiles cut into one-foot squares have been turned "+
         "diagonally and fitted point-to-point.  The rows "+
         "alternate %^ORANGE%^copper %^RESET%^and %^BOLD%^"+
         "cream%^RESET%^ so that, when viewed from an angle, the "+
         "floor appears to be a giant chessboard.",
      ({"wardrobe","wooden wardrobe"}) : "%^ORANGE%^The large "+
         "wardrobe along the western wall is about seven feet "+
         "tall and nearly as wide as the wall itself.  It bears "+
         "four pairs of doors, each pair fitted with %^BOLD%^"+
         "brass handles%^RESET%^%^ORANGE%^ to ensure a proper "+
         "close.%^RESET%^",
      ({"robes","ceremonial robes"}) : "Opening a door of the "+
         "wardrobe, you peek inside and see rows of ceremonial "+
         "robes.  Unlike the typical %^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^"+
         "%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n"+
         "%^RESET%^%^ORANGE%^-%^YELLOW%^o%^RESET%^%^ORANGE%^r"+
         "%^YELLOW%^a%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RESET%^"+
         "%^ORANGE%^e robes %^RESET%^the monks wear daily, "+
         "many of these are crafted from brilliant colors that "+
         "must have special significance.",
      ({"table","redwood table","chairs","redwood chairs"}) : 
         "%^RED%^The oval table in the southern part of the room "+
         "is massive, easily seating twelve or more comfortably.  "+
         "Rumor has it that the table was crafted ages ago by "+
         "a master carver on Graez who gifted the table to the "+
         "Altherian monks long before the war of Intruder.  It is "+
         "said to be one of the few remaining relics from before "+
         "that time.  The chairs, sadly, were lost to age long "+
         "ago, and they have been replaced by newer, straight-"+
         "backed chairs from the same material.%^RESET%^",
      ({"window","stained glass window"}) : "The towering "+
         "%^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
         "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
         "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
         "%^BLUE%^w %^RESET%^is a veritable riot of color, "+
         "breaking the almost dull serenity of the rest of the cathedral.  "+
         "The window is as wide as the table and reaches all "+
         "the way from the marble floor to just a few feet "+
         "from the ceiling, arching into a point.  The colorful "+
         "panels are different sizes and shapes, all working "+
         "together to create a breathtaking abstract image.",
      ({"sconce","sconces","brass sconces","candles"}) : "Aside "+
         "from the window, the illumination of the room is "+
         "provided by the many candles that burn in simple "+
         "brass sconces fitted with glass lids.  They line "+
         "the eastern wall, each with a candle to help brighten "+
         "the room.",
      ({"cabinet","wooden cabinet","tall cabinet"}) : "The tall "+
         "cabinet in the northwestern corner looks positively "+
         "narrow when compared with the wardrobe.  It has two "+
         "doors that open from the center, each fitted with a "+
         "%^ORANGE%^burnished brass handle%^RESET%^.",
      ({"incense","supplies"}) : "Opening one of the cabinet "+
         "doors, you find sticks of incense, extra candles, "+
         "bottles of ink, stacks of parchment, and other such "+
         "supplies needed to keep the cathedral in working order."
   ]));
   set_door("tower door","/d/attaya/newseneca/rooms/cath_tower1","east",0);
   set_door_description("tower door","%^ORANGE%^The simple oaken door "+
      "to the east is stained a deep brown.  It is set with "+
      "burnished %^BOLD%^brass hinges %^RESET%^%^ORANGE%^and "+
      "a matching %^BOLD%^handle%^RESET%^%^ORANGE%^.%^RESET%^");
   set_door("door","/d/attaya/newseneca/rooms/cath_foyer","north",0);
   set_door_description("door","%^ORANGE%^The simple oaken door "+
      "to the north is stained a deep brown.  It is set with "+
      "burnished %^BOLD%^brass hinges %^RESET%^%^ORANGE%^and "+
      "a matching %^BOLD%^handle%^RESET%^%^ORANGE%^.%^RESET%^");
}
