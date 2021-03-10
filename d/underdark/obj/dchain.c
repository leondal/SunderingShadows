inherit "/std/armour";

void create() {
    ::create();
    set_name("chain");
   set_id(({"chain","chainmail","dark chain","dark chainmail"}));
   set_short("%^BOLD%^%^BLACK%^darkened chainmail%^RESET%^");
   set_long(
        "%^BOLD%^%^BLACK%^This armor is made of interlocking "+
                "metal rings.  It is always worn with a layer of quilted\n"+
               "fabric underneath, to prevent painful chafing and to\n"+
               "cushion the impact of blows.  It fits perfectly on \n"+
      "your torso area. It also seems the lightweight metal has been darkened somehow.");
   set_weight(20);
    set("value", 125);
     set_type("chain");
    set_limbs( ({ "torso" }) );
    set_ac(5);
}
