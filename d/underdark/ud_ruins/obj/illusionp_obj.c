#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

void activate_powder();
void do_round();
void cleanup_prev_round();
void set_effect();
void remove_powder();
void set_melee_debuff();
void remove_melee_debuff();
void set_caster_debuff();
void remove_caster_debuff();
void set_paranoia();
void fake_stab();
void fake_leave();
void fake_attack();

int active, duration, userlvl, created_at;

void create() {
    ::create();
    set_name("illusionp_obj");
    set_id(({"illusionp_obj"}));
    set_weight(0);
    set_property("no animate",1);
    set_hidden(1);
    duration = 0;
    active = 0;
    userlvl = 0;
    created_at = time();
    set_heart_beat(1);
}

void init() {
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    add_action("look_screw","look");
    add_action("who_screw","who");
    if (!active) {
        activate_powder();
    }
}

void set_userlvl(int lvl) {
    userlvl = lvl;
}

void activate_powder() {
    duration = roll_dice(1,8) + 2 - (int)BONUS_D->query_stat_bonus(ETO,"wisdom");
    if (duration <= 0) {
        tell_object(ETO,
            "%^MAGENTA%^Your vision %^WHITE%^glazes %^MAGENTA%^over momentarily "
            "as you breathe in some of the "
            "c%^BOLD%^o%^RESET%^%^MAGENTA%^l%^YELLOW%^o%^RESET%^%^MAGENTA%^r"
            "%^BOLD%^%^CYAN%^f%^RESET%^%^MAGENTA%^ul "
            "d%^BOLD%^%^GREEN%^u%^RED%^s%^RESET%^%^MAGENTA%^t, but you are able "
            "to fight off its effects!"
        );
        tell_room(EETO,
            "%^MAGENTA%^"+ETO->QCN+"'s vision %^WHITE%^glazes %^MAGENTA%^over "
            "momentarily as "+ETO->QS+" breathes in some of the "
            "c%^BOLD%^o%^RESET%^%^MAGENTA%^l%^YELLOW%^o%^RESET%^%^MAGENTA%^r"
            "%^BOLD%^%^CYAN%^f%^RESET%^%^MAGENTA%^ul "
            "d%^BOLD%^%^GREEN%^u%^RED%^s%^RESET%^%^MAGENTA%^t, but "+ETO->QS+" "
            "seems to fight off its effects!"
        ,({ETO}));
        active = -1;
        return;
    }
    ETO->set_property("powdered", 1);
    active = 1;
    tell_object(ETO,
        "%^MAGENTA%^You can't help but breathe in some of the "
        "%^BOLD%^c%^GREEN%^o%^ORANGE%^l%^MAGENTA%^o%^CYAN%^r%^MAGENTA%^f"
        "%^RED%^u%^MAGENTA%^l %^RESET%^%^MAGENTA%^dust! Your vision "
        "%^WHITE%^glazes %^MAGENTA%^over for a moment."
    );
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+" is caught in the cloud of "
        "%^BOLD%^c%^GREEN%^o%^ORANGE%^l%^MAGENTA%^o%^CYAN%^r%^MAGENTA%^f"
        "%^RED%^u%^MAGENTA%^l %^RESET%^%^MAGENTA%^dust! "+ETO->QP+" vision "
        "%^WHITE%^glazes %^MAGENTA%^over!"
    ,({ETO}));
    call_out("do_round",ROUND_LENGTH);
}

void do_round() {
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    cleanup_prev_round();
    if (duration <= 0) {
        remove_powder();
        return;
    }
    duration--;
    set_effect();
    if(random(2)) {
        switch(random(3)) {
            case 0:
                fake_stab();
                break;
            case 1:
                fake_leave();
                break;
            case 2:
                fake_attack();
                break;
        }
    }
    call_out("do_round",ROUND_LENGTH);
}

void remove_powder() {
    tell_object(ETO,
        "%^CYAN%^The nightmarish visions fade as reality begins to reassert "
        "itself, leaving you in a cold sweat."
    );
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+" seems to shake off a stupor, looking more aware "
        "of "+ETO->QP+" surroundings."
    ,({ETO}));
    ETO->remove_property("powdered");
    TO->remove();
}

// Per-round effects

