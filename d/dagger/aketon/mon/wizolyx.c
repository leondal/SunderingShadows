#include "/d/dagger/aketon/short.h"

inherit "/std/spell_vend.c";

void create() {
   int i,j;
   object ob;
   mapping spells_sold,spells_to_sell;
   string *spells;
   ::create();
   set_name("wizolyx");
   set_id( ({"wizolyx","wizard","elder"}) );
   set_short("Wizolyx the elder wizard");
   set("aggressive",0);
   set_long("Wizolyx is an aged elf. He looks as though he is much older "
      "then the citizens you saw in the city. His hair, gray and tangled "
      "drops down over his gnarled face. An old grey rag he wears and a "
      "cane he walk with. He is studying the scrolls in his hands and not "
      "noticing what is happening in the shop. Perhaps he will listen to "
      "your needs if you speak up.\nType <list spells> to see what he has "
      "to offer you.");
   set_gender("male");
   set_alignment(5);
   set_race("elf");
   set_hd(45,4);
   set_property("strength","spells");
   set_stats("intelligence",25);
   set_stats("wisdom",20);
   set_body_type("human");
   set_size(2);
   set_class("mage");
   set_mlevel("mage",45);
   set_guild_level("mage",45);
   set_stoneSkinned(50);
   set_exp(20000);
   set_property("no steal",1);
   set_property("no rush",1);
   set_property("weapon resistance",2);
   set_property("spell resistance",10);
   set_hp(500);
   set_max_hp( query_hp() );
   set_overall_ac(0);
   add_money("gold",random(100) + 1000);
   add_money("platinum",random(100) + 300);
   set_spell_chance(90);
   set_spells( ({"color spray",
      "hideous laughter",
      "magic missle",
      "vampiric touch",
      "finger of death",
      "lightning bolt",
      "ice storm",
      "powerword kill",
      "powerword stun",
      "acid_arrow",
      "prismatic spray",
      "meteor swarm",
      "monster summoning vi",
      "monster summoning vii"}) );
   spells_sold = (["acid arrow":40000,
      "animate dead":55000,
      "armor":10000,
      "burning hands":10000,
      "chain lightning":72000,
      "chill touch":10000,
      "color spray":10000,
      "cone of cold":55000,
      "conjure air elemental":60000,
      "conjure earth elemental":60000,
      "conjure fire elemental":62000,
      "conjure water elemental":58000,
      "detect invisibility":30000,
      "dispel magic":35000,
      "domination":58000,
      "dragon scales":75000,
      "finger of death":80000,
      "fireball":40000,
      "hideous laughter":24000,
      "hold person":36000,
      "ice storm":52000,
      "incendiary cloud":93000,
      "invisibility":26000,
      "light":10000,
      "lightning bolt":36000,
      "magic missile":10000,
      "meteor swarm":99000,
      "monster summoning i":35000,
      "monster summoning ii":45000,
      "monster summoning iii":50000,
      "monster summoning iv":58000,
      "monster summoning v":66000,
      "monster summoning vi":74000,
      "monster summoning vii":82000,
      "powerword kill":90000,
      "powerword stun":73000,
      "prismatic spray":78000,
      "ray of enfeeblement":32000,
      "rope trick":25000,
      "scorcher":30000,
      "sleep":10000,
      "stoneskin":160000,
      "teleport":60000,
      "teleport without error":80000,
      "vampiric touch":45000,
      "wall of fire":45000,
      "web":30000]);
   for(i = 0;i < sizeof(spells_sold);i++)
      spells_sold[keys(spells_sold)[i]] += random(5000);
   spells = ({});
   spells_to_sell = ([]);
   for(j = 1;j < 20;j++)
      spells = spells +
      ({ keys(spells_sold)[random( sizeof(keys(spells_sold)) )] });
   spells = distinct_array(spells);
   for(j = 0;j < sizeof(spells);j++)
      spells_to_sell[spells[j]] = spells_sold[spells[j]];
   set_spells_sold(spells_to_sell);
   set_wielding_limbs( ({"right hand","left hand"}) );
}
