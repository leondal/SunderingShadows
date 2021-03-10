#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Jewellers Loupe");
	set_id(({ "loupe", "jewellers loupe", "magnifying glass", "gold loupe" }));
	set_short("%^RED%^J%^YELLOW%^e%^RED%^weller's Loupe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a small magnifying glass made of %^YELLOW%^gold%^RED%^.  The loupe is held to one eye to examine %^BOLD%^%^WHITE%^g%^CYAN%^e%^WHITE%^ms %^RED%^more closely.  A skilled jeweller could use this to identify the best quality gems for their work.%^RESET%^

AVATAR
	);
set_weight(2);
	set_value(275);
         set_item_bonus("craft, jeweller",1);
}
