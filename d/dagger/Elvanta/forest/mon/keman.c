inherit "/std/comp_vend.c";

create() {
   ::create();
set_name("Keman");
set_id( ({"keman", "clerk", "shop keeper", "shopkeeper"}) );
set_short("Keman, The Alchemist");
   set("aggressive", 0);
   set_level(19);
set_long("Keman will sell you components for your spells.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(5);
   set("race", "human");
   set_hd(19,1);
    set_body_type("human");
    set_property("no bump", 1);
      set_components(100);
	add_money("silver", 500);
}

