#include "/d/dagger/cave2/short.h"

inherit "/d/dagger/cave2/mon/wonder.c";
int num;
object ob;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if( TP->query_invis() && random(3) ){
      tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
      TP->set_invis();
	kill_ob(TP, 3);
    }
}

	void create() {
	    ::create();
	    num = 90;
	    set_name("Demon Summoner");
	    set_id( ({"demon", "summoner", "demon summoner", "man", "cavemon"}) );
	    set_short("Demon Summoner");
	    set_long(
	      "The demon summoner is one of the spawn of satan.  Dressed in a flowing blood red robe, the robe itself is bleeding, and as he walks he leaves a trail of blood behind him.  His long scrawny beard is also blood red, stained from rubbing against his sacrifices and robe.  He is tall, but lanky.  He holds a great black gem in his hands, which is encrusted with blood.  As he grins at you, you can almost feel him pulling your soul towards him, into him, and deeper into the gem itself."
	    );
	    set_race("demon");
	    set_body_type("human");
	    set_gender("male");
	    set_size(1+random(3));
	    set_class("cleric");
	    set_mlevel("cleric", 14);
	    set_hd(14,3);
	    set_max_hp(250);
	    set_hp(250);
	    set_exp(4000);
	    set_overall_ac(0);
	    set("aggressive", 20);
	    set_mob_magic_resistance("average");
	    set_alignment(6);
	    add_money("gold", random(500));
	    add_money("silver", random(1500));
	    ob=new(OPATH "bloodrobe");
	    if(!random(7)) ob->set_property("monsterweapon", 1);
	    ob->move(TO);
      command("wear robe");
	    set_property("swarm",1);
	    set_funcs(({"summon"}));
	    set_func_chance(90);
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
	}

	void summon(object targ){
	    object mon;
	    int i;
	    int num2;

	    num2 = random(2) + 1;
	    num -= 50;
	    if(num <= 10) num = 10;
	    set_func_chance(num);

	    tell_room(ETO, "%^BOLD%^%^RED%^The summoner cackles insanely as he starts to rub the gem while chanting slowly.");
	    tell_room(ETO, "%^BOLD%^%^RED%^The air in front of you starts to shimmer!!!");
	    tell_room(ETO, "%^BOLD%^%^RED%^Suddenly a great rift opens between you and the summoner, and several demons step out of it to attack you!");

	    for(i=0;i<num2;i++) {
		if(random(2)) mon = new("/d/dagger/cave2/mon/demon.c");
		else mon = new("/d/dagger/cave2/mon/demon2.c");
		mon->move(ETO);
		mon->kill_ob(targ);
	    }
	}
