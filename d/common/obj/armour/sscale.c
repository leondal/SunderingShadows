inherit "/d/common/obj/armour/scale";

void create() {
    ::create();
    //set_name("sscale");
    //set("id", ({ "scale","armor", "scale mail","mail" }) );
    set_short("A small suit of scale mail armor");
   // set_long("This is a coat and leggings of leather covered with overlapping "
   //   "pieces of metal, much like the scales of a fish."
   // );
    set_size(1);
   // set_weight(40);
   // set("value", 120);
   // set_type("armour");
   // set_limbs( ({ "torso" }) );
   // set_ac(4);
}

int is_metal() { return 1; }