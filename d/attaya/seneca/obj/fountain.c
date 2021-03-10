#include <std.h>
#include <daemons.h>
inherit OBJECT;


void create() {
    ::create();
    set_id( ({"fountain","tier","majestic fountain"}) );
    set_name("fountain");
    set_short("A magnificent marble fountain");
    set_weight(1000000);
    set_long(
      "%^BOLD%^%^CYAN%^The magnificent marble fountain is at the heart of Seneca.  It is arranged in three tiers that allow water to flow from level to level before finally pouring into a large pool of crystal clear water.  The fountain is topped by a statue of a young woman sitting next to a waterfall and holding a flower."
    );
    set_value(0);
}
