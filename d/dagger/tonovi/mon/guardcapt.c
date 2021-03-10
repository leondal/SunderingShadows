#include "/d/dagger/tonovi/town/short.h"

inherit MPATH"guard_inherit";

void create(){
    ::create();
    set_name("Tonovi Guard Captain");
    set_id( ({"guard", "tonovi guard", "captain", "Gtonovimon"}) );
    set_short("Tonovi Guard Captain");
    set_long(
@STYX
This is a captain of the trained guards of Tonovi.  He has a
ruthless sneer on his face that indicates he enjoys his job a
little too much.
STYX
    );
    set_gender("male");
    set_race("human");
    set_body_type("human");
    set_hd(24,1);
    set_property("full attacks", 1);
    set_overall_ac(2);
    set_alignment(6);
    set_max_hp(250);
    set_hp(250);
//    set_property("swarm", 1);
    add_money("gold", random(100)+200);
    add_money("silver", random(200));
    if(!random(3)) add_money("platinum", random(10));
    set_speed(30);
    set_moving(1);

    switch(random(10)) {
      case 0..5 :
         new(CWEAP"longsword")->move(TO);
         command("wield longsword");
         new(CWEAP"shortsword")->move(TO);
         command("wield shortsword");
         break;
      case 6..7 :
         new(ROADOBJ "Mbroad+1")->move(TO);
         command("wield sword");
         break;
      case 8 :
         new(ROADOBJ "Maxe+1")->move(TO);
         command("wield axe");
         break;
      case 9 :
         new(ROADOBJ "Mhammer+1")->move(TO);
         command("wield hammer");
         break;
    }
    if(!random(3))  new(ROADOBJ "studded+1")->move(TO);
    else { new(CARMOR"leather")->move(TO); }
    command("wear leather");
    if(!random(3))  new("/d/shadow/obj/clothing/silkcloak")->move(TO);
    command("wear cloak");
}