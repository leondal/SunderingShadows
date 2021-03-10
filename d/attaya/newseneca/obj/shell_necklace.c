#include <std.h>

inherit ARMOUR;

#define SHELLS ({"conch shell","cowry shell","scallop shell","clamshell","shark tooth","starfish","sand dollar"})

int val;
string COLOR, mycolor, METAL, metal, SHELL, CRITTER, STONE;

void create(){
   ::create();
   SHELL = SHELLS[random(sizeof(SHELLS))];
   val = random(26);
   switch(val) {
      case 0..3:
         METAL = "%^RESET%^%^ORANGE%^brass";
         metal = "brass";
         break;
      case 4..6:
         METAL = "%^YELLOW%^bronze";
         metal = "bronze";
         break;
      case 7..10:
         METAL = "%^BOLD%^%^WHITE%^silver";
         metal = "silver";
         break;
      case 11..14:
         METAL = "%^BOLD%^%^CYAN%^mithril";
         metal = "mithril";
         break;
      case 15..20:
         METAL = "%^YELLOW%^gold";
         metal = "gold";
         break;
      case 21..22:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold";
         metal = "rose gold";
         break;
      case 23..25:
         METAL = "%^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^in%^CYAN%^u%^WHITE%^m";
         metal = "platinum";
         break;
   }
   set_value(val+100);
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_name("necklace");
   set_short("a %^"+METAL+" "+SHELL+" necklace%^RESET%^");
   set_id(({"necklace","shell necklace","various shell necklace",""+metal+" necklace",""+metal+" "+SHELL+" necklace",""+SHELL+" necklace"}));
   set_long("A thin, exquisitely made chain of "+METAL+" %^RESET%^"+
      "supports a "+METAL+"-dipped "+SHELL+" %^RESET%^in this pretty "+
      "necklace.  The delicate chain is joined by a clasp, and "+
      "no further ornamentation is present - or, indeed, needed - "+
      "for this simple, elegant piece of jewelry.");
}
