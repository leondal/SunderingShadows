//~Circe~ 10/27/07
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^RED%^scarlet","%^BOLD%^%^BLUE%^cob%^BLACK%^a%^BLUE%^lt","%^BOLD%^%^WHITE%^white","%^BOLD%^%^GREEN%^cha%^YELLOW%^r%^GREEN%^tre%^YELLOW%^u%^GREEN%^se","%^BOLD%^%^MAGENTA%^pale pink","%^RESET%^%^MAGENTA%^violet","%^RESET%^%^RED%^maroon","%^BOLD%^%^CYAN%^sky blue","%^RESET%^%^ORANGE%^tan","%^RESET%^m%^ORANGE%^u%^RED%^l%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^i%^ORANGE%^c%^RESET%^o%^RED%^l%^ORANGE%^o%^BOLD%^%^BLACK%^r%^RESET%^e%^ORANGE%^d","%^BOLD%^%^BLACK%^m%^BLUE%^u%^CYAN%^l%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^i%^BLUE%^c%^BLACK%^o%^RESET%^%^CYAN%^l%^BOLD%^o%^WHITE%^r%^BLACK%^e%^BLUE%^d","%^RESET%^%^RED%^m%^BOLD%^u%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^t%^RED%^i%^RESET%^%^ORANGE%^c%^RED%^o%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^o%^ORANGE%^r%^BOLD%^%^RED%^e%^BLACK%^d","%^YELLOW%^m%^GREEN%^u%^RESET%^%^GREEN%^l%^ORANGE%^t%^WHITE%^i%^YELLOW%^c%^RESET%^%^GREEN%^o%^BOLD%^l%^RESET%^o%^ORANGE%^r%^YELLOW%^e%^GREEN%^d"})

void create(){
   string COLOR;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   set_name("puka shell necklace");
   set_id(({"necklace","puka necklace","shell necklace","puka shell necklace"}));
   set_short("a "+COLOR+" puka shell necklace%^RESET%^");
   set_long("This necklace is crafted entirely from "+COLOR+" puka "+
      "shells %^RESET%^cut into small, flat squares.  The squares have "+
      "holes drilled into their centers and have been threaded on a "+
      "thin cord so that they lie flat against each other.  The ends "+
      "of the cord are left long so the necklace may be tied on.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(25+random(11));
}