// Chernobog (6/3/21)
// Scroll Shop Inherit

#include <std.h>
#include <spellsbylevel.h>
#include <daemons.h>
#include "/d/common/common.h"
inherit "/std/room";

#define SCRL_CLASSES ({"bard", "mage", "cleric", "druid", "inquisitor", "paladin", "ranger", "magus"})

void create(){
    ::create();
    set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set_short("Scroll storage base");
    set_long("Supplies and such are stored here.\n");
}

void reset(){
    int i = 0;
    object scroll;
    string * rclass;
    string * rspell;
    object wand;
    
    ::reset();

    for (i = 0; i < 3; i++){
        if (!present("book " + i)){
            new("/d/common/obj/misc/book")->move(TO);
        }
    }
    
    for (i = 0; i < 11; i++){
        if (!present("paper " + i)){
            new("/d/common/obj/misc/paper")->move(TO);
        }
    }
    
    for (i = 0; i < 11; i++){
        if (!present("parchment " + i)){
            new("/d/tharis/obj/parchment")->move(TO);
        }
    }
    
    for (i = 0; i < 3; i++){
        if (!present("quill " + i)){
            new("/d/common/obj/rand/r_quill")->move(TO);
        }
    }
    
    // Assortment of scrolls from 1st to 4th level
    for (i = 0; i < 11; i++){
        if (!present("scroll " + i)){
            rclass = SCRL_CLASSES[random(sizeof(SCRL_CLASSES))];
            rspell = MAGIC_D->query_random_spell(rclass, (roll_dice(1, 4)));
            scroll = new("/d/magic/safe_scroll");
            scroll->set_spell_name(rspell);
            scroll->move(TO);
        }
    }
    
    wand = new("/d/magic/obj/r_wand");
    wand->set("spell", "secret chest");
    wand->make_me();
    wand->move(TO);

    // Assortment of wands from 1st to 4th level
    for (i = 0; i < 4; i++){
        if (!present("wand " + i)){
            rclass = SCRL_CLASSES[random(sizeof(SCRL_CLASSES))];
            rspell = MAGIC_D->query_random_spell(rclass, (roll_dice(1, 4)));
            wand = new("/d/magic/obj/r_wand");
            wand->set("spell", rspell);
            wand->set("spell type", rclass);
            wand->make_me();
            wand->move(TO);
        }
    }

}

