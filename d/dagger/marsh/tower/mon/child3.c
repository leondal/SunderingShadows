#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit WEAPONLESS;

void create() {
    :: create();
    set_name("child");
    set_id(({
        "child","child of the damned"
    }));
    set_short("%^RESET%^%^MAGENTA%^Child of the damned%^RESET%^");
    set_long("%^RED%^"
        "He is walking like a small child,\n"
	"But watch his eyes burn you away,\n"
	"Black holes in his golden stare,\n"
	"God knows he wants to go home.%^RESET%^"
);
set_property("magic",1);
    set_gender("male");
    set_property("undead",1);
    set_level(23);
    set_hd(23,4);
    set_weight(80);
    set_attacks_num(4);
    set_damage(3,5);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand"}));
    set_overall_ac(-10);
    set_body_type("human");
    set_race("human");
    set_class("fighter");
    set("aggressive",50);
    set_guild_level("fighter",25);
    set_stats("strength",25);
    set_stats("constitution",23);
    set_stats("dexterity",25);
    set_stats("wisdom",30);
    set_stats("intelligence",30);
    set_stats("charisma",20);
    set_mob_magic_resistance("average");
    set_exp(27500);
    set_max_level(36);
    set_max_hp(300);
    set_hp(300);
    set_alignment(3);
    add_money("gold",random(500)+300);
    set_emotes(1,({
        "%^BLUE%^The child cries a low haunting stifled moan of agony.%^RESET%^",
	"The child looks deep into your soul.",
	"The child beckons for you to come closer.",
    }),0);
    set_funcs(({"damn"}));
    set_func_chance(30);
    new( OPATH "dart3.c" )->move(TO);
    new( OPATH "note4.c" )->move(TO);
}
void damn(object targ){
    object ob,here,sucker,*players;
    int x,num_p,finder;
    finder = 0;
    if(!targ) return;
    here=environment(TO);
    players=all_inventory(here);
    num_p=sizeof(players);
    for(x=0;x<num_p;x++) {
        sucker=players[x];
        if((living(sucker)) && sucker !=(TO) &&
        userp(sucker) && finder == 0) {
            targ = sucker;
        }
    }
    tell_room(ETO,
	"%^BOLD%^%^RED%^"
	"The child's eyes fall upon "+targ->query_cap_name()+
	"!"
    ,targ);
    tell_object(targ,
	"%^BOLD%^%^RED%^"
	"The child's eyes fall upon you!"
    );
            call_out("wrack",2,targ);
            call_out("wrack",5,targ);
            call_out("wrack",9,targ);
            call_out("wrack",12,targ);
            call_out("wrack",20,targ);
            call_out("wrack",28,targ);
            call_out("wrack",34,targ);
            call_out("wrack",40,targ);
            call_out("wrack",45,targ);
            call_out("wrack",60,targ);
    return 1;
    set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes"
    }));
    set_scrambling(1);
}
void wrack(object targ) {
    if(!targ) return;
    if(!objectp(TO)) return;
    tell_object(targ,
	"%^BOLD%^%^RED%^You are torn apart as the sorrow and damnation of "
	"the child fills you mind, body and soul!%^RESET%^"
    );
    tell_room(ETO,
	"%^BOLD%^%^RED%^"
	+targ->query_cap_name()+
	" screams and claws at "
	+targ->query_possessive()+
	" eyes in utter inner agony!%^RESET%^"
    ,targ);
    targ->do_damage("torso",random(15)+5);
    targ->set_paralyzed(2,"%^BLUE%^The shadows grip you!");
    return;
}
void set_paralyzed(int time,string message){return 1;}
