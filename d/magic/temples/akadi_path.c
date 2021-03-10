#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(FOOT_PATH);
   set_name("A winding footpath");
   set_short("A winding footpath");
   set_long("This path is lined with smoothed %^BOLD%^%^BLACK%^gray "+
      "gravel%^RESET%^, leading up the mountainside towards a very "+
      "wide %^BOLD%^ledge%^RESET%^.  It looks as though it may once "+
      "have supported a structure of some kind, but now most of the "+
      "plateau has been swept clear.  Oddly, a few sticks of incense "+
      "have been left here, almost as if in offering, and a lonely "+
      "handful of silken pennants stand fluttering in the %^CYAN%^wind "+
      "%^RESET%^that whistles around you.\n");
/*   set_long("This path is lined with smoothed %^BOLD%^%^BLACK%^gray "+
      "gravel%^RESET%^, leading up the mountainside towards a very "+
      "wide %^BOLD%^ledge %^RESET%^supporting a large %^BOLD%^%^CYAN%^"+
      "crystalline structure %^RESET%^which looks to be a temple.  The "+
      "%^CYAN%^wind %^RESET%^picks up in the area, and you can hear it "+
      "whistling around you as you climb higher, nearing the building.\n");*/
   set_smell("default","Crisp mountain air is tinged with a hint of incense.");
   set_listen("default","The wind whistles through the mountainside.");
   set_exits(([
      "southwest" : "/d/shadow/room/mountain/road6",
   ]));
}