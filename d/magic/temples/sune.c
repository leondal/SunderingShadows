#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(1);
   set_short("%^RED%^An ornate garden memorial%^RESET%^");
   set_long("%^RED%^An ornate garden memorial%^RESET%^\n"
"%^BOLD%^%^WHITE%^A beautiful and breathtaking balance between nature and architecture unfolds before you.  Smooth white marble columns and alcoves rest in the lush %^GREEN%^green"
"%^BOLD%^%^WHITE%^ park.  Sculpted hedges in the shapes of animals create private and secluded recesses within the area.  Scattered about in an eye-pleasing manner are %^RESET%^%^RED%^deep "
"crimson roses%^BOLD%^%^WHITE%^, their fragrant perfume scenting the air.  In the center of the memorial lays a white marble pool, its waters still and crystal clear.  A large white marble "
"statue of a comely female with flowing locks of %^RESET%^%^RED%^crimson%^BOLD%^%^WHITE%^ overlooks the pool, her reflection mirrored in the water.  She holds one hand extended, as if to offer "
"%^RESET%^%^CYAN%^blessings %^BOLD%^%^WHITE%^to any that approach.  Despite being a partially outdoor structure, it seems as if rain or snow never make their way inside these grounds"
".\n%^RESET%^");
   set_smell("default","The air is heavily scented with roses.");
   set_listen("default","A serene feeling lies upon the area, and even the bustle of the city beyond seems distant.");
   set_exits(([
      "out":"/d/dagger/Torm/city/c109"
   ]));
   set_items(([
      "roses":"%^RED%^Deep crimson rose bushes and wild rose vines outnumber any "+
		"other variety of roses around the temple.  The roses are tastefully "+
		"planted around the memorial grounds.%^RESET%^",
	"pool":"%^BOLD%^The large white marble pool is where visitors occasionally "+
            "gather, to reflect for a time, or even to purify and cleanse themselves "+
            "in the water.  Deep crimson rose petals float on the waters, infusing"+
		" the pool with their fragrant aroma.",
	"statue":"%^BOLD%^A large white marble statue of a radiantly beautiful"+
		"woman looks out over the temple gardens and sacred pool, one hand "+
            "extended as if to bless any that approach.",
   ]));
}