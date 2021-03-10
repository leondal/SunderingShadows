#include <std.h>

inherit "/d/common/obj/misc/torch.c";

void create()
{
	::create();
	add_id("catacombs_torch_key");
	set_short("A small torch");
	set_long("%^BOLD%^%^YELLOW%^This small torch "+
	"is only about one foot long.  You do not know "+
	"for how long it will burn, but perhaps it will "+
	"last long enough to help you see, should you "+
	"need its light.%^RESET%^");	
	set_value(0);
}


