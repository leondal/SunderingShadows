#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("elven journal");
   set_short("A leather bound journal");
   set_id(({"book","journal","leather bound journal","elven journal"}));
   set_long("This is a large leather bound journal. The first hundred"+
   " or so pages have been either torn out or blotted with ink to"+
   " make them unreadable. Only a few pages towards the middle seem"+
   " legible if you can read it, while the rest of the book is empty.");
   set_weight(10);
   set_value(1);
}

void init()
{
   ::init();
   add_action("read","read");
}

void read(string str)
{
   if(str == "journal") {
      if(TP->query_lang("elven") < 1) {
         tell_object(TP,"You don't even know what language this"+
         " journal is in, there's no way you can read it.");
         tell_room(ETP,""+TPQCN+" stares at the journal blankly.",TP);
         return 1;
      }
      if(TP->query_lang("elven") < 75) {
         tell_object(TP,"The journal is obviously written in elven"+
         " but you can't make out enough of the words to really"+
         " understand what it says.");
         tell_room(ETP,""+TPQCN+" stares intensely at the journal before"+
         " giving up.",TP);
         return 1;
      }
      tell_object(TP,"You read the elven journal carefully.");
      tell_room(ETP,""+TPQCN+" reads a leather bound journal.",TP);
      TP->more("/d/dagger/aketon/obj/elven_journal");
      return 1;
   }
}
