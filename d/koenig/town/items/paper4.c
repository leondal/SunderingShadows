#include <std.h>
inherit OBJECT;

void create()
{ 
  ::create();
  set_name("paper");
  set_id( ({"paper"}) );
  set_short("a piece of paper");
  set_long(
@PEGASUS
Here is a list of potions for you to gather old friend. I have listed
what each one does and its color so that you will not harm yourself.
Take care and may we see each other again one day.
    POTION                             COLOR
<<<*******************************************>>>  
    shrinking                    yellow    
    enlarge                      dull yellow
    strength                     red
    pain                         cyan
    invisibility                 blue
    paralyze                     purple
    poison                       brown
    weakness                     dull red
    heal w/side effect           redishgold

PEGASUS
   );
  set_value(0);
  set_weight(1);
}
