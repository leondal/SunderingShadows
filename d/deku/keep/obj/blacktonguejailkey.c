#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("blacktongue jail key");
    set_id(({"key","jail key","blacktongue jail key"}));
    set_short("%^RED%^key%^RESET%^");
    set_long("This key is approximately two inches long and made "+
    "from a mithril alloy.  The head "+
    "of the key is in the shape of an ogre skull and the "+
    "teeth form a repeating pattern of two "+
    "long and three short.");
    set_value(4);
    set_weight(1);
}

