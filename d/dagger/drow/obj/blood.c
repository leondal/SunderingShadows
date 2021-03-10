#include <std.h>
#include "/d/dagger/drow/short.h"
inherit OBJECT;
void create() {
    ::create();
    set_name("blood");
    set_id(({"blood","pool","pool of blood"}));
    set_short("%^RESET%^%^RED%^pool of blood%^RESET%^");
    set_long("%^RED%^This is nothing more than a small pool of blood. "
	"You notice it is quite fresh and wonder what montrosity left it "
	"here. As you examine the blood, you hear a low howl in the "
	"distance and a shiver runs up your spine.%^RESET%^");
    set_weight(1000000);
}
void init() {
    ::init();
    add_action("get_func","get");
}
int get_func(string str) {
    string what;
    what = str;
    if(what == "blood" || what == "pool" || what == "pool of blood") {
    write("%^RED%^You cannot get the pool of blood!");
	return 1;
    } else {
	return 0;
    }
}
