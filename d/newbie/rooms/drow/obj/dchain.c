// changed to run from the chainmail inherit, had incorrect settings. Nienne, 04/07
inherit "/d/common/obj/armour/chain";

void create() {
    	::create();
    	set_name("drow chain");
    	set_id(({"chain", "armor", "chain mail","mail","drow chain" }));
        set_short("%^BLUE%^%^BOLD%^drow chain mail%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^darkened chain mail%^RESET%^");
    	set_long(
    		"%^BOLD%^%^BLUE%^This is armor made for drow by drow artisans.  "+
    		"The metal has been blackened with an unknown substance and there "+
    		"is no reflective metal to be seen.  This armor is made of "+
    		"interlocking metal rings. It is always worn with a layer of "+
    		"quilted fabric underneath, to prevent painful chafing and to "+
    		"cushion the impact of blows. Several layers of mail are normally "+
    		"hung over vital areas. The links yield easily to blows, absorbing "+
    		"some of the shock. Most of the weight is carried on the shoulders, "+
    		"and it is uncomfortable to wear for long periods of time.\n"+
    		"%^RESET%^"
 	);
      set_lore("This chain mail is crafted by drow armorers "+
         "who consider its creation an artform.  Many drow "+
         "armorers spend their lifetimes working on "+
         "perfecting their technique with items such as this "+
         "one.  However, you can tell by the slight problems "+
         "with the interlocking rings that this armor was "+
         "crafted by an apprentice, not a master.");
      set_property("lore difficulty",8);
    	set("value", 75);
    set_property("magic item",({"illuminate","extra_armor"}) );
}
int extra_armor(string str){
        if(!str) return 0;
        write("passed");
        return 1;
}
