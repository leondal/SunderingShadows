#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <class_types.h>
#include <feats.h>
#include <schoolspells.h>

inherit DAEMON;

nosave mapping __ALL_FEATS;
nosave mapping __USABLE_FEATS;

/**
 * Checks for any class feat changes
 */
void validate_class_feats(object ob)
{
    string fname, * myclassfeats, * classfeats, * toremove = ({}), * toadd = ({});

    if (!objectp(ob)) {
        return;
    }
    if (!userp(ob)) {
        return;
    }

    myclassfeats = collapse_array(values(ob->query_class_feats()));
    classfeats = get_all_class_feats(ob);

    if (!sizeof(myclassfeats)) {
        return;
    }

    if (!sizeof(classfeats)) {
        return;
    }

    foreach(fname in myclassfeats)
    {
        if (member_array(fname, classfeats) == -1) {
            toremove += ({ fname });
        }
    }
    foreach(fname in classfeats)
    {
        if (member_array(fname, myclassfeats) == -1) {
            toadd += ({ fname });
        }
    }
    if (sizeof(toremove)) {
        tell_object(ob, "%^BOLD%^%^RED%^\nYou have class feats that don't belong to any of your classes: %^RESET%^" + implode(toremove, ", "));
        tell_object(ob, "%^BOLD%^%^RED%^These feats will be removed.\n");
        foreach(fname in toremove)
        {
            tell_object(ob,"%^BOLD%^%^RED%^Removing:%^RESET%^ " + fname);
            remove_feat(ob, "class", fname);
        }
        ob->delete("free_feat_wipe");
    }
    if (sizeof(toadd)) {
        "/cmds/mortal/_feats"->cmd_feats("fix");
    }
}

