//darkwood_sign.c - Added by Circe 10/4/03
#include <std.h>
inherit OBJECT;

void create()
{
        ::create();
        set_name("sign");
        set_short("A sign post");
        set_id(({"sign","sign post"}));
        set_long(
        "A wooden sign has been staked into the ground here. It has some writing"+
        " on it that you could read."
        );
        set_read(
@CIRCE
	  %^BOLD%^%^GREEN%^DARKWOOD CORNERS
	
        %^RESET%^City of Shadow - North
        City of Tharis - Southwest
        City of Azha - Southwest
        Darkwood Forest - Southeast
CIRCE
        );
        set_weight(1000000);
        set_property("no animate",1);
        set_value(0);
}
