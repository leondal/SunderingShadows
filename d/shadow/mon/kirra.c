#include <std.h>
inherit "/std/psion_vend.c";

void create(){
    ::create();
    set_name("kirra");
    set_id(({"kirra","clerk","shop keeper","girl","psion","shopkeeper",}));
    set_short("Kirra, a young girl");
    set("aggressive", 0);
    set_long("Kirra is only young, with whispy blonde curls that "+
       "chase their way around her head in a golden aura.  Her "+
       "waifish figure is clad in a dress as colorful as the "+
       "crystals of this place, complete with little golden "+
       "shoes on her feet.  Her lively sapphire eyes dart to and "+
       "fro as her tiny fingers hold out her wares to passers-by.");
    set_gender("female");
    set_alignment(5);
    set_race("human");
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
