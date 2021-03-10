inherit "/d/common/obj/armour/coif.c";

void create() {
    	::create();
    	set_name("drow coif");
    	set_id(({ "helm", "chain", "coif", "helmet", "chain coif", "drow coif" }));
        set_short("%^BLUE%^%^BOLD%^drow chain coif%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^darkened chain coif%^RESET%^");
    	set_long(
    		"%^BOLD%^%^BLUE%^"+
    		"This is a piece of drow armor made by a drow for a drow.  The "+
    		"coif is a hood made out of interlinked metal loops.  The coif will "+
    		"protect the wearer from slashing cuts to the head and neck, "+
    		"but offers little protection from bludgeoning damage.  The "+
    		"metal of the coif have been blackened by an unknown "+
    		"substance so that there is not reflective surfaces on the coif to "+
    		"be seen.\n"+
		"%^RESET%^");
      set_lore("This darkened coif is meant to be worn only "+
         "by drow.  Like the other drow creations, any other "+
         "race seen wearing such an item should be able to "+
         "defend himself, as the drow take wearing such things "+
         "as an insult.  Drow craftsmen spend their entire "+
         "lives learning to perfect this art, and it is "+
         "evident from the slight problems with the coif that "+
         "it was made by an apprentice.");
       set_property("lore difficulty",7);
        //set_weight(10);
    	set("value", 30);
        set_type("chain");
    	set_limbs( ({ "head" }) );
        //set_ac(1);
}
