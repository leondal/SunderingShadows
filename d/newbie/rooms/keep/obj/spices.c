#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("box of spices");
   set_id(({"box","spice box","box of spices","small box","spices"}));
   set_short("%^RESET%^%^RED%^A small box of %^ORANGE%^s%^RESET%^p%^RED%^i%^ORANGE%^c%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^s%^RESET%^");
   set_long("%^RESET%^This is a %^RED%^small wooden box %^RESET%^with a "
"%^ORANGE%^rusted latch%^RESET%^.  It looks a little worn with age, but seems "
"to have remained well sealed.  Opening it reveals several small satchets of "
"%^ORANGE%^s%^RESET%^p%^RED%^i%^ORANGE%^c%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^s"
"%^RESET%^.  Obviously these would have been a valuable commodity at one time, "
"but perhaps a shopkeeper would still offer you a few %^YELLOW%^coins "
"%^RESET%^for them.");
   set_weight(2);
   set_value(50);
}
