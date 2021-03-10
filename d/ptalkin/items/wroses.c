#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("white roses");
set_id(({"white roses", "roses", "whiteroses", "gift"}));
set_short("white roses");
set_long("This is a bouquet of twelve long stemmed half opened white roses.  The roses are joined with small boughs of evergreen and tied with a deep green satin ribbon.  The odour wafting from the roses is almost cinnamon and leaves a smile upon your face.  A small card, hand written lies within the bouquet.");
set_weight(2);
set_value(25);
}
void init(){
::init();
add_action("read", "read");
}
int read(string str){
if(str!="card")
return 0;
write("%^BOLD%^RED%^The note reads -- for M'lady, pure of heart, pure of soul, pure of mind, .... from your knight in shining armour.");
tell_room(environment(TP), TPQCN+" reads a card hidden within the flowers.", TP);
return 1;
}
