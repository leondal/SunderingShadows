//Updated to bring in line with area difficulty - Octothorpe 4/15/10

inherit "/d/common/obj/armour/fullplate";

void create() {
    	::create();
     	set_id(({ "armor","full plate armor","plate","large fullplate","red fullplate"}));
    	set_obvious_short("%^BOLD%^%^RED%^A suit of fever iron full plate armor%^RESET%^");
	set_short("%^BOLD%^%^RED%^Fever Iron Plate%^RESET%^");
    	set("long", 
        	"%^RESET%^%^RED%^This is the impressive suit of fever iron platemail."+
		" Fever iron is prized by many followers of Tempus of the dark red"+
		" luster that appears when forged. This impressive suit of armor "+
		"appears to have seen many battles, with dents and scratches on the"+
		" metal. All the "
        	"plates are interlocking and carefully angled to deflect blows. "+
		"The metal plates are backed by padding and chainmail. The weight"+
		" is well distributed. A raised relief image of a flaming longsword"+
		" adorns the front and back breastplate.");
    	set_size(3);
    	set_property("enchantment",3+random(2));
	set_lore("Fever iron was discoved by a clan of dwarven blacksmith "+
		"and armorers loyal to Tempus in the year 566.  Clan Ironanvil"+
		" soon made use of this new form of iron to fashion armor and "+
		"weapons for the followers of Tempus.  One firbolg warrior of "+
		"Tempus earned the right to have a suit of plate mail custom made"+
		" for him after a succesful military campaign on Laerad.  Fighting"+
		" to repel the invasion of bugbear and trolls, Vanskar the Red, was"+
		" able to allow his army of human clerics and warriors to enter the"+
		" city walls of Asgard.  The Asgardian people, distrustful in nature"+
		" to any large folk, all stood in awe at the large firbolg single "+
		"handedly killed 34 trolls and 28 bugbears that day.");
	set_property("lore",13);

}
