#include "/d/dagger/tonovi/town/short.h"

inherit MONSTER;

void create(){
    ::create();
    set_name("Tonovi Guard");
    set_id( ({"guard", "tonovi guard", "town guard", "Gtonovimon"}) );
    set_short("Tonovi Guard");
    set_long(
@G
This is one of the trained guards of Tonovi, a soldier
that showed promise and was given the prestigious task
of protecting his homeland.  Dressed in typical soldierly
armor, he looks quite prepared to do whatever is needed.
G
    );
    set_gender("male");
    set_race("human");
    set_body_type("human");
    set_hd(15,1);
    set_property("full attacks", 1);
    set_overall_ac(0);
    set_alignment(3);
    set_max_hp(175);
    set_hp(175);
    set_property("swarm", 1);
    add_money("gold", random(100));
    add_money("silver", random(200));
    if(!random(3)) add_money("platinum", random(30));
    set_speed(50);
    set_moving(1);
    switch(random(20)) {
      case 0..15 :
         new(CWEAP"longsword")->move(TO);
         command("wield longsword");
         new(CWEAP"shortsword")->move(TO);
         command("wield shortsword");
         break;
      case 16..17 :
         new(ROADOBJ "Mbroad+1")->move(TO);
         command("wield sword");
         break;
      case 18 :
         new(ROADOBJ "Maxe+1")->move(TO);
         command("wield axe");
         break;
      case 19 :
         new(ROADOBJ "Mhammer+1")->move(TO);
         command("wield hammer");
         break;
    }
    if(!random(15))  {
        set_overall_ac(8);
        new(ROADOBJ "Mcoif")->move(TO);
        new(ROADOBJ "Mchain+1")->move(TO);
        command("wear coif");
        command("wear chainmail");
    }
}
