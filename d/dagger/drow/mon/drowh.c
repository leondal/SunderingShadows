//fixed typos, added blocking exit, randomly wear black robe. Styx 7/15/01
// making them tougher and gear monsterweapons due to abuse of ooc info. *Styx*  11/9/03, last change 2/13/02

#include <std.h>
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("drow hunter");
   set_id(({"drow","hunter","drow hunter","drowmon"}));
    set_short("%^BOLD%^%^BLACK%^Drow hunter%^RESET%^");
    set("long",
	"%^BOLD%^%^BLUE%^This is one of the standard male hunter "
	"types of the Drow Elves of Underdark.  Its blazing "
	"%^RED%^red%^BLUE%^ eyes are filled with hatred.  Its jet "
	"coal skin glistens sickeningly, but your attention is mostly "
   "drawn to the evil grin on its lips.  Under its garments "
   "you can make out the taut muscles of the creature and its "
   "stance shows that he is ready and more than willing to die "
	"in battle.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(20+random(3),3);  // was 11+random(3),3
    set_size(2);
    set_overall_ac(5);
    set_max_hp(100+random(20));  // was 60+random(20)
    set_hp(query_max_hp());
//    set_wielding_limbs(({"right hand","left hand"}));  don't need this
    set_body_type("humanoid");
    set_stats("strength",18);
    set_stats("dexterity",20);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_property("swarm",1);
    set_property("full attacks", 1);   // added this too
    set_mob_magic_resistance("average");  // was 7
    set_exp(1500);  // was 800
    set_max_level(20);
    set_alignment(9);
    set_emotes(2,({
	"The drow hunter looks you over.",
	"The drow hunter says: How did this human and his companions manage "
	"to sneak into the city?",
	"The drow hunter says: Lucky we managed to kill him before he "
	"escaped the caverns.",
	"The drow hunter says: His companions died where the cavern "
	"collapsed... made the job of killing them all easier.",
	"The drow hunter says: Something to the north is making me feel "
	"sick... a sickness like the sun brings.",
	"The drow hunter says: Do not speak of the sun!",
	"The drow hunter looks to the north and quivers a bit.",
	"The drow hunter says: It is time to return to the city to report "
	"of this success."
    }),0);
    ob = new("/d/dagger/drow/obj/marmor.c");
	ob->set_property("monsterweapon", 1);
	ob->move(TO);
	command("wear armor");
    if(!random(10)) {
       ob = new("/d/dagger/drow/obj/blcloak.c");
	  ob->set_property("monsterweapon", 1);
	  ob->move(TO);
          command("wear robe");
    }
    ob = new("/d/dagger/drow/obj/blsword.c");
	ob->move(TO);
	ob->set_property("monsterweapon", 1);
	command("wield sword");
    ob = new("/d/dagger/drow/obj/bldagger.c");
	ob->move(TO);
	ob->set_property("monsterweapon", 1);
	command("wield dagger");
}

void aggfunc() {
    object shape;
    string mrace=TP->query_race();
    if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();
    if(TP->query_invis()) return 1;
    if (mrace == "drow") {
	force_me ("bow");
	return;
    } else {
	TP->kill_ob(TO,0);
	force_me("say You shall perish!\n");
	force_me("say %^RED%^Do not let them escape!\n");
	force_me("block south");
    }
}
