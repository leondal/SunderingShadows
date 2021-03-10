inherit "/std/comp_vend.c";
create() {
   ::create();
   set_name("seath");
   set_id(({"Seath","seath","clerk","shopkeeper","shop keeper"}));
   set_short("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^eath, the %^BOLD%^A%^RESET%^l%^BOLD%^%^CYAN%^c%^RESET%^h%^BOLD%^%^CYAN%^e%^RESET%^m%^BOLD%^%^CYAN%^i%^RESET%^s%^BOLD%^%^CYAN%^t%^RESET%^");
   set("aggressive", 0);
   set_level(19);
   set_long("Seath Talltree will sell you components for spells.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(5);
   set("race", "human");
   set_hd(19,1);
   set_exp(10);
   set_body_type("human");
   set_property("no bump", 1);
   set_class("mage");
    set_components(100);
   set_spells(({"magic missile","acid arrow","chill touch"}));
   set_spell_chance(75);
   remove_std_db();
}
