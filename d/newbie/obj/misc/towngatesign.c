#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"sign","large sign"}) );
    set_name("large sign");
    set_short("A large sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long(
@NEWBIE
                   %^BOLD%^%^YELLOW%^CAUTION travelers!!
The gates maybe open, but danger may lurk just outside.  The city may not always be safe, but it is certainly far more perilous outside.  If you haven't armor, weapons you've trained in, and some gold in the bank to come back to if the worst befalls you, you will certainly want to turn back to the safety of the city for now and better prepare yourself.
NEWBIE
    );
    set_value(0);
}

void init(){
	::init();
}

int __Read(string str){
	if (str && str == "sign") {
		write("%^BOLD%^%^YELLOW%^CAUTION travelers!!\nThe gates may be open, "
		"but danger may lurk just outside.  The city may not always be safe, "
		"but it is certainly far more perilous outside.  If you haven't armor, "
		"weapons you've trained in, and some gold in the bank to come back to "
		"if the worst befalls you, you will certainly want to turn back to the "
      "safety of the city for now and better prepare yourself." );
   return 1;
   } else {
      return ::__Read(str);
   }
}
