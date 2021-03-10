//hallway inherit for Asgard Keep by ~Circe~ 8/14/15

#include <std.h>
#include "/d/laerad/laerad.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("light", 3);
   set_indoors(1);
   set_name("Hallway of Asgard Keep");
   set_short("Hallway of Asgard Keep");
   set_long("%^BOLD%^%^BLACK%^Hallway of Asgard Keep%^RESET%^\n"+
      "This wide hallway has clean %^BOLD%^stone walls %^RESET%^draped "
      "in brightly colored %^CYAN%^ta%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^es"
      "%^YELLOW%^t%^RESET%^%^CYAN%^r%^GREEN%^i%^RESET%^%^CYAN%^es %^RESET%^"
      "meant to give the illusion of being %^GREEN%^outdoors%^RESET%^. "
      "At various intervals along the hall, doorways open onto shops where "
      "the inhabitants of the keep gather to forget their troubles. Some "
      "seem truly at ease, like the children who dart about between the legs "
      "of their elders. Others, however, wear dark expressions and speak in "
      "hushed tones when they chance to meet. Tension fills the air, despite "
      "the carefree facade the citizens try to maintain. A deep %^BOLD%^%^BLUE%^"
      "blue runner%^RESET%^ edged in %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^ "
      "stretches the length of the hallway, muffling footsteps.\n\n");
   set_smell("default","The hallway smells of stone mixed with various perfumes "
      "and the faint scent of sulfur.");
   set_listen("default","Night or day, the keep is alive with the murmur of the "
      "ocean, the ringing of the forge, and the gossip of the citizens.");
   set_items(([
      ({"stone","stones","walls"}) : "The smooth walls are made of well-fitted "
         "%^BOLD%^white stone%^RESET%^ veined with darker %^BOLD%^g%^RESET%^r"
         "%^BOLD%^%^BLACK%^a%^WHITE%^y%^RESET%^. Much of the wall is covered with "
         "brilliant tapetries, with sconces for torches spaced at regular intervals.",
      ({"torches","sconces","sconce"}) : "Practical %^BOLD%^%^BLACK%^iron sconces "
         "%^RESET%^have been hammered into the wall at regular intervals, holding "
         "torches that light the otherwise dim hallway. Despite their warm glow, "
         "they cannot fully chase away the gloom that covers this island.",
      ({"tapestry","tapestries"}) : "Hanging from decorative %^ORANGE%^wooden rods "
         "%^RESET%^all along the hallway are beautiful tapestries woven to depict "
         "scenes of the ocean and Parnelli Forest. %^BOLD%^%^CYAN%^Waves %^RESET%^crest "
         "and crash on the %^ORANGE%^sandy shore%^RESET%^, tiny %^GREEN%^pi%^BOLD%^x"
         "%^RESET%^%^GREEN%^i%^CYAN%^e%^GREEN%^s %^RESET%^flit among vibrant %^MAGENTA%^f"
         "%^BOLD%^l%^RESET%^%^MAGENTA%^ow%^RED%^e%^RESET%^%^MAGENTA%^rs%^RESET%^, and "
         "%^BOLD%^%^BLACK%^jaguars %^RESET%^stalk %^ORANGE%^stags %^RESET%^through the "
         "trunks of %^GREEN%^trees%^RESET%^.",
      ({"runner","rug","carpet"}) : "The floor is covered in rich blue runner edged in "
         "gold that was clearly tailored for the keep. It turns at crisp angles and "
         "gives an overall composed look to the hallway."
   ]));
}