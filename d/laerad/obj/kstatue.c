//Coded by Bane//
#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_id(({"statue","statue of king flagg"}));
    set_short("A statue of King Flagg");
    set_long(
	"This is a massive statue standing over 15 feet tall.  The King "+
	"is dressed in fullplate armor and holds a broad sword over his "+
   "shoulder.  The statue is kept very clean as the people of Asgard truly "+
	"love and respect their king."
    );
    set_value(0);
    set_weight(9999);
}
