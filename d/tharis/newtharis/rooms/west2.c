#include <std.h>
#include "../tharis.h"
inherit STORAGE"rich";

void create(){
    ::create();
    set_long(::query_long()+" \n%^BOLD%^%^BLACK%^Just to the south, a grand %^RESET%^%^MAGENTA%^hotel %^BOLD%^%^BLACK%^looms above the the street.%^RESET%^%^RESET%^\n");
    set_exits(([
        "east" : ROOMS"west1",
        "west" : ROOMS"west3",
        "south" : "/d/tharis/newtharis/hotel_tharis/room/foyer",
    ]));
    add_item("hotel","%^RESET%^The exterior of this dignified hotel is constructed from large %^BOLD%^%^BLACK%^m%^WHITE%^o%^RESET%^t%^BOLD%^t%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d black %^RESET%^and %^BOLD%^%^BLACK%^g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^e %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^e%^BLACK%^s %^RESET%^that have been fit together in an intricate pattern. The hotel itself is quite large, %^BOLD%^%^BLACK%^looming %^RESET%^four stories tall over the street. Much of the fourth story features floor to ceiling %^CYAN%^w%^BOLD%^i%^RESET%^%^CYAN%^nd%^BOLD%^o%^RESET%^%^CYAN%^ws%^WHITE%^. Hanging near the entrance to the hotel is a large %^BOLD%^%^BLACK%^ebony wood %^RESET%^sign emblazoned with a simple, but stylish, violet '%^MAGENTA%^V%^WHITE%^'.");
}