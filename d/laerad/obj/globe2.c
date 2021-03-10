//Coded by Bane//
#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_id(({"globe","globe of invulnerability"}));
    set_short("A large globe of invulnerability");
    set_long(
	"This is a large globe of invulnerable force. As you take a "+
	"closer look you think you can see someone trapped inside."
    );
    set_value(0);
    set_weight(9999);
}
