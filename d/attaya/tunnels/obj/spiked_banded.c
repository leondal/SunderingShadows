inherit "/d/common/obj/armour/banded.c";

void create() {
    ::create();
    set_name("gleaming spiked banded armor");
    set("id", ({ "banded", "armor", "banded armor", "spiked", 
                                "spiked armor", "spiked banded" }) );
    set_short("%^ORANGE%^Sp%^YELLOW%^i%^RESET%^%^ORANGE%^ked"
           +" %^RESET%^b%^BOLD%^%^WHITE%^a%^RESET%^nded %^ORANGE%^armor");
    set_long("%^ORANGE%^This armor is made up of overlapping strips of"
      +" %^RESET%^metal%^ORANGE%^ sewn to a backing of leather and "
      +"%^RESET%^chainmail%^ORANGE%^. The whole thing %^RESET%^gle"
      +"%^BOLD%^%^WHITE%^a%^RESET%^ms %^ORANGE%^oddly, and it is hard to"
      +" determine what %^RESET%^metal%^ORANGE%^ it might be made of."
      +" Strange sp%^YELLOW%^i%^RESET%^%^ORANGE%^kes protrude at odd"
      +" angles from most of the strips, which cover the more vulnerable"
      +" areas. The %^RESET%^chain%^ORANGE%^ and leather protect the"
      +" joints, where freedom of movement must be assured. Unusually,"
      +" this banded armour does not seem to require the standard array"
      +" of straps and buckles to hold it together and keep the weight"
      +"  more or less evenly distributed.");
    set("value", 2000);
    set_type("armour");
    set_property("enchantment",4);
    set_wear(("The armour seems to slide and lock into place without any"
             +" noticable means for holding it together. Once on, it"
             +" feels surprisingly light."));
    set_remove(("The armour comes off in sections and is relatively easy"
               +" to remove, although it takes some time, as most armour"
               +" does. You need to be careful not to spike yourself."));

}
