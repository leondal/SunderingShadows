#include "/d/dagger/aketon/short.h"

inherit OBJECT;

void check_uses();
void add_used(int used);

int uses;

create() {
   ::create();
   set_name("sliding leather");
   set_id( ({"leather","strip","sliding leather"}) );
   set_short("A strip of leather");
   set_long("This is a strip of ordinary looking leather. You can use it "
      "as a handle or something like that sometimes. May be you can slap "
      "people with it!");
   set_weight(1);
   set("value",50);
   uses = 2;
}

void add_used(int used) {
   uses -= used;
   call_out("check_uses",1);
   return;
}

void check_uses() {
   if(!uses)
      if(ETO->is_player()) {
         tell_object(ETO,"The leather strip is used due to overheating.");
         remove();
         return;
      }
   return;
}
