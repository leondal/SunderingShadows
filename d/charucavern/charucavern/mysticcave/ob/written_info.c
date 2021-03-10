#include <std.h>
inherit OBJECT;

void create()
{
	::create();
	set_name("crumpled paper");
	set_id(({ "paper", "crumpled paper", "parchment", }));
	set_short("%^YELLOW%^A piece of smeared parchment%^RESET%^");
	set_long("%^BOLD%^%^YELLOW%^This piece of paper has been smeared "+
    "with a thick, unidentifable substance. You can still make out some "+
    "of the writing but it looks as if it were scribled quickly.%^RESET%^");
	set_read("%^BOLD%^%^YELLOW%^Me no no why me here, but me writes "+
    "cuz something big is around here.. somewhere... and me is afraid me "+
    "cant control what me does no more. It spits oozes and tells me to "+
    "guard a big stone... me no want to... it come about no on purpose me "+
    "thinks.... stupid humans never no what they doze...%^RESET%^");

	set_language("wizish");
	set_weight(0);
	set_value(0);
}