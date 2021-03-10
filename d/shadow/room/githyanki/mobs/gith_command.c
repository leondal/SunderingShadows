// Githyanki Commander  - LoKi - 01-02-2008 ((gith_guard.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("githyanki");
    set_id(({"githyanki","monster","commander","githyanki commander","Ul-lek","ul-lek","Ul-lek Githyanki Commander"}));
    set_race("githyanki");
    set_gender("male");
    set_short("%^RESET%^%^MAGENTA%^Ul-%^RESET%^%^BOLD%^%^BLACK%^l%^RESET%^"+
"%^MAGENTA%^ek Git%^RESET%^%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^yanki "+
"Comma%^RESET%^%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^der%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^Dressed in a flowing robe and a set of "+
"%^RESET%^%^BOLD%^%^BLACK%^obsidion vambraces%^RESET%^%^MAGENTA%^, this "+
"githyanki is an almost gaunt elven figure. He stands taller then any of "+
"the other githyanki you have seen, and has an almost tangible aura of "+
"%^RESET%^%^BOLD%^%^MAGENTA%^power %^RESET%^%^MAGENTA%^to him. His %^RESET%^"+
"%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^lver h"+
"%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^ir %^RESET%^%^MAGENTA%^flows "+
"over his shoulders freely. He wields a %^RESET%^%^WHITE%^runic silver sword"+
" %^RESET%^%^MAGENTA%^in one hand, and a %^RESET%^%^RED%^set of claws"+
"%^RESET%^%^MAGENTA%^ in the other.%^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(22);
    set_hd(22,2);
    set_max_hp(random(50)+500);
    set_hp(query_max_hp());
    set_overall_ac(0);
	set_speed(0);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",19);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
      
    set_class("ranger");
    add_search_path("/cmds/ranger");
    set_mlevel("ranger",22);
    set_guild_level("ranger",22);

    set_class("psion");
    set_mlevel("psion",22);
    add_search_path("/cmds/psion");
    set_guild_level("psion",22);

    set_spell_chance(20);
    set_spells(({"swarm of crystals", 
"power leech", 
"breath of the black dragon", 
"mind thrust"}));

    set_exp(15000);
    set_max_level(27);
    add_money("gold",random(2000));
    add_money("silver",random(1000));
    add_money("platinum",random(200));
    add_money("electrum",random(300));

    set_body_type("human");
    set_spoken("wizish");
    command("speech %^RESET%^%^RED%^snarl angrily%^RESET%^");
    force_me("pose %^BLACK%^%^BOLD%^Sitting on the throne%^RESET%^");

    ob = new(OBJ"gith_key");
    ob->move(TO);

    ob = new(OBJ"lesser_silver_sword");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield sword");
    
    ob = new ("/d/common/obj/weapon/claw.c");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment",2);
    command("wield claw");
    
    ob = new(OBJ"obsidion_vambraces");
    ob->move(TO);
    command("wear bracers");

    ob = new("/d/common/obj/armour/robe");
    ob->move(TO);
    ob->set_short("%^BLACK%^%^BOLD%^flowing black robe%^RESET%^");
    ob->set_property("enchantment",2);
    ob->set_property("monsterweapon",1);
    command("wear robe");

    ob = new(OBJ"gith_symbol.c");
    ob->move(TO);

    set_property("add kits",random(15)+20);

    set("aggressive","agg_func");
    set_achats(10,({"%^BLACK%^%^BOLD%^Ul-lek screams for "+
"reinforcements%^RESET%^",
"%^BLACK%^%^BOLD%^Ul-lek lunges at you%^RESET%^"}));
}

void agg_func(int flag) {
    if (TP->query_invis()){ return; }
    if(!flag){
       force_me("say More weak mortals attempt to rescue"+
" my slave! I will decorate my throne with your skulls!");
       force_me("pose clear");
       if(!TO->query_property("animal_affinity")){
          new("/cmds/spells/a/_animal_affinity.c")->use_spell(TO,TO,20,100,"psion");
       }
       flag = 1;
    }
    force_me("emoteat "+TPQN+ " $M screams and rushes $N.");
    force_me("kill "+TPQN+"");
    return;
}

void heart_beat(){
        ::heart_beat();
  
        if(!objectp(TO) || !objectp(ETO)) return;
        if(query_hp()< 200 && present("vial",TO)){
            force_me("quaff vial");
            force_me("quaff vial");
            force_me("quaff vial");
            force_me("quaff vial");
            force_me("quaff vial");

        }
}