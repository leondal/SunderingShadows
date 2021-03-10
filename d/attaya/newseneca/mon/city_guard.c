//adapted from other city guardsmen by ~Circe~
//11/22/07 for new Seneca

#include <std.h>
#include "/d/common/common.h"

#define CITYLAW "seneca law"

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming

void set_guard_stuff();
void hairColor();
void eyeColor();
void doHeight();
void doWeight();
void blow_horn(object watchman);

void create() {
    string rank;
    ::create();
    will_open_doors(1);
    set_nogo(({"/d/attaya/newseneca/rooms/boardwalk3"}));
    set_name("Seneca Guard");
    set_id(({"Seneca Guard","seneca guard","human","guard", CITYLAW}));
    set_short("A tall human");
    set_gender(random(2)?"male":"female");
    hairColor();
    eyeColor();
    set_race("human");
    set_hd(60+random(10),1);
    set_hp(TO->query_max_hp());
    set_new_exp(20,"normal");
    set_class("fighter");
        add_search_path("/cmds/fighter");
        set_fighter_style("soldier");
        set_speed(30);
        add_attack_bonus(15);
        add_damage_bonus(10);
        set_property("add kits",50);
        set_monster_feats(({
            "parry",
            "powerattack",
            "shatter",
            "sunder",
            "rush",
            "damage resistance",
            "improved damage resistance",
            "improved toughness",
            "regeneration",
            "toughness",
            "expertise",
            "knockdown",
				    "disarm",
            "scramble",
            "dodge",
            "evasion",
            "defensive roll",
            "mobility",
            "death ward",
            "unyielding soul",
            "resistance",
            "improved resistance",
            "increased resistance",
            "spring attack"
                  }));
        set_funcs(({
            "rushit",
            "flashit",
            "shatterit",
            "sunderit",
            "rushit",
            "kdit",
            "kdit",
            "disarmit"
        }));
        set_func_chance(35);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    rank = set_ranks(([
        18 : "rookie",
        20 : "sergeant",
        24 : "lieutenant",
        28 : "captain",
        30 : "Commander",
    ]));
    add_id(rank);
    add_id(capitalize(rank));
    set_short("A "+query("hair")+" haired, "+query("eye")+" eyed"
        " "+query_gender()+" human in a Seneca guard uniform");
    set_ac(2 - random(10));
    set_detecting_invis(random(2));
    set_exp(1);
    set_long("Dressed in the %^BOLD%^%^RED%^red-trimmed %^BLUE%^"+
       "uniform %^RESET%^%^CYAN%^of the %^BOLD%^Seneca Guard%^RESET%^"+
       "%^CYAN%^, this "+query_gender()+" guard wears an insignia "+
       "indicating a rank of %^BOLD%^%^WHITE%^"+rank+"%^RESET%^"+
       "%^CYAN%^ on "+query_possessive()+" left shoulder.  On the "+
       "right shoulder is a an embroidered %^BOLD%^%^WHITE%^eagle "+
       "%^RESET%^%^CYAN%^in flight, the symbol of the %^BOLD%^"+
       "Seneca Guard%^RESET%^%^CYAN%^.  Constantly under threat from "+
       "Intruder, the %^BOLD%^Seneca Guard %^RESET%^%^CYAN%^has grown "+
       "over the years from an ornamental guard to a force of hardened "+
       "warriors who are constantly vigilant.  Patrolling the streets, "+
       "this guard seems to take "+query_possessive()+" job seriously, "+
       "enforcing the law and repelling Intruder with equal dedication.");
    if(rank == "sergeant" || rank == "lieutenant"){
    set_property("add kits",10);
    RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    }
    if(rank == "Commander" || rank == "captain") {
      set_property("add kits",15);
        RANDGEAR->armor_me(TO, "armorpl", 20, 1, 75);
        } else {
        RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    }
    new("/d/common/obj/armour/coif")->move(TO);
        command("wear coif");
    switch(random(4)) {
        case 0:
            RANDGEAR->arm_me(TO, "edgedm", 30, 2, 75);
            RANDGEAR->arm_me(TO, "edgeds", 30, 2, 75);
            break;
        case 1:
            RANDGEAR->arm_me(TO, "edgedl", 30, 2, 75);
            break;
        case 2:
            RANDGEAR->arm_me(TO, "bluntm", 30, 2, 75);
            RANDGEAR->arm_me(TO, "blunts", 30, 2, 75);
            break;
        case 3:
            RANDGEAR->armor_me(TO, "shield", 30, 1, 75);
            RANDGEAR->arm_me(TO, "tool", 30, 2, 75);
            break;
    }
    set_guard_stuff();
}

void set_guard_stuff() {
    set_jail_location("/d/attaya/newseneca/rooms/jail_main");
    set_guarding("Seneca");
        set_bad_races(({"undead"}));
    set_race_action("capture");
    set_race_messages(([
        "undead"      : "%^BOLD%^One of Intruder's minions, destroy it!",
          ]));
    ARREST_MSG        = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG       = "%^BOLD%^You are under arrest, criminal!";
    RACE_CAPTURE_MSG  = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG         = "%^BOLD%^Begone! Do not return to Seneca!";
    KILL_MSG          = "%^BOLD%^For your crimes, you now die!";
    JAIL_MSG          = "%^BOLD%^Off to jail you go for your crimes!";
    return;
}

void do_special_combat_actions() {
   blow_horn(TO);
}

void hairColor() {
  switch (random(6)) {
    case 0:        set("hair","blonde");        break;
    case 1:        set("hair","red");           break;
    case 2:        set("hair","sandy");        break;
    case 3:        set("hair","black");         break;
    case 4:        set("hair","gray");          break;
    case 5:        set("hair","brown");         break;
  }
}

void eyeColor() {
  switch (random(5)) {
    case 0:        set("eye","blue");         break;
    case 1:        set("eye","gray");         break;
    case 2:        set("eye","green");        break;
    case 3:        set("eye","brown");        break;
    case 4:        set("eye","azure");        break;
  }
}

void doHeight() {
    int feet, halves;
    int height = 63+random(20);
    feet = height/12;
    halves = "";
    if (height%12) {
        halves = (height%12<4)?"":((height%12<9)?" and a half":"");
        if (height%12>8) {
            height++;
        }
    }
    set("height",""+feet+halves);
}

void doWeight() { set("weight",(140+random(140))); }

int isMagic() { return ::isMagic() + detecting_invis(); }

void blow_horn(object ob) {
    if(!objectp(ob)) { return; }
    if(horn) { return; }
    broadcast_area("/d/attaya/newseneca/rooms", "%^BOLD%^%^RED%^The warning horn blows,
alerting the city guards!");
    horn = 1;
}

void heart_beat() {
    ::heart_beat();
    if(!sizeof(query_attackers())) { horn=0; return; }
}

int isWatch() {
    return 1;
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}
void disarmit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("disarm "+targ->query_name());
}
