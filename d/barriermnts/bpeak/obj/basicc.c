#include <std.h>
inherit "/d/common/obj/weapon/club_lg.c";



void create() {
    ::create();
   set_id(({"club","A very large club"}));
   set_name("%^BOLD%^%^BLACK%^A crudely made club%^RESET%^");
   set_obvious_short("A crude club");
   set_long("%^BOLD%^%^BLACK%^This is a very large club that is crudely cut from"
" large tree trunks.  It looks like it would hurt a whole lot as all of the cuts"
" are uneven.%^RESET%^");
   set("value",0);
   set_cointype("gold");
   set_property("enchantment",3);  
}

