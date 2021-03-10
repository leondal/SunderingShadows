//changed to use common inherited files
//did have thief tools but since there is a thief guild in the city and 
//fencing is to change that anyway, I left them out      Styx 9/2/01

inherit "/d/common/inherit/gs_storage.c";

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
 	 set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/attaya/seneca/pawnshop"]) );
}

void reset() {
   ::reset();
}
