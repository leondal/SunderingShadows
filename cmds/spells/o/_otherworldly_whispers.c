// based on legend lore, scaled ID & study.
#include <spell.h>
inherit SPELL;

object ob,*ppl;
int i;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("otherworldly whispers");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS otherworldly whispers on OBJECT");
    set_description("This invocation draws upon the knowledge of unnamed beings beyond. "
"The warlock can draw upon his or her connection with them to reveal secrets that might "
"otherwise remain hidden. A more powerful warlock will be able to reveal the nature of "
"more obscure items.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_room(place,"%^BLUE%^Closing "+caster->QP+" eyes, "+caster->QCN+" concentrates.%^RESET%^",caster);
    tell_object(caster,"%^BLUE%^After inspecting the item, you close your eyes and concentrate upon it.%^RESET%^");
    return "display";
}

void spell_effect(int prof) {
    int iddiff, lorediff;
    if (!arg)    {
        tell_object(caster,"You don't notice that here.");
        dest_effect();
        return;
    }
    
    ob = present(arg,environment(caster));
    if (!ob) ob = present(arg,caster);

    if (!ob) {
        tell_object(caster,"You do not see that.");
        dest_effect();
        return;
    }
    if(living(ob)) {
        tell_object(caster,"You suspect you would need a more powerful invocation to reveal "+arg+"'s secrets!");
        dest_effect();
        return;
    }
    spell_successful();
    
    tell_object(caster,"%^BLUE%^Low %^BOLD%^%^BLACK%^wh%^RESET%^is%^BOLD%^%^BLACK%^pe%^RESET%^r%^BOLD%^%^BLACK%^s %^RESET%^%^BLUE%^fill your ears, and your voice echoes the "+arg+"'s true nature.%^RESET%^");
    tell_room(place,"%^BLUE%^"+caster->QCN+" seems to fall momentarily into a trance, and "+caster->QS+" voices the true name of the "+arg+".%^RESET%^",caster);
    ppl = all_inventory(environment(caster));
    for (i = 0;i < sizeof(ppl);i++) {
        if (interactive(ppl[i])) ob->add_identified(ppl[i]->query_name());
    }
    
    tell_object(caster,"%^BLUE%^Low %^BOLD%^%^BLACK%^wh%^RESET%^is%^BOLD%^%^BLACK%^pe%^RESET%^r%^BOLD%^%^BLACK%^s %^RESET%^%^BLUE%^fill your ears, revealing the origins of the "+arg+" to you:%^RESET%^");
    tell_object(caster,ob->query_lore());
    ob->add_studied(caster->query_name());
    
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
