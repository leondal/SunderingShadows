//oriaum_bplate - for new Seneca ~Circe~ 12/13/07
#include <std.h>

inherit "/d/common/obj/armour/breastplate";

void create(){
   ::create();
   set_name("bronze chestguard");
   set_obvious_short("%^RESET%^%^ORANGE%^bronze chestguard%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Chestguard of the %^CYAN%^Oriaum Clan%^RESET%^");
   set_id(({"breastplate","chestguard","chest guard","bronze chestguard","oriaum chestguard","Chestguard of the Oriaum Clan"}));
   set_long("%^RESET%^%^ORANGE%^Supported by well-oiled leather "+
      "straps that cross in the back, this chestguard is made "+
      "from a thickened shield of leather hardened with a layer "+
      "of %^YELLOW%^bronze%^RESET%^%^ORANGE%^.  Swirling images "+
      "have been carved along the edge of the rounded bronze "+
      "piece, an artistic representation of whipping wind.  "+
      "The armor is designed to be centered on the chest when "+
      "worn, providing protection to the vital organs though "+
      "not much else.%^RESET%^");
   set_lore("A relic of the Oriaum Clan of Graez, this particular "+
      "type of breastplate was worn by their warriors for centuries.  "+
      "They were designed to use the items found in abundance around "+
      "the island and provide as much mobility as possible.  Typically, "+
      "the Oriaum warriors combined this chestguard with nothing "+
      "more than a kilt, trusting to the gods - and to the fear "+
      "created when these wild-seeming warriors charged into "+
      "battle barely clothed.  The leader of the Oriaum warriors "+
      "who came to the aid of Seneca in the battle against "+
      "Intruder was named Kalimex.  He led his men into the "+
      "heart of the Kinnesaruda Empire, from which they never returned, "+
      "though their legend lives on.");
   set_property("lore difficulty",15);
   set_weight(30); //lighter than normal due to construction
   set_value(3500);
}

int isMagic(){
   int magicrobe;
   magicrobe = ::isMagic();
   magicrobe = magicrobe+1;
   return magicrobe;
}