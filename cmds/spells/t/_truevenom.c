//~Circe~ 10/13/15 for psywarriors

#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

object mywpn, mypoison;
string mypname, pname;
#define Poisons ({ "wyvern_poison", "shadow_essence", "purple_worm_poison", "large_scorpion_venom", "giant_wasp_poison", "deathblade" })

void create() {
    ::create();
    set_spell_name("truevenom");
    set_spell_level(([ "psywarrior" : 4 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS truevenom on <weapon>");
    set_description("Upon using this power, the psionic character manifests "
       "a powerful poison to coat his weapon. A target struck by the poisoned "
       "weapon will suffer the same fate as any individual struck by the "
       "physical poisons found in the world. This power allows the psionic character "
       "to manifest more powerful poisons than those conjured by Prevenom. Once "
       "the poison has been applied, a corrosive layer of ectoplasm remains, "
       "inflicting extra damage on the psionic character's enemies for a short "
       "time.\n\nNOTE: When using this power, "
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
    if(caster->query_property("truevenom")){
       tell_object(caster, "You have already envenomed your weapon!");
       return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int i, mylevel, doses;
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
      if(mywpn->query_property("temp_oiled")){
         mywpn->remove_property("temp_oiled");
      }
      mywpn->set_property("temp_oiled","damage bonus acid 5");
      mywpn->remove_property("added short string");
      mywpn->set_property("added short string",({" %^BOLD%^%^GREEN%^{{"
         "%^RESET%^%^GREEN%^en%^BOLD%^%^BLACK%^v%^%^RESET%^%^GREEN%^en"
         "%^WHITE%^o%^GREEN%^med%^BOLD%^%^GREEN%^}}%^RESET%^"}));
      mywpn->set_property("added short",mywpn->query_property("added short string"));
    	if (interactive(caster)){
         tell_object(caster, "%^BOLD%^%^BLACK%^You gather the very essence of "
            "%^RESET%^%^GREEN%^p%^BOLD%^o%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^"
            "%^GREEN%^o%^BOLD%^n %^BOLD%^%^BLACK%^from the ether around you and "
            "coat your "+arg+" in a v%^RESET%^%^GREEN%^is%^BOLD%^c%^RESET%^"
            "%^GREEN%^ou%^BOLD%^%^BLACK%^s layer of %^GREEN%^"+pname+"%^BLACK%^.%^RESET%^");
      }
      tell_room(place,"%^BOLD%^%^BLACK%^As "+caster->QCN+" concentrates on "+caster->QP+" "
         ""+arg+", a v%^RESET%^%^GREEN%^is%^BOLD%^c%^RESET%^%^GREEN%^ou%^BOLD%^%^BLACK%^s "
         "layer of %^RESET%^%^GREEN%^p%^BOLD%^o%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^"
         "%^GREEN%^o%^BOLD%^n %^BLACK%^coats the weapon.%^RESET%^",caster);
      caster->set_property("truevenom",1);
      caster->set_property("spelled", ({TO}) );
      addSpellToCaster();
      caster->remove_paralyzed();
      spell_successful();

      mylevel = clevel;

      spell_duration = ((clevel + roll_dice(1, 20)) / 10 + 1) * ROUND_LENGTH;
      set_end_time();
      call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if(objectp(caster)){
       tell_object(caster,"%^RESET%^%^GREEN%^The %^BOLD%^ec%^RESET%^%^GREEN%^t"
          "%^BOLD%^op%^BOLD%^%^BLACK%^l%^GREEN%^as%^RESET%^m%^BOLD%^%^GREEN%^ic "
          "sheen %^RESET%^%^GREEN%^surrounding your weapon dissipates.%^RESET%^");
       caster->remove_property("truevenom");
    }
    if(objectp(mywpn)){
       mywpn->remove_property_value("added short",(string)mywpn->query_property("added short string"));
       mywpn->remove_property("temp_oiled");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
