#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ice diamond");
	set_id(({ "ice", "diamond", "ice diamond"}));
	set_short("%^BOLD%^%^WHITE%^I%^BOLD%^%^CYAN%^c%^WHITE%^e Di%^CYAN%^a%^WHITE%^mond%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This is a remarkable gemstone that is translucent in color and roughly the size of a human head."
		" It is extremely c%^CYAN%^o%^WHITE%^ld to the touch with a few naturally ja%^CYAN%^gg%^WHITE%^ed, r%^CYAN%^a%^WHITE%^z%^CYAN%^o%^WHITE%^r"
		"-sh%^CYAN%^a%^WHITE%^rp edges. %^RESET%^");
	set_weight(50);
    set_value(50000);
}
