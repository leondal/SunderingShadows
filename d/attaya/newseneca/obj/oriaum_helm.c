//Oriaum Clan Helm by ~Circe~ 12/13/07
#include <std.h>

inherit "/d/common/obj/armour/helm";

void create(){
   ::create();
   set_name("bronze helm");
   set_id(({"helm","helmet","great helm","bronze helm","oriaum helm","helm of the oriaum warrior"}));
   set_obvious_short("%^BOLD%^%^BLACK%^crested %^RESET%^%^ORANGE%^bronze helm%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Helm of the %^CYAN%^Oriaum Warrior%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Designed for maximum visibility "+
      "and protection as well as air flow, this helmet is crafted "+
      "with face guards that curve around each cheek, ending in "+
      "points well below the chin.  The center of the face mask "+
      "is left open, with a nose guard extending between the eyes.  "+
      "The eye slits are angular, giving the helm a fierce "+
      "expression, while the helm is completed with a crest of "+
      "fine %^BOLD%^%^BLACK%^horse hair %^RESET%^%^ORANGE%^"+
      "sprouting from a bronze base.  The whole helm can be "+
      "pushed back to rest atop the head when not in use, "+
      "and the complete leather lining provides for maximum "+
      "comfort when the helm is needed for battle.%^RESET%^");
   set_lore("This helm was a staple of the legendary "+
      "warriors of the Oriaum Clan who hailed from "+
      "Graez.  Their line has long since died out, "+
      "but rumors abound of warriors still on Graez "+
      "who wear helms such as these and fight with "+
      "blinding dual scimitars.  It is certainly "+
      "possible that some of their descendents remain - "+
      "or that a band of admirers have taken up their way "+
      "of life.");
   set_property("lore difficulty",15);
   set_weight(9); //slightly lighter due to construction
   set_value(450);
}

int isMagic(){
   int magicrobe;
   magicrobe = ::isMagic();
   magicrobe = magicrobe+1;
   return magicrobe;
}