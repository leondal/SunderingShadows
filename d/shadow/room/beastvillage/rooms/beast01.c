#include <std.h> 
#include "../defs.h" 
inherit INH+"southbeast"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"%^RESET%^%^ORANGE%^  A wide hole in the ground opens here, where a mighty "
"oak tree has broken through the surface of a cavern. Below you can see the cave "
"and the rift that spans it.  The tree, still anchored in the soil provides a "
"bridge leading down to a shelf on the far side of the rift below.%^RESET%^\n"); 

add_item(({"rift","ledge","shelf","hole"}),"%^RESET%^%^RED%^Through the hole in the "
"ground you can see that a wide chasm opens underground.  Though wide and deep, "
"the tree appears to have provided a safe means to reach the shelf along the "
"eastern side of the chasm.%^RESET%^");

add_item(({"tree","oak","branches","roots","bridge"}),"%^RESET%^%^ORANGE%^The "
"remains of a large oak tree have formed a ledge that leads from the surface down "
"to one of the wider sections of the rift's ledge. The heavy branches seem to have "
"braced the tree in place on the shelf, while the thickly gnarled roots continue "
"to cling to the surface.%^RESET%^"); 

set_exits(([ 

"north":ROOMS"beast02",
"down":"/d/underdark/upper/chasm14",

])); 

}