void cleanup_prev_round() {
    if (ETO->query_property("illusionp-melee")) {
        remove_melee_debuff();
    }
    if (ETO->query_property("illusionp-caster")) {
        remove_caster_debuff();
    }
}

void set_effect() {
    // Current in-battle effects:
    // 0 -  Melee debuff. Target sees visions and receives a massive attack
    // penalty.
    // 1 - Caster debuff. Target perceives a ghostly hand around their throat.
    // Prevents casting for that round.
    // 2 - Paranoia. Target becomes paralyzed for that round.
    switch(random(3)) {
        case 0:
            set_melee_debuff();
            break;
        case 1:
            set_caster_debuff();
            break;
        case 2:
            set_paranoia();
            break;
    }
}

void set_melee_debuff() {
    tell_object(ETO,
        "%^BOLD%^%^CYAN%^A hundred "
        "t%^RESET%^ra%^BOLD%^%^CYAN%^n%^WHITE%^s%^CYAN%^l%^RESET%^u%^BOLD%^c"
        "%^RESET%^e%^BOLD%^n%^CYAN%^t "
        "%^WHITE%^s%^RESET%^p%^BOLD%^%^CYAN%^e%^RESET%^ct%^BOLD%^r%^CYAN%^e"
        "%^WHITE%^s %^CYAN%^suddenly leap from hiding and attack you with "
        "%^BLACK%^g%^RESET%^l%^BOLD%^eami%^RESET%^n%^BOLD%^%^BLACK%^g "
        "%^WHITE%^w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e "
        "d%^RESET%^a%^BOLD%^g%^RESET%^g%^BOLD%^e%^RESET%^r%^BOLD%^s%^CYAN%^! "
        "You swing about wildly in an attempt to fight them off!"
    );
    ETO->set_property("illusionp-melee",1);
    ETO->add_attack_bonus(((int)BONUS_D->new_bab(1,ETO) / 2) * -1);
}

void remove_melee_debuff() {
    ETO->remove_property("illusionp-melee");
    ETO->add_attack_bonus(((int)BONUS_D->new_bab(1,ETO) / 2));
}

void set_caster_debuff() {
    if(!objectp(ETO)) { return; }
    tell_object(ETO,
        "%^BOLD%^%^GREEN%^Suddenly a portal opens up in the air in front of you! "
        "A giant s%^RESET%^%^GREEN%^c%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^y "
        "g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n "
        "h%^RESET%^%^GREEN%^a%^BOLD%^nd reaches through and grasps you by the "
        "neck, choking you!"
    );
    ETO->set_property("illusionp-caster",1);
    ETO->set_static("spell interrupt",
        "%^BOLD%^%^RED%^The monstrous hand still grips your throat!"
    );
    ETO->set_property("spell interrupt",
        "%^BOLD%^%^RED%^The monstrous hand still grips your throat!"
    );
}

void remove_caster_debuff() {
    if (objectp(ETO)) {
        ETO->remove_property("illusionp-caster");
        ETO->set_static("spell interrupt", 0);
        ETO->remove_property("spell interrupt");
    }
}

void set_paranoia() {
    tell_object(ETO,
        "%^BOLD%^%^BLACK%^Your vision suddenly "
        "%^RESET%^b%^BOLD%^%^BLACK%^l%^RESET%^u%^BOLD%^%^BLACK%^r"
        "%^RESET%^s%^BOLD%^%^BLACK%^, and an army of "
        "n%^RED%^i%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^t"
        "%^BOLD%^m%^RESET%^a%^BOLD%^%^BLACK%^r%^RED%^i%^RESET%^%^RED%^s"
        "%^BOLD%^%^BLACK%^h "
        "c%^RESET%^%^RED%^r%^BOLD%^e%^BLACK%^a%^RESET%^t%^BOLD%^%^RED%^u"
        "%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^es begins to crawl out of "
        "the air before you, hungry for your "
        "%^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^! You are too terrified "
        "to react!%^RESET%^"
    );
    ETO->set_paralyzed((ROUND_LENGTH * 2) - 2,
        "%^BOLD%^%^RED%^You are gripped by sheer terror!"
    );
}

// Harmless effects

