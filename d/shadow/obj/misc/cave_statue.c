#include <std.h>
inherit OBJECT;


void create() {
    ::create();
    set_id( ({"statue"}) );
    set_name("statue");
    set_short("A small statue");
    set_weight(100000);
    set_long(
	"This is a small statue, maybe a foot tall. It appears to be "+
	"affixed to the ground. It appears to be a statue of an old wizard. "+
	"As you look closer, you notice that the left hand of the statue "+
	"has the ring finger extended. Also you notice some marks on the "+
   "chest of the statue, as well as around its neck. The right hand "+
	"is extended, with the hand in a loose fist. The statue seems to be "+
	"waiting for someone to <place> the proper pieces in order to complete it."
    );
}
