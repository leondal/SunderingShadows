#include <std.h>
inherit MONSTER;
#include "../ogres.h"

void create() {
    ::create();
    set_name("ogre slave");
    set_id( ({"ogre", "ogre slave", "slave", "Ogre Slave", "cavemon"}) );
    set_short("%^RESET%^%^ORANGE%^Og%^RESET%^%^WHITE%^r%^RESET%^"+
"%^ORANGE%^e S%^RESET%^%^WHITE%^l%^RESET%^%^ORANGE%^ave%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^A giant ogre wielding a club made of %^RESET%^"+
"%^BOLD%^%^WHITE%^bone%^RESET%^%^ORANGE%^, this beast is gaunt and under "+
"nourished. It's %^RESET%^%^YELLOW%^yel%^RESET%^%^ORANGE%^l%^RESET%^%^YELLOW%^"+
"ow sk%^RESET%^%^ORANGE%^i%^RESET%^%^YELLOW%^n %^RESET%^%^ORANGE%^is pock marked"+
" and disease is evident in patches of %^RESET%^%^WHITE%^p%^RESET%^%^BOLD%^%^WHITE%^"+
"u%^RESET%^%^WHITE%^ss fi%^RESET%^%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^led so%^RESET%^"+
"%^RED%^r%^RESET%^%^WHITE%^es%^RESET%^%^ORANGE%^. A simple loin cloth of ragged leather"+
" covers most of what it should. A mad look seems to linger in its semi intelligent "+
"%^RESET%^%^RED%^red eyes%^RESET%^%^ORANGE%^. %^RESET%^"
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 18);
    set_hd(12,7);
    set_attack_bonus(2);
    set_stats("strength", 18);
    set_stats("dexterity", 8);
    set_stats("constitution", 18);
    set_stats("intelligence", 3);
    set_stats("wisdom", 5);
    set_stats("charisma", 3);
    set_speed(20);
        set_nogo( ({"/d/dagger/ogres/rooms/0_2", "/d/dagger/ogres/rooms/ogremaze55"}) );
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_max_hp(115);
    set_hp(115);
    set_property("full attacks", 2);
    add_money("gold", random(25));
    new(OBJ"bone")->move(TO);
    command("wield bone");
}
