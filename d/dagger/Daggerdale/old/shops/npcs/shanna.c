
inherit "/std/comp_vend.c";

void create() {
   ::create();
   set_name("shanna");
   set_id( ({ "shanna", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Shanna, The Alchemist");
   set("aggressive", 0);
   set_level(19);
   set_long("Shanna is a lovely female elf, with long blonde hair. \n"+
        "Shanna will sell you all sorts of magic things.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("female");
   set_alignment(5);
   set("race", "elf");
   set_hd(19,1);
   set_body_type("human");
   set_property("no bump", 1);
   set_components(100);
}

