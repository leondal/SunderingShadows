inherit "std/room";

void create() {
  ::create();
    set_property("light", 2);
    set("short", "A fork in the road");
    set("long",
        "Several paths diverge here through the jungle area "
        "known infamously as the Outlands.  Your life is in danger "
        "here as no form of law exists.  The path back to civilization "
        "is the one to the northwest.");
    set_items(
        (["path" : "There are three of them here.",
	  "paths" : "The northwest one leads towards civilization."])  );
    set_exits( 
	      (["northwest" : "/d/standard/outland2",
		"east" : "/d/standard/outlands/t_path",
		"southwest" : "/d/standard/outlands/hideout"]) );
}
