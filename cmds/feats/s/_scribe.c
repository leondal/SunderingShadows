#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("scribe");
    feat_syntax("scribe SPELL_NAME [as level SPELL_LEVEL] [for NUM times]");
    feat_prereq("Bard, Cleric, Druid, Inquisitor, Mage, Magus, Paladin, Ranger, Sorcerer, Oracle");
    feat_desc("This feat allows a character to use their knowledge of the arcane to scribe simple scrolls of spells they already know. Such scrolls are only good for a single use. You must have an empty parchment sheet in your inventory for scribe to work. It has to be parchment, other writing materials won't do.

SPELL_NAME
  The spell you wish the scroll to cast when it is used.

SPELL_LEVEL
  Optinal scroll power you can specify. By default scroll will be scribed with maximum power available.

NUM
  Defines how many scrolls you want to scribe.

To scribe a scroll you must expend five gold coins per spell level and one parchment.

%^BOLD%^N.B.%^RESET%^ Multiclassing characters will use currently %^ULINE%^posed%^RESET%^ class for this feat. Use <pose> to switch it. You can not use spells that channel positive or negative energy with each cast, such as heal or harm, with this feat.");
    set_target_required(0);
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("mage") &&
        !ob->is_class("sorcerer") &&
        !ob->is_class("cleric") &&
        !ob->is_class("bard") &&
        !ob->is_class("thief") && // Thief is here not by mistake
        !ob->is_class("inquisitor") &&
        !ob->is_class("oracle") &&
        !ob->is_class("ranger") &&
        !ob->is_class("cypher") &&
        !ob->is_class("paladin") &&
        !ob->is_class("magus") &&
        !ob->is_class("druid")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_scribe(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    if (!stringp(str)) {
        str = "";
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object ob, tp;
    int level, number;
    int spell_clevel, scroll_amount;
    string tmp, str, levelstring;
    ::execute_feat();

    if (!arg) {
        return help();
    }
	    if (!environment(caster)->is_lab() && !present("portable lab", environment(caster))) {
        write("You can only enchant items in a laboratory.");
        return 1;
    }

    if (regexp(arg, "as level [0-9]+ for [0-9]+ times$")) {
        if (sscanf(arg, "%s as level %d for %d times", str, spell_clevel, scroll_amount) != 3) {
            help();
            return 1;
        }
    } else if (regexp(arg, "for [0-9]+ times$")) {
        if (sscanf(arg, "%s for %d times", str, scroll_amount) != 2) {
            help();
            return 1;
        }
    } else if (regexp(arg, "as level [0-9]+$")) {
        if (sscanf(arg, "%s as level %d", str, spell_clevel) != 2) {
            help();
            return 1;
        }
    } else if (regexp(arg, "[ a-z]+")) {
        if (sscanf(arg, "%s", str) != 1) {
            help();
            return 1;
        }
    } else {
        help();
        return 1;
    }

    tmp = MAGIC_D->get_spell_file_name(str);

    if ((regexp(tmp, ".*(cure|cause).*wounds") || regexp(tmp, "repair.*undead") || regexp(tmp, (".*(heal|harm)"))) && str != "aura of healing" && str != "shadow healing") {
        tell_object(caster,"You puzzle, unsure how to scribe this spell.");
        return 1;
    }

    if (!objectp(find_object_or_load(tmp))) {
        tell_object(caster, "You don't know a spell named " + str + "."); return 1;
    }

    level = tmp->query_spell_level(TP->query_class());

    if (!FEATS_D->usable_feat(caster, "clone scroll") || (FEATS_D->usable_feat(caster, "clone scroll")  && (!present(str, caster) || !present(str, caster)->is_scroll()))) {
        if (MAGIC_D->is_mastering_class(TP->query_class()) && member_array(str, TP->query_mastered_spells(TP->query_class())) == -1) {
            tell_object(caster, "You don't have that spell mastered with your posed class.\n");
            return 1;
        }

        if (!(caster->query_memorized(TP->query_class(), str))) {
            tell_object(caster, "That spell isn't in your memory.\n");
            return 1;
        }
    }

    if (!spell_clevel) {
        spell_clevel = TP->query_guild_level(TP->query_class()) + TP->query_property("empowered");
    } else {
        if (spell_clevel > TP->query_guild_level(TP->query_class()) + TP->query_property("empowered")) {
            tell_object(caster, "%^BOLD%^%^RED%^You can't scribe spell with power so great. Maximum level available to you now is %^CYAN%^" + (TP->query_guild_level(TP->query_class()) + TP->query_property("empowered")) + "%^RED%^. \n");
            return 1;
        }
    }

    ob = present("parchment11", caster);
    if (!objectp(ob = present("parchment11", caster))) {
        tell_object(caster, "You don't have any parchment!");
        return 1;
    }

    if (!scroll_amount) {
        scroll_amount = 1;
    }

    if (!caster->query_funds("gold", spell_clevel * 5 * scroll_amount)) {
        tell_object(caster, "You don't have enough money. You need " + (spell_clevel * 5 * scroll_amount) + "gold.");
        return 0;
    }

    tell_room(environment(caster), "%^BOLD%^" + caster->QCN + " sits and begins to scribe a spell onto some parchment.", caster);
    tell_object(caster, "%^BOLD%^You sit and start to scribe " + str + " onto the parchment.");

    call_out("scribe", ROUND_LENGTH, str, spell_clevel, caster, scroll_amount, ENV(caster));

    return;
}

void cancel(object ob, string spell){
    if (!objectp(ob)) {
        return;
    }
    ob->remove();
    write("You interrupt your scribing.");
    tell_room(environment(caster),""+caster->QCN+" interrupts "+caster->QP+" attempt to scribe a new scroll.",caster);
    caster->remove_paralyzed();
    remove_call_out("scribe");
}

void scribe(string spell, int spell_clevel, object tp, int scroll_amount, object place)
{
    object scroll, compbag;
    object paper;
    string tmp, * comp_names;
    int x;

    if (!objectp(tp)) {
        return 0;
    }

    if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 0;
    }

    if (sizeof(caster->query_attackers())) {
        tell_object(tp, "Enemies interrupt your scribing.");
        return 0;
    }

    if (ENV(tp) != place) {
        tell_object(tp, "Movement interrupted your scribing.");
        return 0;
    }

    paper = present("parchment11", tp);

    if (!objectp(paper = present("parchment11", tp))) {
        tell_object(tp, "You don't have any parchment!");
        return 0;
    }

    if (!tp->query_funds("gold", spell_clevel * 5 * scroll_amount)) {
        tell_object(tp, "You don't have enough money. You need " + (spell_clevel * 5 * scroll_amount) + "gold.");
        return 0;
    }

    scroll_amount--;


    tell_object(tp,"%^ORANGE%^You carefully scribe a scroll of %^BOLD%^" +spell+"%^RESET%^%^ORANGE%^, then seal the powers inside with golden vapour, spending %^BOLD%^" +spell_clevel * 5+"%^RESET%^%^ORANGE%^ gold.");
    tell_room(ENV(tp),"%^ORANGE%^" +tp->QCN+" carefully scribes a scroll, then seals it with golden vapour.", tp);

    if (scroll_amount) {
        tell_object(tp, "%^BOLD%^There are " + scroll_amount + " scrolls left to scribe.");
    }

    scroll = new("/d/magic/scroll");
    scroll->set_spell_name(spell);
    scroll->set_passed((string)tp->query_name());
    scroll->set_clevel(spell_clevel);
    scroll->move(environment(tp));
    paper->remove();
    caster->use_funds("gold", spell_clevel * 5);

    if (scroll_amount) {
        call_out("scribe", ROUND_LENGTH, spell, spell_clevel, tp, scroll_amount, ENV(tp));
    }
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
