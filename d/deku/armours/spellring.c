//An attempt at a ring of spell storing
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/jewelry/ring";

string spell1, spell2, type1, type2;
int spell1_power, spell2_power;

void full();

void create()
{
    ::create();

    set_name("A snow white ring");
    set_id(({"ring","white ring","snow white ring","spell ring",
    "ring of spell storing","spell storing ring"}));
    set_short("%^BOLD%^%^WHITE%^A ring of spell storing%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A snow white ring%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The band of this ring is made from "+
    "a snow white substance.  It is etched with symbols which "+
    "seem to continually ravel and unravel in a slow, surreal "+
    "pattern.  A strange %^CYAN%^blue gem%^BOLD%^%^WHITE%^ "+
    "rests at the top of the band.  Careful observation reveals that "+
    "the gem is, in fact, composed of two chambers.  Each chamber "+
    "contains a seperate gray mist.  The mist swirls continually, "+
    "its speed changing, becoming slower and then faster, until "+
    "reaching a blur before suddenly beginning anew.  Only after "+
    "observing the mist do you catch a glimpse of a phrase "+
    "written on the underside of the band.%^RESET%^ ");

    set_lore("These rings were much more common ages ago.  They "+
    "were originally formed by a group of magi who were set "+
    "in the field of researching the uses and benefits of the "+
    "weave.  They were determined to be mostly safe, "+
    "presenting no more opportunity for abuse than any other "+
    "magical device.  Certain safe guards were placed on the "+
    "remaining few to keep them from becoming articles that "+
    "might be somehow manipulated and eventually abused in "+
    "a way that could not be tolerated.  Those safeguards "+
    "are relatively unknown, but a few of them were "+
    "written into the bands of the remaining rings.  "+
    "The three elven magi known for assisting in their "+
    "creation are rumored to still dwell somewhere in the "+
    "realm of the elves, but they have not been seen in the "+
    "last several centuries.");

    set_property("lore difficulty",8);

    set_language("elven");
    set_read("\n%^RED%^Examine my ring,\n"+
    "\t%^CYAN%^to see what magic it contains. \n%^RESET%^"+
    "%^RED%^Store it with energy, \n"+
    "\t%^CYAN%^but only a fool should try to fill more than the present chambers, \n%^RESET%^"+
    "\t%^CYAN%^and beware, beyond %^YELLOW%^ball lightning%^RESET%^%^CYAN%^ dwells disaster.\n%^RESET%^"+
    "%^RED%^Release it in times of need,\n"+
    "\t%^CYAN%^or release at a target to use its effects upon them.%^RESET%^%^RESET%^");
    set_weight(1);
    set_value(1000);
    set_property("magic nonstacking",1);
}

int isMagic(){ return 1;}

void init() {
    if (!userp(ETO)) return;
    ::init();
    if(living(ETO)) {
        add_action("store_spells","store");
        add_action("release","release");
        add_action("examine","examine");
    }
}

