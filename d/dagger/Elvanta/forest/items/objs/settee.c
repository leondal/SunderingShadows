#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name ("settee");
set_short ("pale rose settee");
set_long("Pale rose covered settees curve around the half walls of the gazebo.  They are made of amber wood and covered in pale rose damask.  They look sturdy, yet inviting, a place to rest and sit for a while.");
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
