
inherit "/std/fence";

void create() {
   ::create();
   set_name("slump");
   set_id( ({ "slump","Slump","shop keeper"}) );
   set_short("Slump, the thief's guild shopkeeper");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells goods that will help thieves.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set_class("thief");
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
//   set_storage_room("/d/tharis/Tharis/storage/tstorage");
   set_property("no bump", 1);
   set_hd(19,3);
   set_exp(10);
}

int should_interact(object ob) { return 1;}
