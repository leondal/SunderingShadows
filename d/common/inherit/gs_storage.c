//general storage to inherit for easy maint. of common gear for general stores
//by Styx 7/28/01
#include <std.h>
#include "/d/common/common.h"
inherit "/std/room";

void create()
{
    ::create();
    set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set_short("Common general storage base");
    set_long("Supplies and such are stored here but YOU shouldn't be here.\n");
    set_exits( (["up" : "/d/shadow/room/city/gs_store"]) );
    set_had_players(3);
}

void reset()
{
    int i;
    object scroll;
    ::reset();

    if (base_name(TO) == "/d/common/inherit/gs_storage") {
        return;
    }
// to keep the inheritable stores from loading the items they're supposed
// to load in their children.
    if (!present("bookxxx")) {
        new(CMISC "book")->move(TO);
    }
    if (!present("bookxxx") && !random(3)) {
        new(CMISC "book")->move(TO);
    }
    if (!present("canvasxxx")) {
        new(CMISC "canvas")->move(TO);
    }
    if (!present("canvasxxx") && !random(3)) {
        new(CMISC "canvas")->move(TO);
    }
    if (!present("chest") && !random(3)) {
        new(CMISC "chest")->move(TO);
    }
    if (!present("schest") && !random(6)) {
        new(CMISC "schest")->move(TO);
    }
    if (!present("large sack")) {
        new(CMISC "sack")->move(TO);
    }
    if (!present("large sack 2")) {
        new(CMISC "sack")->move(TO);
    }
    if (!present("ssack") && !random(3)) {
        new(CMISC "ssack")->move(TO);
    }
    if (!present("pouch")) {
        new(CMISC "pouch")->move(TO);
    }
    if (!present("spouch") && !random(4)) {
        new(CMISC "spouch")->move(TO);
    }
    if (!present("climb_tool")) {
        new(CMISC "climb_tool")->move(TO);
    }
    if (!present("thief_tools")) {
        new(CMISC "thief_tools")->move(TO);
    }
    if (!present("climb_tool 2") && !random(3)) {
        new(CMISC "climb_tool")->move(TO);
    }
    if (!present("rope")) {
        new(CMISC "rope")->move(TO);
    }
    if (!present("rope 2")) {
        new(CMISC "rope")->move(TO);
    }
    if (!present("basket") && !random(3)) {
        new(CMISC "basket")->move(TO);
    }
    if (!present("sbasket") && !random(4)) {
        new(CMISC "sbasket")->move(TO);
    }
    if (!present("torch")) {
        new(CMISC "torch")->move(TO);
    }
    if (!present("torch 2") && !random(2)) {
        new(CMISC "torch")->move(TO);
    }
    if (!present("flint")) {
        new(CMISC "flint")->move(TO);
    }
    if (!present("lantern")) {
        new(CMISC "lantern")->move(TO);
    }
    if (!present("reg_oil")) {
        new(CMISC "oil")->move(TO);
    }
    if (!present("reg_oil 2")) {
        new(CMISC "oil")->move(TO);
    }
    if (!present("reg_oil 3")) {
        new(CMISC "oil")->move(TO);
    }
    if (!present("beacon") && !random(3)) {
        new(CMISC "beacon")->move(TO);
    }
    if (!present("bullseye")) {
        new(CMISC "bullseye")->move(TO);
    }
    if (!present("flint") && !random(4)) {
        new(CMISC "flint")->move(TO);
    }
    if (!present("lkchest") && !random(8)) {
        new(CMISC "lkchest")->move(TO);
    }
    for (i = 0; i < 3; i++) {
        if (!present("weapsheath " + i)) {
            new(CSHEATH "sheath_randomizer")->move(TO);
        }
    }
    if (!present("small sheath")) {
        new(CSHEATH "sheath_small")->move(TO);
    }
    if (!present("medium sheath")) {
        new(CSHEATH "sheath_medium")->move(TO);
    }
    if (!present("medium holster")) {
        new(CSHEATH "sheath_mbludgeon")->move(TO);
    }
    if (!present("weapsheath 5") && !random(2)) {
        new(CSHEATH "sheath_randomizer")->move(TO);
    }
    if (!present("deck")) {
        new("/d/shadow/obj/misc/deckofcards")->move(TO);
    }
    if (!present("die")) {
        new("/d/common/obj/misc/die")->move(TO);
    }
    if (!present("die 2")) {
        new("/d/common/obj/misc/d20")->move(TO);
    }
    if (!present("bandage")) {
        new(CMISC "bandage")->move(TO);
    }
    if (!present("eyepatch") && !random(3)) {
        new(CMISC "eyepatch")->move(TO);
    }
    if (!present("soap")) {
        new(CMISC "soap")->move(TO);
    }
    if (!present("bloodshard")) {
        new("/d/common/obj/special/bloodshard")->move(TO);
    }
    for (i = 0; i < 5; i++) {
        if (!present("parchment " + i)) {
            new("/d/tharis/obj/parchment")->move(TO);
        }
    }
    /*for (i = 0; i < 6; i++) {
        scroll = new("/d/magic/safe_scroll");
        scroll->move(TO);
        scroll->set_spell(random(7) + 1);
    }

    {
        scroll = new("/d/magic/safe_scroll");
        scroll->move(TO);
        scroll->set_spell_name("secret chest");
		scroll->set_clevel(10);
    }

    new("/d/magic/obj/r_wand")->move(TO);

    {
        object wand;
        wand = new("/d/magic/obj/r_wand");
        wand->set("spell", "secret chest");
        wand->make_me();
        wand->move(TO);

        wand = new("/d/magic/obj/r_wand");
        wand->set("spell", "heal");
        wand->set("level", roll_dice(8, 6));
        wand->set("uses", roll_dice(2, 6));
        wand->make_me();
        wand->move(TO);

    }*/

    while (!present("paper 6")) {
        new(CMISC "paper")->move(TO);
    }
    if (!present("dark lantern")) {
        new(CMISC "darkbeacon")->move(TO);
    }
    if (!present("shield strap")) {
        new(CSHEATH "shieldstrap")->move(TO);
    }
    if (!present("dark oil")) {
        new(CMISC "darkoil")->move(TO);
    }
    if (!present("tent bag")) {
        new("d/charucavern/mizatencampment/ob/tent")->move(TO);
    }
    if (!random(3)) {
        while (!present("dart 3")) {
            new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
        }
    }
}
