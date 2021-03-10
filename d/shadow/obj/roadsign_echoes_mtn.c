#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"sign","wooden sign"}) );
    set_name("wooden sign");
    set_short("A large wooden sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long(
@STYX
The sign reads:\n
To the south is the Kobold Forest.
  (The old, original newbie area - to be upgraded as time permits).
%^BOLD%^%^BLUE%^To the north are the Echoes Mountains, where young adventurers might 
wish to seek to further their pursuit of fame and fortune.

%^YELLOW%^The city of Shadow, the nearest major civilization, is to the east.
STYX
    );
    set_value(0);
}

void init(){
   ::init();
   add_action("read_sign","read");
}

int read_sign(string str){
   if(str != "sign") return 0;
   TP->force_me("look sign");
   return 1;
}

