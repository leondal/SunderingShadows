inherit "/d/common/obj/armour/studded.c";

void create() {
    	::create();
    	set_name("drow studded");
    	set_id(({ "studded","armor", "studded armor","drow leather", "drow Studded" }));
        set_short("%^BLUE%^%^BOLD%^drow studded leather armor%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^dark studded leather armor%^RESET%^");
    	set_long(
     		"%^BOLD%^%^BLUE%^"+
     		"This is armor made for drow by drow.  This armor is made from "+
     		"black leather (not hardened like regular leather armor) reinforced "+
     		"with close-set metal rivets.  The metal rivets have been blackened by "+
     		"an unknown substance to not reflective surfaces are present in the metal.  "+
     		"Similar to the brigadine armor, except the spacing is wider.\n"+
     		"%^RESET%^"
     	);
      set_lore("Made by a drow craftsman, this leather armor "+
         "is often worn by drow warriors in the underdark.  The "+
         "leather is said to be hardened roethe hide.  Roethe are "+
         "the cattle of the underdark, and drow often keep large "+
         "numbers of them in the larger caverns.");
      set_property("lore difficulty",3);
    	set_weight(25);
    	set("value", 20);
    	set_type("leather");
    	set_limbs( ({ "torso" }) );
    	set_ac(3);
}
