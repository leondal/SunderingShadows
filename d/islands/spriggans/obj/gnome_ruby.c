//gnome_ruby.c - by Circe for the Bracers of the Forgotten Folk
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("ruby");
   set_id(({"gem","ruby","flawless gem","flawless ruby"}));
   set_short("%^RESET%^%^RED%^R%^BOLD%^u%^RESET%^%^RED%^b%^BOLD%^"+
      "y %^RESET%^%^RED%^of the %^CYAN%^Forgotten Folk%^RESET%^");
   set_obvious_short("%^RED%^a flawless ruby%^RESET%^");
   set_long("%^RESET%^%^RED%^This %^BOLD%^ruby %^RESET%^%^RED%^"+
      "is flawlessly formed and has been cut into a smooth "+
      "orb that reflects the %^YELLOW%^light%^RESET%^%^RED%^.  "+
      "Its weight seems more than a simple gem should bear.%^RESET%^");
   set_lore("This is the legendary Ruby of the Forgotten Folk.  "+
      "Legend has it that gnomes were born of the earth, and each "+
      "gnomish race has taken a gem as something of a totem or "+
      "symbol of their heritage.  The svirfneblin, or deep gnomes, "+
      "prize rubies above all other gems.");
   set_property("lore difficulty",14);
   set_value(1800);
   set_weight(5);
}

int is_gnome_ruby(){ return 1; }