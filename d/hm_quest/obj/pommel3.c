#include <std.h>
inherit OBJECT;

string owner;

void create() {
    ::create();
    set_name("pommel");
    set_id(({"pommel3","hm_quest_bone","bone pommel","pommel"}));
    set_short("%^RESET%^%^WHITE%^Bone pommel%^RESET%^");
    set_long("This unusual %^ORANGE%^pommel %^RESET%^appears to have once been part of a sword. It has been is designed in the likeness of a strange bone, and is heavy enough to have served as "
"the balance for a sizeable weapon. The pommel is surprisingly %^RED%^warm %^RESET%^to the touch, and glows with a faintly %^CYAN%^magical %^RESET%^aura. It leaves you wondering where the rest "
"of the sword could be. One side bears a few notches, enough so that you could attach it to a hilt if you could find one to fit.%^RESET%^");
    set_weight(2);
    set_value(0);
    set_heart_beat(1);
}

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}

void heart_beat() {
    string holder;
    if(!objectp(ETO)) return;
    if(!interactive(ETO)) return;
    holder = ETO->query_true_name();
    if(holder != owner) {
      tell_object(ETO,"The bone pommel vanishes!");
      TO->remove();
    }
}