inherit "/std/comp_vend.c";

void create() {
   ::create();
   set_name("Pardima");
   set_id( ({ "Pardima", "pardima", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Pardima, The Alchemist");
   set("aggressive", 0);
   set_level(19);
   set_long("Pardima will sell you components for your spells.\n"+
            "<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(5);
   set("race", "human");
   set_hd(19,1);
   set_exp(20);
   set_body_type("human");
   set_components(100);
}
