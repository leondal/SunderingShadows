#include "/d/islands/giant/giant.h";

inherit WEAPON;

void create(){
   ::create();
   set_id(({"club","large club"}));
   set_name("nail club");
   set_short("A large nail club");
   set_long(
@TERRATO
   This is a big club with a large iron nail sticking
out from it's head.  It would probably infict a great
deal of pain.
TERRATO
   );
   set_weight(15);
   set_size(3);
   set("value",700);
   set_wc(1,10);
   set_large_wc(3,7);
   set_type("bludgeoning");
   set_hit((:TO, "hit_fun":));
}
int hit_fun(object targ){

   if(random(5) == 4){
      tell_object(TP, "%^RED%^The club %^BOLD%^RIPS%^RESET%^%^RED%^ at your foes flesh with the nail!%^RESET%^");
      tell_object(targ, "%^RED%^The club wielded by "+TPQCN+" rips at your flesh!%^RESET%^");
      tell_room(ETP, "%^RED%^"+TPQCN+"'s club %^BOLD%^RIPS%^RESET%^ %^RED%^at "+TP->query_possessive()+" foe's flesh!%^RESET%^", (({targ,TP})));
      return (random(4)+1);
   }
   return 0;
}
