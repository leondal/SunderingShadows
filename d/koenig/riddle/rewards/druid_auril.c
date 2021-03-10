//druid_auril.c - reward for Riddle Quest. Circe 4/9/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("auril wooden armor");
	set_id(({"armor","wooden armor","birchwood armor","suit of birchwood armor","winter's might","might armor"}));
	set_short("%^BOLD%^%^WHITE%^Wi%^RESET%^n%^BOLD%^t%^CYAN%^e%^BOLD%^"
	   "%^WHITE%^r%^RESET%^'%^BOLD%^s M%^RESET%^i%^BOLD%^g%^CYAN%^h%^BOLD%^%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A suit of %^RESET%^bi%^BOLD%^r"
	   "%^RESET%^chw%^BOLD%^o%^RESET%^od a%^BOLD%^r%^RESET%^mo%^BOLD%^r%^RESET%^");
	set_long("%^RESET%^This unusual suit of armor is a masterpiece of long "
	   "swaths of %^RESET%^bi%^BOLD%^r%^RESET%^chw%^BOLD%^o%^RESET%^od "
	   "attached with enchanted thread of %^BOLD%^s%^RESET%^i%^BOLD%^l"
	   "%^RESET%^v%^BOLD%^e%^RESET%^r.  The armor is fashioned so that "
	   "subtle flashes of %^BOLD%^%^BLUE%^de%^CYAN%^e%^BLUE%^p b%^CYAN%^l"
	   "%^BLUE%^ue %^RESET%^are revealed when the wearer moves.  Carved "
	   "along the shoulder plates is a repeating design of stylized "
	   "%^BOLD%^sn%^CYAN%^o%^WHITE%^wfl%^CYAN%^a%^WHITE%^kes%^RESET%^, "
	   "the only adornment on this otherwise simple, if masterfully crafted, armor.%^RESET%^");
	set_lore("This armor is crafted by master smiths sworn to Auril's service.  "
	   "Only they know the secret of gathering the birchwood whole and unharmed, "
	   "and only they know they the proper way to enchant it to avoid breaking "
	   "and splintering.  This armor is granted only to those druids who serve "
	   "the Ice Maiden with all of their souls.");
	set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the wooden armor.");
}
