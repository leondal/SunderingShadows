#include "/d/islands/giant/giant.h";

inherit WEAPON;

void create(){
   ::create();
   set_id(({"mace","giant mace"}));
   set_name("decorative mace");
   set_short("%^RESET%^%^BOLD%^A large decorated mace");
   set_long(
@TERRATO
   This mace is intricatly designed and is very well made.  The four faces
of it's head each have a bass-relief telling a tale of glory and battle
as told in Hill Giant lore.
TERRATO
   );
   set_weight(15);
   set_size(3);
   set("value",700);
   set_wc(1,10);
   set_large_wc(3,7);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_hit((:TO, "hit_fun":));
}
int hit_fun(object targ){

   if(random(5) == 4){
      tell_object(TP, "%^RED%^The mace bashes your foe's skull in!%^RESET%^");
      tell_object(targ, "%^RED%^The mace wielded by "+TPQCN+" bashes your skull in!%^RESET%^");
      tell_room(ETP, "%^RED%^"+TPQCN+"'s mace bash's "+TP->query_possessive()+" foe's skull in!%^RESET%^", (({targ,TP})));
      return (random(4)+1);
   }
   return 0;
}
