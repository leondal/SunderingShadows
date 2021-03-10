#include "../brew.h"
inherit BREWPOTION;

string * query_valid_args();

void create() {
    ::create();
    set_property("instant potion",1); // ok to stack, spell is now doing the legwork.
}

int potion_effect(object drinker,int mystrength,string str) {
    object spellob;
    ::potion_effect(drinker,mystrength,str);
    spellob=new("/cmds/spells/r/_resist_energy");
    spellob->set_silent_casting(1);
    spellob->set_cast_string("");
    spellob->use_spell(drinker,str,mystrength,100,"potion");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    object spellob;
    ::potion_backfire(drinker,mystrength,str);
    spellob=new("/cmds/spells/r/_resist_energy");
    spellob->set_silent_casting(1);
    spellob->set_cast_string("");
    spellob->use_spell(drinker,str,mystrength,-100,"potion");
    return 1;
}

string * query_valid_args() { return ({ "acid","cold","electricity","fire","sonic" }); }