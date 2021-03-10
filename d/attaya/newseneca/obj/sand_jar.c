//~Circe~ 10/30/07
#include <std.h>

inherit OBJECT;

#define GROUP1 ({"%^RESET%^%^RED%^red","%^BOLD%^%^MAGENTA%^pink","%^BOLD%^%^GREEN%^light green"})

#define GROUP2 ({"%^BOLD%^%^RED%^scarlet","%^RESET%^%^GREEN%^pine green","%^BOLD%^%^CYAN%^turquoise","%^RESET%^%^MAGENTA%^purple"})

#define GROUP3 ({"%^RESET%^%^CYAN%^cyan","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^indigo","%^RESET%^%^ORANGE%^orange","%^YELLOW%^yellow"})

void create(){
   string COLOR1, COLOR2, COLOR3, base, BASE;
   COLOR1 = GROUP1[random(sizeof(GROUP1))];
   COLOR2 = GROUP2[random(sizeof(GROUP2))];
   COLOR3 = GROUP3[random(sizeof(GROUP3))];
   ::create();
   set_name("shell rose");
   switch(random(2)){
      case 0:  BASE = "%^BOLD%^%^WHITE%^white";
               base = "%^BOLD%^%^WHITE%^";
               break;
      case 1:  BASE = "%^BOLD%^%^BLACK%^black";
               base = "%^BOLD%^%^BLACK%^";
               break;
   }
   set_short(""+base+"a jar of %^RED%^p%^MAGENTA%^a%^GREEN%^i%^CYAN%^n"+
      "%^YELLOW%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLUE%^d "+base+"sand%^RESET%^");
   set_id(({"painted sand jar","jar of painted sand","painted sand","jar"}));
   set_long(""+base+"This narrow jar is perfectly clear, revealing "+
      "the painted sand inside.  Layers of "+COLOR1+""+base+", "+
      ""+COLOR2+""+base+", and "+COLOR3+" sand"+base+" alternate "+
      "at different thicknesses with bands of "+BASE+" sand.  "+
      "The varying bands of sand look %^RESET%^%^CYAN%^windswept"+
      ""+base+", echoing the landscape of the beach.%^RESET%^");
   set_weight(1);
   set_value(35);
}