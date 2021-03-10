//tea.c - Tea for the mage tower of new Seneca
//~Circe~ 1/4/07
inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("tea");
   set_id(({"tea","mystical tea","cup of tea","cup of mystical tea","drink"}));
   set_strength(20);
   set_weight(1);
   set_type("soft drink");
   set_empty_name("cup");
   set_short("%^RESET%^%^CYAN%^A cup of %^BOLD%^mystical "+
      "%^RESET%^%^ORANGE%^tea%^RESET%^");
   set_destroy();
   set_long("%^BOLD%^%^WHITE%^A delicate white porcelain cup "+
      "with %^MAGENTA%^pink flowers %^WHITE%^surrounds a fragrant "+
      "tea that has a slightly %^CYAN%^blue tinge%^WHITE%^.  "+
      "The tea is quite warm, and little puffs of %^RESET%^steam "+
      "%^BOLD%^rise to form %^CYAN%^arcane runes %^WHITE%^before "+
      "dissipating.%^RESET%^");
   set_my_mess("As you sip the tea, you swear you have the answers to all things.  Oh damn, gone again...");
   set_your_mess("drinks the tea and brightens for a moment.");
}
