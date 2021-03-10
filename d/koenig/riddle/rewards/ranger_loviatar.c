//ranger_loviatar.c - reward for Riddle Quest. Circe 7/12/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
	set_name("hide");
	set_id(({"hide","whipped hide","slashed hide","slashed armor","armor"}));
	set_short("%^RED%^W%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^p"+
         "%^RESET%^%^RED%^p%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^Hide%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^slashed hide armor%^RESET%^");
	set_long(
@CIRCE
%^BOLD%^%^BLACK%^This armor is made of dusky gray hide covered with what looks to be whip slashes edged in %^RESET%^%^RED%^dull red%^BOLD%^%^BLACK%^, much like blood.  At first glance, it appears someone took quite a beating while wearing this armor, though closer inspection reveals this to be simply a clever design.  The design of the armor would perhaps allow one to feign weakness.
CIRCE
	);
	set_lore(
@CIRCE
Rangers of Loviatar take pride in the Whipped Hide, wearing it as a mark of honor.  The first such hide was created when Marian Fleskin, a devout follower of Loviatar, was severely beaten in a public square for her tempting of citizens to experience the torment of Loviatar.  When several men came to her seeking this exquisite torment, Marian was finally captured, put on trial, and flogged in her armor.  The original suit was passed down as a relic, and followers began making replicas, which are now worn by rangers of the Willing Whip.
CIRCE
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RED%^You remove the Whipped Armor and feel Loviatar's caress leave you.%^RESET%^");
	return 1;
}
