#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit WEAPON;

int charges,countdown,xx,yy;
void init() {
    ::init();
    charges = 0;
    countdown = 0;
    add_action("word_func","sivaar");
}
void create() {
    ::create();
    set_name("staff");
    set_id(({"staff","wooden staff","staff of sorcery"}));
    set_short("%^GREEN%^Staff of sorcery%^RESET%^");
    set_property("enchantment",2);
    set_obvious_short("wooden staff");
    set_long(
            "%^GREEN%^The staff is covered in ancient runic script. It is "
            "about six feet long and made of a gnarled piece of oak. "
            "At the striking end of the staff is small bauble-like "
            "sphere. The sphere continously changes colours in a rythmic "
            "pattern.%^RESET%^"
            );
    set_weight(5);
    set("value",400);
    set_prof_type("staff");
    set_wc(2,4);
    set_large_wc(2,4);
    set_size(2);
    set_type("bludgeoning");
    set_heart_beat(1);
    set_hit((:this_object(),"extra_hit":));
    set_wield((:this_object(), "extra_wield":));
    set_unwield((:this_object(), "extra_unwield":));
}

int extra_hit(object ob) {
    int zz,dam,cost;
    object vic = ETO->query_current_attacker();
    if(random(8) > 2) return 0;

    if(!objectp(ob)) return 1;
    zz=random(6)+1;
    switch(zz) {
        case 1:
            dam = random(charges) + 2;
            charges = charges - 1;
            message("my_action",
                    "%^GREEN%^The staff's sphere glows %^WHITE%^white%^GREEN%^ "
                    "as you strike your foe!\n"
                    "%^CYAN%^You feel refreshed!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^WHITE%^white%^GREEN%^ "
                    "as it strikes "
                    +ob->query_cap_name()+"!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^WHITE%^white%^GREEN%^ "
                    "as it strikes you!"
                    "%^RESET%^"
                    ,ob);
            ETO->heal(dam);
            return 1;

        case 2:
            dam = random((int)ETO->query_stats("intelligence"))/2;
            message("my_action",
                    "%^GREEN%^The staff's sphere glows %^RED%^red%^GREEN%^ "
                    "as you strike your foe!\n"
                    "%^RED%^"+ob->query_cap_name()+
                    "'s body is wracked with intense seizing pains!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^RED%^red%^GREEN%^ "
                    "as it strikes "+ob->query_cap_name()+"!"
                    "%^RED%^"+ob->query_cap_name()+
                    "'s body is wracked with intense seizing pains!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^RED%^red%^GREEN%^ "
                    "as it strikes you!"
                    "%^RED%^Your body is wracked with intense seizing pains!"
                    "%^RESET%^"
                    ,ob);
            return dam;

        case 3:
            dam = random((int)ETO->query_level());
            message("my_action",
                    "%^GREEN%^The staff's sphere glows %^MAGENTA%^purple%^GREEN%^ "
                    "as you strike your foe!\n"
                    "%^MAGENTA%^"+ob->query_cap_name()+
                    "'s body is frozen in time!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^MAGENTA%^purple%^GREEN%^ "
                    "as it strikes "
                    +ob->query_cap_name()+"!"
                    "%^MAGENTA%^"+ob->query_cap_name()+
                    "'s body is frozen in time!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^MAGENTA%^purple%^GREEN%^ "
                    "as it strikes you!"
                    "%^RED%^Your body is frozen in time!"
                    "%^RESET%^"
                    ,ob);
            vic->set_paralyzed(dam,"%^MAGENTA%^Your body is frozen in time!"
                               "%^RESET%^");
            return 1;

        case 4:
            dam = (int)ETO->query_hp()/10;
            dam = random(dam)+2;
            if(dam > 10) dam = 10;
            cost = dam/5;
            if(cost < 1) cost = 1;
            message("my_action",
                    "%^GREEN%^The staff's sphere glows %^BLUE%^blue%^GREEN%^ "
                    "as you strike your foe!\n"
                    "%^BLUE%^The staff channels some of your inner essense to "
                    "decimate "+ob->query_cap_name()+
                    "'s skull!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^BLUE%^blue%^GREEN%^ "
                    "as it strikes "
                    +ob->query_cap_name()+"!"
                    "%^BLUE%^"+ob->query_cap_name()+
                    "'s screams in pain!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^BLUE%^blue%^GREEN%^ "
                    "as it strikes you!"
                    "%^BLUE%^You feel an intense pain deep in your skull!"
                    "%^RESET%^"
                    ,ob);
            vic->heal(-(dam));
            ETO->do_damage("torso",cost);
            return 1;

        case 5:
            dam = random(6)+2;
            message("my_action",
                    "%^GREEN%^The staff's sphere glows %^BOLD%^%^RED%^"
                    "orange%^RESET%^%^GREEN%^ "
                    "as you strike your foe!\n"
                    "%^BOLD%^%^RED%^"+ob->query_cap_name()+
                    "'s body is engulfed in flames!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^BOLD%^%^RED%^orange%^RESET%^%^GREEN%^ "
                    "as it strikes "
                    +ob->query_cap_name()+"!"
                    "%^BOLD%^%^RED%^"+ob->query_cap_name()+
                    "'s body is engulfed in flames!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The sphere of the staff wielded by "
                    +ETO->query_cap_name()+" glows %^BOLD%^%^RED%^orange%^RESET%^%^GREEN%^ "
                    "as it strikes you!"
                    "%^BOLD%^%^RED%^Your body is engulfed in flames!"
                    "%^RESET%^"
                    ,ob);
            return dam;

        case 6:
            dam = random((int)ETO->query_stats("wisdom")/2)+1;
            message("my_action",
                    "%^GREEN%^The staff drains your foe of his life force!"
                    "%^RESET%^"
                    ,ETO);
            message("other_action",
                    "%^GREEN%^The staff wielded by "
                    +ETO->query_cap_name()+" glows %^WHITE%^white%^GREEN%^ "
                    "as it strikes "
                    +ob->query_cap_name()+"!"
                    "%^RESET%^"
                    ,environment(ob),(({ETO, ob})));
            message("my_action",
                    "%^GREEN%^The staff wielded by "
                    +ETO->query_cap_name()+" glows %^WHITE%^white%^GREEN%^ "
                    "as it strikes you!"
                    "%^RESET%^"
                    ,ob);
            ETO->heal(dam);
            dam = 1;
            if(random(10000) < 1) {
                dam = random(500);
            }
            if(random(2000) < 1) {
                ETO->set_paralyzed(100,"%^RED%^The staff is attempting to take "
                                   "control of your mind!\n%^GREEN%^"
                                   "It takes all of your concentration to resist!"
                                   "%^RESET%^");
            }
            return dam;
    }
}
void heart_beat() {
    object owner,env,obj;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    env = ETO;
    if(objectp(env) && living(env) && objectp(environment(env))) {
        owner = env;
        env = environment(env);
    }
    if(!TO->query_wielded()) return;
    if( obj = present("corpse",env)) {
        charges = charges + 1;
        if(charges > 5) charges = 5;
        tell_object(owner,
                    "%^BOLD%^%^RED%^The staff glows warmly as it satisfys "
                    "it's hunger\nfor power from the essense of the corpse before you."
                    "%^RESET%^"
                   );
        owner->heal(random(charges)+ 1);
        obj->remove();
        return;
    }
    xx = random(700);
    yy = random(9)+1;
    if(xx < 1) {
        if(yy == 1) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "I am hungry fool! FEED ME!!!"
                       );
        }
        if(yy == 2) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "Are we killing or what?!?"
                       );
        }
        if(yy == 3) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "Grrr...*grumble*...what the hell..."
                       );
        }
        if(yy == 4) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "Uhhh...not that it matters but...How high is your "
                        "wisdom?"
                       );
        }
        if(yy == 5) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "You sure take your time don't you?"
                       );
        }
        if(yy == 6) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "The best things to kill are thieves. I *REALLY* "
                        "hate thieves!"
                       );
        }
        if(yy == 7) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "By the way...if you use the mental command: sivaar "
                        "during combat I might be able to let some sparks "
                        "fly."
                       );
        }
        if(yy == 8) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "Hmmm...I just can't seem to penetrate your "
                        "cranium."
                       );
        }
        if(yy == 9) {
            tell_object(owner,
                        "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                        "Must you carry this worthless other junk around with "
                        "you?!?"
                       );
        }
        if(yy == 10) {
            if(charges != 5) {
                tell_object(owner,
                            "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                            "GET ME CORPSES!!!"
                           );
            }
            else {
                tell_object(owner,
                            "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
                            "Well well well! What do ya know...I am actually "
                            "full."
                           );
            }
        }
    }
    return;
}
int word_func() {
    object victim = ETO->query_current_attacker();
    object ob = ETO->query_current_attacker();
    int shockdam;
    if(TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(charges < 1) return 0;
    if(ETO->query_paralyzed() || ETO->query_disable()) return 0;
    if(victim->query_ghost()) return 0;
    if(ETO->query_property("no attack")) return 0;
    if(victim->query_property("no attack")) return 0;
    if(environment(ETO)->query_property("no kill")) return 0;
    if(victim->query_property("no kill")) return 0;
    if(!victim) {
        write(
             "%^BOLD%^%^RED%^The staff tells you: %^RESET%^"
             "Are you an idiot??? I said when you are *IN* combat!"
             );
        return 1;
    }
    else {
        shockdam = (charges) * (random(6)+2);
        charges = 0;
        message("my_action",
                "%^RED%^A shower of sparks leaves the staff and "
                "shock "+victim->query_cap_name()+
                "'s body!"
                "%^RESET%^"
                ,ETO);
        message("other_action",
                "%^RED%^A shower of sparks leaves the staff held by "
                +ETO->query_cap_name()+
                "and shock "+ob->query_cap_name()+
                "'s body!"
                "%^RESET%^"
                ,environment(ob),(({ETO, ob})));
        message("my_action",
                "%^RED%^A shower of sparks leaves the staff held by "
                +ETO->query_cap_name()+
                "and shock your body!"
                "%^RESET%^"
                ,ob);
        victim->do_damage("torso",shockdam);
        ETO->set_paralyzed(5,"You are still using the staff!");
        write(
             "%^BOLD%^%^RED%^The staff tells you: %^RESET%^That was "
             "some good timing on my part huh?%^RESET%^"
             );
        return 1;
    }
}
int extra_wield() {
    if(!ETO) return 0;
    if(!ETO->is_class("mage") && !ETO->is_class("bard") && !ETO->is_class("sorcerer")) {
//added sorcerer since they are now in game. ~Circe~ 5/11/11
        tell_object(ETO,"You will never wield this!\n");
        return 0;
    }
    if((int)ETO->query_lowest_level() < 20) {
        write("You do not have the power for this weapon "
              "puny one!\n%^RED%^The staff vanishes!%^RESET%^");
        TO->remove();
        return 0;
    }
    if((string)ETO->query_race() != "Drow" && (string)ETO->query_race() != "drow") {
        if(random(100) > (int)ETO->query_stats("wisdom")+(int)ETO->query_level()) {
            write("The staff resists you...this time.");
            countdown = countdown + 1;
            return 0;
        }
    }
    write(
         "%^BOLD%^%^RED%^The staff tells you: %^RESET%^I am ready to serve "
         "master. I am hungry for energy as always."
         "\n%^RED%^The staff giggles inanely.%^RESET%^"
         );
    say(
       "%^RED%^"+ETO->query_cap_name()+" cackles insanely!%^RESET%^"
       );
    charges = 0;
    return 1;
}
int extra_unwield() {
    countdown = countdown + 1;
    charges = 0;
    write(
         "The staff tells you: WAIT!!! What "
         "are you doing?!? Have I not served well enough?"
         );
    if(countdown > (int)ETO->query_stats("wisdom") * 3) {
        write(
             "The staff tells you: Your puny mind "
             "does not deserve to control me!"
             "\nThe staff vanishes!"
             );
        call_out("remove",1);
    }
    return 1;
}
