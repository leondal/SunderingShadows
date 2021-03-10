
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_short("
%^ORANGE%^You are entering a desert south of Seneca.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You are entering a desert south of Seneca.%^RESET%^
Heading in all directions you see a desert. It is dry and desolate.
You can vaguely see bits of green springing from the ground. Some hardy plants are trying to survive here. As you look out at what is stretched before you, you seem to pause and consider your chances of survival.
There is a sign hung on a post. You had best read it.

ZERINA
);
set_light(3);
set_property("indoors",0);
set_climate("desert");

set_items(([

]));

set_exits(([
"north" : "/d/attaya/ ",
"southwest" : "/d/attaya/crafters/desert/des2.c",
"southeast" : "/d/attaya/crafters/desert/des3.c",

]));

set_smell("default", "It smells of desolation here.");
set_listen("default", "You can only hear your own breathing.");
}
void reset(){
::reset();
if(!present("sign"))
new("/d/attaya/crafters/desert/sign.c")->move(this_object());
}

