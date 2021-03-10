#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("drow_gem");
    set_id(({"drow_gem","gem"}));
    set_short("%^RED%^%^BOLD%^red gem%^RESET%^");
   set_long("%^RED%^A lovely red gem.%^RESET%^");
    set_weight(1);
    set_value(500);
}
void save_me(string file) { return 1; }
