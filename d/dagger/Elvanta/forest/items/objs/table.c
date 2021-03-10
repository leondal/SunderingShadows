#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name ("table");
set_short("tables");
set_long("%^CYAN%^Low long tables sit in front of the benches by the walls.  Small bowls of flowers, cups of wine, and books lay upon the tables.%^RESET%^");
set_weight (10);
set_value (0);
}
void  init()
{
::init();
add_action("lookatflowers", "look");
add_action("lookatdecanters", "look");
add_action("lookatgoblets", "look");
}
int lookatflowers(string str)
{
if(str!="flowers")
return 0;
write("%^GREEN%^Bowls and vases of different shapes and colours are upon every other pillar.  Bright marigolds, russian irises, heart's ease, and tall grasses fill the many containers.", TP);
tell_room(environment(TP), TPQCN+ "stops to look at the pillars and the flowers and sculptures sitting there.", TP);
return 1;
}
int lookatdecanters(string str)
{
if(str!="decanters")
return 0;
write("%^CYAN%^the decanters are made from fine blown glass.  Many coloured spirits fill the decanters ranging from pale green to a deep violet.", TP);
tell_room(environment(TP), TPQCN+ "looks upon the many decanters filled with spirits.", TP);
return 1;
}
int lookatgoblets(string str)
{
if(str!="goblets")
return 0;
write("%^CYAN%^Goblets made of shining silver, carved into delicate long stemmed lilies match the decanters.  The open cupped petals of the goblets would hold a healthy dose of spirits.", TP);
return 1;
}