void obsolete_feat(object ob) {
    string mytype, * obsolete, * bad_feats=({}), * removing_feats, * myspells, * schoolspells;
    int i, j, num, freebs;
    object feat_ob;

    if (!objectp(ob)) {
        return;
    }
    if (!userp(ob)) {
        return;
    }
    if (!userp(ob)) {
        return;
    }

    obsolete = ({ "greater spell focus", "crushingstrike", "lightning reflexes", "iron will", "great fortitude", "blade block", "unassailable parry", "greater two weapon fighting", "two weapon defense", "calm", "rapid shot", "wild shape dragon", "hardenedminions", "slippery caster", "thick skinned caster", "wild shape wolf", "archmage", "body cognition", "chronicler", "presence of mind", "shadow adept", "shadowdancer", "stalwart", "versatile arcanist", "wild shape dragon", "wild shape elemental", "eschew materials", "fated", });

    for (i = 0; i < sizeof(obsolete); i++) {
        if (has_feat(ob, obsolete[i])) {
            bad_feats += ({ obsolete[i] });
        }
    }
    if (!sizeof(bad_feats)) {
        return;
    }

    num = ob->query("free_feats");
    freebs = num;

    for(i=0;i<sizeof(bad_feats);i++) {
        switch(bad_feats[i]) {

        case "greater spell focus":

            removing_feats = ({ "armored caster","greater spell penetration","spell penetration","greater spell focus" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^RED%^%^BOLD%^The feat Greater Spell Focus has been marked "
                    "as obsolete and you have had the feats in the MagicAccuracy tree refunded.  For "
                    "each feat that you had in this tree you will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the MagicAccuracy tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "crushingstrike":

            removing_feats = ({ "crushingstrike","blade block","impale","light weapon","sweepingblow" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^RED%^%^BOLD%^The feat CrushingStrike has been marked "
                    "as obsolete and you have had the feats in the TwoHandedWeapons tree refunded.  For "
                    "each feat that you had in this tree you will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the TwoHandedWeapons tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "lightning reflexes": case "iron will": case "great fortitude":

            removing_feats = ({ "lightning reflexes","iron will","great fortitude","improved resistance","increased resistance" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^RED%^%^BOLD%^The feats Great Fortitude, Iron Will and "
                    "Lightning Reflexes have been marked as obsolete and you have had the feats in "
                    "the MagicResistance tree refunded.  For each feat that you had in this tree you "
                    "will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the MagicResistance tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "blade block": //revoking blade block for those now with the fighter or cavalier class parry feat

            if(has_feat(ob,"blade block") && has_feat(ob,"parry")) {
              mytype = get_feat_type(ob,"blade block");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"blade block",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^blade block");
              tell_object(ob,"%^RED%^%^BOLD%^The feat Blade Block has been removed from your "
                    "list now that the fighter/cavalier class feat Parry is able to substitute for it.  "
                    "You have been refunded a free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "unassailable parry": //revoking feat for those now with the fighter or cavalier class parry feat

            if(has_feat(ob,"unassailable parry") && has_feat(ob,"parry")) {
              mytype = get_feat_type(ob,"unassailable parry");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              if(mytype != "class") { // had to put this in cuz fighter/ranger multis were freaking out with the class feat! N, 6/15.
                remove_my_feat(ob,"unassailable parry",1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^unassailable parry");
                tell_object(ob,"%^RED%^%^BOLD%^The feat Unassailable Parry has been removed from your "
                    "list now that the fighter/cavalier class feat Parry is able to substitute for it.  "
                    "You have been refunded a free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
              }
            }
            freebs = num;
            break;

        case "greater two weapon fighting": case "two weapon defense": //revising dual-wield tree feats

            removing_feats = ({ "greater two weapon fighting","two weapon defense" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
              tell_object(ob,"%^RED%^%^BOLD%^The upper dual-wield tree feats have been revised, "
                    "and the obsolete ones have been removed from your list.  You have been refunded "
                    "equivalent free feat/s to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "calm": //revoking feat from non-bards

            if(has_feat(ob,"calm") && !ob->is_class("bard")) {
              mytype = get_feat_type(ob,"calm");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"calm",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^calm");
              tell_object(ob,"%^RED%^%^BOLD%^The feat Calm has been removed from your "
                    "list as it is restricted to the bard class only.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "stalwart": //revoking feat from non-inquises

            if (has_feat(ob, "stalwart") && !ob->is_class("inquisitor")) {
                mytype = get_feat_type(ob, "stalwart");
                if (mytype == "other") {
                    num++;
                }
                remove_my_feat(ob, "stalwart", 1);
                tell_object(ob, "%^YELLOW%^Removing feat %^BLUE%^stalwart");
                tell_object(ob, "%^RED%^%^BOLD%^The feat stalwart has been removed from your list as it is restricted to the inquisitor class only. You have been refunded a free feat to spend that will cost you no experience points. Type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats", num);
            }

            freebs = num;
            break;

        case "rapid shot": //revoking redundant archery feat

            if(has_feat(ob,"rapid shot")) {
              mytype = get_feat_type(ob,"rapid shot");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"rapid shot",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^rapid shot");
              tell_object(ob,"%^RED%^%^BOLD%^The feat Rapid Shot has been removed from "
                    "your list as it is no longer in game.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "wild shape dragon": //revoking from non-hms if they had it before it was transferred.

            if(has_feat(ob,"wild shape dragon") && !high_mortalp(ob) && CONFIG_D->check_config("HM") == 0) {
              mytype = get_feat_type(ob,"wild shape dragon");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"wild shape dragon",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^wild shape dragon");
              tell_object(ob,"%^RED%^%^BOLD%^The feat Wild Shape dragon has been removed from "
                    "your list as you are not a HM with access to it.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "hardenedminions": //revoking from those without the new pre-reqs.

            if(has_feat(ob,"hardenedminions") && !has_feat(ob,"spell power")) {
              mytype = get_feat_type(ob,"hardenedminions");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"hardenedminions",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^hardenedminions");
              tell_object(ob,"%^RED%^%^BOLD%^The feat Hardenedminions has been changed "
                    "to the spellpower tree and has new pre-requisites.  You may have been refunded a "
                    "free feat (if bought with levelling feats) to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "slippery caster": //removing upper magicprot tree

            removing_feats = ({ "slippery caster","tough skin","armoredtitan" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            // and since class feats can't be run through remove_my_feat:
            if(has_feat(ob,"thick skinned caster")) {
                mytype = get_feat_type(ob,"thick skinned caster");
                if(mytype == "class") {
                  remove_feat(ob,"class","thick skinned caster");
                  tell_object(ob,"%^YELLOW%^Removing class feat %^BLUE%^thick skinned caster");
                }
            }
            if(num > freebs) {
              tell_object(ob,"%^RED%^%^BOLD%^The MagicProtection feats tree has been removed, "
                    "and the obsolete ones have been removed from your list.  You have been refunded "
                    "equivalent free feat/s to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "thick skinned caster": //had to add this as an extra for those who paid for the feat rather than got it free

            if(has_feat(ob,"thick skinned caster")) {
                mytype = get_feat_type(ob,"thick skinned caster");
                if(mytype == "class") continue; // let this be removed elsewhere (or just left alone, not hurting anything)
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,"thick skinned caster",1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
              tell_object(ob,"%^RED%^%^BOLD%^The MagicProtection feats tree has been removed, "
                    "and since you had paid to buy 'thick skinned caster', you have been refunded an "
                    "equivalent free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "wild shape wolf":

            removing_feats = ({ "wild shape cat","wild shape large animal","wild shape bear","wild shape small animal","wild shape wolf" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            tell_object(ob,"%^RED%^%^BOLD%^The class-based 'wild shape' feats have been marked "
                    "as obsolete and you have had the feats in that tree removed.  As these were all class "
                    "levelling feats, no free feats have been provided to replace them.  You may, however, "
                    "wish to <feats fix> as the druid class now has a new set of levelling feats.%^RESET%^");
            break;

        case "eschew materials":
            remove_my_feat(ob,"eschew materials",1);
            ob->set("free_feats",1);
            tell_object(ob,"%^BOLD%^%^MAGENTA%^Your feat eschew materials%^MAGENTA%^ has been refunded.%^RESET%^");
            break;

        case "archmage":
        case "body cognition":
        case "chronicler":
        case "presence of mind":
        case "shadow adept":
        case "shadowdancer":
        case "versatile arcanist":
        case "wild shape dragon":
        case "wild shape elemental":

            removing_feats = ({ "archmage","body cognition","chronicler","presence of mind","shadow adept",
                    "shadowdancer", "versatile arcanist","wild shape dragon","wild shape elemental" });
        for (j = 0; j < sizeof(removing_feats); j++) {
            if (!has_feat(ob, removing_feats[j])) {
                continue;
            }

            feat_ob = find_object_or_load("/cmds/feats/" + removing_feats[j][0..0] + "/_" + replace_string(removing_feats[j], " ", "_") + ".c");
            if (objectp(feat_ob)) {
                if (feat_ob->is_obsolete() || !feat_ob->prerequisites(ob)) {
                    remove_my_feat(ob, removing_feats[j], 1);
                    if (removing_feats[j] == "archmage") {
                        ob->delete("spellmastery_spell");
                    }
                    if (removing_feats[j] == "shadowdancer") {
                        ob->InitInnate();
                    }

                    tell_object(ob, "%^YELLOW%^Removing feat %^BLUE%^" + removing_feats[j] + "");
                    num++;
                }
            }
        }
        update_usable(ob);

            if (num > freebs) {
                tell_object(ob, "%^RED%^%^BOLD%^Most of the epic feats have been removed and "
                            "converted into prestige classes instead.  Receiving free feats for epic feats that "
                            "you lost.%^RESET%^");
                ob->set("free_feats", num);
            }
            break;

        default:
            return;
        }
    }
    return;
}

void clear_usable_feats()
{
    __USABLE_FEATS = ([]);
    return;
}

int can_gain_type_feat(object ob, string feat, string feattype)
{
    int MAX_ALLOWED, GAINED;
    if (!objectp(ob)) { return 0; }
    if (!stringp(feat)) { return 0; }
    if (has_feat(ob, feat)) { return 0; }
    if (!meets_requirements(ob, feat)) { return 0; }

    switch (feattype) {
    case "class":
        MAX_ALLOWED = (ob->query_highest_level() / 3) + 1;
        GAINED = ob->query_other_feats_gained();
        break;
    case "racial":
        MAX_ALLOWED = racial_bonus_feats(ob);
        GAINED = ob->query_racial_feats_gained();
        break;
    case "martial":
        MAX_ALLOWED = number_feats(ob, "martial", MELEECLASSES);
        GAINED = ob->query_bonus_feats_gained();
        break;
    case "spellcraft":
        MAX_ALLOWED = number_feats(ob, "spellcraft", CASTERCLASSES);
        GAINED = ob->query_magic_feats_gained();
        break;
    case "hybrid":
        MAX_ALLOWED = number_feats(ob, "hybrid", HYBRIDCLASSES);
        GAINED = ob->query_hybrid_feats_gained();
        break;
    case "arcana":
        MAX_ALLOWED = number_feats(ob, "arcana", ({ "magus" }));// (ob->query_class_level("magus") / 3);
        GAINED = ob->query_arcana_feats_gained();
        break;
    case "divinebond":
        MAX_ALLOWED = number_feats(ob, "divinebond", ({ "paladin" }));
        GAINED = ob->query_divinebond_feats_gained();
        break;
    case "rage":
        MAX_ALLOWED = number_feats(ob, "rage", ({ "barbarian" }));
        GAINED = ob->query_rage_feats_gained();
        break;
    default:
        MAX_ALLOWED = 0;
        GAINED = 0;
        break;
    }

    if (GAINED >= MAX_ALLOWED) { return 0; }
    return 1;
}

mixed identify_hybrid() { return HYBRID; }

int add_my_feat(object ob, string type, string feat)
{
    int allowed, num, level, i, num_feats, mod;
    string * subset;
    if(!objectp(ob)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!stringp(feat)) { return 0; }

    level = ob->query_other_feats_gained();
    if(!level) { level = 1; }
    else { level = level * 3; }

    switch(type)
    {
    case "class":
        if(gain_feat(ob,type,feat,ob->query_character_level()))
        {
            num = ob->query_class_feats_gained();
            if(!num) num = 0;
            num += 1;
            ob->set_class_feats_gained(num);
            update_usable(ob);
            if(feat == "grandmaster of the way")
                ob->init_ki();
            return 1;
        }
        else return 0;
    case "racial":
        num = 1;
        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = ob->query_racial_feats_gained();
            num += 1;
            ob->set_racial_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "martial":
        num = 1;
        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = ob->query_bonus_feats_gained();
            num += 1;
            ob->set_bonus_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "magic":
        num = 1;
        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = ob->query_magic_feats_gained();
            num += 1;
            ob->set_magic_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "hybrid":
        num = 1;
        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = ob->query_hybrid_feats_gained();
            num += 1;
            ob->set_hybrid_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "arcana":
        num = 1;
        if (gain_feat(ob, type, feat, num))
        {
            num = 0;
            num = ob->query_arcana_feats_gained();
            num += 1;
            ob->set_arcana_feats_gained(num);
            if (feat == "greater arcane pool")
                USER_D->init_pool(ob, "arcana");
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "divinebond":
        num = 1;
        if (gain_feat(ob, type, feat, num))
        {
            num = 0;
            num = ob->query_divinebond_feats_gained();
            num += 1;
            ob->set_divinebond_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "rage":
        num = 1;
        if (gain_feat(ob, type, feat, num))
        {
            num = 0;
            num = ob->query_rage_feats_gained();
            num += 1;
            ob->set_rage_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "other":
        if(gain_feat(ob,type,feat,level))
        {
            num = ob->query_other_feats_gained();
            if(!num) num = 0;
            num += 1;
            ob->set_other_feats_gained(num);
            if(get_category(feat) == "EpicFeats") { // to track
              num = ob->query_epic_feats_gained();
              if(!num) num = 0;
              num += 1;
              ob->set_epic_feats_gained(num);
            }
            update_usable(ob);
            return 1;
        }
        else return 0;

    default:
        return 0;
    }
    return 0;
}

int remove_my_feat(object ob,string feat,int bypass)
{
    string type;
    int num;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!bypass && !can_remove_feat(ob,feat)) { return 0; }
    type = get_feat_type(ob,feat);
    if(type == "class") { return 0; }
    remove_feat(ob,type,feat);
    switch(type)
    {
    case "racial":
        num = ob->query_racial_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_racial_feats_gained(num);
        update_usable(ob);
        return 1;
    case "martial":
        num = ob->query_bonus_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_bonus_feats_gained(num);
        update_usable(ob);
        return 1;
    case "magic":
        num = ob->query_magic_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_magic_feats_gained(num);
        update_usable(ob);
        return 1;
    case "hybrid":
        num = ob->query_hybrid_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_hybrid_feats_gained(num);
        update_usable(ob);
        return 1;
    case "arcana":
        num = ob->query_arcana_feats_gained();
        if (!num) num = 0;
        num -= 1;
        ob->set_arcana_feats_gained(num);
        if (feat == "greater arcane pool")
            USER_D->init_pool(ob, "arcana");
        update_usable(ob);
        return 1;
    case "divinebond":
        num = ob->query_divinebond_feats_gained();
        if (!num) num = 0;
        num -= 1;
        ob->set_divinebond_feats_gained(num);
        update_usable(ob);
        return 1;
    case "rage":
        num = ob->query_rage_feats_gained();
        if (!num) num = 0;
        num -= 1;
        ob->set_rage_feats_gained(num);
        update_usable(ob);
        return 1;
    case "other":
        num = ob->query_other_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_other_feats_gained(num);
        if(get_category(feat) == "EpicFeats") { // to track
          num = ob->query_epic_feats_gained();
          if(!num) num = 0;
          num -= 1;
          ob->set_epic_feats_gained(num);
        }
        update_usable(ob);
        return 1;
    }
    return 1;
}

int can_remove_feat(object ob,string feat)
{
    object myfeat;
    string *needed_feats,file,*player_feats, *replaced_by;
    int i;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!has_feat(ob,feat)) { return 0; }
    if(member_array(feat,get_all_removable_feats(ob)) == -1) { return 0; }
    file = DIR_FEATS+"/"+feat[0..0]+"/_"+feat+".c";
    //if(find_player("saide")) tell_object(find_player("saide"), "file = "+file);
    file = replace_string(file," ","_");
    if(catch(myfeat = new(file))) { return 0; }
    if(!objectp(myfeat)) { return 0; }
    needed_feats = myfeat->query_required_for();
    replaced_by = myfeat->query_replaced_by();
    destruct(myfeat);

    player_feats = (string *)ob->query_player_feats();
    if(pointerp(replaced_by) && sizeof(replaced_by)) { if(sizeof(player_feats - replaced_by) != sizeof(player_feats)) return 1; }
    if(pointerp(player_feats) && sizeof(player_feats))
    {
        for(i=0;i<sizeof(player_feats);i++)
        {
            if(player_feats[i] == feat) { continue; }

            if(member_array(player_feats[i],needed_feats) != -1)
            {

                return 0;
            }
        }
    }
    return 1;
}

string* get_all_removable_feats(object ob)
{
    string* feats, * cls_feats = ({}), * classes, file, myspec;
    int i;

    if (!objectp(ob)) {
        return ({});
    }
    classes = ob->query_classes();
    for (i = 0; i < sizeof(classes); i++) {
        myspec = ob->query_combat_spec(classes[i]);
        file = DIR_CLASSES + "/" + classes[i] + ".c";
        cls_feats += class_feat_array(classes[i], myspec, ob);
    }
    feats = (string*)ob->query_player_feats();
    feats -= cls_feats;
    return feats;
}

string* get_all_class_feats(object ob)
{
    string* feats, * cls_feats = ({}), * classes, file, myspec;
    int i;

    if (!objectp(ob)) {
        return ({});
    }
    classes = ob->query_classes();
    for (i = 0; i < sizeof(classes); i++) {
        myspec = ob->query_combat_spec(classes[i]);
        file = DIR_CLASSES + "/" + classes[i] + ".c";
        cls_feats += class_feat_array(classes[i], myspec, ob);
    }
    feats = cls_feats;
    return feats;
}

void update_usable(object ob)
{
    __USABLE_FEATS[ob->query_name()] = ({});
    return;
}

mixed get_usable(object ob)
{
    if(__USABLE_FEATS[ob->query_name()]) return __USABLE_FEATS[ob->query_name()];
}

// gain_feat(player,(class bonus other), feat, level
varargs int gain_feat(object ob, string type, string feat,int level)
{
    if(!objectp(ob)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!stringp(feat)) { return 0; }

    if(has_feat(ob,feat)) { return 0; }

    if(!meets_requirements(ob,feat))
    {
        tell_object(ob,"You do not meet the prerequisites for the "
            "feat "+feat+".");
        return 0;
    }
    if(get_category(feat) == "EpicFeats" && ob->query_epic_feats_gained() > 0) {
        tell_object(ob,"You have already bought one epic feat, you can't buy another.");
        return 0;
    }
    if(member_array(type,({"class","racial","martial","magic","other","hybrid","arcana","divinebond" })) == -1) { return 0; }

    add_feat(ob,type,feat,level);

    return 1;
}

int meets_requirements(object ob, string feat)
{
    object obj;
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))          { return 0; }
    if(catch(obj = new(file)))      { return 0; }
    if(!obj->prerequisites(ob))    { return 0; }
    obj->dest_effect();
    if(objectp(obj)) obj->remove();
    return 1;
}

int display_meets_requirements(string feat, object ob)
{
	int x;
	if(!objectp(ob)) return 0;
	if(!stringp(feat)) return 0;
	return meets_requirements(ob, feat);
}

int display_is_active(string feat, object ob)
{
    int x;
    if (!objectp(ob)) return 0;
    if (!stringp(feat)) return 0;
    return is_active(ob, feat);
}

int display_is_activable(string feat, object ob)
{
    int x;
    if (!objectp(ob)) return 0;
    if (!stringp(feat)) return 0;
    if (pick_color(feat, ob) == "%^BOLD%^%^CYAN%^") return 1;
    if (pick_color(feat, ob) == "%^YELLOW%^") return 1;
    return 0;
}

int display_is_known(string feat, object ob)
{
    if(!objectp(ob) || !stringp(feat))
        return 0;
    
    return has_feat(ob, feat);
}

int filter_feats(object ob, string feat)
{
    object obj;
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))          { return 0; }
    if(catch(obj = new(file)))      { return 0; }
//    if(!obj->prerequisites(ob))    { return 0; }
    obj->dest_effect();
    if(objectp(obj)) obj->remove();
    return 1;
}

int display_filtered_feats(string feat, object ob)
{
    int x;
	if(!objectp(ob)) return 0;
	if(!stringp(feat)) return 0;
	return filter_feats(ob, feat);
}

int is_temporary(object ob,string feat)
{
    string *tmp_feats = ({});

    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!is_feat(feat)) { return 0; }

    tmp_feats = (string*)ob->query_temporary_feats();

    if(member_array(feat,tmp_feats) == -1) { return 0; }

    if(!has_feat(ob,feat)) { return 1; }

    ob->clear_temporary_feats();

    if(!usable_feat(ob,feat)) { return 1; }

    ob->set_temporary_feats(tmp_feats);

    return 0;
}

int is_active(object ob,string feat)
{
    object *feats;
    string *names=({}),name;
    int i;

    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(!has_feat(ob,feat))              { return 0; }

    feats = (object *)ob->query_property("active_feats");
    if(!pointerp(feats))                { return 0; }
    if(!sizeof(feats))                  { return 0; }
    for(i=0;i<sizeof(feats);i++)
    {
        if(!objectp(feats[i])) { continue; }
        names += ({ (string)feats[i]->query_feat_name() });
    }
    if(member_array(feat,names) == -1)  { return 0; }
    return 1;
}

void reverse_permanent_feat(object ob,string feat)
{
    string file;
    int i;

    if(!objectp(ob))            { return; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))      { return; }
    if(!is_permanent(ob,feat))  { return; }
    file->reverse_permanent_effects(ob);
    file->dest_effect();
    return;
}

void execute_permanent_feat(object ob,string feat)
{
    string file;
    int i;

    if(!objectp(ob))            { return; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))      { return; }
    if(!is_permanent(ob,feat))  { return; }
    file->permanent_effects(ob);
    file->dest_effect();
    return;
}

int is_permanent(object ob,string feat)
{
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file->is_permanent_feat())  { return 0; }
    file->dest_effect();
    return 1;
}

int can_use_feat(object ob,string feat)
{
    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(is_temporary(ob,feat))           { return 1; }
    if(!meets_requirements(ob,feat))    { return 0; }
    return 1;
}

int usable_feat(object ob,string feat)
{
    string *tmp,*feats;
    int i;

    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(!userp(ob))
    {
        tmp = (string *)ob->query_monster_feats();
        if(!sizeof(tmp)) { return 0; }
        if(member_array(feat,tmp) == -1) { return 0; }
        else { return 1; }
    }
    if(!ob->query("new_class_type"))    { return 0; }

    feats = (string*)ob->query_temporary_feats();
    if(sizeof(feats))
    {
        if(member_array(feat,feats) != -1) { return 1; }
    }

    if(!avatarp(ob))
    {
        if(pointerp(__USABLE_FEATS[ob->query_name()]))
        {
            if(member_array(feat,__USABLE_FEATS[ob->query_name()]) != -1) { return 1; }
        }
    }

    if (avatarp(ob) && !ob->query("persona") && !ob->query("testing")) {
        return 1;
    }

    if (!userp(ob)) {
        return 1;
    }
    if (!has_feat(ob, feat)) {
        return 0;
    }
    if (!can_use_shifted(ob, feat)) {
        return 0;
    }
    if (!can_use_feat(ob, feat)) {
        return 0;
    }
    if (!level_to_use(ob, feat)) {
        return 0;
    }

    if(!mapp(__USABLE_FEATS)) { __USABLE_FEATS = ([]); }
    if(!pointerp(__USABLE_FEATS[ob->query_name()])) { __USABLE_FEATS[ob->query_name()] = ({}); }
    __USABLE_FEATS[ob->query_name()] += ({ feat });

    return 1;
}

int level_to_use(object ob,string feat)
{
    mapping player;
    int feat_level,player_level;

    if(!objectp(ob))        { return 0; }
    if(!stringp(feat))      { return 0; }
    if(!has_feat(ob,feat))  { return 0; }

    player       = player_data(ob);
    player_level = player["level"];
    feat_level   = level_of_feat(ob,feat);
    if(feat_level == -1)    { return 0; }
    if(feat_level > player_level) { return 0; }
    return 1;
}

int can_use_shifted(object ob, string feat)
{
    string file;

    if (!objectp(ob)) {
        return 0;
    }
    if (!has_feat(ob, feat)) {
        return 0;
    }

    if (!ob->query_property("shapeshifted")) {
        return 1;
    }                                                     // not shifted, don't bother to check

    file = DIR_FEATS + "/" + feat[0..0] + "/_" + feat + ".c";
    file = replace_string(file, " ", "_");

    if (file->allow_shifted()) {
        return 1;
    }

    return 0;
}

int level_of_feat(object ob,string feat)
{
    mapping feats;
    string type,*tmp;
    int *levels,level,i;

    if(!objectp(ob))          { return -1; }
    if(!stringp(feat))        { return -1; }
    if(is_temporary(ob,feat)) { return ob->query_character_level(); }
    if(!has_feat(ob,feat))    { return -1; }
    type   = get_feat_type(ob,feat);
    feats  = get_feats(ob,type);
    levels = keys(feats);
    if(!pointerp(levels))     { return -1; }
    if(!sizeof(levels))       { return -1; }
    for(i=0;i<sizeof(levels);i++)
    {
        tmp = feats[levels[i]];
        if(!pointerp(tmp)) { continue; }
        if(member_array(feat,tmp) == -1) { continue; }
        level = levels[i];
        return level;
    }

}

int has_feat(object ob, string feat)
{
    string* feats;
    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!is_feat(feat)) {
        return 0;
    }
    if (userp(ob)) {
        feats = ob->query_player_feats();
    }else {
        feats = ob->query_monster_feats();
    }
    if (!pointerp(feats)) {
        return 0;
    }
    if (!sizeof(feats)) {
        return 0;
    }
    if (member_array(feat, feats) == -1) {
        return 0;
    }
    return 1;
}

int is_feat(string feat)
{
    mapping tmp;
    string *feats=({}),*cats,*hold;
    int i,j;

    tmp = get_all_feats();
    if(!mapp(tmp))      { return 0; }
    //this should be doing the same thing - but hopefully will cut down on
    //processing time and too long evaluation errors - Saide April 2016
    cats = values(tmp);
    if(!pointerp(cats)) { return 0; }
    for(i=0;i<sizeof(cats);i++)
    {
        if(member_array(feat, cats[i]) != -1) { return 1; }
        continue;
    }
    return 0;

    /*cats = keys(tmp);
    if(!sizeof(cats))   { return 0; }
    for(i=0;i<sizeof(cats);i++)
    {
        hold = tmp[cats[i]];
        if(!pointerp(hold)) { continue; }
        if(!sizeof(hold))   { continue; }
        for(j=0;j<sizeof(hold);j++)
        {
            feats += ({ hold[j] });
        }
    }
    if(member_array(feat,feats) == -1) { return 0; }
    return 1;*/
}

string get_feat_type(object ob,string feat)
{
    mapping feats;
    string type,*tmp,*types;
    int i,j;

    if(!objectp(ob))        { return 0; }
    if(!stringp(feat))      { return 0; }
    if(!has_feat(ob,feat))  { return 0; }
    if(!is_feat(feat))      { return 0; }
    tmp = ({ "class","racial","martial","magic","other","hybrid","arcana","divinebond" });
    for(i=0;i<sizeof(tmp);i++)
    {
        feats = get_feats(ob,tmp[i]);
        types  = keys(feats);
        if(!sizeof(types)) { continue; }
        for(j=0;j<sizeof(types);j++)
        {
            if(!pointerp(feats[types[j]])) { continue; }
            if(member_array(feat,feats[types[j]]) != -1) { return tmp[i]; }
        }
    }
    return 0;
}

void remove_feat(object ob, string type, string feat)
{
    mapping feats;
    int* levels, i, level;
    string* tmp;

    if (!objectp(ob)) {
        return;
    }
    if (!stringp(type)) {
        return;
    }

    if (!stringp(feat)) {
        return;
    }

    feats = get_feats(ob, type);
    levels = keys(feats);
    level = -1;
    if (!sizeof(levels)) {
        return;
    }
    for (i = 0; i < sizeof(levels) && level == -1; i++) {
        tmp = feats[levels[i]];
        if (member_array(feat, tmp) != -1) {
            level = levels[i];
        }
    }
    tmp -= ({ feat });
    feats[level] = tmp;
    if (is_feat(feat)) {
        if (is_permanent(ob, feat)) {
            reverse_permanent_feat(ob, feat);
        }
    }

    set_feats(ob, type, feats);
    //redundant since query_player_feat works entirely differently now - Saide
    //take_feat(ob,feat);
    return;
}

varargs void add_feat(object ob, string type, string feat,int level)
{
    mapping feats,player;
    int num;
    if(!objectp(ob))        { return; }
    if(!stringp(type))      { return; }
    if(!stringp(feat))      { return; }
    if(!is_feat(feat))      { return; }
    if(has_feat(ob,feat))   { return; }

    feats  = get_feats(ob,type);
    player = player_data(ob);

    if(level) { num = level; }
    else { num = player["level"]; }
    if(!pointerp(feats[num])) { feats[num] = ({ feat }); }
    else { feats[num] += ({ feat }); }
    if(is_permanent(ob,feat)) { execute_permanent_feat(ob,feat); }

    set_feats(ob,type,feats);

    return;
}

void give_feat(object ob,string feat)
{
    string *feats;
    if(!objectp(ob))    { return; }
    if(!stringp(feat))  { return; }
    feats = ob->query_player_feats();
    feats += ({ feat });
    ob->set_player_feats(feats);
    return;
}

void take_feat(object ob,string feat)
{
    string *feats;
    if(!objectp(ob))    { return; }
    if(!stringp(feat))  { return; }
    feats = ob->query_player_feats();
    feats -= ({ feat });
    ob->set_player_feats(feats);
    return;
}

void set_feats(object ob,string type,mapping feats)
{
    if(!objectp(ob))    { return; }
    if(!stringp(type))  { return; }
    if(!mapp(feats))    { return; }

    switch(type)
    {
    case "class":
        ob->set_class_feats(feats);
        break;
    case "racial":
        ob->set_racial_feats(feats);
        break;
    case "martial":
        ob->set_bonus_feats(feats);
        break;
    case "magic":
        ob->set_magic_feats(feats);
        break;
    case "hybrid":
        ob->set_hybrid_feats(feats);
        break;
    case "arcana":
        ob->set_arcana_feats(feats);
        break;
    case "divinebond":
        ob->set_divinebond_feats(feats);
        break;
    case "rage":
        ob->set_rage_feats(feats);
        break;
    case "talent":
        ob->set_talent_feats(feats);
        break;
    case "other":
        ob->set_other_feats(feats);
        break;
    }
    return;
}

mapping get_feats(object ob,string type)
{
    mapping feats;
    if(!objectp(ob)) { return ([]); }
    switch(type)
    {
    case "class":
        feats = ob->query_class_feats();
        break;
    case "racial":
        feats = ob->query_racial_feats();
        break;
    case "martial":
        feats = ob->query_bonus_feats();
        break;
    case "magic":
        feats = ob->query_magic_feats();
        break;
    case "hybrid":
        feats = ob->query_hybrid_feats();
        break;
    case "arcana":
        feats = ob->query_arcana_feats();
        break;
    case "divinebond":
        feats = ob->query_divinebond_feats();
        break;
    case "rage":
        feats = ob->query_rage_feats();
        break;
    case "talent":
        feats = ob->query_talent_feats();
        break;
    case "other":
        feats = ob->query_other_feats();
        break;
    }
    if(!mapp(feats))
    {
        ob->init_feats();
        return ([]);
    }
    return feats;
}

// expand this if I need it
mapping player_data(object ob)
{
    mapping data;
    data = ([ "level" : ob->query_highest_level(), ]);
    return data;
}

int calculate_psionic_feats(object ob){
   string file, *featies=({});
   object tmp;
   int i, num=0;
   if(!objectp(ob)){ return 0; }
   featies += ob->query_player_feats();
   if(!sizeof(featies)){ return 0; }
   for(i=0;i<sizeof(featies);i++){
      if(!FEATS_D->is_feat(featies[i])) continue;
      file = DIR_FEATS+"/"+featies[i][0..0]+"/_"+featies[i]+".c";
      file = replace_string(file," ","_");
      if(!file_exists(file)) continue;
      if(catch(tmp = new(file))) continue;
      if(tmp->is_psionic_feat()) num++;
      if(objectp(tmp)) tmp->remove();
   }
   return num;
}

void create()
{
    ::create();
    __ALL_FEATS = ([]);
    __USABLE_FEATS = ([]);
    build_feat_list();
}

void build_feat_list()
{
    string* folders = ({}), category, name, file, * files = ({});
    mapping feats = ([]);
    int i, y;

    folders = get_dir(FEAT_FILE);
    if (!sizeof(folders)) {
        // An attempt to make the feat daemon kickstart itself if none of the feats load -Ares
        call_out("create", 5);
        return;
    }
    for (i = 0; i < sizeof(folders); i++) {
        files = get_dir(FEAT_FILE + folders[i] + "/");
        for (y = 0; y < sizeof(files); y++) {
            // hopefully prevent backups an anything not ending in .c from bugging the daemon
            if (strsrch(files[y], ".c") != (strlen(files[y]) - 2)) {
                continue;
            }
            file = FEAT_FILE + "" + folders[i] + "/" + files[y] + "";
            file = replace_string(file, " ", "_");

            // This line tests for feats with errors
            if (catch(category = file->query_feat_category())) {
                continue;
            }
            name = file->query_feat_name();
            file->dest_effect();
            if (!pointerp(feats[category])) {
                feats[category] = ({ name });
            }else {
                feats[category] += ({ name });
            }
        }
    }
    __ALL_FEATS = feats;
    return;
}

string get_category(string featname)
{
    string category,name,file;

    file = FEAT_FILE + featname[0..0]+"/_"+featname+".c";
    file     = replace_string(file," ","_");
    if(!file_exists(file)) return "NIL";
    category = file->query_feat_category();
    name     = file->query_feat_name();
    file->dest_effect();
    if(category != "") return category;
    return name;
}

mapping get_all_feats()
{
    if(!mapp(__ALL_FEATS) || __ALL_FEATS == ([]))
    {
        build_feat_list();
    }
    return __ALL_FEATS;
}

////////////////////////////////////////////////
//  Display related stuff  /////////////////////
////////////////////////////////////////////////

string format_category(string cat)
{
    string *tmp,display;
    int i;

    tmp = explode(cat," ");

    tmp[0] = capitalize(tmp[0]);
    tmp[0] = "%^RESET%^%^MAGENTA%^"+tmp[0]+"%^RESET%^";
    display = "\n"+IDT+arrange_string(tmp[0],(ALIGN_SPACER -1));

    if(sizeof(tmp) == 2)
    {
        tmp[1] = capitalize(tmp[1]);
        tmp[1] = "%^RESET%^%^MAGENTA%^"+tmp[1]+"%^RESET%^";
        display += arrange_string(tmp[1],(ALIGN_SPACER-5));
    }
    return display;
}

string pick_color(string feat, object targ)
{
    int has, active, level_check, permanent, temporary;

    has = has_feat(targ, lower_case(feat));
    active = is_active(targ, lower_case(feat));
    level_check = usable_feat(targ, lower_case(feat));
    permanent = is_permanent(targ, lower_case(feat));
    temporary = is_temporary(targ, lower_case(feat));

    if (temporary) {
        return "%^BOLD%^%^BLUE%^";
    }
    if (!has) {
        return "%^CYAN%^";
    }
    if (!level_check) {
        return "%^RED%^";
    }
    if (permanent) {
        return "%^BOLD%^%^GREEN%^";
    }
    if (active) {
        return "%^YELLOW%^";
    }

    return "%^BOLD%^%^CYAN%^";
}

string format_feat(string feat,object targ) {
    int level,level_check;
    string display,tmp;

    feat = capitalize(feat);
    level_check = can_use_feat(targ, lower_case(feat));
    level = level_of_feat(targ, lower_case(feat));
    if (!level || level == -1) {
        tmp = "%^CYAN%^--";
    } else if (!level_check) {
        tmp = "%^BOLD%^%^RED%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "class")) {
        tmp = "%^BOLD%^%^MAGENTA%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "racial")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "martial")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "spellcraft")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "hybrid")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "arcana")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "divinebond")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "rage")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else if (bought_as_type_feat(feat, targ, "talent")) {
        tmp = "%^BOLD%^%^YELLOW%^" + level + "%^RESET%^";
    } else {
        tmp = "%^CYAN%^" + level + "%^RESET%^";
    }
    if (level && level < 10 && level != -1) {
        tmp = " " + tmp + "";
    }
    display = "%^RESET%^%^BOLD%^ " + tmp + "%^RESET%^ ";
    display += pick_color(feat, targ) + feat + "%^RESET%^";
    return display;
}

int is_feat_obsolete(string feat)
{
    object obj;
    string str;

    str = "/cmds/feats/"+feat[0..0]+"/_";
    //tell_object(find_player("saide"), "str = "+str);
    feat = replace_string(feat," ","_");
    str = str + feat +".c";
    if(!objectp(obj=find_object_or_load(str))) { return 0; }
    if(obj->is_obsolete()) { return 1; }
    return 0;
}

// Designed to dynamically update itself when we add new categories and feats, so we don't have
// to mess with it again.  -Ares
void display_feats(object ob,object targ, string mytype)
{
    int i,j,tmp;
    string *categories,*left_cats=({}),*right_cats=({}),*left_column,*right_column,display_cat,*display_feats,*classes,targ_class;
    string *display = ({}),*temp=({}),*good=({}),*currentlist=({}),*badcategories=({});
    mapping feats=([]),temp_feats=([]);
    object class_ob;

    temp_feats = get_all_feats();
    categories = keys(temp_feats);
    if(!mytype || mytype == "") mytype = "all";
    switch(mytype) {
      case "spellcraft": currentlist += SPELLFEATS; break;
      case "martial": currentlist += MELEEFEATS; break;
      case "hybrid": currentlist += SPELLFEATS; currentlist += MELEEFEATS;  break;
      case "arcana": currentlist += MAGUSFEATS;  break;
      case "divinebond": currentlist += PALADINFEATS;  break;
      case "rage": currentlist += RAGEFEATS; break;
      //case "talent": currentlist += TALENTFEATS; break;
      case "general": currentlist += GENERALFEATS; break;
      case "epic": currentlist += EPICFEATS; break;
      case "prestige": currentlist += PRESTIGE_FEATS; break;
      case "custom":
        if(sizeof(targ->query("custom_feat_array"))) currentlist += targ->query("custom_feat_array"); break;
      case "all": case "allowed": currentlist += SPELLFEATS; currentlist += MELEEFEATS; currentlist += GENERALFEATS; currentlist += MAGUSFEATS; currentlist += PALADINFEATS; currentlist += EPICFEATS; currentlist += PRESTIGE_FEATS; break;
      default: currentlist += SPELLFEATS; currentlist += MELEEFEATS; currentlist += GENERALFEATS; currentlist += MAGUSFEATS; currentlist += PALADINFEATS; currentlist += EPICFEATS; currentlist += PRESTIGE_FEATS; break;
    }

    if (!targ->is_class("bard") && !avatarp(targ)) {
        currentlist -= ({ "Performance" });
    }
    if (!targ->is_class("inquisitor") && !avatarp(targ)) {
        currentlist -= ({ "Inquisition" });
    }
    if (!targ->is_class("monk") && !avatarp(targ)) {
        currentlist -= ({ "KiEnhancement", "KiOffense", "KiDefense"});
    }
    if (!targ->is_class("druid") && !targ->is_class("ranger") && !avatarp(targ)) {
        currentlist -= ({ "WildernessLore", "SavageCombat" });
    }
    if (!targ->is_class("psion") && !targ->is_class("psywarrior") && !avatarp(targ)) {
        currentlist -= ({ "Psionics" });
    }
    if (!targ->is_class("magus") && !avatarp(targ)) {
        currentlist -= ({ "MagusArcana", "Steel&Magic" });
    }
    if (!targ->is_class("paladin") && !avatarp(targ)) {
        currentlist -= ({ "DivineBond" });
    }
    
    if (!targ->is_class("barbarian") && !avatarp(targ)) {
        currentlist -= ({ "RagePower" });
    }
    /*
    if (!targ->is_class("paladin") && !targ->is_class("bard") && !avatarp(targ)) {
        currentlist -= ({ "RogueTalent" });
    }
    */

    classes = targ->query_classes();
    for (i = 0; i < sizeof(PRESTIGE_FEATS); i++) {
        targ_class = PRESTIGE_MAP[PRESTIGE_FEATS[i]];
        if (member_array(targ_class, classes) != -1) {
            continue;
        }
        if (avatarp(targ)) {
            continue;
        }
        currentlist -= ({ PRESTIGE_FEATS[i] });
    }

    for (i = 0; i < sizeof(categories); i++) {
        if (member_array(categories[i], currentlist) != -1) {
            temp = temp_feats[categories[i]];
            //added by saide to allow a player to get only
            //a list of feats they are allowed to take
            if (mytype == "allowed") {
                temp = filter_array(temp, "display_meets_requirements", TO, targ);
            }
            if (mytype == "active") {
                temp = filter_array(temp, "display_is_activable", TO, targ);
            }
            if(mytype == "known")
            {
                temp = filter_array(temp, "display_is_known", this_object(), targ);
            }
            good = ({});
            for (j = 0; j < sizeof(temp); j++) {
                if (is_feat_obsolete(temp[j])) {
                    continue;
                }
                good += ({ temp[j] });
            }
            if (sizeof(good)) {
                feats[categories[i]] = good;
                continue;
            }else {
                badcategories += ({ categories[i] });
            }
            continue;
        }else {
            badcategories += ({ categories[i] });
        }
    }
    if(sizeof(badcategories)) categories -= badcategories;

    if (!objectp(ob)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }

    if (!sizeof(categories) && mytype == "active") {
        tell_object(ob, "%^BOLD%^%^RED%^You don't have any active feats at the moment.%^RESET%^");
        return;
    }

    categories = sort_array(categories, 1);
    {
        int vertical = ob->getenv("VCOLUMNS") ? 1 : 0;
        string * obuff;

        if (vertical) {
            obuff = ({});
            for (i = 0; i < sizeof(categories); i++ )
            {
                obuff += ({"%^BOLD%^%^WHITE%^" + categories[i]});
                obuff += map(sort_array(feats[categories[i]], 1), (: format_feat($1, $2) :),targ);
                obuff += ({" "});
            }
            tell_object(ob, auto_format_page(obuff, ob, 34));
        } else {
            for (i = 0; i < sizeof(categories); i++)
            {
                obuff = map(sort_array(feats[categories[i]], 1), (: format_feat($1, $2) :),targ);
                tell_object(ob, "%^BOLD%^%^WHITE%^" + categories[i]);
                tell_object(ob, auto_format_page(obuff, ob, 34));
            }

        }
    }
    return;
}

////////////////////////////////////////////////
//  End Display related stuff  /////////////////
////////////////////////////////////////////////

string* class_feat_array(string myclass, string spec, object ob)
{
    string file, * feat_array;
    mapping cls_feats;
    int* featkeys, i;

    if (!myclass) {
        return 0;
    }
    file = DIR_CLASSES + "/" + myclass + ".c";
    if (!file_exists(file)) {
        return 0;
    }
    cls_feats = file->class_featmap(spec, ob);
    if (!mapp(cls_feats)) {
        return 0;
    }
    featkeys = keys(cls_feats);
    if (!sizeof(featkeys)) {
        return 0;
    }

    feat_array = ({});
    for (i = 0; i < sizeof(featkeys); i++) {
        feat_array += cls_feats[featkeys[i]];
    }
    return feat_array;
}

int bought_as_type_feat(string feat, object targ, string feattype) {
    string* feat_array;
    mapping type_feats;
    int* featkeys, i;

    feat = lower_case(feat);
    if (!has_feat(targ, feat)) return 0;
    switch (feattype) {
    case "class":
        type_feats = targ->query_class_feats();
        break;
    case "racial":
        type_feats = targ->query_racial_feats();
        break;
    case "martial":
        type_feats = targ->query_bonus_feats();
        break;
    case "spellcraft":
        type_feats = targ->query_magic_feats();
        break;
    case "hybrid":
        type_feats = targ->query_hybrid_feats();
        break;
    case "arcana":
        type_feats = targ->query_arcana_feats();
        break;
    case "divinebond":
        type_feats = targ->query_divinebond_feats();
        break;
    case "rage":
        type_feats = targ->query_rage_feats();
        break;
    case "talent":
        type_feats = targ->query_talent_feats();
        break;
    default:
        type_feats = targ->query_class_feats();
        break;
    }
    if (!mapp(type_feats)) return 0;
    featkeys = keys(type_feats);
    if (!sizeof(featkeys)) return 0;

    feat_array = ({});
    for (i = 0;i < sizeof(featkeys);i++) feat_array += type_feats[featkeys[i]];
    if (!sizeof(feat_array)) return 0;
    if (member_array(feat, feat_array) == -1) return 0;
    return 1;
}

int racial_bonus_feats(object ob) {
    int num = 0;
    string myrace, subrace;
    myrace = ob->query_race();
    subrace = (string)ob->query("subrace");

    if (myrace == "human") { //bonus feat for baseline humans
        if (!subrace || subrace == "" || (subrace != "dhampir" && subrace != "tiefling" && subrace != "aasimar" && subrace != "feytouched" && (strsrch(subrace, "genasi") == -1))) {
            num++;
        }
    }
    return num;
}

int number_feats(object obj, string category, string* valid_classes) {
    string* subset;
    int i, j, BONUS_ALLOWED;
    if (!sizeof(valid_classes)) {
        if (category == "racial") {
            BONUS_ALLOWED = racial_bonus_feats(obj);
        }else {
            BONUS_ALLOWED = (obj->query_highest_level() / 3) + 1;
        }
    }else {
        subset = obj->query_classes();
        if (!sizeof(subset)) {
            tell_object(obj, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return -1;
        }
        for (i = 0; i < sizeof(subset); i++) {
            j = 0;
            if (member_array(subset[i], valid_classes) == -1) {
                continue;
            }
            switch (subset[i]) {
                //martials
            case "fighter":
                j = 1 + ((obj->query_class_level("fighter") + 1) / 2);
                /*
                if (obj->query_class_level("fighter") < 21) {
                    j = (obj->query_class_level(subset[i]) / 2) + 2;
                } else {
                    j = 12 + (((obj->query_class_level(subset[i])) - 16) / 5);
                }
                */
                break;
            case "paladin":
                if (category == "divinebond") {
                    if (obj->query_class_level("paladin") > 4)
                        j = 1;
                    if (obj->query_class_level("paladin") > 20)
                        j = 2;
                }
                else {
                    j = ((obj->query_class_level(subset[i]) - 16) / 5);
                }
                break;
            case "barbarian":
                
                if(category == "rage")
                {
                    if(obj->query_class_level("barbarian") > 5)
                        j = 1;
                    if(obj->query_class_level("barbarian") > 11)
                        j = 2;
                    if(obj->query_class_level("barbarian") > 20)
                        j = 3;
                    if(obj->query_class_level("barbarian") > 30)
                        j = 4;
                }
                else
                    j = ((obj->query_class_level(subset[i]) - 16) / 5);
                break;
            case "thief":
                /*
                if(category == "talent")
                {
                    if(obj->query_class_level("thief") > 5)
                        j = 1;
                    if(obj->query_class_level("thief") > 10)
                        j = 2;
                    if(obj->query_class_level("thief") > 20)
                        j = 3;
                    if(obj->query_class_level("thief") > 30)
                        j = 4;
                }
                    
                else
                */
                    j = ((obj->query_class_level(subset[i]) - 16) / 5);
                break;
            
                //casters
            case "psion":
            case "sorcerer":
            case "mage":
            case "oracle":
            case "cleric":
                j = ((obj->query_class_level(subset[i]) + 4) / 5);
                break;
                //hybrids
            case "magus":
                if (category == "arcana") {
                    j = (obj->query_class_level(subset[i]) / 3);
                }
                else {
                    j = ((obj->query_class_level(subset[i]) + 1) / 6);
                }
                break;
            case "psywarrior":
                if (obj->query_class_level("psywarrior") < 21) {
                    j = (obj->query_class_level(subset[i]) / 3) + 2;
                } else {
                    j = 7 + (((obj->query_class_level(subset[i])) - 16) / 5);
                }
                break;
            case "bard":
                /*
                if(category == "talent")
                {
                    if(obj->query_class_level("bard") > 10)
                        j = 1;
                    if(obj->query_class_level("bard") > 20)
                        j = 2;
                }
                else
                */
                    j = ((obj->query_class_level(subset[i]) - 16) / 5);
                break;
            default:
                j = ((obj->query_class_level(subset[i]) - 16) / 5);
                break;
            }
            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }
    }

    return BONUS_ALLOWED;
}
