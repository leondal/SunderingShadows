//~Circe~ 9/29/15 for psywarriors

#include <priest.h>
#include <daemons.h>
inherit SPELL;

object mywpn, mypoison;
string myshort, mypname, pname;
#define Poisons ({ "small_centipede_poison", "medium_spider_venom", "greenblood_oil", "blue_whinnis", "bloodroot", "black_adder_venom" })

void create() {
    ::create();
    set_spell_name("prevenom");
    set_spell_level(([ "psywarrior" : 1, ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS prevenom on <weapon>");
    set_description("Upon using this power, the psionic character manifests "
       "a powerful poison to coat his weapon. A target struck by the poisoned "
       "weapon will suffer the same fate as any individual struck by the "
       "physical poisons found in the world.\n\nNOTE: When using this power, "
       "you must specify a weapon as the target. The first such weapon in your "
       "inventory will be chosen, and items in containers will be ignored.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell() {
    if(!arg){
       tell_object(caster,"You must specify a target weapon for this power!");
       return 0;
    }
    return 1;
}

void spell_effect(int prof){
      int i;
      int doses;
    	if (!objectp(caster)){
        dest_effect();
        return;
    	}
      if(!arg){
         tell_object(caster,"You must specify a target weapon for this power!");
         dest_effect();
         return;
      }
      if(!mywpn = present(arg,caster)){
         tell_object(caster,"You don't have any "+arg+" in your inventory!");
         dest_effect();
         return;
      }
      if(!mywpn->is_weapon()){
         tell_object(caster,"That "+arg+" is not a weapon!");
         return;
      }
      i = random(sizeof(Poisons));
      mypname = Poisons[i];
      mypoison = new("/d/common/obj/poisons/base/"+mypname+".c");
      if(!objectp(mypoison)){
         tell_object(caster,"Something seems to be wrong with your poison. Please contact a wiz.");
         return;
      }
      pname = mypoison->query_poison_name();
      doses = clevel/12 +1;
      mywpn->set("PoisonDoses", doses);
	  mywpn->set("PoisonType", pname);
      mywpn->set("whoImmune", caster->query_name());
    	if (interactive(caster)){
         tell_object(caster, "%^RESET%^%^GREEN%^As you concentrate on your "
            ""+arg+", a faint coat of %^BOLD%^g%^RESET%^%^GREEN%^l%^RESET%^is"
            "%^GREEN%^t%^BOLD%^e%^WHITE%^n%^RESET%^in%^BOLD%^%^GREEN%^g poison "
            "%^RESET%^%^GREEN%^coalesces around it.%^RESET%^");
         tell_object(caster,"%^BOLD%^%^GREEN%^Your "+arg+" has been covered in "
            "%^BLACK%^"+pname+"%^GREEN%^!%^RESET%^");
      }
      tell_room(place,"%^RESET%^%^GREEN%^As "+caster->QCN+" concentrates on "+caster->QP+" "
            ""+arg+", a faint coat of %^BOLD%^g%^RESET%^%^GREEN%^l%^RESET%^is"
            "%^GREEN%^t%^BOLD%^e%^WHITE%^n%^RESET%^in%^BOLD%^%^GREEN%^g poison "
            "%^RESET%^%^GREEN%^coalesces around it.%^RESET%^",caster);
        caster->remove_paralyzed();
        spell_successful();
    if(objectp(mypoison)) mypoison->remove();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
