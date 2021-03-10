//~Circe~ 10/30/07
#include <std.h>
inherit ARMOUR;

#define COLORS ({"white","pale pink","dusky gray","sea-green","multicolored"})

void create(){
   string COLOR,color;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   switch(COLOR){
      case "white" : COLOR = "%^BOLD%^%^WHITE%^w%^RESET%^h"+
                     "%^BOLD%^i%^RESET%^t%^BOLD%^e";
                     color = "%^BOLD%^%^WHITE%^";
                     break;
      case "pale pink" : COLOR = "%^BOLD%^%^MAGENTA%^pale pink";
                     color = "%^RESET%^%^MAGENTA%^";
                     break;
      case "dusky gray" : COLOR = "%^BOLD%^%^BLACK%^d%^RESET%^u"+
                     "%^BOLD%^%^BLACK%^s%^RESET%^k%^BOLD%^%^BLACK%^"+
                     "y %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^a"+
                     "%^BOLD%^%^BLACK%^y";
                     color = "%^BOLD%^%^BLACK%^";
                     break;
      case "sea-green" : COLOR = "%^RESET%^%^GREEN%^s%^CYAN%^e"+
                     "%^GREEN%^a%^CYAN%^-%^GREEN%^g%^CYAN%^r"+
                     "%^GREEN%^e%^CYAN%^e%^GREEN%^n";
                     color = "%^RESET%^%^CYAN%^";
                     break;
      case "multicolored" : COLOR = "%^RESET%^%^CYAN%^m%^BOLD%^%^BLACK%^"+
                     "u%^RESET%^l%^GREEN%^t%^CYAN%^i%^BOLD%^%^BLACK%^c"+
                     "%^RESET%^%^CYAN%^o%^RESET%^l%^GREEN%^o%^BOLD%^%^BLACK%^"+
                     "r%^RESET%^e%^GREEN%^d";
                     color = "%^BOLD%^%^BLACK%^";
                     break;
   }
   set_name("strand of pearls");
   set_id(({"necklace","pearl necklace","strand of pearls","pearl strand","strand"}));
   set_short(""+color+"a "+COLOR+" "+color+"pearl strand%^RESET%^");
   set_long(""+color+"This breathtaking necklace is crafted from "+
      ""+COLOR+" "+color+"pearls meticulously matched to be "+
      "the exact same size.  Each pearl has a brilliant luster that "+
      "creates a soft shine, making this a truly remarkable piece.%^RESET%^");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(600);
}