int examine(string str) {
    string tmp;
    if(!str) return 0;
    if(str == "ring" || str == "gem") {
        if(TP->query_bound() || TP->query_unconscious()
            || TP->query_paralyzed()) {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        if(!spell1 && !spell2) {
            tell_object(ETO,"You examine the strange "+
            "blue gem and find nothing of measure.");
            return 1;
        }

        tell_object(ETO,"You examine the strange "+
        "blue gem and realize that some strange "+
        "energy resides within it.\n");

        tmp = "%^RESET%^%^BLUE%^St%^CYAN%^o%^RESET%^%^BLUE%^r%^CYAN%^e%^RESET%^"+
        "%^BLUE%^d%^CYAN%^:  %^BOLD%^%^WHITE%^";

        if(spell1) tell_object(ETO,tmp + capitalize(spell1) +"%^RESET%^\n");
        if(spell2) tell_object(ETO,tmp + capitalize(spell2) + "%^RESET%^\n");
        return 1;
    }
    return 0;
}

string get_spell(string str) {
    if(!str) return 0;
    str = replace_string(str," ","_");
    return "/cmds/spells/"+str[0..0]+"/_"+str+".c";
}

void do_successful_store(int len) {
    tell_object(ETO,"%^RED%^You carefully concentrate on the ring "+
    "and begin muttering incantations.%^RESET%^");
    tell_room(EETO,ETO->QCN+"%^RED%^ focuses on "+ETO->QP+
    " ring and begins muttering incantations.%^RESET%^",ETO);
    ETO->set_paralyzed(len * 8,"%^RED%^You are concentrating "+
    "on storing your spell in the ring.%^RESET%^");
}

void do_disaster_damage(object who, int dam) {
    int x;
    string *contents;
    if(!objectp(who)) return;
    contents = all_living(environment(who));
    contents -= ({who});
    contents = filter_array(contents,"is_non_immortal_player",FILTERS_D);

    tell_object(who,"%^RED%^You are horribly burned by the "+
    "tremendous explosion!%^RESET%^");
    tell_room(environment(who),who->QCN+"%^RED%^ is horribly "+
    "burned by the tremendous explosion!%^RESET%^",who);

    who->do_damage("head",roll_dice(dam,20));
    who->add_attacker(TO);
    who->continue_attack();
    if(objectp(who)) {
        who->remove_attacker(TO);
    }
    for(x = 0;x < sizeof(contents);x++) {
        tell_object(contents[x],"%^RED%^You are scorched by the flames "+
        "from the explosion!%^RESET%^");
        tell_room(environment(contents[x]),contents[x]->QCN+
        "%^RED%^ is scorched by the flames from the explosion!"+
        "%^RESET%^",contents[x]);
        contents[x]->do_damage("head",roll_dice(dam,8));
        contents[x]->add_attacker(TO);
        contents[x]->continue_attack(TO);
        if(objectp(contents[x])) {
            contents[x]->remove_attacker(TO);
        }
    }
}


void do_disaster(object who, int dam, int step) {
    switch(step) {
    case 0:
        do_successful_store(dam);
        call_out("do_disaster",5,who,dam,1);
        break;
    case 1:
        tell_object(who,"%^RED%^You become suddenly confused "+
        "and alarms go off inside your head as you realize "+
        "the power you've tried to toss into the "+
        "ring has overwhelmed it!%^RESET%^");
        tell_room(environment(who),who->QCN+"%^RED%^ opens "+
        who->QP+" mouth in a silent scream!%^RESET%^",who);
        call_out("do_disaster",5,who,dam,2);
        break;
    case 2:
        tell_object(who,"%^RED%^You try to cry out, but "+
        "your voice has failed you, and you watch in horror as "+
        "the tiny ring erupts into a massive explosion!%^RESET%^");
        tell_room(environment(who),who->QCN+"%^RED%^'s ring "+
        "explodes into a massive ball of fire!%^RESET%^",who);
        do_disaster_damage(who,dam);
        break;
    }
}

int store_spells(string str) {
    string spell, file, type, *comps;
    mapping amcomps;
    int x;

    if(!str) {
        write("What spell do you wish to store in the ring? <store spelltype spellname>.\n");
        return 1;
    }
    if(sscanf(str,"%s %s",type,spell) != 2) {
        write("What spell do you wish to store in the ring? <store spelltype spellname>.\n");
        return 1;
    }
    if(!TP->is_class(type)) {
        write("You are not a "+type+"! <store spelltype spellname>\n");
        return 1;
    }
    if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if((int)TP->query_memorized(type,spell) < 1) {
        write("You don't have the spell you are trying to "+
        "store memorized!");
        return 1;
    }
    file = replace_string(spell," ","_");
    file = "/cmds/spells/"+file[0..0]+"/_"+file;
    if(!file_exists(file+".c")) {
        write("You have no knowledge of such a spell.");
        return 1;
    }
    if(file->query_components(type)) {
        comps = keys(file->query_components(type));
    }
    if(sizeof(comps)) {
        for (x = 0;x < sizeof(comps); x++) {
            switch(type) {
                case "bard":
                if((int)present("bard_compx",TP)->query_bard_comp(comps[x]) == 0) {
                    tell_object(ETO,"You lack the needed compositions for the spell!");
                    return 1;
                }
                break;
                case "psion":
                if((int)present("psi_compx",TP)->query_psi_comp(comps[x]) == 0) {
                    tell_object(ETO,"You lack the needed crystals for the spell!");
                    return 1;
                }
                break;
                default:
                if((int)present("compx",TP)->query_comp(comps[x]) == 0) {
                    tell_object(ETO,"You lack the needed components for the spell!");
                    return 1;
                }
                break;
            }
        }
    }
    amcomps = file->query_components(type);
    for (x = 0;x < sizeof(comps); x++) {
        if(!amcomps[comps[x]]) break;
        switch(type) {
            case "bard": present("bard_compx", ETO)->use_bard_comp(comps[x],amcomps[comps[x]]);
            break;
            case "psion": present("psi_compx", ETO)->use_psi_comp(comps[x],amcomps[comps[x]]);
            break;
            default: present("compx", ETO)->use_comp(comps[x],amcomps[comps[x]]);
            break;
        }
    }
    TP->set_memorized(type,spell,-1);

    if((int)file->query_spell_level(type) > 5 || (spell1 && spell2)) {
        do_disaster(ETO,(int)file->query_spell_level(type),0);
        return 1;
    }

    do_successful_store((int)file->query_spell_level(type));

    if(!spell1) {
        spell1 = spell;
        type1 = type;
        spell1_power = to_int(random((int)ETO->query_guild_level(type)) / (random(3) + 1));
        return 1;
    }
    if(!spell2) {
        spell2 = spell;
        type2 = type;
        spell2_power = to_int(random((int)ETO->query_guild_level(type)) / (random(3) + 1));
        return 1;
    }
}

void set_spell(string thetype, string str) {
    string spell;
    str = replace_string(str," ","_");
    spell = "/cmds/spells/"+str[0..0]+"/_"+str;

    if(!file_exists(spell+".c")) {
        write("No Such Spell.");
        return 1;
    }
    if(spell1 && spell2) {
        write("The ring is currently full.");
        return 1;
    }
    if(!spell1) {
        spell1 = str;
        type1 = thetype;
        spell1_power = 10 + random(11);
        return 1;
    }
    if(!spell2) {
        spell2 = str;
        type2 = thetype;
        spell2_power = 10 + random(11);
        return 1;
    }
}

void clear_spell(string str) {
    if(!str) return 0;
    if(str == "spell1") {
        spell1 = 0;
        type1 = 0;
        spell1_power = 0;
    }
    if(str == "spell2") {
        spell2 = 0;
        type2 = 0;
        spell2_power = 0;
    }
}

int release(string str) {
    string spell, targ;
    object vic;
    if(!TO->query_worn()) {
        write("You need to wear the ring first.");
        return 1;
    }
    if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!spell1 && !spell2) {
        write("The ring currently has no spells stored.");
        return 1;
    }
    if(!str) {
        write("You must either <release spellname> OR <release spellname at target>");
        return 1;
    }

    if(sscanf(str,"%s at %s",spell,targ) == 2) {
        if(!(vic = present(targ,EETO))) {
            return notify_fail("That's not here!\n");
        }
        if(spell == spell1) {
            new(get_spell(spell1))->use_spell(ETO,vic,spell1_power,100,type1);
            ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
            clear_spell("spell1");
            return 1;
        }
        if(spell == spell2) {
            new(get_spell(spell2))->use_spell(ETO,vic,spell2_power,100,type2);
            ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
            clear_spell("spell2");
            return 1;
        }
    }

    if(str == spell1) {
        new(get_spell(spell1))->use_spell(ETO,0,spell1_power,100,type1);
        ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
        clear_spell("spell1");
        return 1;
    }

    if(str == spell2) {
        new(get_spell(spell2))->use_spell(ETO,0,spell2_power,100,type2);
        ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
        clear_spell("spell2");
        return 1;
    }
    write("No such spell currently stored.");
    return 1;

}
