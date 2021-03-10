//Coded by Bane//
#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_id(({"phylactery","gem"}));
    set_name("phylactery");
    set_short("A gorgeous gem");
    set_long(
	"This is a fantastic ruby gem bound in leather straps.  The sides "+
	"of the gem are inscribed with runes and the leather straps have designs "+
	"painted on them in white.  A close look reveals what looks like a human "+
	"figure inside the gem."
    );
    set_weight(9999);
    set_value(2000);
    set_property("no animate",1);
}
