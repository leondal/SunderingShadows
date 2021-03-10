inherit "/std/vendor";

create() {
    ::create();
   set_name("bertha");
   set_id( ({ "bertha", "vendor", "shop keeper", "keeper", "shopkeeper", "meanie" }) );
    set_short("Bertha, the keeper of Outland Supply");
   set("aggressive", 0);
  set_level(15);
    set_long("She trades in ill-gotten goods.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(-130);
   set("race", "dwarf");
   set_hp(600);
   add_money("gold", random(120));
    set_body_type("human");
    set_currency("gold");
    set_storage_room("/d/standard/outlands/storage");
    set_skill("melee",90);
    set_skill("bargaining", 100);
    set_skill("stealing", 50);
}