void fake_stab() {
    int max_hp,cur_hp,i,j;
    if (!objectp(TO)) { return; }
    if (!objectp(ETO)) { return; }
    max_hp = ETO->query_max_hp();
    cur_hp = ETO->query_hp();
    j = random(3)+1;
    for (i=0;i<j;i++) {
        cur_hp -= roll_dice(((int)ETO->query_level() / 2),6);
        tell_object(ETO,
            "%^BOLD%^%^WHITE%^Mysterious Figure stabs you in the back!\n%^RED%^Hp: "
            "%^RESET%^"+cur_hp+"    "+(cur_hp*100/max_hp)+"%"
        );
    }
}

void fake_leave() {
    string *exits;
    string fake_exit, message;
    object *players;
    object fake_player;
    if (!objectp(TO)) { return; }
    if (!objectp(ETO)) { return; }
    if (!objectp(EETO)) { return; }
    exits = EETO->query_exits();
    if (!sizeof(exits)) { return; }
    fake_exit = exits[random(sizeof(exits))];
    players = filter_array(all_inventory(EETO),"is_non_immortal_player",FILTERS_D);
    players -= ({ETO});
    if (sizeof(players) <= 0) { return; }
    fake_player = players[random(sizeof(players))];
    if (!sscanf(fake_player->query_message_out(),"out %s", message)) { return; };
    message = "%^BOLD%^%^GREEN%^"
        +fake_player->QCN+" "
        +replace_string(message,"$D","%^BOLD%^%^GREEN%^"+fake_exit);
    tell_object(ETO, message);
}

void fake_attack(){
    object *players;
    object fake_player;
    if (!objectp(TO)) { return; }
    if (!objectp(ETO)) { return; }
    if (!objectp(EETO)) { return; }
    players = filter_array(all_inventory(EETO),"is_non_immortal_player",FILTERS_D);
    players -= ({ETO});
    if (sizeof(players) <= 0) { return; }
    fake_player = players[random(sizeof(players))];
    tell_object(ETO,
        "%^BOLD%^%^RED%^"+fake_player->QCN+" attacks you!"
    );
}

// These two actions have a chance of overriding their respective commands.
// (may add additional echoes/conditions later)

int look_screw(string str) {
    if (!objectp(TO)) { return 0; }
    if (!objectp(ETO)) { return 0; }
    if (!random(3)) { return 0; }
    tell_object(ETO,
        "%^BOLD%^%^RED%^The Land of the Dead\n%^RESET%^%^RED%^You are in the "
        "middle of a vast, featureless field. Millions of "
        "%^BOLD%^bloody%^RESET%^%^RED%^, mutilated corpses lie scattered on the "
        "crimson-stained ground, slain by your hand. You realize that you are "
        "fated to stay here in this world forever, alone and "
        "forsaken.\n\n%^BOLD%^%^CYAN%^There is no "
        "escape.%^RESET%^%^RED%^\n\n%^BOLD%^%^MAGENTA%^Numerous "
        "%^RESET%^%^RED%^b%^BOLD%^o%^RESET%^%^RED%^dys %^BOLD%^o%^RESET%^%^RED%^f "
        "%^BOLD%^y%^RESET%^%^RED%^o%^BOLD%^ur a%^RESET%^%^RED%^l%^BOLD%^ly"
        "%^MAGENTA%^ are here.\n"
    );
    return 1;
}

int who_screw(string str) {
    string res;
    if (!objectp(TO)) { return 0; }
    if (!objectp(ETO)) { return 0; }
    if (!random(3)) { return 0; }
    res =
        "                           "
        "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-\n"
        "                        -=> %^GREEN%^S h a d o w G a t e "
        "%^BLUE%^<=-\n"
        "                     -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
        "                       %^BLACK%^--=> %^RESET%^THIS IS YOUR FAULT "
        "%^BOLD%^%^BLACK%^<=--%^RESET%^\n"
        "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--==--=="
        "--==--==--==--"
        "\n\n%^BOLD%^%^BLACK%^"
        "                         "
        "        You\n\n\n"
        "                         "
        "           Are\n\n\n"
        "                         "
        "       %^RED%^Alone%^RESET%^\n\n"
        "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--==--=="
        "--==--==--==--";

    tell_object(ETO, res);
    return 1;
}

void heart_beat() {
    if(!objectp(TO)) { return; }
    if (time() - created_at > 100 || active == -1) { TO->remove(); }
}


int save_me(string file) { return 1;}
int is_invincible(){ return 1;}
int is_detectable(){ return 0;}
