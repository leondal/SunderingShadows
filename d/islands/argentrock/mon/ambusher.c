//Based off of fey_ri.c for easy balancing -- Yves 2/17/18
#include <std.h>
#include "../argabbr.h"
#include "../desc.h"
inherit MONSTER;

string gender_c;

void create(){
    object obj;
    string short_c;
    ::create();
    set_name("An elven ambusher");
    set_id(({
        "ambusher",
        "elven ambusher",
        "elf",
        "argmon",
        "outpostmon"
    }));
    set_gender(random(2)?"male":"female");
    if(query_gender() == "male"){
        gender_c = "%^RED%^male%^RESET%^";
    }
    else{
        gender_c = "%^BOLD%^%^MAGENTA%^female%^RESET%^";
    }
    short_c = "%^BOLD%^%^RED%^A camouflaged %^RESET%^"+gender_c+" %^BOLD%^%^RED%^elf%^RESET%^";
    set_short(short_c);
    set_long((:TO,"long_desc":));
    set_race("elf");
    set_body_type("elf");
    set_hd(30+(random(14)),12);
    set_stats("strength",20);
    set_stats("intelligence",14);
    set_stats("dexterity",18);
    set_stats("charisma",12);
    set_stats("constitution",16);
    set_stats("wisdom",random(5)+15);
    set_overall_ac(-10);
    set_property("full attacks",1);
    set_size(2);
    avoid_traps(1);
    add_attack_bonus(random(10)+5);
    set_alignment(4);
    set_hidden(1);
    set_mob_magic_resistance("low");
    switch(random(6)){
        case 0:
            set_class("fighter");
            set_mlevel("fighter",query_hd());
            set_guild_level("fighter",query_hd());
            add_search_path("/cmds/fighter");
            set_stats("strength",25);
            set_parrying(1);
            switch(random(6)){
                case 0..3:
          					obj=new(OBJ+"pearl_longsword.c");
          					if(random(3)){
          						obj->set_property("monsterweapon",1);
          					}
          					obj->move(TO);
          					break;
          			default:
          					obj=new(OBJ+"pearl_2hsword.c");
          					if(random(3)){
          						obj->set_property("monsterweapon",1);
          					}
				            break;
            }
            obj->move(TO);
            obj=new(OBJ+"lion_plate.c");
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new("/d/common/obj/rand/r_helm.c");
            obj->set_property("enchantment",2);
            if(random(2)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            command("wield sword");
            force_me("wearall");
        break;
        case 1:
            set_class("thief");
            set_mlevel("thief",query_hd());
            set_guild_level("thief",query_hd());
            add_search_path("/cmds/thief");
            set_class("fighter");
            set_mlevel("fighter",query_hd());
            set_guild_level("fighter",query_hd());
            add_search_path("/cmds/fighter");
            set_parrying(1);
            set_thief_skill("hide in shadows",95);
            set_thief_skill("move silently",95);
            set_stats("dexterity",18);
            set_stats("constitution",17);
            set_scrambling(1);
            switch(random(6)){
                case 0..3:
                    obj=new(OBJ+"serpent_lblade.c");
                    if(random(3)){
                        obj->set_property("monsterweapon",1);
                    }
                    obj->move(TO);
                    obj=new(OBJ+"serpent_lblade.c");
                    obj->set_property("monsterweapon",1);
                    obj->move(TO);
                break;
                default:
                    obj=new(OBJ+"feline_lblade.c");
                    if(random(3)){
                        obj->set_property("monsterweapon",1);
                    }
                    obj->move(TO);
                    obj=new(OBJ+"feline_lblade.c");
                    obj->set_property("monsterweapon",1);
                    obj->move(TO);
                break;
            }
            obj=new(OBJ+"phoenix_leather.c");
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new("/d/common/obj/rand/rand_leath_head.c");
            obj->set_property("enchantment",2);
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            command("wield sword");
            command("wield sword 2");
            command("wearall");
        break;
        case 2:
            set_class("cleric");
            set_mlevel("cleric",query_hd());
            set_guild_level("cleric",query_hd());
            add_search_path("/cmds/cleric");
            set_class("fighter");
            set_mlevel("fighter",query_hd());
            set_guild_level("fighter",query_hd());
            add_search_path("/cmds/fighter");
            set_diety("nimnavanon");
            set_spell_chance(70);
            set_spells( ({
                "thorn spray",
                "sticks into snakes",
                "flame strike",
                "cause critial wounds",
                "dispel magic",
                "thorn spray"
            }) );
            obj=new(OBJ+"diamond_star.c");
            if(random(4)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new(OBJ+"lion_plate.c");
            if(random(5)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new("/d/common/obj/rand/r_helm.c");
            obj->set_property("enchantment",2);
            if(random(4)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new("/d/common/obj/rand/steelshield.c");
            obj->set_property("enchantment",4);
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            force_me("wearall");
            command("wield star");
        break;
        case 3:
            set_class("mage");
            set_mlevel("mage",query_hd());
            set_guild_level("mage",query_hd());
            add_search_path("/cmds/wizard");
            set_class("fighter");
            set_mlevel("fighter",query_hd());
            set_guild_level("fighter",query_hd());
            add_search_path("/cmds/fighter");
            set_parrying(1);
            set_stats("intelligence",18);
            set_stats("wisdom",16);
            set_spell_chance(85);
            set_spells( ({
                "chain lightning",
                "powerword stun",
                "ball lightning",
                "powerword stun",
                "scorcher",
                "magic missile",
                "greater shout",
                "dispel magic"
            }) );
            obj=new("/d/common/obj/rand/mage_robes.c");
            obj->set_property("enchantment",3);
            if(random(5)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            if(query_gender() == "female"){
                obj=new(OBJ+"diamond_fan.c");
                if(random(4)){
                    obj->set_property("monsterweapon",1);
                }
                obj->move(TO);
            }
            else{
                obj=new(OBJ+"flame_fan.c");
                if(random(4)){
                    obj->set_property("monsterweapon",1);
                }
                obj->move(TO);
            }
            obj=new("/d/common/obj/rand/rand_leath_head.c");
            obj->set_property("enchantment",2);
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            if(random(5) < 1){
                obj = new("/d/magic/scroll");
                obj->set_av_spell(9-random(3));
                obj->move(TO);
            }
                obj = new("/d/magic/scroll");
                obj->set_av_spell(6-random(2));
                obj->move(TO);
            command("wield fan");
            command("wearall");
        break;
        case 4:
            set_class("ranger");
            set_mlevel("ranger",query_hd());
            set_guild_level("ranger",query_hd());
            add_search_path("/cmds/ranger");
            set_stats("strength",17);
            set_stats("dexterity",18);
            switch(random(6)){
                case 0..3:
                    obj=new(OBJ+"leaf_tblade.c");
                    obj->set_property("monsterweapon",1);
                    obj->move(TO);
                    obj=new(OBJ+"leaf_tblade.c");
                    if(random(3)){
                        obj->set_property("monsterweapon",1);
                    }
                    obj->move(TO);
                break;
                default:
                    obj=new(OBJ+"vine_tblade.c");
                    obj->set_property("monsterweapon",1);
                    obj->move(TO);
                    obj=new(OBJ+"vine_tblade.c");
                    if(random(3)){
                        obj->set_property("monsterweapon",1);
                    }
                    obj->move(TO);
                break;
            }
            obj=new(OBJ+"phoenix_leather.c");
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new("/d/common/obj/rand/rand_leath_head.c");
            obj->set_property("enchantment",2);
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            command("wield sword");
            command("wield sword 2");
            command("wearall");
        break;
        default:
            set_class("mage");
            set_mlevel("mage",query_hd());
            set_guild_level("mage",query_hd());
            set_class("fighter");
            set_mlevel("fighter",query_hd());
            set_guild_level("fighter",query_hd());
            add_search_path("/cmds/fighter");
            set_class("thief");
            set_mlevel("thief",query_hd());
            set_guild_level("thief",query_hd());
            add_search_path("/cmds/thief");
            set_scrambling(1);
            set_parrying(1);
            set_stats("charisma",18);
            set_stats("dexterity",19);
            set_spell_chance(85);
            set_spells( ({
                "ball lightning",
                "shout",
                "prismatic spray",
                "sonic orb",
                "powerword stun",
                "hideous laughter",
                "magic missile",
                "greater shout",
                "dispel magic"
            }) );
            obj=new(OBJ+"phoenix_leather.c");
            if(random(4)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new(OBJ+"elec_knife.c");
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            obj=new(OBJ+"elec_knife.c");
            obj->set_property("monsterweapon",1);
            obj->move(TO);
            obj=new("/d/common/obj/rand/rand_leath_head.c");
            obj->set_property("enchantment",2);
            if(random(3)){
                obj->set_property("monsterweapon",1);
            }
            obj->move(TO);
            command("wield knife");
            command("wield knife 2");
            command("wearall");
            if(random(5) < 1){
                obj = new("/d/magic/scroll");
                obj->set_av_spell(9-random(4));
                obj->move(TO);
            }
            obj = new("/d/magic/scroll");
            obj->set_av_spell(6-random(1));
            obj->move(TO);
        break;
    }
    // obj = new("/d/common/obj/potion/healing");
    // obj->move(TO);
    // obj->set_uses(random(15)+15);
    set_property("add kits",random(15)+15);
    set_size(2);
    add_money("gold",random(400));
    add_money("silver",random(200));
    add_money("platinum",random(80));
    add_money("electrum",random(300));
    set_hp(800+(random(150)));
    set_property("swarm",1);
    set("aggressive",0);
    set_speed(30);
    set_funcs(({"special"}));
    set_func_chance(35);
    set_property("no bow",1);
    set_property("no dominate",1);
    set_property("no trip",1);
    set_property("no paralyze",1);
    set_exp( 400*query_hd() );
    set_max_level(36);
    set_languages( ({ "elven","common" }) );
    set_nogo( ({ PATH+"platform01" }) );
}

string long_desc() {
    string eye_c,hair_c,adj,hair_style;
    eye_c = EYE[random(sizeof(EYE))];
    hair_c = HAIR[random(sizeof(HAIR))];
    adj = ADJ[random(sizeof(ADJ))];
    hair_style = HAIR_STYLE[random(sizeof(HAIR_STYLE))];
    return
        "%^GREEN%^This is a %^ORANGE%^wood elf%^GREEN%^ of "+adj+" build with smooth %^ORANGE%^olive%^GREEN%^ skin. "
        +capitalize(QP)+" large%^RESET%^ "+eye_c+" %^GREEN%^eyes sparkle soflty in the "
        "light and "+QS+" has brilliant%^RESET%^ "+hair_c+" %^GREEN%^hair that is "
        +hair_style+". "+capitalize(QS)+" wears a strange %^BOLD%^%^BLACK%^gray cloak%^RESET%^%^GREEN%^, "
        "over "+QP+" armaments that changes hues and patterns of %^BOLD%^green%^RESET%^%^GREEN%^, "
        "%^ORANGE%^brown%^GREEN%^, %^YELLOW%^tan%^RESET%^%^GREEN%^ and %^BOLD%^%^BLACK%^gray%^RESET%^%^GREEN%^ when "+QS+" moves. The cloak makes it hard "
        "to see "+QO+" against the backdrop of the forest.%^RESET%^";
}

void special(object targ) {
    tell_room(ETO,
        "%^GREEN%^The elf reaches out quickly and jabs "+targ->QCN+" in the "
        "neck, causing "+targ->QO+" to try and scream in agony!%^RESET%^",targ
    );
    tell_object(targ,
        "%^GREEN%^The elf reaches out quickly and jabs you in the neck. "
        "You try and scream out but you are having trouble breathing!%^RESET%^"
    );
    TO->set_property("magic",1);
        targ->do_damage(targ->return_target_limb(),(roll_dice(6,10))+10);
    TO->set_property("magic",-1);
}

void init(){
    int i;
    object prej, *living;
     ::init();
    if(!objectp(TO) || !objectp(ETO)) return;
    living = all_living(ETO);
    living -= ({ TO });
    if(!sizeof(living)) return;
    prej = new(OBJ+"prejudice_d");
    for (i =0;i<sizeof(living);i++) {
        if(!objectp(living[i])) continue;
        if(prej->query_elf_prejudice(living[i])) {
            force_me("stab "+living[i]->query_name()+"");
            force_me("kill "+living[i]->query_name()+"");
            force_me("watch");
        }
    }
}

void heart_beat(){
     ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    // if(query_hp()< 140 && present("vial",TO)){
    //     force_me("open vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    //     force_me("quaff vial");
    // }
}
