#include <std.h>
inherit OBJECT;

string owner;
int owned;
void checkme();

void create(){
  ::create();
  set_name("ivory token");
  set_id(({"token","gleaming ivory token","gleaming token","ivory token","token of spirit","dojospirittoken"}));
  set_short("%^RESET%^%^WHITE%^gl%^BOLD%^e%^RESET%^%^WHITE%^aming ivo%^BOLD%^r%^RESET%^%^WHITE%^y token%^RESET%^");
  set_long((:TO,"long_desc":));
  set_value(0);
  set_weight(0);
  set_lore("Tokens such as this are used as a mark of prowess among the women of the Vasati Aadhyaatmika, a small dojo upon the island of Laerad. This particular token "
"bears the mark of spirit.");
  set_property("lore difficulty",25);
}

void init(){ 
  ::init(); 
  set_long((:TO, "long_desc":));
  if(userp(ETO) && !owned) {
    owned = 1;
    owner = (string)ETO->query_name();
  }
  call_out("checkme",1);
}

string long_desc() {
   if((int)TP->query_skill("academics") > 25) {
     return("%^RESET%^%^WHITE%^This small, flat token shapes a perfect circle in your hand, its edges smooth to the touch. It appears to be made of some kind of dull ivory "
"stone, but its flawless surface doesn't lend any further hints to whether it might be precious and valuable, or simply painted granite. A single mark has been etched into "
"its surface, gleaming bright %^BOLD%^silver%^RESET%^%^WHITE%^, which you recognize as an ancient symbol of spirit.%^RESET%^\n");
   }
   return("%^RESET%^%^WHITE%^This small, flat token shapes a perfect circle in your hand, its edges smooth to the touch. It appears to be made of some kind of dull ivory "
"stone, but its flawless surface doesn't lend any further hints to whether it might be precious and valuable, or simply painted granite. A single mark has been etched into "
"its surface, gleaming bright %^BOLD%^silver%^RESET%^%^WHITE%^, though you're not sure what it means.%^RESET%^\n");
}

void checkme() {
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!owned) {
     tell_room(ETO,"%^BOLD%^%^WHITE%^The token vanishes!%^RESET%^");
     TO->remove();
   }
   if((string)ETO->query_name() != owner) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The token vanishes!%^RESET%^");
     TO->remove();
   }
}

string query_owner() { return owner; }