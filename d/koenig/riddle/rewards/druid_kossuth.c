//druid_kossuth.c - reward for Riddle Quest. Circe 1/1/16
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
	set_id(({"armor","wooden armor","wood armor","fiery armor","flame's kiss"}));
	set_short("%^RESET%^%^RED%^F%^BOLD%^l%^RESET%^%^ORANGE%^a%^YELLOW%^m%^RESET%^%^RED%^e"
         "%^BOLD%^'%^RESET%^%^ORANGE%^s %^RED%^K%^BOLD%^i%^RESET%^%^ORANGE%^s%^RED%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of %^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^e"
         "%^RED%^r%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^ armor%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This armor is crafted from smooth plates made of wood and "
         "darkened to a dull matte black. The edges are painted with chaotic waves of "
         "%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^, %^RESET%^%^ORANGE%^"
         "ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^, and %^YELLOW%^yel%^RESET%^"
         "%^ORANGE%^l%^YELLOW%^ow%^BLACK%^ with flashes of %^RESET%^%^BLUE%^bl%^BOLD%^u"
         "%^RESET%^%^BLUE%^e %^BOLD%^%^BLACK%^and %^WHITE%^whi%^RESET%^t%^BOLD%^e%^BLACK%^, "
         "giving the illusion of %^RESET%^%^RED%^f%^BOLD%^l%^RESET%^%^ORANGE%^a%^YELLOW%^m"
         "%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^. The armor has been painted with some sort of "
         "lacquer that catches the light, making the wood seem to %^RESET%^%^RED%^sm%^BOLD%^"
         "o%^RESET%^%^RED%^ld%^YELLOW%^e%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^.%^RESET%^");
	set_lore("The lacquer used to finish this armor is a carefully guarded secret known "
         "only to those who craft for the church of Kossuth. Suits of armor such as this are "
         "awarded only to those deemed worthy to serve as druids for the Lord of Flames.");
      set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the wooden armor.");
}
