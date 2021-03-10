#include <std.h>
inherit OBJECT;
int touch (string str);

void create() {
        ::create();
                set_name("map of cursed lands");
                set_id( ({ "map" }) );
                set_short("A map of the Cursed lands");
                set_long(
@STOP
It's a map of the Cursed Lands.
You can %^GREEN%^view%^RESET%^ where all the rooms are located.
STOP
);
                set_weight(1);
                set("coin_type","platinum");
                set_value(500);
                set_cointype("platinum");
                }
void init() {
        add_action("look", "look");
        add_action("look", "view");
        }

int look (string str) {
      if(!id(str)) {
        notify_fail("Look at what?\n");
        return 0;
        }
       write(
@MAP
        %^BOLD%^%^RED%^         MAP of the CURSED LANDS!%^RESET%^
%^YELLOW%^





                              
                              4
                              |
                              3
                              |
                    8-7-6-5-2-1
                   /          |
                 9            E
%^RESET%^
MAP
);
                              
        return 1;
}

