#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("eveningstars");
set_id(({"eveningstars", "eveningstar", "gift", "flowers"}));
set_short("eveningstars");
set_long("%^BLUE%^With eight pointed petals, midnight blue, one inch long, these flowers surround a center of silver.  The eight stamens stand 1/4 inch high in a circle, looking much like a silver crown set upon blue velvet.  The smell from these flowers fills your senses with thoughts of cool autumn days and deep winter nights.  A small card lies within the bouquet of eveningstars and pale cream orchids.");
set_weight(2);
set_value(15);
}
void init(){
::init();
add_action("read", "read");
}
int read(string str){
if(str!="card")
return 0;
write("%^BLUE%^The card reads -- just to let you know, you are appreciated.");
tell_room(environment(TP), TPQCN+" reads a card hidden within the flowers.", TP);
return 1;
}
