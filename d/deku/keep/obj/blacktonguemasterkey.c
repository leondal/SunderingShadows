#include <std.h>

inherit OBJECT;

void create()
{
    ::create();	
    set_name("blacktongue master key");
    set_id(({"Key","key","Master Key","master key",
    "Blacktongue Master Key","blacktongue master key"}));
    set_short("%^BOLD%^%^WHITE%^metal key%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This key is approximately five "+
    "inches long and made from a heavy "+
    "metal.  The head of the key is carved into "+
    "the shape of a wolf head and the teeth have been "+
    "made into the likeness of pointed teeth.%^RESET%^");
    set_value(4);
    set_weight(1);	
}

