#include <std.h>
inherit "/std/psion_vend.c";

void create(){
    ::create();
    set_name("hroath");
    set_id(({"hroath","clerk","shop keeper","duergar","psion","shopkeeper",}));
    set_short("Hroath, a duergar merchant");
    set("aggressive", 0);
    set_long("Hroath appears to be fairly old for a duergar, "+
       "with dull gray skin and a snowy-white beard.  His face "+
       "is wrinkled with the weight of decades, lined up his "+
       "brow towards his completely bald head.  His eyes are "+
       "black as coal and lack any friendliness or joy at all.  "+
       "He wears a simple black robe that lacks ornamentation, "+
       "with his bare feet striking softly on the ground as he "+
       "moves.");
    set_gender("male");
    set_alignment(6);
    set_race("duergar");
    set_body_type("human");
    set_class("psion");
    set_hd(30,2);
    set_level(30);
    set_guild_level("psion",30);
    set_property("no bump", 1);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","microcosm",
       "energy bolt","energy bolt"}));
}
