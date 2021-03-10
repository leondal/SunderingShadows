//druid_grumbar.c - reward for Riddle Quest. Circe 3/24/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("grumbar wooden armor");
	set_id(({"armor","wooden armor","earthshield armor","earthshield","shale armor","suit of shale armor"}));
	set_short("%^RESET%^%^ORANGE%^Ea%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^"
         "ths%^RESET%^h%^ORANGE%^ie%^YELLOW%^l%^RESET%^%^ORANGE%^d Ar"
         "%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^or%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of shale armor%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^A well-crafted suit of leather forms the "
         "base of this armor, though its mystique arises from the countless "
         "%^BOLD%^%^BLACK%^sha%^WHITE%^l%^BLACK%^e pl%^WHITE%^a%^BLACK%^tes "
         "%^RESET%^%^ORANGE%^and %^RESET%^cr%^BOLD%^y%^RESET%^sta%^BOLD%^"
         "%^BLACK%^l%^RESET%^li%^YELLOW%^n%^RESET%^e s%^YELLOW%^p%^RESET%^"
         "ik%^BOLD%^%^BLACK%^e%^RESET%^s %^ORANGE%^arranged in meticulous "
         "patterns all over the armor.  Designed to resemble a small ea"
         "%^YELLOW%^r%^RESET%^%^ORANGE%^th el%^BOLD%^%^BLACK%^e%^RESET%^"
         "%^ORANGE%^men%^RESET%^t%^ORANGE%^al, the armor makes the wearer "
         "look wider, cutting an intimidating figure.  Miraculously, the "
         "armor makes no sound when it moves, and its colors seem to blend "
         "into natural surroundings, making the wearer seem at one with nature.%^RESET%^");
	set_lore("Known as Earthshield Armor, this suit is believed by many to "
         "be blessed by Grumbar himself.  In truth, it is merely crafted by "
         "Grumbaran armorsmiths, but it is nonetheless prized by followers of "
         "the Earthlord, who feel his steadfast resolve in the very rivets "
         "that hold it together.");
	set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the shale armor.");
}
