#include <std.h>
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

void create(){
    ::create();
		set_name("clam shell");
        set_id(({"shell","clam shell"}));
        set_short("%^BOLD%^%^WHITE%^an open clam shell%^RESET%^");
        set_long("This appears to be the remains of a clam "+
			"shell.  It is probably of little value.");
        set_weight(1);
        set_value(5);
}
