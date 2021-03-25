//trail8.c - Connecting Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit TRAIL;

void create()
{
	::create();
	set_long(
	"%^BOLD%^%^GREEN%^This is a %^ORANGE%^di%^RESET%^%^ORANGE%^r%^BOLD%^t %^RESET%^%^ORANGE%^p%^BOLD%^ath %^GREEN%^that winds its way through %^RESET%^%^GREEN%^the lower foothills %^BOLD%^of the mountains. It has been fairly well defined. The larger %^RESET%^sto%^BOLD%^ne%^RESET%^s %^BOLD%^%^GREEN%^have been removed completely, the smaller ones have been set on the sides to help define it more clearly. The dirt of the path is fine, as though it has gotten %^RESET%^%^GREEN%^much use %^BOLD%^in its day. Your footsteps stir up the %^BLACK%^d%^RESET%^us%^BOLD%^%^BLACK%^t %^GREEN%^as you move along the %^ORANGE%^tra%^RESET%^%^ORANGE%^i%^BOLD%^l%^GREEN%^. A fine %^RESET%^%^RED%^red %^BOLD%^%^GREEN%^film of dust has settled itself over your belongings already. Just to the west, a %^RESET%^%^CYAN%^larger path %^BOLD%^%^GREEN%^meets with this one.%^RESET%^\n" 
	);
	set_exits(([
	"northeast" : VILSTREAM"trail7",
	"west" : "/d/shadow/room/forest/road56",
	]));
}
