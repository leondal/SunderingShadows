//General difficulty increase Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("nicodemus");
    set_id(({
        "nicodemus","my_nicodemus","mage"
    }));
    set_short("%^RESET%^%^RED%^Nicodemus, Arch-mage of Demongate%^RESET%^");
    set_long(
	"The wizened old man before you is clad in a black robe covered in "
	"runes and holds a long black rod. His eyes show a power within of "
	"an ancient age. His long white hair flows down around him like a "
	"mane of a great beast. Despite his age, he looks extremly stout "
	"and capable of defending himself physically, although you sense "
	"he would sooner stoop to frying attackers with powers of a more "
	"arcane nature."
    );
    set_gender("male");
    set_level(30);
    set_hd(30,9);
    set_size(2);
    set_weight(80);
    set_wielding_limbs(({"right hand","left hand"}));
   set_overall_ac(-30);
   set_property("no bump",1);
   set_property("no paralyze",1);
   set_property("no tripped",1);
    set_property("weapon resistance",1);
   set_property("no hold",1);
    set_property("no steal",1);
    set_body_type("human");
    set_race("human");
    set_class("mage");
     set_mlevel("mage",50);
      set_guild_level("mage",50);
   set_spell_chance(85);
   set_spells(
       ({"fireball",
               "greater dispel magic",
               "monster summoning ix",
               "phantom guardians",
               "phantasmal killer",
               "stormbolts",
               "stormbolts",
               "meteor swarm",
               "meteor swarm",
               "hellball"}));
    set_stats("strength",22);
    set_stats("constitution",30);
    set_stats("dexterity",30);
    set_stats("wisdom",35);
    set_stats("intelligence",40);
    set_stats("charisma",20);
    set_alignment(5);
   set_property("add kits",25);
    set_mob_magic_resistance("average");
    set_exp(80000);
    set_max_level(36);
   set_max_hp(4000);
   set_hp(4000);
    add_money("gold",random(2000)+500);
        set_monster_feats(({
      "indomitable",
       "force of personality",
         "unyielding soul",
      "resistance",
      "improved resistance",
      "increased resistance",

      "spell reflection",
          "toughness",
          "improved toughness",
          "damage resistance",
          "improved damage resistance",
          "regeneration",
          "parry"
    }));
    set_emotes(1,({
        "%^BLUE%^Nicodemus traces ancient runic patterns in the air.%^RESET%^",
	"%^RED%^Nicodemus cackles and mystic energy dances on his fingertips!",
	"Nicodemus grumbles something to himself and laughs.",
        "%^MAGENTA%^Nicodemus says: %^RESET%^Vecna gave me his rod to guard until he returns...I shall not fail him.",
    }),0);
     new( OPATH "rod.c" )->move(TO);
     new( OPATH "castershoes.c" )->move(TO);
    command("wield rod in left hand");
    set_funcs(({"special"}));
    set_func_chance(40);
}
int special() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int wisdom, intel, i, max, number, main_number;
    string hit_limb;
    object here,*inv;
    main_number = 8;
    here = ETO;
    xx=random(3)+1;
    switch(xx) {
    case 1:
	message("environment",
	    "%^BLUE%^%^BOLD%^Nicodemus traces the symbols of death in "
	    "the air!%^RESET%^"
	,environment(ob));
	tell_object(targ,
	    "%^RED%^%^BOLD%^Nicodemus points the %^GREEN%^finger of "
	    "death%^RED%^ towards you!%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^RED%^%^BOLD%^Nicodemus points the %^GREEN%^finger of death "
	    "%^RED%^ at "+targ->query_cap_name()+"!%^RESET%^"
	,targ);
	if("/daemon/saving_d"->saving_throw(targ,"spell")) {
	    message("environment",
	        "%^RED%^%^BOLD%^For some reason the aura is weak!%^RESET%^"
	    ,environment(ob));
            targ->do_damage("torso",random(50)+25);
            return 1;
	} else {
	    message("environment",
	        "%^RED%^%^BOLD%^The aura of death seizes it's foe and enforces "
	        "the death symbol!%^RESET%^"
	    ,environment(ob));
	    targ->do_damage("torso",random(100)+100);
	    return 1;
        }
    case 2:
    say("%^YELLOW%^"
        "Nicodemus mutters the incantation of the inferno!\n"
	"An immense amount of "
	"%^RESET%^%^RED%^heat%^YELLOW%^, "
	"%^RED%^flames%^YELLOW%^ "
	"and %^WHITE%^molten lava%^YELLOW%^ fill the "
	"area!"
	"%^RESET%^"
    );
    for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++) {
        number = random(main_number)+5;
         if(!living(inv[i])) continue;
         if(!inv[i]->query_property("no paralyze"))
            inv[i]->set_paralyzed(5+random(6),
		"You are paralyzed from pain."
	 );
	 if(inv[i] == TO) continue;
	 if(wizardp(inv[i])) continue;
        while(number > 0) {
            hit_limb=inv[i]->return_target_limb();
            message("env",
		"%^BOLD%^%^RED%^"
		+inv[i]->query_cap_name()+" recoils in pain "
                "as "+inv[i]->query_possessive()+
		" "+hit_limb+" burns in flame!"
            ,environment(inv[i]), inv[i]);
            message("target",
		"%^BOLD%^%^RED%^Your "+hit_limb+" screams with "
		"pain from the fire!"
	    ,inv[i]);
            inv[i]->do_damage(inv[i]->return_target_limb(), (random(40)/2) + 8);
           number--;
        }
    }
    return 1;
    case 3:
    tell_object(targ,
        "%^BOLD%^%^RED%^Nicodemus snaps his fingers!\n%^BLUE%^"
	"Suddenly you appear elsewhere!"
	"%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^Nicodemus snaps his fingers!\n%^BLUE%^"
        +targ->query_cap_name()+" vanishes in a flash of smoke!%^RESET%^"
    ,targ);
    targ->move_player("/d/darkwood/room/road18");
    targ->set_paralyzed(100,"%^RED%^You are paralyzed from the plane shift!");
    return 1;
    }
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(TO->query_hp() < 100) {
	TO->add_hp(random(1));
    }
    return;
}
