//ranger_mask.c - reward for Riddle Quest. Circe 4/25/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
	set_name("hide");
	set_id(({"hide","glamered hide","shifting hide","variegated hide","gray hide"}));
	set_short("%^BOLD%^%^BLACK%^G%^RESET%^l%^BOLD%^a%^RESET%^m"+
         "%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^e%^RESET%^d %^BOLD%^"+
         "%^BLACK%^Hide%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^v%^RESET%^a%^BOLD%^r"+
         "%^RESET%^i%^BOLD%^%^BLACK%^e%^RESET%^g%^BOLD%^a%^RESET%^t"+
         "%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^BLACK%^gray hide%^RESET%^");
	set_long(
@CIRCE
%^BOLD%^%^BLACK%^This armor is made of thin hide originally a deep black color.  The hide has been carefully worked with lighter patches and stripes, creating a shifting effect that makes the armor difficult to spot.  It could probably quite easily be concealed beneath robes, hiding within the shadows there.  The armor is a work of art in its own right.  Much time and skill must have gone into its construction to make it so supple and easily hidden.%^RESET%^
CIRCE
	);
	set_lore(
@CIRCE
The Glamered Hide is a well-kept secret of the small, relatively unknown order of rangers of Mask.  The Lord of Shadows is not normally one to be concerned with the wilderness, and indeed his rangers follow this trend.  They do roam the wilderness, but mostly to seek out caravans and the like who are travelling from city to city.  Maskarran rangers rarely attack openly, but they learn such secrets as they can and pass them along to the clergy, who find useful ways to use them.  Some say the rangers of Mask are little more than inept thieves...a claim they continually work to disprove.
CIRCE
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel vulnerable as you slip out of the shadows of the armor.");
	return 1;
}
