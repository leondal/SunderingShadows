// /d/guilds/alliance/gate.c

#include <std.h>

inherit VAULT;

void create()
{
    ::create();
    set_indoors(1);
    set_light(2);
    set_travel(PAVED_ROAD);
    set_terrain(STONE_BUILDING);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_property("no phase", 1);
    set_short("At the Drawbridge gate");
    set_long("%^CYAN%^At the Drawbridge Gate%^RESET%^BOLD%^\nYou are walking past the gate that secures the castle and controls the drawbridge. You see the iron gates hanging above  your head. On each side you see a door that leads to the  drawbridge control. In the ceiling you see a hole where archers can send arrows or rocks down at attacking troops. You also see a few torches on the wall.");
    set_listen("default", "The sound of the drawbridge chains fills the gate.");
    set_smell("default", "You can smell a combination of iron, rock and torches.");
    set_exits(([
                   "north" : "/d/guilds/alliance/hall/yard.c",
                   "out" : "/d/guilds/alliance/hall/bridge.c",
               ]));

    set_door("gate", "/d/guilds/alliance/hall/bridge", "out");
    set_open("gate", 0);
    add_lock("gate", "alliance ring", "lock", "There is no keyhole in this lock, but rather a circular depression with a tiny engraved image of two gauntlets shaking hands.  Otherwise it is a gigantic, but otherwise normal, gate lock.");
    set_locked("gate", 1, "lock");
    lock_difficulty("gate", get_phouse_lock_dc("epic"), "lock");

    set_post_exit_functions(({ "out" }), ({ "gone_out" }));
}

void gone_out()
{
    tell_object(TP, "As you leave, you see a sign above you that says %^BOLD%^%^WHITE%^'Remember to lock the gate as you leave!'%^RESET%^");
    return;
}
