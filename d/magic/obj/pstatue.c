//Coded by Bane//
#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_name("statue");
    set_id(({"statue"}));
    set_short("A stone statue");
    set_long(
	"This is a large stone statue.  It is holding its hands up in "+
	"front of its face.  Its visage is contorted into one of horror, it "+
	"looks almost as if this statue was alive at one point."
    );
    set_value(0);
    set_weight(9999);
}
