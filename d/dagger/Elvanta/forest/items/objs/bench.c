#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("bench");
set_short("a long padded bench");
set_long("%^CYAN%^These long benches are set against the walls, and can sit four to six individuals, they are comfortable, and well made.  Exquisite carvings cover the legs as a true artist has designed them.%^RESET%^");
set_weight (50);
set_value (0);
}
void init ()
{
::init ();
add_action("rest", "rest");
}
int rest(string str)
{
if(str!="settee")
return 0;
write("As you sit upon the settee you are eased into comfortable molding cushions.  Your back feels eased by the settee and your head relaxes into soft yet strong cushions.  You feel greatly at ease.", TP);
tell_room(environment(TP), TPQCN+ "sits upon a settee and eases back into the cushions, sighing with content.", TP);
return 1;
}
