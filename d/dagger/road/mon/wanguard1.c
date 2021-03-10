//made the weapons monsterweapons most of the time and put the armor in the
//describe & adjusted AC accordingly.  There are other places to get mithril.

#include "/d/dagger/road/short.h"
inherit "/d/dagger/road/mon/wonder";
object ob;

create (){
    ::create ();
    set_name("Wandering guard");
    set_id( ({"guard", "wandering guard", "Wandering guard", "human"}) );
    set_short("Wandering guard");
    set_long(
      "This is one of the guards that travels the roads in dagger to try to keep them 'safe'.  Paid by the regency of Tonovi, their loyalty is not to the people like it is advertised, but to the duke instead.  A hatred of elves is raised in them early.  He is dressed in simple chain and armed simply."
    );
    set_property("swarm",1);
    set_gender("male");
    set("race", "human");
    set_body_type("human");
    set_hd(11,1);
    set_size(2);
    set_overall_ac(-2);       //was 3 but reduced 6 to replace the chain removed
    set_class("fighter");
    set_stats("strength", 18);
    set_stats("intelligence", 8);
    set_stats("dexterity", 16);
    set_stats("charisma", 10);
    set_stats("wisdom", 14);
    set_stats("constitution", 17);
    set_alignment(3);
    set_max_hp(100);
    set_hp(100);
    set_exp(1000);
    set("aggressive", 0);
    set_speed(8);
    set_moving(1);
    if(!random(5))  add_money("gold", 150 + random(100));
    set_wielding_limbs( ({"left hand","right hand"}) );
    ob = new(OPATH "Mlong+1");
    if(random(10)) ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield sword");
}
