
//      Spell Coder room
//      Thorn@Shadowgate
//      6/21/95
//      Wizard Coding
//      /d/magic/immort.c

#include <std.h>

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("Wizard Coder Room");
set_long(
@THORN
You are standing in the middle of the Great Library of Hallow's End,
home of thousands of texts of magic and mystery collected from all
over the World.  Wizards come here to study their craft and research
arcane spells and artifacts.  A heavy atmosphere of magic is in the
air.  In front of you is the great register of Hallow's End, where 
the High Mages of ShadowGate enumerate their knowledge.  
THORN
);
    set_exits(
              (["start" : "/d/shadowgate/adv_main",
                "inner" : "/d/shadowgate/arch/4th_floor",
                "thorn" : "/realms/thorn/workroom"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "spell board", "register" }) );
    ob->set_board_id("spellcoding");
    ob->set_max_posts(30);
    ob->set_location("/d/magic/immort");
    ob->set("short", "Spell Coding Board");
    ob->set("long", "This is the Spell Coding Board, for the spell coding"+
    " wizards to keep others appraised of their progress....\n");

}
