//removing since it's not IG and it keeps coming up on scrolls.  Circe 6/10/04
//Think I've fixed the problem with it - Saide - June 2008
// Modified by PAtor@ShadowGate
// August 25 1995
#include <std.h>
#include <langs.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;
int theProf;

int is_curse()
{
    return 1;
}

void create() {
    ::create();
    set_spell_name("garble");
    set_spell_level(([ "mage" : 3, "bard" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS garble on TARGET");
    set_description("This will remove from the target the ability to understand, both read and write any language. This should not change the ability to teach the language.");
    mental_spell();
    set_verbal_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "clay model ziggurat" : 1, ]),
    ]));
    set_save("will");
}

query_cast_string() {
   return caster->QCN+" starts to mouth out syllables.\n";
}

void spell_effect(int prof) {
    	int i;
    	string what;
    	string arg;
    	object ob;
	theProf = prof;
	tell_object(caster,"%^BOLD%^You start to cast garble.");
    if(do_save(target,0)||mind_immunity_damage(target)) {
         tell_object(target,"%^RED%^You feel an assault upon your mind but shake it off!%^RESET%");
         tell_object(caster,"%^RED%^"+target->QCN+" %^RESET%^%^RED%^shakes off the effects or your spell!%^RESET%^");
         if(objectp(TO)) TO->remove();
         return;
      }
      tell_object(target,"%^BOLD%^You start to feel knowledge you "+
	"had leave your mind, you feel yourself know less but not what you now don't know.");
    	spell_successful();
    	for (i =0;i<sizeof(ALL_LANGS);i++)
	{
      	target->subtract_lang_overload(ALL_LANGS[i],prof);
    	}
    	addSpellToCaster();
    	target->set_property("spelled",({TO}));
        spell_duration = (clevel / 2 + roll_dice(1, 20)) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;

    if (objectp(target))
    {
	    	for (i =0;i<sizeof(ALL_LANGS);i++)
		{
          		target->add_lang_overload(ALL_LANGS[i],theProf);
    		}
    }  // moved it to here, but I wonder if they log out without a successful
       // dest if that leaves the benefit or something else bad happens *Styx*
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void do_spell_blowup(int prof){
    MAGIC_D->fizzile(TO);
}
