#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit FEAT;

int FLAG;

int light_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_armor_prof("light")) {
        return 0;
    }
    return 1;
}

int armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_armor_prof("light")) {
        return 1;
    }
    if (ob->query_armor_prof("medium")) {
        return 1;
    }
    if (ob->query_armor_prof("heavy")) {
        return 1;
    }
    return 0;
}

void create() {
    ::create();
    feat_type("premanent");
    feat_category("MagicDamage");
    feat_name("spellmastery");
    feat_syntax("spellmastery [SPELLNAME]");
    feat_desc("Upon taking this feat you gain ability to select a spell (with %^ORANGE%^<spellmastery>%^RESET%^ command) you can cast indefinitely, without needing to prepare it. Only spells of 1st and 2nd level may be picked for SpellMastery. If you have more than one class able to use the same spell, the power of the SpellMastery (as well as armor checks, etc) will be based upon the highest of these.

%^ORANGE%^<spellmastery>%^RESET%^ without an argument will display currently spellmastered spell.

%^BOLD%^N.B.%^RESET%^ Spellmastery is not connected to <master> in any way. It just allows you to cast the spell without memorization. You still have to know the spell to cast it, have it in your spellbook, mastered or in your spell list.

%^BOLD%^N.B.%^RESET%^ Psions, Psywarriors, Monks and Warlocks are not affected by this feat.");

    permanent(1);
    allow_tripped(1);
}

int cmd_spellmastery(string args)
{
    int cancastflag;
    string * myclasses, myclass;

    if(!args)
    {
        write("%^BOLD%^Your current spellmastery spell is:%^RESET%^ "+TP->query("spellmastery_spell"));
        return 1;
    }

    if(TP->query("spellmastery_change") > time() - 60*60*24*3)
    {
        write("%^BOLD%^%^WHITE%^You can change your mastered spell only once in three days.");
        return 1;
    }

    cancastflag = 0;
    myclasses = TP->query_classes();
    foreach(myclass in myclasses)
    {
        if(member_array(args,keys(MAGIC_D->index_castable_spells(TP,myclass)))!=-1)
            cancastflag++;
    }

    if(!cancastflag)
    {
        write("%^BOLD%^%^RED%^None of your classes can cast this spell.");
        return 1;
    }

    write("%^BOLD%^%^RED%^Setting spellname spell to:%^RESET%^ "+args);

    TP->set("spellmastery_change",time());
    TP->set("spellmastery_spell",args);

    return 1;
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    string *classes,file;
    int i;
    if(!objectp(ob)) { return 0; }

    //Single-class warlocks or warlocks + prestige have no use for this feat.
    //Also true of psion/psywarrior
    if(ob->query_level() == ob->query_prestige_level("warlock") ||
       ob->query_level() == ob->query_prestige_level("psion") ||
       ob->query_level() == ob->query_prestige_level("psywarrior"))
    {
        dest_effect();
        return 0;
    }

    classes = (string *)ob->query_classes();
    for(i=0;i<sizeof(classes);i++)
    {
        file = DIR_CLASSES+"/"+classes[i]+".c";
        if(file->caster_class()) { return ::prerequisites(ob); }
    }
    
    return 0;
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void execute_feat() {
    ::execute_feat();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
