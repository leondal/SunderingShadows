// Chernobog (5/1/21)
// Shadow Coliseum

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"cart","concessions cart","servingcart"}));
	set_name("concessions cart");
	set_short("%^RESET%^%^MAGENTA%^A %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^c%^BOLD%^o%^RED%^n%^RESET%^c%^BOLD%^e%^RED%^s%^RESET%^s%^BOLD%^i%^RED%^o%^RESET%^n%^BOLD%^s %^RESET%^%^MAGENTA%^cart%^WHITE%^");
	set_long("%^RESET%^%^MAGENTA%^This %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^c%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^t %^RESET%^%^MAGENTA%^is loaded up with various supplies and foodstuffs. There are several %^ORANGE%^casks of ale %^MAGENTA%^on a lower shelf, and the countertop is crowded between a dozen large %^RED%^turkey legs %^MAGENTA%^roasting over a %^RED%^g%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^l%^RESET%^%^RED%^l %^MAGENTA%^and a %^BOLD%^%^WHITE%^gla%^RESET%^s%^BOLD%^s ca%^RESET%^s%^BOLD%^e %^RESET%^%^MAGENTA%^full of %^YELLOW%^p%^WHITE%^o%^ORANGE%^pc%^WHITE%^or%^ORANGE%^n%^RESET%^%^MAGENTA%^. A cloth banner wraps around the front of the cart in white and red stripes. There is a %^WHITE%^menu %^MAGENTA%^posted on one corner of the cart.%^WHITE%^");
	set_weight(1000000);
	set_value(0);
	set_property("no animate",1);
}

