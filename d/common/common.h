// Common Definitions File.
// Garrett 05/30/2001

// Note how I defined these headers, that you shouldn't need a + after the
// definition. You might even get an error.

// Revision 4.

#define COBJ "/d/common/obj/"+
#define CWEAP COBJ"weapon/"+
#define CARMOR COBJ"armour/"+
#define CARMOUR CARMOR
#define CMISC COBJ"misc/"+
#define CLRWEAP COBJ"lrweapon/"+
#define CSHEATH COBJ"sheath/"+
#define CPOTION COBJ"potion/"+  /*Added 6/3/01 by Styx & copied in more potions*/
#define RANDGEAR "/d/common/daemon/randgear_d.c"
#define RANDSTUFF "/d/common/daemon/randstuff_d.c"
#define RANDTREAS "/d/common/daemon/randtreasure_d.c"
#define MOUNTS "/d/common/mounts/"+

// Yay backwards compatibility.

#define MISCDIR CMISC""
#define WEAPONDIR CWEAP""
#define ARMOURDIR CARMOR""
#define ARMORDIR CARMOR""
#define LRWEAPONDIR CLRWEAP""

// Most Used Objects.

#define SLAMP COBJ"misc/street_light.c"
#define HEALKIT "/d/common/obj/potion/healing.c"
#define HEALKIT_II "/d/common/obj/potion/extra_heal.c"
#define HEALKIT_III "/d/common/obj/potion/advanced_heal.c"
#define HEALKIT_IV "/d/common/obj/potion/legendary_heal.c"
#define HEALKIT_V "/d/common/obj/potion/epic_heal.c"
#define SHEATH_INHERIT CSHEATH"sheath_inherit.c"

#define N_AMB_RING "/realms/styx/misc/ambassador_ring.c"
