#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("goldenslippers");
set_id(({"goldenslippers", "golden slippers", "flowers", "gift"}));
set_short("goldenslippers");
set_long("%^ORANGE%^The bouquet is filled with goldenslippers.  A pretty plant with flowers shaped like tiny lady's slippers.  Their golden colour gleams while little silver and deep blue threads of colour create a lacework design upon each petal.  Small green leaves, acorn shaped climb the golden stem of the flower.  A deep blue satin ribbon intricately wraps around the flowers to create a bouquet of delight.  A small card lies nestled in the bouquet.");
set_weight(2);
set_value(20);
}
void init(){
::init();
add_action("read", "read");
}
int read(string str){
if(str!="card")
return 0;
write("%^ORANGE%^The card reads -- for my friend, my companion and soulmate.");
tell_room(environment(TP), TPQCN+" reads a card hidden within the flowers.", TP);
return 1;
}
