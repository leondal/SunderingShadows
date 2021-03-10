//leader2.c - Leader's hall for Lothwaite.  Circe 11/1/04
#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Grand Hall of Lothwaite");
   set_short("%^RESET%^%^ORANGE%^Grand Hall of Lothwaite%^RESET%^");
   set_long("%^ORANGE%^This grand hall is fashioned with a high, "+
      "arching ceiling.  Strong wooden columns rise along the walls, "+
      "the surface of each column carved with intricate %^YELLOW%^"+
      "knotwork %^RESET%^%^ORANGE%^inset with countless %^YELLOW%^"+
      "bees%^RESET%^%^ORANGE%^ fitted with %^YELLOW%^amber "+
      "%^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^onyx%^RESET%^%^ORANGE%^.  "+
      "The overall effect is dazzling, especially when compared "+
      "with the relatively rustic atmosphere of the village.  "+
      "The walls here are made of thick %^RESET%^pine planks%^ORANGE%^, "+
      "quite unlike the wattle walls of other buildings.  The center "+
      "of the hall is dominated by a long %^YELLOW%^table %^RESET%^"+
      "%^ORANGE%^bounded on either side by low benches.  The floor "+
      "here is set with %^CYAN%^ceramic tiles %^ORANGE%^that "+
      "look to have been imported.  All around the perimeter of "+
      "the room, %^YELLOW%^torches %^RESET%^%^ORANGE%^burn brightly "+
      "in burnished %^RESET%^silver sconces%^ORANGE%^.  The table "+
      "ends a few feet short of the base of a large %^BOLD%^%^BLUE%^"+
      "raised dais %^RESET%^%^ORANGE%^decorated with %^BOLD%^%^BLUE%^"+
      "deep blue tiles%^RESET%^%^ORANGE%^.  Sitting atop the dais is "+
      "a huge %^YELLOW%^oaken throne%^RESET%^%^ORANGE%^.  To both "+
      "the right and left, large %^GREEN%^deep green rugs %^ORANGE%^"+
      "lie upon the %^CYAN%^tiled floor%^ORANGE%^, providing a bit of "+
      "contrast and a comfortable place to recline before the %^RED%^"+
      "fireplaces%^ORANGE%^.  Here, many people relax and listen to "+
      "the tales of the Master Scald of Lothwaite.%^RESET%^\n");
   set_items(([
      "ceiling" : "The ceiling arches high overhead, the columns "+
         "joining to look almost like the backbone of some great "+
         "beast.  Their jewels sparkle in the light of the torches, "+
         "giving the room an enchanting feel.",
      ({"column","columns","bees"}) : "Each of the %^ORANGE%^columns "+
         "%^RESET%^has been painstakingly carved with intricate "+
         "%^YELLOW%^knotwork%^RESET%^, symbolizing the unity of the "+
         "village.  Each piece was carved by hand by a different "+
         "member of the community, creating subtle variations.  "+
         "Within the %^YELLOW%^knotwork %^RESET%^are countless "+
         "representations of the %^YELLOW%^bees %^RESET%^of "+
         "Lothwaite, each set with %^YELLOW%^amber %^RESET%^and "+
         "%^BOLD%^%^BLACK%^onyx%^RESET%^.",
      ({"wall","walls","planks","pine planks"}) : "The walls are "+
         "made of thick, smooth pine planks that block the wind "+
         "and give the hall a rich appearance.",
      ({"table","bench","benches"}) : "The long table is fairly "+
         "narrow.  It does not seem to be used for meals, but "+
         "rather for discussions of village life.  The benches on "+
         "either side provide a comfortable place for a firbolg to "+
         "relax while dealing with pressing matters.",
      ({"floor","tiles","ceramic tiles"}) : "%^CYAN%^The floor is "+
         "fitted with many ceramic tiles.  Each is a varying shade "+
         "of blue, and they all have different scenes and patterns "+
         "painted upon their surface.  Their overall chaotic appearance "+
         "seems to somehow come together to create a pleasing look.",
      ({"torches","sconces","silver sconces"}) : "Silver sconces are "+
         "fitted midway up the columns, each holding a torch that "+
         "burns brightly, adding to the light of the room.",
      ({"dais","raised dais","throne"}) : "The %^BOLD%^%^BLUE%^dais "+
         "%^RESET%^is covered in well-made %^BOLD%^%^BLUE%^blue tiles "+
         "%^RESET%^that shimmer lightly in the glow of the torches.  "+
         "A tall %^YELLOW%^oaken throne %^RESET%^stands upon it, its "+
         "back carved in various images of bees and knotwork.  The "+
         "throne has been padded with a %^GREEN%^deep green cushion "+
         "%^RESET%^trimmed in %^YELLOW%^gold%^RESET%^.",
      ({"rug","rugs","fireplace","fireplaces"}) : "The two fireplaces "+
         "burn brightly year-round, as much as testament to the "+
         "firbolg belief that a warm hearth is a sign of community as "+
         "a means to provide warmth and light.  The %^GREEN%^green "+
         "rugs %^RESET%^are trimmed in %^YELLOW%^gold braid %^RESET%^"+
         "much like the cushion upon the throne.  On these rugs, many "+
         "citizens of Lothwaite recline to listen to the stories of "+
         "the scalds."
   ]));
   set_smell("default","The rich fragrance of the fire hangs in the air.");
   set_listen("default","The voices of storytellers and citizens fill the hall.");
   set_exits(([
      "south" : PATHEXIT"leader1",
   ]));
}