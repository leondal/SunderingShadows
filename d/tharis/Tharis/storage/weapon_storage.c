//changed to use the common inherit weapon storage for easier global maint.
// & save memory.  Also fixed the up exit.  *Styx*  9/3/01

inherit "/d/common/inherit/wpn_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short", "Tharis Weapon Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : "/d/tharis/Tharis/weapon"]) );
}

void reset() {
  ::reset();
}

