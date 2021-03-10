#include <std.h>
#define EARTH "%^BOLD%^%^YELLOW%^Earth%^RESET%^"
#define FIRE "%^BOLD%^%^RED%^Fire%^RESET%^"
#define WATER "%^BOLD%^%^CYAN%^Water%^RESET%^"
#define WIND "%^BOLD%^Wind%^RESET%^"
#define ELEMENTS "%^BOLD%^%^MAGENTA%^E%^CYAN%^l%^ORANGE%^e%^BLUE%^m%^RED%^e%^RESET%^%^BLUE%^n%^RED%^t%^GREEN%^s%^RESET%^"

inherit ARMOUR;
string OWNER;
int in_use, uses;
mapping pstats;

void do_all();

void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
    add_action("call_elem", "test");
    add_action("call_elem", "callto");
}

void create() {
    ::create();
    in_use = 0;
    uses = 6;
    pstats = ([]);
    set_name("elemental plate armor");
    set("id", ({"elemental plate", "armor", "plate", "plate armor"}) );
    set("short", "%^BOLD%^%^CYAN%^Elemental Plate armor%^RESET%^");
    set_long(
      "   This suit of armor is made of a strange %^BOLD%^%^ORANGE%^brown%^RESET%^ metal that you can't identify.  It reminds you of dirt.  Veins of %^RED%^flame red%^RESET%^ and %^CYAN%^ocean blue%^RESET%^ cross through the metal.  There are 4 gems in the shoulders, inscribed with runes.  You can almost hear the elements call to you."
    );
    set_weight(50);
    set("value", 25000);
    set_type("armour");
    set_limbs( ({"torso" }) );
    set_ac(9);
    set_property("enchantment", 5);
    set_property("magic resistance", "40");
    set_wear((:this_object(), "extra_wear":));
    set_remove((:TO, "remove_me":));
}

int extra_wear() {
    if( ((int)TP->query_level() < 25) || ((string)TP->query_name() != OWNER)) {
      tell_object(TP, "%^CYAN%^The elements do not accept you.");
      TO->remove();
      return 0;
    }
    tell_object(TP, "You slip into the %^BOLD%^%^ORANGE%^Armor of the Elements%^RESET%^ and feel a strange power flow through you.\nYou feel "+EARTH+" lend you his strength, "+FIRE+" his power, "+WATER+" her resistance, and "+WIND+" her speed.");
    return 1;
}

int remove_me(){
    if(in_use){
      tell_object(TP, "The power of the elements is still coursing through your body!");
      return 0;
    }
    tell_object(TP, "%^BOLD%^%^RED%^You feel the power of the elements leave you as you slip from the suit of armor.%^RESET%^");
    return 1;
}


int call_elem(string str){
    int stat, time;

    if(!TO->query_worn()){
      return 0;
    }
    if(in_use){
      tell_object(TP, "The power of the elements is already in you.");
      return 1;
    }

    if(uses < 0){
      tell_object(TP, "The armor has been drained of its power, and crumbles to dust.");
      TO->remove();
      return 1;
    }
    if(!str){
      tell_object(TP, "You must call upon either "+WIND+", "+WATER+", "+FIRE+", "+EARTH+", or all the "+ELEMENTS+".");
      return 1;
    }

    time = (int)TP->query_lowest_level()*8;
    if(wizardp(TP)) time = 200;

    switch(str){
      case "fire":
        if(uses < 2) {
          tell_object(TP, "There is not enough power in the armor.");
          return 1;
        }
        tell_object(TP, "You call upon the rage of "+FIRE+"!!");
        stat = TP->query_stats("constitution");
        stat = 25 - stat;
        TP->add_stat_bonus("constitution", stat);
        TP->add_damage_bonus(7);
        uses -= 2;
        in_use = 1;
        call_out("remove_power", time, "fire", stat);
        break;
      case "earth":
        if(uses < 2) {
          tell_object(TP, "There is not enough power in the armor.");
          return 1;
        }
        tell_object(TP, "You call upon the strength of "+EARTH+"!!");
        stat = TP->query_stats("strength");
        stat = 25 - stat;
        TP->add_stat_bonus("strength", stat);
        TP->add_attack_bonus(10);
        uses -= 2;
        in_use = 1;
        call_out("remove_power", time, "earth", stat);
        break;
      case "wind":
        if(uses < 2) {
          tell_object(TP, "There is not enough power in the armor.");
          return 1;
        }
        tell_object(TP, "You call upon the speed of "+WIND+"!!");
        stat = TP->query_stats("dexterity");
        stat = 25 - stat;
        TP->add_stat_bonus("dexterity", stat);
        uses -= 2;
        in_use = 1;
        call_out("remove_power", time, "wind", stat);
        break;
      case "water":
        tell_object(TP, "You call upon "+WATER+" to heal you.");
        TP->set_hp((int)TP->query_max_hp());
        TP->heal(1);
        uses -= 1;
        in_use = 1;
        call_out("remove_power", time, "water", 0);
        break;
      case "elements":
        if(uses < 5) {
          tell_object(TP, "There is not enough power in the armor to do that.");
          return 1;
        }
        tell_object(TP, "You call up all of the "+ELEMENTS+" to aid you in your battle!");
        TP->set_hp((int)TP->query_max_hp());
        TP->heal(1);
        do_all();
        uses = 0;
        in_use = 1;
        break;
      default:
        tell_object(TP, "You cannot call upon that element.");
    }
    return 1;
}

void remove_power(string str, int stat){

    tell_object(TP, "You feel yourself returning to normal.");
    switch(str){
      case "fire":
        TP->add_stat_bonus("constitution", -stat);
        TP->add_damage_bonus(-7);
        break;
      case "earth":
        TP->add_stat_bonus("strength", -stat);
        TP->add_attack_bonus(-10);
        break;
      case "wind":
        TP->add_stat_bonus("dexterity", -stat);
        break;
      default:
        TP->heal(20);
    }
    in_use = 0;
}

void set_uses(int x) {uses = x;}
int query_uses() {return uses;}

void do_all(){
    int time, stat;

    pstats["strength"] = 25 - (int)TP->query_stats("strength");
    pstats["dexterity"] = 25 - (int)TP->query_stats("dexterity");
    pstats["constitution"] = 25 - (int)TP->query_stats("constitution");

    time = (int)TP->query_lowest_level()*4;
    if(wizardp(TP)) time = 100;

    stat = pstats["strength"];
    TP->add_stat_bonus("strength", stat);
    stat = pstats["dexterity"];
    TP->add_stat_bonus("dexterity", stat);
    stat = pstats["constitution"];
    TP->add_stat_bonus("constitution", stat);
    TP->add_damage_bonus(12);
    TP->add_attack_bonus(15);
    call_out("undo_elem", time);
}

void undo_elem(){
    int stat;

    stat = pstats["strength"];
    TP->add_stat_bonus("strength", -stat);
    stat = pstats["dexterity"];
    TP->add_stat_bonus("dexterity", -stat);
    stat = pstats["constitution"];
    TP->add_stat_bonus("constitution", -stat);
    TP->add_damage_bonus(-12);
    TP->add_attack_bonus(-15);
    tell_object(TP, "Having expended the greatest power of the armor, it crumbles to dust around you.");
    in_use = 0;
    TO->remove();
}
