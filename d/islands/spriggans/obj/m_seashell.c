//Seashell creator for items that wash up on shore on Leilani ~Circe~ 5/27/07
#include <std.h>

#define COLORS ({"%^BOLD%^%^WHITE%^p%^RESET%^e%^BOLD%^a%^RESET%^r%^BOLD%^l%^RESET%^",\
"%^RESET%^gr%^BOLD%^%^BLACK%^a%^RESET%^y",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^BOLD%^%^CYAN%^aqua%^RESET%^",\
"%^RESET%^%^MAGENTA%^rose%^RESET%^",\
"%^RESET%^%^GREEN%^se%^CYAN%^a%^GREEN%^gr%^CYAN%^e%^GREEN%^en%^RESET%^",\
"%^RESET%^%^CYAN%^periwinkle%^RESET%^",\
"%^RESET%^%^ORANGE%^tan%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^",\
"%^YELLOW%^gold%^RESET%^",\
"%^BOLD%^%^WHITE%^silver%^RESET%^"})

#define FEATURES ({"%^BOLD%^%^WHITE%^g%^RESET%^l%^BOLD%^i%^RESET%^t%^BOLD%^t%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g",\
"%^BOLD%^%^WHITE%^pe%^BLACK%^b%^WHITE%^bl%^BLACK%^e%^WHITE%^d%^RESET%^",\
"%^RESET%^b%^CYAN%^a%^RESET%^n%^CYAN%^d%^RESET%^e%^CYAN%^d%^RESET%^",\
"spe%^BOLD%^%^BLACK%^ck%^RESET%^led",\
"solid",\
"%^BOLD%^%^WHITE%^s%^YELLOW%^h%^WHITE%^i%^YELLOW%^m%^WHITE%^m%^YELLOW%^e%^WHITE%^r%^YELLOW%^i%^WHITE%^n%^YELLOW%^g%^RESET%^"})

inherit DAEMON;

int i, j, val;
string COLOR, TYPE, typename, FEATURE, ADD;

void create_shell(object obj){
   i = random(sizeof(FEATURES));
   FEATURE = FEATURES[i];
   j = random(sizeof(COLORS));
   COLOR = COLORS[j];
   val = random(16)+3;
   switch(val) {
      case 3..6:
         TYPE = "%^BOLD%^%^WHITE%^clamshell%^RESET%^";
         typename = "clamshell";
         ADD = "Both halves of the clamshell are still attached, making "
            "the shell look like nothing so much as a pair of angel wings.";
         break;
      case 7..10:
         TYPE = "%^BOLD%^%^WHITE%^limpet%^RESET%^";
         typename = "limpet";
         ADD = "The limpet is an oval-shaped shell with a raised crown and "
         "an extremely smooth interior.";
         break;
      case 11..14:
         TYPE = "%^BOLD%^%^WHITE%^scallop shell%^RESET%^";
         typename = "scallop shell";
         if(!random(4)){
            ADD = "A rare treat, both halves of this scallop shell are "
               "still attached, making it a beautiful find.";
         }else{
            ADD = "This is only one half of the scallop shell, still a "
               "lovely piece.";
         }
         break;
      case 15..17:
         TYPE = "%^BOLD%^%^WHITE%^cerith%^RESET%^";
         typename = "cerith";
         ADD = "The cerith is a slender, pointed, conical shell with "
            "numerous spiralling chambers inside.";
         break;
      default:
         TYPE = "%^BOLD%^%^WHITE%^conch%^RESET%^";
         typename = "conch";
         ADD = "This large conch shell is a fantastic find!  It has several "
            "unbroken spikes near the crown, and it is over four inches high.";
         break;
   }
   obj->set_value(val+1);
   obj->set_cointype("gold");
   obj->set_weight(1);
   obj->set_name("shell");
   obj->set_id(({"shell",""+typename+"","treasure","seashell"}));
   obj->set_short("%^BOLD%^%^WHITE%^a "+FEATURE+" "+COLOR+" "+TYPE+"%^RESET%^");
   obj->set_long("This pretty little "+TYPE+" is colored a "+FEATURE+" "+COLOR+".  "
      ""+ADD+"  It reflects the light and would make a good addition to any collection.");
}
