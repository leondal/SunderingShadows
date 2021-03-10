// /d/newbie/obj/misc/rock.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long("This is a small rock, nothing more than an annoyance in your shoe.");
set_name("a small rock");
   set_short("a small rock");
   set_id(({"rock","small rock"}));
   set_weight(2);
   set_value(0);
}
