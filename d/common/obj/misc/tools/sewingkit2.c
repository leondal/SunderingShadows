#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Sewing Kit");
	set_id(({ "sewing kit", "kit" }));
	set_short("%^RESET%^%^ORANGE%^A small %^RED%^se%^ORANGE%^wing kit%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a delicate sewing kit made of soft suede.  It is bound by %^RED%^a length of red ribbon%^ORANGE%^, but it unfolds to display several small pockets.  There is a pocket for several %^BOLD%^%^WHITE%^needles%^RESET%^%^ORANGE%^ of varying sizes, one for small pieces of bark bound with different %^BLUE%^col%^GREEN%^our%^YELLOW%^ed t%^RED%^hrea%^MAGENTA%^ds%^RESET%^%^ORANGE%^, one for a small %^BOLD%^%^WHITE%^pair of scissors%^RESET%^%^ORANGE%^ and another that holds a %^BOLD%^%^WHITE%^silver thimble%^RESET%^%^ORANGE%^.  It is an ideal size for packing away and taking on your travels.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(250);
	set_lore(
@AVATAR
%^YELLOW%^This is a small sewing kit of the sort that is commonly used when travelling.  It is ideal for making small repairs away from home, but has everything a seamstress would need to create a new item if the need arose.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",1);
}