//stormcone.c

#include <std.h>
#include <daemons.h>

inherit OBJECT;

object caster;

void create(){
   ::create();

   set_name("Storm cone");
   set_short("Cone of raging wind");
   set_id(({"stormcone","storm cone","cone","storm"}));
   set_long(
@OLI
   This is a raging wind storm. The wind buffets the life out of
everything around it.
OLI
   );
   set_weight(100000);

   set_property("no animate",1);
}

void set_caster(object ca){
   caster = ca;
   set_heart_beat(5);
}

void heart_beat(){
   object *inven;
   int i,j;

   if(!objectp(caster) || !present(caster, ETO)) {
      if(objectp(query_property("spell"))){
         query_property("spell")->dest_effect();
	 return;
      }
      remove();
      return;
   }

   tell_room(ETO,"%^BOLD%^%^CYAN%^Winds whirl around you with immense force.");

   inven = all_living(ETO);
   inven -= ({caster});
   inven = filter_array(inven, "is_non_immortal",FILTERS_D);

   j = sizeof(inven);
   for (i=0;i<j;i++) {
      if(!objectp(inven[i])) continue;

      if (random(5) < 3) {
	 tell_room(ETO,"%^BOLD%^%^CYAN%^"+inven[i]->query_cap_name()+" is buffeted horribly with the force of the winds.",inven[i]);
         tell_object(inven[i],"%^BOLD%^%^CYAN%^You are pummeled with the force of the winds.");
	 caster->kill_ob(inven[i],1);
	
	 if(objectp(query_property("spell"))){
	    query_property("spell")->damage_targ(inven[i], "torso", roll_dice(5,4));
	 } else {
	    inven[i]->do_damage("torso",roll_dice(5,4));
	 }
      }

      if(!objectp(inven[i])) continue;

      if(!random(5)){
	 tell_room(ETO,"%^YELLOW%^A bolt of lightning shrieks from the storm and impales "+inven[i]->query_cap_name()+".",inven[i]);
	 tell_object(inven[i],"%^YELLOW%^A bolt of lightning shrieks toward you from the storm.");
	 caster->kill_ob(inven[i],1);

	 if(objectp(query_property("spell"))){
	    query_property("spell")->damage_targ(inven[i], "torso", roll_dice(3,4));
	 } else {
	    inven[i]->do_damage("torso",roll_dice(3,4));
	 }

      }
   }
}


