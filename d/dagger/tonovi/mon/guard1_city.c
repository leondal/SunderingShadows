#include "/d/dagger/tonovi/town/short.h"
#include "/d/common/common.h"

inherit MPATH"guard_inherit";

void create(){
    ::create();
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
    set_hd(15+random(15),1);
    set_hp(roll_dice(query_hd(),15));
    set_property("full attacks", 1);
    set_alignment(3);
    set_moving(1);
    set_speed(50);
    set_overall_ac(5 - random(10));
    add_money("gold", random(100));
    add_money("silver", random(200));
    if(!random(5))
      new(ROADOBJ "Mlong+1")->move(TO);
    else
      new(SHADOWWEAP "longsword")->move(TO);
    command("wield longsword");
    if(!random(15)) {
       set_overall_ac(6);
       new(ROADOBJ "studded+1")->move(TO);
       command("wear leather");
    }
}
