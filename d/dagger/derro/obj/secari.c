//Updated dagger - Cythera 8/05
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
	::create();
  	set_id(({"secari","dagger"}));
  	set_name("secari");
  	set_short("%^BOLD%^%^BLACK%^ S%^RED%^e%^BLACK%^c"+
		"%^RED%^a%^BLACK%^ri%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A curved %^RED%^engraved%^BLACK%^ dagger%^RESET%^");
  	set_long("%^BOLD%^%^BLACK%^The dagger you are looking at holds"+
		" a mark of exquisite craftsmanship. The blade of deep, "+
		"hollow-ground edges is slightly longer than is usual and"+
		" elegantly curves backward. An ornament %^BOLD%^%^RED%^twining"+
		" serpents %^BOLD%^%^BLACK%^made of %^RESET%^%^RED%^f%^BOLD%^"+
		"%^RED%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e"+
		"%^BOLD%^%^RED%^s%^BOLD%^%^BLACK%^ is engraved on its lower "+
		"half gives the blade a glint of %^BOLD%^%^RED%^red%^BOLD%^"+
		"%^BLACK%^ - it appears as if the adamantium was inlaid with"+
		" pieces of %^RESET%^%^ORANGE%^dark orange%^BOLD%^%^BLACK%^"+
		" gemstones. An adamantium cast hilt is darker than the blade"+
		" and has the grip wrapped in soft black leather.%^RESET%^");
	set_lore("The Secare is a sacrifical dagger used typically by"+
		" the Derro.  The secari daggers are "+
		"enchanted to drink in blood from their victim and store it deep"+
		" inside the dagger.  When the user of the sinister secari needs"+
		" an extra punch to their attack, they are able to spray the hot"+
		" boiling blood back at their target.  Needless to say with a "+
		"dagger like this, many sinister, murderous, dark hearted people"+
		" seek this foul blade out.");
	set_property("lore",15);
  	set_value(500);
        set_property("enchantment",2);
}