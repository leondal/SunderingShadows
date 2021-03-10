#include <std.h>
#include "../witchlair.h"
inherit OBJECT;

void create(){
   ::create();
   set_name("paper");
   set_id(({"paper","piece of paper"}));
   set_short("piece of paper");
   set_long("This is a piece of paper. It is a regular "
"quality sheet used for writing.");
   set_value(1);
   set("language","undercommon");
   set("read","%^RESET%^%^GREEN%^To the shaman\n"
     "%^RESET%^%^RED%^As promised, your predecessor has"
     " been dealt with. You and your tribe are to keep "
     "guard over the entrance to my home. Any foolish "
     "enough to enter are to be kept alive, and NOT ONE "
     "DROP of blood wasted. I will drain them at my leisure."
     " Failure to obey will result in punishment worse than"
     " death.\n\n\n"
     "%^RESET%^%^BLUE%^~Ahkserin");
}
