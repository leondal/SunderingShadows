//gnome_diamond.c - by Circe for the Bracers of the Forgotten Folk
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("diamond");
   set_id(({"gem","diamond","flawless gem","flawless diamond"}));
   set_short("%^RESET%^%^BLUE%^D%^BOLD%^i%^RESET%^%^BLUE%^a"+
      "%^BOLD%^m%^RESET%^%^BLUE%^o%^BOLD%^n%^RESET%^%^BLUE%^d "+
      "of the %^CYAN%^Forgotten Folk%^RESET%^");
   set_obvious_short("%^BLUE%^a flawless diamond%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This %^BOLD%^diamond %^RESET%^%^BLUE%^"+
      "is flawlessly formed with a brilliant %^BOLD%^blue cast %^RESET%^"+
      "%^BLUE%^and has been cut into a fantastic "+
      "lozenge that reflects the %^YELLOW%^light%^RESET%^%^BLUE%^.  "+
      "Its weight seems more than a simple gem should bear.%^RESET%^");
   set_lore("This is the legendary Diamond of the Forgotten Folk.  "+
      "Legend has it that gnomes were born of the earth, and each "+
      "gnomish race has taken a gem as something of a totem or "+
      "symbol of their heritage.  The enterprising rock gnomes, those "+
      "with the highest aptitude for mechanical engineering, prize "+
      "diamonds above all other gems.");
   set_property("lore difficulty",14);
   set_value(1800);
   set_weight(5);
}

int is_gnome_diamond(){ return 1; }