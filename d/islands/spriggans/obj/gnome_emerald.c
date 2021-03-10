//gnome_emerald.c - by Circe for the Bracers of the Forgotten Folk
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("emerald");
   set_id(({"gem","emerald","flawless gem","flawless emerald"}));
   set_short("%^RESET%^%^GREEN%^E%^BOLD%^m%^RESET%^%^GREEN%^e"+
      "%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^d "+
      "of the %^CYAN%^Forgotten Folk%^RESET%^");
   set_obvious_short("%^GREEN%^a flawless emerald%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This %^BOLD%^emerald %^RESET%^%^GREEN%^"+
      "is flawlessly formed and has been cut into a fantastic "+
      "square-cut that reflects the %^YELLOW%^light%^RESET%^%^GREEN%^.  "+
      "Its weight seems more than a simple gem should bear.%^RESET%^");
   set_lore("This is the legendary Emerald of the Forgotten Folk.  "+
      "Legend has it that gnomes were born of the earth, and each "+
      "gnomish race has taken a gem as something of a totem or "+
      "symbol of their heritage.  The forest gnomes, those closest "+
      "to nature, prize emeralds above all other gems.");
   set_property("lore difficulty",14);
   set_value(1800);
   set_weight(5);
}

int is_gnome_emerald(){ return 1; }