//druid_malar.c - reward for Riddle Quest. Circe 4/9/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("malar hide armor");
	set_id(({"armor","hide armor","hunters pride","hunter's pride","pride","pride armor"}));
	set_short("%^RESET%^%^RED%^Hu%^ORANGE%^n%^RED%^te%^BOLD%^r"
	   "%^RESET%^%^RED%^'s Pr%^BOLD%^i%^RESET%^%^RED%^de%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A suit of %^RED%^hi%^ORANGE%^"
	   "d%^RED%^e arm%^ORANGE%^o%^RED%^r%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This armor is made from the collected "
	   "hides of various beasts, all carefully selected and joined to form one "
	   "stunning piece.  The sleek %^BOLD%^%^BLACK%^black pelt %^RESET%^"
	   "%^ORANGE%^of a sacred %^BOLD%^%^BLACK%^disp%^WHITE%^l%^BLACK%^acer "
	   "be%^WHITE%^a%^BLACK%^st%^RESET%^%^ORANGE%^ forms the chest piece, "
	   "while the shoulders are adorned with the lightly spotted coat of a "
	   "%^BOLD%^%^BLACK%^ja%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^kal%^RESET%^"
	   "%^RED%^w%^BOLD%^%^BLACK%^ere%^RESET%^%^ORANGE%^.  Various other "
	   "points are crafted from the hides of other predatory beasts "
	   "including %^RESET%^wol%^RED%^v%^RESET%^eri%^RED%^n%^RESET%^es "
	   "%^ORANGE%^and %^BOLD%^%^BLACK%^panthers%^RESET%^%^ORANGE%^.  The "
	   "masterfully crafted armor allows the wearer to move smoothly and "
	   "quietly while providing protection from weapons of all sorts.%^RESET%^");
	set_lore("This armor is crafted from beasts sacred to Malar to show "
	   "the wearer's respect for the Beastlord.  Each animal was tracked, "
	   "killed, and offered in sacrifice to the deity before its pelt was "
	   "removed and sewn into this armor, which is in turn a mark of respect "
	   "among Malar's druids.");
	set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the hide armor.");
}
