#include "../brew.h"
inherit BREWPOTION;

void create() {
    ::create();
    set_property("instant potion",1); // ok to stack, spell is now doing the legwork.
}

int potion_effect(object drinker,int mystrength,string str) {
    object spellob;
    ::potion_effect(drinker,mystrength,str);
    if(member_array("regeneration",(string*)drinker->query_temporary_feats()) != -1) {
      tell_object(drinker,"%^MAGENTA%^You wait for a few moments, but nothing seems to happen. You realise it's probably because you are already regenerating!%^RESET%^");
      return 1;
    }
    spellob=new("/cmds/spells/r/_regeneration");
    spellob->set_silent_casting(1);
    spellob->set_cast_string("");
    spellob->use_spell(drinker,drinker,mystrength,100,"potion");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    ::potion_backfire(drinker,mystrength,str);
    tell_object(drinker,"%^MAGENTA%^You wait for a few moments, but nothing seems to happen.%^RESET%^");
    return 1;
}