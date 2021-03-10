#include <std.h>
#include "../valley.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("%^GREEN%^green teardrop%^RESET%^");
	set_id(({"teardrop","tear drop","tear","green teardrop","green tear drop","green tear","emerald teardrop","emerald tear","gteardrop"}));
	set_short("%^RESET%^%^GREEN%^a green teardrop%^RESET%^");
	set_long(
	"%^BOLD%^The %^GREEN%^green teardrop%^WHITE%^ glitters with its"+
	" own inner light. It is large for a teardrop, just over an inch"+
	" in length. It appears to be made of flawless emerald."
	);
	set_weight(1);
	set_value(425);
}
