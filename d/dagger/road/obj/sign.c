#include <std.h>

inherit OBJECT;

void create(){
::create();
set_weight(99999);
set_value(0);
set_short("A signpost");
set_long(
"This sinpost contains a small map of dagger, and marks some of the larger towns."
);
}
//Bugged and causing my avclone command to mess up - Saide

/*
void init(){
::init();
add_action("read", "read");
}

int read(string str){*/
