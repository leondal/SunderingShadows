inherit "/std/comp_vend.c";
create() {
   ::create();
   set_name("vaxalt");
   set_id(({"Vaxalt","vaxalt","clerk","shopkeeper","shop keeper"}));
   set_short("Vaxalt, the Alchemist");
   set("aggressive", 0);
   set_level(19);
  set_long("Vaxalt is the shorter and heftier brother of Skaldar.  He\n"+
            "has little patience for customers who dicker over prices.\n"+
            "He is always eager to sell you components for spells.  To\n"+
            "get a list of shop comands type <%^RED%^help shop%^RESET%^>\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(5);
   set("race", "human");
   set_hd(19,1);
   set_body_type("human");
   set_property("no bump", 1);
   set_class("mage");
   set_components(50);
   set_spells(({"magic missile","acid arrow","chill touch"}));
   set_spell_chance(75);
    set_guild_level("mage",9);
}
