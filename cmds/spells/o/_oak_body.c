// Similar to Iron Body but with less DR and a vulnerability to fire

#include <spell.h>
#include <magic.h>

inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_spell_name("oak body");
    set_spell_level(([ "psywarrior" : 5, "psion" : 7 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS oak body");
    set_bonus_type("natural armor");
    set_description("By using this power, the psionic character lends some of his psychic energy to "
       "protect himself. It causes the manifester to gain some resistance to physical attacks, as well as immunity "
       "to most standard poisons. The oaken nature of the power leaves the manifester "
       "vulnerable to fire attacks. The oaken body brings a minor bonus to strength at the cost of dexterity. "
       "This power does not work together with Stoneskin or Iron Body.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster,"You already have protection of this nature!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
     int mylevel;
     ::spell_effect();
     tell_room(environment(caster),"%^RESET%^%^GREEN%^As "+caster->QCN+" closes "
               ""+caster->QP+" eyes and breathes deeply, "+caster->QP+" visible skin "
               "begins changing, sprouting rich, %^ORANGE%^brown %^GREEN%^v%^ORANGE%^e"
               "%^GREEN%^i%^ORANGE%^n%^GREEN%^s and taking on the hue of a l%^RESET%^"
               "%^ORANGE%^i%^GREEN%^v%^ORANGE%^i%^RESET%^%^GREEN%^ng o%^ORANGE%^a%^GREEN%^k!%^RESET%^",caster);
     tell_object(caster,"%^RESET%^%^GREEN%^As you turn your focus within, your "
                 "skin begins to morph into l%^RESET%^%^ORANGE%^i%^GREEN%^v%^ORANGE%^i"
                 "%^RESET%^%^GREEN%^ng o%^ORANGE%^a%^GREEN%^k, granting you strength "
                 "and protection!%^RESET%^");
     mylevel = clevel;
     if(caster->query_stats("strength") > 29){
          mybonus = 0;
     }else if(caster->query_stats("strength") > 28){
          mybonus = 1;
     }else{
          mybonus = 2;
     }
     if(mybonus){
          caster->add_stat_bonus("strength",mybonus);
          caster->add_stat_bonus("dexterity",-2); //if they get a strength bonus, they get the dexterity negative
     }

     caster->set_property("spelled",({TO}));
     caster->set_property("iron body",1);
     caster->set_property("damage resistance",10); //iron body is 15
     caster->set_property("poison immunity",1);
     caster->set_resistance("fire",-5);
     addSpellToCaster();
     spell_successful();
     spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 1800;
     set_end_time();
     call_out("dest_effect",spell_duration);
}

void dest_effect() {
   if(objectp(caster) && objectp(environment(caster)))
   {
      tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+caster->QCN+"'s skin glows "
      "and flickers before the %^GREEN%^o%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^n "
      "pr%^ORANGE%^o%^GREEN%^tec%^ORANGE%^t%^GREEN%^ion %^ORANGE%^fades away.%^RESET%^",caster);
      tell_object(caster,"%^RESET%^%^ORANGE%^You feel suddenly light and vulnerable "
      "as the %^GREEN%^o%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^n "
      "pr%^ORANGE%^o%^GREEN%^tec%^ORANGE%^t%^GREEN%^ion %^ORANGE%^surrounding you fades away.%^RESET%^");
       if(mybonus)
       {
           caster->add_stat_bonus("strength",(-1*mybonus));
           caster->add_stat_bonus("dexterity",2);
       }
       caster->set_property("damage resistance",-10);
       caster->set_property("poison immunity",-1);
       caster->set_property("iron body",-1);
       caster->set_resistance("fire",5);
       caster->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
