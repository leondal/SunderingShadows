#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("mask of feathers");
   set_short("%^BOLD%^%^RED%^Mask of Feathers%^RESET%^");
   set_id(({"mask","mask of feathers","feather mask","feathered mask"}));
   set_long("This beautiful mask is covered with many different brightly"+
   " colored feathers. There are slits for the eyes and a pair of nose"+
   " holes. A strap in the back helps keep it in place. There doesn't seem to be"+
   " any pattern or design, but it is lovely.");
   set_weight(2);
    set_value(30);
    set_type("clothing");
    set_limbs(({"head"}));
   set_wear("%^BOLD%^%^RED%^You feel a bit more wild as you put on the mask.");
   set_remove("You settle down again and remove the mask of feathers.");
   set_size(random(3)+1);
}
