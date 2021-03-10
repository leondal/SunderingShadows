//Coded by Lujke


#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("Keystone");
    set_id( ({"keystone","stone","key", "gem stone" }) );
    set_short("%^BOLD%^%^CYAN%^A shimmering gem%^RESET%^");
    set_weight(1);
    set_long("%^BOLD%^%^CYAN%^A sh%^BOLD%^%^YELLOW%^i%^BOLD%^"
      +"%^CYAN%^mm%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^r%^BOLD%^"
      +"%^YELLOW%^i%^BOLD%^%^CYAN%^ng gem, of unique shape.");
}


