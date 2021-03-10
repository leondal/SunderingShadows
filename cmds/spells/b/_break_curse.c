//removed mention of non-specialized mages and sorcerers being unable to cast the spell ~Circe~ 8/2/19
#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("break curse");
    set_spell_level(([ "mage" : 4, "bard" : 3, "paladin" : 3, "cleric" : 3, "inquisitor":3,]));
    set_spell_sphere("abjuration");
    set_domains("magic");
    set_mystery("godclaw");
    set_syntax("cast CLASS break curse on TARGET
        cast CLASS break curse on OBJECT [at PLAYER]");
    set_description("This spell will break curses that have been placed upon a living or magical item, unravelling the corrupted weave around it. Unlike dispel magic, this spell will always succeed if its caster level is greater than that of the curse. This spell will affect spells that dispel magic can not.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_casting_string()
{
    if (spell_type == "cleric") {
        return "%^BLUE%^" + caster->QCN + " begins to glow with a blue " + "radiance as " + caster->QS + " chants words filled with power.";
    }
    return "%^BLUE%^" + caster->QCN + " begins to glow with a blue radiance as " + caster->QS + " utters words filled " + "with power.";
}

int preSpell() {
   if(!arg) {
       tell_object(caster, "You must specify what to remove the curse from.");
       return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    string what,who;
    object ob, ob2;
    int ench;
    if(!stringp(arg))
    {
        what = "";
    }
    else if (sscanf(arg,"%s at %s", what, who) != 2) {
        what = arg;
        who = 0;
    }
    if(!who)
        ob = present(what,caster);
    else
    {
// if((string)caster->realName(who) != "") who = (string)caster->realName(who);
        if(!ob2 = present(who, ENV(caster)))
        {
            tell_object(caster,"That person isn't here.");
            dest_effect();
            return;
        }
        ob = present(what,ob2);
    }

    if(!objectp(ob))
        ob = present(what, place);

    if (!objectp(ob))
    {
        tell_object(caster,"Your target is not present.");
        dest_effect();
        return;
    }

    if(ob->is_living())
    {
        object * all_spells;
        object i;

        all_spells = ob->query_property("spelled");
        all_spells = filter_array(all_spells, (:objectp($1):));
        all_spells = filter_array(all_spells, (:$1->is_curse():));

        if(sizeof(all_spells))
        {
            foreach(i in all_spells)
            {
                if(clevel + roll_dice(1, 20)>= i->query_clevel())
                {
                    tell_object(caster,"%^BOLD%^You dispel " + i->query_spell_name());
                    i->dest_effect();
                }
                else
                {
                    tell_object(caster,"%^BOLD%^%^RED%^You failed to dispel " + i->query_spell_name());
                }
            }
        }
        else
        {
            tell_object(caster,"%^BOLD%^%^CYAN%^Your spell fails to hit any curses.");
        }

        spell_successful();
        dest_effect();
        return;
    }

    ench = ob->query_property("enchantment");
    if (ench > -1) {
        tell_object(caster,"That object is not cursed.");
        dest_effect();
        return;
    }
    if(ob->query_property("no remove") || ob->query_property("no remove curse")) {
        tell_object(caster,"That curse is too powerful even for you to break.");
        dest_effect();
        return;
    }
    ob->remove_property("enchantment");
    if(spell_type == "cleric") {
	if((string)caster->query_diety() == "shar") {
	    tell_room(place,"%^MAGENTA%^The tendrils of shadow converge upon"+
                      " "+what+", concealing it in darkness.");
	}
	else {
            if((string)caster->query_diety() == "cyric") tell_room(place,"%^BOLD%^%^BLACK%^The black flames jet out, "
                                                                   "piercing "+what+".");
            else tell_room(place,"%^BLUE%^Motes of %^BOLD%^b%^WHITE%^l%^BLUE%^u"+
                           "%^WHITE%^e%^BLUE%^-%^WHITE%^w%^BLUE%^h%^WHITE%^i%^BLUE%^t"+
                           "%^BLUE%^e%^RESET%^%^BLUE%^ energy surround "+what+", glowing"+
                           " brilliantly.");
        }
    }
    else tell_room(place,"%^BLUE%^Motes of %^BOLD%^b%^WHITE%^l%^BLUE%^u"+
                   "%^WHITE%^e%^BLUE%^-%^WHITE%^w%^BLUE%^h%^WHITE%^i%^BLUE%^t"+
                   "%^BLUE%^e%^RESET%^%^BLUE%^ energy surround "+what+", glowing"+
                   " brilliantly, before shattering in all directions.");
    spell_successful();
    dest_effect();
}
