//dhammer.c

#include <std.h>

inherit WEAPON;

void badStuff();

void create() {
    ::create();

   set_name("%^RED%^Hammer of Destruction%^RESET%^");
    set_id(({"hammer","Great hammer","great hammer","hammer of destruction","Hammer of Destruction"}));
   set_obvious_short("a massive hammer");
   set_short("%^RED%^Great Hammer of Destruction%^RESET%^");

    set_long(
@OLI
%^BLUE%^This hammer has a long thick handle on average about 4
inches in diameter. The handle is ornately carved with geometrics.
The thickness of the handle is obviously to support the massive head.
Both ends of the head are heavily blunted through possibly <smash>ing
the earth around them. The thick metal binding around each end has
been reached causing the wood metal mixture to fold down around
the bands. Obviously this hammer, to have survived the beating its
life has given it, must contain some great worth or great power.
OLI
    );
    set_wc(1,12);
    set_large_wc(1,12);
    set_property("enchantment",5);
    set_weight(45);
    set_value(15000);
    set_wield("%^RED%^The great geometrics grip into your hands.");
    set_type("bludgeoning");
//    set_prof_type("large hammer");
//changing to prof "giant hammer" after bug reports that you have to 
//be large and it takes two hands - Circe 12/20/04
    set_prof_type("giant hammer");
    set_prof_level(45);
    set_size(4);
    set_hit((:TO,"hitem":));
    set_weapon_prof("exotic");
}

int hitem(object targ) {
    if (!objectp(targ)) return 6;

    if (random(10)) return 6;

    switch (random(2)) {
    case 0:
        tell_room(environment(targ), "%^RED%^The hammer slams down on "+targ->query_cap_name()+"'s body, crushing "+targ->query_objective()+" underneath the wieght.",({targ,query_wielded()}));
        tell_object(targ,"%^RED%^The hammer weilded by "+query_wielded()->query_cap_name()+" slams into you leaving pieces of your body limp with pain.");
        tell_object(query_wielded(),"%^RED%^You land a blow of tremendous force on "+targ->query_cap_name()+", leaving "+targ->query_objective()+" limp!");
         targ->set_paralyzed(random(10),"You're trying to shake off that last blow.");
        return 0;
    case 1:
        tell_room(environment(targ),"%^BOLD%^%^BLUE%^A thunderous crack of thunder shakes the room.");
        return 6+random(6);
    }
}

void init() {
    ::init();
    if((string)TO->query_weapon_prof() != "exotic") TO->set_weapon_prof("exotic"); // changing to exotic kthx - Nienne.
    add_action("smash","smash");
    add_action("smash","pound");
}

int smash(string str) {

    if (!query_wielded()) return 0;

    tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" swings wildly at the floor and brings the head of the hammer down onto the floor in a thunderous blow.",TP);
    write("%^BOLD%^%^BLUE%^You swing the hammer down with a thunderous crash.");
    if (!ETP->query_property("indoors")) {
        tell_room(ETP,"Nothing happens.");
        return 1;
    }
    if (!str) {
        if (!sizeof(ETP->query_exits())) {
            tell_room(ETP,"Nothing happens.");
            return 1;
        }
        tell_room(ETP,"%^RED%^The room trembles with the force of the blow and you turn to see the exits all closed.");
        ETP->collapse_all_exits();

    } else {
        if (member_array(str, ETP->query_exits()) == -1) {
            tell_room(ETP,"Nothing happens.");
            return 1;
        }
        tell_room(ETP,"%^RED%^The room trembles with the force of the blow and the "+str+" is caved in.");
        ETP->collapse_exit(str);
    }

    if (!random(100) && userp(TP))
        badStuff();
    return 1;
}

void badStuff() {
    tell_room(ETP,"%^RED%^After you realize the exits have closed, the trembling gets worse and your realize ....");

    call_out("moreBadStuff",10,TP);
}

moreBadStuff(object ob) {

    object *inven;
    int i,j,hp;

    tell_room(environment(ob),"%^RED%^The ceiling of the room colapses on you.");
    inven = all_living(environment(ob));
    for (i=0;i<j;i++) {
        if (!objectp(inven[i])) continue;
        hp = inven[i]->query_hp();
        inven[i]->do_damage("torso",hp+1);
        inven[i]->add_attacker(TP);
        inven[i]->continue_attack();
        inven[i]->remove_attacker(TP);
    }
}

