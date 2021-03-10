inherit "/std/vendor";

create() {
    ::create();
   set_name("horace");
   set_id( ({ "bingy", "vendor", "shop keeper", "keeper", "shopkeeper", "nerd" }) );
   set_short("Bingy, the halfling halfwit");
   set("aggressive", 0);
   set_level(12);
   set_long("He buys and sells good for adventuring.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "elf");
   set_hp(480);
   add_money("gold", random(200));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/standard/storage");
   set_skill("melee",100);
   set_skill("bargaining", 100);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
