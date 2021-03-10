#include <std.h>
#include "/d/ptalkin/ptalkin.h"

inherit BAG;

object CHOCO;

void create()
{
  ::create();
  set_name("chocolates box");
  set_id(({"box", "a box", "gift"}));
  set_short("A box of chocolates");
  set_long(
@PATOR
%^ORANGE%^
This lightweight hand crafted box was made from golden allen trees.
The detailed carving of flowers and hearts is exquisite.  
There is a note resting upon the lid. Perhaps you should read the 
note to find out who sent this to you.
PATOR
);
  set_weight( 2);
  set_value(25);
}

void init(){
::init();
	CHOCO=new(PITEM+"chocolates");
	CHOCO->set_box(TO);
	CHOCO->move(TO);
	add_action("read", "read");
	add_action("get_it", "get");
}

int get_it(string str) {
	if (str != "chocolate from box") {
		return 0; }
	else {
		CHOCO->move(environment(TO));
		tell_object(ETO,
			"The box vanishess as you take out the chocolate");
		destruct(TO);
		return 1;
		}
}
int read(string str){
  if(str!="note") return 0;

  write("%^BOLD%^RED%^The note reads -- from a secret admirer.");
  tell_room(environment(TP), TPQCN+" reads the note from the box.", TP);

return 1;
}
