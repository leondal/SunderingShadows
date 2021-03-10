//~Circe~ 10/27/07
#include <std.h>
inherit ARMOUR;

#define CHAINS ({"%^RESET%^%^ORANGE%^leather thong","%^BOLD%^%^BLACK%^leather thong","%^BOLD%^%^WHITE%^silken cord","%^YELLOW%^thin gold chain","%^BOLD%^%^WHITE%^thin silver chain"})

#define BEADS1 ({"%^GREEN%^olive green","%^BLUE%^indigo","%^RESET%^%^MAGENTA%^purple","%^BOLD%^%^BLACK%^ebony","%^RESET%^%^ORANGE%^deep brown","%^RED%^brick red"})

#define BEADS2 ({"%^BOLD%^%^CYAN%^aquamarine","%^BOLD%^%^GREEN%^emerald green","%^BOLD%^ivory","%^BOLD%^%^RED%^scarlet","%^BOLD%^%^MAGENTA%^fuscia","%^YELLOW%^gold","%^BOLD%^%^BLUE%^cobalt blue"})

void create(){
   string CHAIN, BEAD1, BEAD2;
   ::create();
   CHAIN = CHAINS[random(sizeof(CHAINS))];
   BEAD1 = BEADS1[random(sizeof(BEADS1))];
   BEAD2 = BEADS2[random(sizeof(BEADS2))];
   set_name("shark tooth necklace");
   set_id(({"necklace","shark necklace","tooth necklace","shark tooth necklace"}));
   set_short("a %^BOLD%^%^BLACK%^shark tooth %^RESET%^necklace");
   set_long("Simple in design, this necklace features a small "+
      "%^BOLD%^%^BLACK%^shark tooth %^RESET%^hanging on a "+
      ""+CHAIN+"%^RESET%^.  The tooth has been filed somewhat to retain "+
      "its point but not injure the wearer.  Bracing the tooth "+
      "on either side are pairs of beads in "+BEAD1+" %^RESET%^and "+
      ""+BEAD2+"%^RESET%^.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(10+random(6));
}