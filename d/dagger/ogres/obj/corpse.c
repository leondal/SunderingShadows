

#include <std.h>
#include "../ogres.h"


inherit BAG;

void create(){
    ::create();
    set_name("mangled corpse");
    set_id(({"corpse","mangled corpse"}));
    set_short("%^RESET%^%^RED%^man%^BOLD%^g%^RESET%^%^RED%^led "+
"%^BOLD%^c%^RESET%^%^RED%^orpse%^RESET%^");
    set_long("%^RESET%^%^RED%^This mangled remains of a "+
"%^RESET%^%^BOLD%^%^BLACK%^corpse %^RESET%^%^RED%^looks like"+
" it used to be a %^RESET%^%^ORANGE%^human%^RESET%^%^RED%^. "+
"It is impossible to tell if this person was killed by %^RESET%^"+
"%^MAGENTA%^demon %^RESET%^%^RED%^or %^RESET%^%^BOLD%^%^RED%^"+
"ogre%^RESET%^%^RED%^, but the ferocity of the attack has left"+
" little to identify them. %^RESET%^\n");
    set_property("no_animate",1);
    set_weight(5000);
      set_value(0);
      set_max_internal_encumbrance(30);
      switch(random(10)){
      case 0..3: new(OBJ"talos_greaves")->move(TO); break;
      case 4..6: new(OBJ"tyr_greaves")->move(TO); break;
      default: new(OBJ"dragoon_greaves")->move(TO); break;
      }
}
