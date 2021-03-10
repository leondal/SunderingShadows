//Octothorpe (12/24/08)
//Underdark Mining Caverns, Dragon Scale Cloak Unique Scales Spell
//Based on Faithful Phantom Guardians spell
///cmds/wizard/_faithful_phantom_guardians.c

#include <std.h>
inherit SPELL;

object *mons = ({});

/*void create(){
   ::create();
   set_spell_name("unique scales");
   set_spell_level(6);
   set_spell_type("wizard");
   set_spell_sphere("conjuration_summoning");
   set_verbal_comp();
   set_somatic_comp();
   set_arg_needed();
}*/

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("fire shield");
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

void spell_effect(int prof)
{
   object ob;
   switch (arg){
      case "geon":
         caster->set_property("fire shield",1);
         caster->set_property("spelled", ({TO}) );
         ob = new("/realms/octothorpe/udmines/spell/emgem.c");
         ob->move(place);
         ob->force_me("protect "+caster->query_name());
         ob->force_me("protect "+caster->query_name());
         caster->add_follower(ob);
         ob->set_property("spelled", ({TO}) );
         ob->set_property("spell_creature", TO);
         ob->set_property("spell", TO);
         ob->add_id("summoned monster");
         ob->add_id(caster->query_name()+"monster");
         mons += ({ob});
         addSpellToCaster();
         spell_successful();
         call_out("dest_effect",100);
         break;
      case "aisl":
         caster->set_property("fire shield",1);
         caster->set_property("spelled", ({TO}) );
         ob = new("/realms/octothorpe/udmines/spell/nightmare.c");
         ob->move(place);
         ob->force_me("protect "+caster->query_name());
         ob->force_me("protect "+caster->query_name());
         caster->add_follower(ob);
         ob->set_property("spelled", ({TO}) );
         ob->set_property("spell_creature", TO);
         ob->set_property("spell", TO);
         ob->add_id("summoned monster");
         ob->add_id(caster->query_name()+"monster");
         mons += ({ob});
         addSpellToCaster();
         spell_successful();
         call_out("dest_effect",100);
         break;
   }
}

void dest_effect()
{
    int i;
    for (i=0;i<sizeof(mons);i++) 
    {
      if (objectp(mons[i])) {
         caster->remove_protector(mons[i]);
         caster->remove_property("fire shield");
         mons[i]->die();
      }
   }
   ::dest_effect();
}

