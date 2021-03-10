// bananapeel.c

#include <std.h>

inherit OBJECT;


void create(){
   ::create();
   set_id(({"peel","banana peel"}));
   set_name("banana peel");
   set_short("%^RESET%^%^ORANGE%^an old %^YELLOW%^b%^RESET%^%^ORANGE%^an%^YELLOW%^an%^RESET%^%^ORANGE%^a peel%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is an old banana peel.  It is yellow on the outside and white on the inside.  Already brown spots are beginning to form.%^RESET%^");
   set_weight(1);
}
