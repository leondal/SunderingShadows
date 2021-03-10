
inherit "/std/vendor";

void create() {
   ::create();
    set_name("Carina");
    set_id( ({ "carina","Carina","shop keeper"}) );
    set_short("Carina - Keeper of the Mage Shop");
   set("aggressive", 0);
    set_level(30);
set_long("Carina buys and sells unwanted goods that other mages sell here. Type <help shop> to get a list of shop commands. ");
   set_gender("female");
   set_alignment(4);
   set_class("mage");
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
set_storage_room("/d/attaya/seneca/town/cguilds/mage/mstorage.c");
   set_property("no bump", 1);
    set_hd(50,6);
   
}
