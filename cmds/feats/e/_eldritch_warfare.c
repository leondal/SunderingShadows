#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object *exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("EldritchKnight");
    feat_name("eldritch warfare");
    feat_prereq("Eldritch Knight L4");
    feat_syntax("eldritch_warfare [arcane|divine|spellsong]");
    feat_desc("The eldritch knight becomes one with magic during combat, if they so wish, the knight can divide their attention and cast during combat at the price of potency of their spells.");
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("eldritch_knight") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_eldritch_warfare(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str,"dark black");
}

void execute_feat()
{
    object obj;
    string castmesson, castmessoff, messon, messoff;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(FEATS_D->is_active(caster,"eldritch warfare"))
    {
        switch(TP->query_property("warfare type")){
            case "arcane":
                castmessoff = "You release your concentration on blending martial and arcane prowess.";
                messoff = ""+caster->QCN+" releases "+caster->QP+" concentration on blending the martial and arcane.";
                break;
            case "divine":
                castmessoff = "You release your concentration on blending martial skill and divine power.";
                messoff = ""+caster->QCN+" releases "+caster->QP+" concentration on blending the martial and divine.";
                break;
            case "spellsong":
                castmessoff = "You release your concentration on the warsongs.";
                messoff = ""+caster->QCN+" releases "+caster->QP+" concentration on the warsongs.";
                break;
            default:
                castmessoff = "You release your concentration on enspelling the martial form.";
                messoff = ""+caster->QCN+" releases "+caster->QP+" concentration on enspelling the martial form.";
                break;
        }
        obj = query_active_feat("eldritch warfare");
        tell_object(caster,cm(castmessoff));
        tell_room(place,cm(messoff), caster);
        caster->remove_property("warfare type");
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    switch(arg){
        case "arcane":
            castmesson = "You concentrate on blending your martial skill and arcane prowess.";
            messon = ""+caster->QCN+" starts to concentrate on blending "+caster->QP+" martial and arcane prowess.";
            break;
        case "divine":
            castmesson = "You concentrate on blending your martial skill and divine power.";
            messon = ""+caster->QCN+" starts to concentrate on blending "+caster->QP+" martial and divine power.";
            break;
        case "spellsong":
            castmesson = "You concentrate on your warsongs, starting to move rhythmically.";
            messon = ""+caster->QCN+" starts moving rhythmically in unison with "+caster->QP+" warsongs.";
            break;
        default:
            castmesson = "You concentrate on enspelling your martial form.";
            messon = ""+caster->QCN+" starts to concentrate on enspelling "+caster->QP+" martial form.";
            break;
    }

    tell_object(caster,cm(castmesson));
    tell_room(place,cm(messon), caster);
    caster->set_property("active_feats",({TO}));
    caster->set_property("cast and attack",1);
    caster->set_property("warfare type", arg);
    return;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("active_feats",({TO}));
        caster->remove_property("cast and attack");
        tell_object(caster,"%^BOLD%^%^BLUE%^Your concentration on eldritch warfare fades.");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
