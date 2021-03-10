inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Daggerdale's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/dagger/Daggerdale/shops/equipshop.c"]) );
}

void reset() {
  ::reset();
}
