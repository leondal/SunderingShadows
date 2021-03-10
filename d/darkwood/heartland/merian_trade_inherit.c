#include <std.h>
inherit ROOM;

	void create(){
   	::create();
   	set_property("indoors",0);
   	set_property("light",2);
   	set_terrain(GRASSLANDS);
   	set_travel(RUTTED_TRACK);
   	set_name("%^ORANGE%^Meriana Trade Route");
   	set_short("%^ORANGE%^Meriana Trade Route");
   	set_long("%^ORANGE%^A flat open plain stretches for miles and"+
		" miles around you.  The Meriana Trade Route cuts through"+
		" the eastern edge of the Great Heartlands, the agricultural"+
		" center of the realms.  The vast open plains landscape provides"+
		" a view of the numerous fields that make up the Great Heartlands."+
		"  Though lightly populated, these plains play vital role to the "+
		"well being of every city and community on the continent, if not the"+
		" world.  Fields of wheat, corn, as well as groves of fruits, and"+
		" gardens of vegetables stretch off into the horizon, making it "+
		"difficult to determine the exact size of these vast plains.\n"+
		"%^GREEN%^The Meriana Trade Route serves as the main trade route out of"+
		" the Heartlands.\n");  
   	set_smell("default","A fresh earthy scent lingers in the air.");
   	set_listen("default","The wind quietly stirs the crops in the fields.");
  	set_items(([
      	({"fields","wheat","corn"}) : "%^YELLOW%^Wheat, corn, barley, "+
			"rye, and other grains thrive in the fertile soil.",
      	({"groves","fruits"}) : "%^GREEN%^Orchards of apples, peaches,"+
			" pears, and other fruits break up the flat open landscape.",
		({"gardens","vegetables"}) : "%^BOLD%^%^GREEN%^Plots of land "+
			"devoted to the growth of melons, gourds, potatoes, tomatoes,"+
			" among the numerous varieties of vegetables stretch off into"+
			" the horizon."]));
  }
