//beach.c ~Circe~ 6/11/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(BEACH);
   set_travel(DIRT_ROAD);
   set_climate("tropical");
   set_property("light", 2);
   set_name("A Golden Beach, Attaya");
   set_short("%^BOLD%^%^WHITE%^A %^YELLOW%^G%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n %^BOLD%^Beach, Attaya%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A %^YELLOW%^G%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n %^BOLD%^Beach, Attaya%^RESET%^\n"+
      "Stretching to the east and west is a blanket of %^BOLD%^g"+
      "%^RESET%^l%^BOLD%^i%^RESET%^t%^BOLD%^t%^RESET%^e%^BOLD%^r"+
      "%^RESET%^i%^BOLD%^n%^RESET%^g %^YELLOW%^g%^WHITE%^o"+
      "%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n %^YELLOW%^s"+
      "%^WHITE%^a%^RESET%^n%^YELLOW%^d%^RESET%^.  The beach is "+
      "rather narrow, bounded by the %^ORANGE%^cliffs %^RESET%^"+
      "rising to the north and the %^BOLD%^%^BLUE%^ocean %^RESET%^"+
      "itself to the south, but what space remains is flat and "+
      "perfect for people to enjoy.  Here and there a lone %^GREEN%^"+
      "palm tree%^RESET%^ dots the landscape, adding just a touch "+
      "of green.  Natural %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^e"+
      "%^RESET%^t%^BOLD%^t%^BLACK%^i%^RESET%^e%^ORANGE%^s%^RESET%^ "+
      "enclose this small cove, helping to protect it from the "+
      "wind.  Far to the east stands a small %^ORANGE%^hut%^RESET%^ "+
      "that would blend in with the sand itself if not for its "+
      "duller finish.  %^BOLD%^Seagulls %^RESET%^ride the wind "+
      "currents overhead or chase little %^BOLD%^sand crabs%^RESET%^ "+
      "while %^BOLD%^s%^YELLOW%^e%^MAGENTA%^a%^WHITE%^s%^RESET%^h"+
      "%^ORANGE%^e%^RESET%^l%^BOLD%^l%^YELLOW%^s %^RESET%^wash up "+
      "on shore, completing the idyllic scene.\n\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   set_listen("default","You can hear the crashing of "+
         "waves on the shore above the occasional cry of a seagull.");
   set_items(([
      ({"beach","golden beach","sand","golden sand"}) : 
         "The soft sand of the beach "+
         "seems to glitter %^YELLOW%^golden %^RESET%^in any "+
         "light.  The beach itself is not very wide between the "+
         "crashing surf and the cliffs upon which this path is "+
         "carved, but there is definitely enough usable space "+
         "for people to enjoy.",
      ({"ocean","surf","white surf"}) : "The breathtaking ocean "+
         "%^BOLD%^%^BLUE%^s%^CYAN%^p%^BLUE%^a%^CYAN%^r%^BLUE%^k"+
         "%^CYAN%^l%^BLUE%^e%^CYAN%^s %^RESET%^%^CYAN%^green "+
         "%^RESET%^and %^BOLD%^%^BLUE%^blue %^RESET%^in the "+
         "light, while the crashing waves create %^BOLD%^white "+
         "surf %^RESET%^upon the shore.",
      ({"cliff","cliffs"}) : "Rising high overhead are the %^ORANGE%^"+
         "cliffs %^RESET%^supporting the town of %^BOLD%^Seneca"+
         "%^RESET%^.  The deep brown rock is shot through with "+
         "%^YELLOW%^golden veins%^RESET%^, causing the cliff to "+
         "sparkle when the light hits it.  A winding pathway "+
         "meanders up the cliff's face, leading to the town.",
      ({"tree","palm tree"}) : "%^GREEN%^Each %^BOLD%^palm tree "+
         "%^RESET%^%^GREEN%^seems an island unto itself, rising "+
         "from the sand in scattered locations.  They provide a "+
         "touch of greenery but very little shade.%^RESET%^",
      ({"jetty","jetties"}) : "Stretching out into the sea like "+
         "arms, the jetties look to be natural rock, though it's "+
         "anyone's guess as to whether or not magic was used in "+
         "their creation.  Their position provides a safe, "+
         "relatively concealed cove here for the people of Seneca "+
         "to enjoy.",
      "hut" : "The hut to the east is formed from natural "+
         "materials, leaving it brown and rustic in appearance.  "+
         "It is difficult to tell what its purpose might be from "+
         "here.",
      ({"seagull","seagulls","gull","gulls"}) : "Wheeling overhead "+
         "and running awkwardly along the shore are several %^BOLD%^"+
         "seagulls%^RESET%^.  They seem to have become accustomed "+
         "to people sharing their beach, and they do not run away.",
      ({"crab","crabs","sand crab","sand crabs"}) : "Tiny little "+
         "%^BOLD%^sand crabs%^RESET%^ dart along the shore, "+
         "running from hole to safe hole and trying to avoid the "+
         "seagulls.  Their sideways scuttling gait allows them "+
         "to move a lot faster than one would think.",
      ({"shell","shells","seashell","seashells"}) : "An assortment "+
         "of %^BOLD%^s%^YELLOW%^e%^MAGENTA%^a%^WHITE%^s%^RESET%^h"+
         "%^ORANGE%^e%^RESET%^l%^BOLD%^l%^YELLOW%^s%^RESET%^ of "+
         "different shapes and sizes wash up from time to time "+
         "on the shore.  Many of them are broken, but they do "+
         "provide color, and occasionally you might get lucky "+
         "and find a whole one."
   ]));
}
