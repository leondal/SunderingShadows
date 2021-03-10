//Randomized elven refugee -- Yves
#include <std.h>
#include "../argabbr.h"
#include "../desc.h"
inherit WEAPONLESS;

string eye_c,hair_c,adj,gender_c;

void create() {
     string short_c;
     eye_c = EYE[random(sizeof(EYE))];
     hair_c = HAIR[random(sizeof(HAIR))];
     adj = ADJ[random(sizeof(ADJ))];
    ::create();
    set_id(({
        "refugee",
        "elven refugee",
        "outpostmon"
    }));
    set_gender(random(2)?"male":"female");
    if(query_gender() == "male"){
        gender_c = "%^RED%^male%^RESET%^";
    }
    else{
        gender_c = "%^BOLD%^%^MAGENTA%^female%^RESET%^";
    }
    if(adj == "average"){
        short_c = "%^BOLD%^%^RED%^An "+adj+" %^RESET%^"+gender_c+" %^BOLD%^%^RED%^elf with %^RESET%^"+eye_c+" %^BOLD%^%^RED%^eyes and %^RESET%^"
            +hair_c+" %^BOLD%^%^RED%^hair%^RESET%^";
    }
    else{
        short_c = "%^BOLD%^%^RED%^A "+adj+" %^RESET%^"+gender_c+" %^BOLD%^%^RED%^elf with %^RESET%^"+eye_c+" %^BOLD%^%^RED%^eyes and %^RESET%^"
            +hair_c+" %^BOLD%^%^RED%^hair%^RESET%^";
    }
    set_name("An elven refugee");
    set_short(short_c);
    set_long((:TO,"long_desc":));
    set_hd(20,10);
    set("aggressive", 0);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_guild_level("fighter",20);
    set_alignment(4);
    set_race("elf");
    add_money("gold", random(25));
    set_body_type("human");
    set_mob_magic_resistance("very low");
    set_overall_ac(-16);
    set_stats("strength",15);
    set_stats("intelligence",13);
    set_stats("wisdom",13);
    set_stats("dexterity",19);
    set_stats("constitution",13);
    set_stats("charisma",14);
    set_max_hp(250+random(50));
    set_hp(query_max_hp());
    set_exp(100);
    set_property("swarm",1);
    set_speed(50);
    set_moving(1);
    set_nogo( ({ PATH+"platform01" }) );
    set_attack_limbs( ({"right hand","left hand"}) );
    set_attacks_num(4);
    set_base_damage_type("bludgeoning");
    set_damage(4,2);
}

string long_desc(){
    string hair_style;
    hair_style = HAIR_STYLE[random(sizeof(HAIR_STYLE))];
    return
        "%^CYAN%^This is a "+gender_c+" %^ORANGE%^wood elf%^CYAN%^ of "+adj+" build. "
        +capitalize(QS)+" once lived upon the island of %^GREEN%^Argentrock%^CYAN%^ and "
        "has now been driven into this %^ORANGE%^treetop%^CYAN%^ refuge by the depraved "
        "%^BOLD%^%^MAGENTA%^Fey'ri%^RESET%^%^CYAN%^. "+capitalize(QP)+" large "+eye_c+" %^CYAN%^eyes sparkle softly "
        "in the %^BOLD%^%^WHITE%^light%^RESET%^%^CYAN%^ and "+QS+" has %^BOLD%^%^WHITE%^brilliant%^RESET%^%^CYAN%^ "+hair_c+" %^CYAN%^hair "
        "that is "+hair_style+". "+capitalize(QS)+" is wearing clothing "
        "that blends in well with the forest, mostly "
        "%^GREEN%^greens%^CYAN%^, %^YELLOW%^tans%^RESET%^%^CYAN%^ and %^ORANGE%^browns%^CYAN%^, as well as a soft %^BOLD%^%^BLACK%^gray cloak%^RESET%^%^CYAN%^.%^RESET%^";
}
