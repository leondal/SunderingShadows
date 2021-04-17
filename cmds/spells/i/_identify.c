//wizard spell identify
//Fixed bug where it was revealing caster's true name ~Circe~ 5/4/11
#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;
object ob,*ppl;
int i;

void create() {
    ::create();
    set_spell_name("identify");
    set_spell_level(([ "mage" : 1, "oracle":1, "magus" : 1, "innate" : 5, "bard" : 1 ]));
    set_spell_sphere("divination");
    set_domains("knowledge");
    set_mystery("lore");
    set_syntax("cast CLASS identify on OBJECT");
    set_description("This is the spell for you to identify the enchantment of items (usually equipment, though it may "
"show attributes of other objects also).  The item must be in your inventory or the room where you are.  NOTE: Anyone in "
"the same room with you will also know the enchantment of that item. Clerics with the Knowledge domain can cast this spell "
"innately by casting one Divine Grace point.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([
      "mage" : ([ "pearl" : 1, "owlfeather" : 1, ]),
    ]));
	set_helpful_spell(1);
}

string query_cast_string() {
    if(objectp(caster)) { return "%^CYAN%^Blinking several times, "+caster->QCN+" chants a short phrase."; }
    return "";
}

int preSpell()
{
    
    if(caster->is_class("cleric"))
    {
        if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
        {
            tell_object(caster, "You don't have the Divine Grace to cast Identify!");
            return 0;
        }
    }
    
    return 1;
}

void spell_effect(int prof) {
    if (!arg)    {
        tell_object(caster,"You don't notice that here.");
        dest_effect();
        return;
    }

//    if ((string) caster->query_name() == "garrett") {
//      tell_object(find_player("garrett"),((environment(caster)->is_lab())?"1 ":"0 ") + identify(environment(caster)) + ":" + prof);
//
//    }
    if((!environment(caster)->is_lab()) && (prof < 100)) {
        tell_object(caster,"You fail to identify anything about this object, you lack the materials to adequately discern its magical nature.");
	dest_effect();
        return;
    }

    ob = present(arg,environment(caster));

    if (!ob)
        ob = present(arg,caster);

    if (!ob) {
        tell_object(caster,"You do not see that.");
        dest_effect();
        return;
    }
    if (living(ob)) {
        tell_object(caster,"You realize "+arg+" is not a statue!");
        dest_effect();
        return;
    }
    spell_successful();

    ppl = all_inventory(environment(caster));
    for (i = 0;i < sizeof(ppl);i++) {
        if (interactive(ppl[i])){
            if(prof > random(100)) {
                ob->add_identified(ppl[i]->query_name());
            }
        }
    }

    if(objectp(caster) && stringp(arg) && strlen(arg))
    {
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+
              capitalize(caster->QCN)+" touches the "+arg+" and reveals its "+
              "magical nature to all.",caster);
        tell_object(caster,"%^BOLD%^%^CYAN%^You touch the "+arg+
                " and reveal its magical nature.");
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
