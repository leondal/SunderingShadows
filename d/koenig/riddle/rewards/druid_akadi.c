//druid_akadi.c - reward for Riddle Quest. Circe 3/23/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("akadi wooden armor");
	set_id(({"armor","wooden armor","wood armor","winds embrace","wind's embrace","ivory armor"}));
	set_short("%^RESET%^%^CYAN%^W%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^d"
         "%^RESET%^%^CYAN%^'%^BOLD%^s %^RESET%^%^CYAN%^E%^BOLD%^m%^RESET%^%^CYAN%^b%^BOLD%^r%^RESET%^%^CYAN%^a%^BOLD%^c%^RESET%^%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^An intricately crafted suit of ivory armor");
	set_long("%^RESET%^%^CYAN%^This well-crafted suit of armor has been "
         "assembled from carefully carved pieces of %^BOLD%^ivory%^RESET%^"
         "%^CYAN%^ dyed in various shades of %^BOLD%^%^BLUE%^b%^RESET%^"
         "%^CYAN%^l%^BOLD%^u%^WHITE%^e%^RESET%^%^CYAN%^.  Attached to a "
         "light suit of %^ORANGE%^pale leather%^RESET%^%^CYAN%^, the pieces "
         "are layered to resemble the %^CYAN%^f%^BOLD%^e%^RESET%^%^CYAN%^a"
         "%^BOLD%^t%^BLUE%^h%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^s "
         "%^RESET%^%^CYAN%^of an exotic bird.  Beginning with %^BOLD%^%^BLUE%^"
         "deep blue %^RESET%^%^CYAN%^at the shoulders, the mock feathers fade "
         "through %^BOLD%^%^BLUE%^h%^RESET%^%^CYAN%^u%^BOLD%^e%^WHITE%^s"
         "%^RESET%^%^CYAN%^ before ending with a faint %^BOLD%^s%^CYAN%^k"
         "%^WHITE%^y %^CYAN%^b%^WHITE%^l%^CYAN%^u%^WHITE%^e%^RESET%^%^CYAN%^ "
         "at the feet.  The excellent craftsmanship of the armor ensures that "
         "the wearer can move freely, and each piece has been painstakingly "
         "secured so that the armor makes no sound.%^RESET%^");
	set_lore("The armor known as Wind's Embrace is prized by druids of Akadi, "
         "who feel their lady's blessings whenever the armor protects them.  "
         "Some claim that a sliver of Akadi is held within each ivory scale, "
         "though others claim it is merely the carefully guarded secret of this "
         "armor's construction that makes it special.  Either way, attaining a "
         "suit of this armor is a mark of honor among druids dedicated to the "
         "Queen of Air.");
   set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the ivory armor.");
}
