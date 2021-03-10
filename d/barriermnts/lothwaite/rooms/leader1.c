//leader1.c - Leader's hall for Lothwaite.  Circe 11/1/04
#include <std.h>
#include "../lothwaite.h"

inherit VAULT;

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
      "in burnished %^RESET%^silver sconces%^ORANGE%^.  The grand "+
      "hall continues to the north, leading to what looks to be a "+
      "%^BOLD%^%^BLUE%^raised dais %^RESET%^%^ORANGE%^set between "+
      "two %^RED%^fireplaces%^ORANGE%^.%^RESET%^\n");
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
      ({"dais","raised dais","fireplace","fireplaces"}) : "The "+
         "northern end of the room looks to end with a raised "+
         "dais supporting a large wooden chair, rather like a throne.  "+
         "On either side of the dais is a massive %^RED%^fireplace"+
         "%^RESET%^, each with a rug lying before it."
   ]));
   set_smell("default","The rich fragrance of the fire hangs in the air.");
   set_listen("default","The voices of storytellers and citizens fill the hall.");
   set_exits(([
      "south" : PATHEXIT"pathway27",
      "north" : PATHEXIT"leader2"
   ]));
   set_door("door",PATHEXIT"pathway27","south",0);
   set_door_description("door","This door is made of solid pine "+
      "planks bound seamlessly together.  The highly varnished "+
      "door has been carved with knotwork and images of bees "+
      "fitted with %^YELLOW%^amber %^RESET%^and %^BOLD%^%^BLACK%^"+
      "onyx%^RESET%^.");
}