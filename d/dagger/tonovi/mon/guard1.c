#include "/d/dagger/tonovi/town/short.h"
#include "/d/common/common.h"

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
of protecting his homeland.  Wearing just leather armor,
you suspect he is one of the newer recruits.
G
    );
    set_gender("male");
    set_race("human");
    set_body_type("human");
    set_hd(12,1);
    set_property("full attacks", 1);
    set_alignment(3);
    set_max_hp(130);
    set_hp(130);
    set_property("swarm", 1);
    set_moving(1);
    set_speed(50);
    set_overall_ac(0);
    add_money("gold", random(100));
    add_money("silver", random(200));
    if(!random(5))
      new(ROADOBJ "Mlong+1")->move(TO);
    else
      new(SHADOWWEAP "longsword")->move(TO);
    if(!random(15)) {
       set_overall_ac(8);
       new(ROADOBJ "studded+1")->move(TO);
       command("wear leather");
    }
    command("wield longsword");
}
