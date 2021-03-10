#include <std.h>
#include "../dragon.h";

inherit OBJECT;

void create() {
   ::create();
   set_name("paper");
   set_id(({"paper"}));
   set_short("%^RESET%^%^GREEN%^A sheet of paper%^RESET%^");
   set_value(0);
   set_weight(0);
   set_long(
   "%^RESET%^%^YELLOW%^You look over the paper and read:\n"+
   " %^RESET%^The symbols for the summoning chamber to be placed"+
   " in a specific order. They are to be written in this manner:\n"+
   " %^BOLD%^%^RED%^GHJKL SOVPRA UKLANKA\n"+
   " %^RESET%^This is all meaningless until we receive the stones from"+
   " Maverin. However, mother wants us to be as prepared as possible."+
   " She also told me to make sure I did not hinder the access to the"+
   " wardstones hidden there."
   );
}
