//Octothorpe (12/21/08)
//Underdark Mining Caverns, Dragon Scale Cloak Lightning Shield Effect
//../obj/dragoncloak.c
//Based upon Fire Shield priest spell
///cmds/priest/_fire_shield.c

#include <std.h>
#include <priest.h>
inherit SPELL;

/*void create(){
   ::create();
   set_author("ares");
   set_spell_name("fire shield");
   set_spell_type("priest");
   set_spell_level(3);
   set_spell_sphere("combat");
   set_spell_domain("fire");
   set_verbal_comp();
}*/

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("electric shield");
    set_spell_level(([ "mage" : 4, "cleric" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_spell_domain("fire");
    set_syntax("cast <classname> fire shield");
    set_description("This spell will surround the caster's body in a roaring shield of flames.  It grants the caster a "
"slight bonus to their armor class, and any opponent striking the caster must make a saving throw or take damage from the "
"blistering heat.\n\nNon-specialized mages cannot cast this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_mage_only(1); // school specific mage spell
    set_components(([
      "mage" : ([ "phosphorus" : 1, ]),
    ]));
    set_save("fort");
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 3) * 21;
    caster->set_property("fire shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(2);
    caster->set_property("added short",({" %^BOLD%^%^RED%^(crackling with electricity)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    call_out("dest_effect",duration);
}

void execute_attack(){
   object *attackers,room;
   int i;

   ::execute_attack();
   if(!objectp(caster)){
      dest_effect();
      return;
   }
   room = environment(caster);
   attackers = caster->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
   if(!sizeof(attackers)){
      room->addObjectToCombatCycle(TO,1);
      return;
   }
   for(i=0;i<sizeof(attackers);i++){
      if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
      tell_room(room,"%^BOLD%^%^BLUE%^"+attackers[i]->QCN+" is "+
         "electrocuted by the crackling shield of %^ORANGE%^e"+
         "%^YELLOW%^l%^BLUE%^e%^YELLOW%^c%^RESET%^%^ORANGE%^tr"+
         "%^YELLOW%^i%^BLUE%^c%^YELLOW%^i%^RESET%^%^ORANGE%^ty "+
         "%^BOLD%^%^BLUE%^around "+caster->QCN+" as "+
         ""+attackers[i]->QS+" strikes "+
         ""+caster->QO+"!%^RESET%^",({caster,target}));
      tell_object(caster,"%^BOLD%^%^BLUE%^"+attackers[i]->QCN+" is "+
         "electrocuted by the shield of %^ORANGE%^e"+
         "%^YELLOW%^l%^BLUE%^e%^YELLOW%^c%^RESET%^%^ORANGE%^tr"+
         "%^YELLOW%^i%^BLUE%^c%^YELLOW%^i%^RESET%^%^ORANGE%^ty "+
         "%^BOLD%^%^BLUE%^as "+attackers[i]->QS+" strikes "+
         "you!%^RESET%^");
       tell_object(target,"%^BOLD%^%^BLUE%^You are electrocuted "+
         "by the shield of %^ORANGE%^e%^YELLOW%^l%^BLUE%^e"+
         "%^YELLOW%^c%^RESET%^%^ORANGE%^tr%^YELLOW%^i%^BLUE%^c"+
         "%^YELLOW%^i%^RESET%^%^ORANGE%^ty %^BOLD%^%^BLUE%^as you "+
         "strike "+caster->QCN+"!%^RESET%^");
       
attackers[i]->do_damage(attackers[i]->return_target_limb(),roll_dice(1,21));
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^BOLD%^%^BLUE%^The shield of capricious "+
         "%^ORANGE%^e%^YELLOW%^l%^BLUE%^e%^YELLOW%^c%^RESET%^%^ORANGE%^"+
         "tr%^YELLOW%^i%^BLUE%^c%^YELLOW%^i%^RESET%^%^ORANGE%^ty "+
         "%^BOLD%^%^BLUE%^flickers and fades away, leaving you "+
         "vulnerable once again.%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^BLUE%^The shield of "+
         "capricious %^ORANGE%^e%^YELLOW%^l%^BLUE%^e%^YELLOW%^c%^RESET%^"+
         "%^ORANGE%^tr%^YELLOW%^i%^BLUE%^c%^YELLOW%^i%^RESET%^%^ORANGE%^"+
         "ty %^BOLD%^%^BLUE%^flickers and fades away, leaving "+
         ""+caster->QCN+" vulnerable once again.%^RESET%^",caster);
      caster->remove_property("fire shield");
      caster->add_ac_bonus(-2);
      caster->remove_property("added short",({" %^BOLD%^%^RED%^(crackling with electricity)%^RESET%^"}));
   }
   ::dest_effect();
   TO->remove();
}