#include <std.h>

inherit "/std/spell_vend.c";

void create()
{
    int i;
    float fi;
    object ob;
    mapping spells_sold;
    set_name("Shea");
    ::create();
    set_id( ({ "shea", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Shea, the spell seller");
    set("aggressive", 0);
    set_level(30);
set_long("Shea is the proprietor of this store. He is a handsome half-elf, with wavy brown hair and a brilliant smile. He is here to serve you and to help you in the purchase of spells. Type <help shop> of a list of commands. ");
    set_gender("male");
    set_alignment(7);
    set("race", "half-elf");
    set_class("mage");
    set_property("strength","spells");
set_property("no animate",1);
    set_hd(144,1);
    set_stats("intelligence",19);
    set_stats("wisdom",10);
    set_stats("strength",8);
    set_stats("charisma",13);
    set_stats("dexterity",18);
    set_stats("constitution",14);
    set_body_type("human");
    set_guild_level("mage",30);
    set_property("no bump", 1);
    spells_sold=([
        "magic missile":6500,
        "sleep":5000,"armor":5500,
   "identify":2600,
        "chill touch":7000,
        "burning hands":4000,
        "color spray":8000,
        "armor":4000,
        "detect invisibility":25000,
        "hideous laughter":18000,
        "invisibility":23000,
       "lower resistance":45000,
     "contingency":65000,
        "rope trick":20000,
        "scorcher":25000,
        "web":21000,
        "acid arrow":33000,
        "dispel magic":30000,
        "fireball":34000,
        "hold person":31000,
        "lightning bolt":31000,
        "monster summoning 1":32000,
        "monster summoning 2":42000,
        "wall of fire":40000,
        "animate dead":50000,
        "cone of cold":50000,
        "domination":53000,
        "teleport":55000,
        "teleport without error":72000
    ]);
    for(i=0;i<sizeof(spells_sold);i++)
        spells_sold[keys(spells_sold)[i]] += (random(2000)-999);
    set_spells_sold(spells_sold);
    set_spell_chance(90);
    set_spells(({"color spray","hideous laughter","acid arrow",
        "sleep","monster summoning 2"}));
    set_size(2);
    set_wielding_limbs( ({ "right hand","left hand" }) );
    i=1000000+random(2000000);
set_emotes(15,({
"%^MAGENTA%^Shea says%^RESET%^: Welcome to my store. Everything you could ever wish for is here...well spells that is. ",
"%^BOLD%^%^BLUE%^Shea laughs heartily!%^RESET%^ ",
"%^CYAN%^Shea scurries around everywhere making sure things are just right in his store.%^RESET%^",
"%^MAGENTA%^Shea mumbles under his breathe saying%^RESET%^: Oooo it is cruel outside the walls of this city. Must make sure all mages get what they need for spells. ",
"%^RED%^Shea cackles softly.%^RESET%^ "}),0);
new("/d/attaya/seneca/cguilds/mage/mrobe.c")->move(TO);
command("wear armor");
}
