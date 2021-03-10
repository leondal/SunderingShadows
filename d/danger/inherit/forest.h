#define NORTH       ({ "0,4","0,5","0,6","0,7","0,8","0,9","0,10","1,4","1,5","1,6","1,7","1,8","1,9","1,10","2,4","2,5","2,6","2,7","2,8","2,9","2,10","3,4","3,5","3,6","3,7","3,8","3,9","3,10" })
#define EAST        ({ "4,14","5,14","6,14","7,14","8,14","9,14","10,14","4,13","5,13","6,13","7,13","8,13","9,13","10,13","4,12","5,12","6,12","7,12","8,12","9,12","10,12","4,11","5,11","6,11","7,11","8,11","9,11","10,11" })
#define SOUTH       ({ "14,4","14,5","14,6","14,7","14,8","14,9","14,10","13,4","13,5","13,6","13,7","13,8","13,9","13,10","12,4","12,5","12,6","12,7","12,8","12,9","12,10","11,4","11,5","11,6","11,7","11,8","11,9","11,10" })
#define WEST        ({ "4,0","5,0","6,0","7,0","8,0","9,0","10,0","4,1","5,1","6,1","7,1","8,1","9,1","10,1","4,2","5,2","6,2","7,2","8,2","9,2","10,2","4,3","5,3","6,3","7,3","8,3","9,3","10,3" })
#define NORTHEAST   ({ "0,14","0,13","0,12","0,11","1,14","1,13","1,12","1,11","2,14","2,13","2,12","2,11","3,14","3,13","3,12","3,11" })
#define SOUTHEAST   ({ "14,14","14,13","14,12","14,11","13,14","13,13","13,12","13,11","12,14","12,13","12,12","12,11","11,14","11,13","11,12","11,11" })
#define SOUTHWEST   ({ "0,0","14,0","14,1","14,2","14,3","13,0","13,1","13,2","13,3","12,0","12,1","12,2","12,3","11,0","11,1","11,2","11,3" })
#define NORTHWEST   ({ "0,1","0,2","0,3","1,0","1,1","1,2","1,3","2,0","2,1","2,2","2,3","3,0","3,1","3,2","3,3" })
#define MIDDLE      NORTH + EAST + SOUTH + WEST + NORTHEAST + SOUTHEAST + SOUTHWEST + NORTHWEST

#define LONG        "%^RESET%^%^GREEN%^You are in a large forest. The green foilage on the ground runs as far as the eye can see. All around massive %^RESET%^%^RED%^redwood %^RESET%^%^GREEN%^trees reach towards the heavens ans their awe inspiring canopies nearly block out the sun. However, just enough %^RESET%^%^ORANGE%^rays of light%^RESET%^%^GREEN%^ pierce the thick canopy to light ground below."

#define NLONG	    "%^BOLD%^%^BLACK%^You are in a large forest. It is nearly pitch black as the %^RESET%^moonlight %^BOLD%^%^BLACK%^is not nearly strong enough to pierce the thick canopy created by the massive %^RESET%^%^RED%^redwood%^BOLD%^%^BLACK%^ trees. In the dead of night, the once majestic trees, almost foreshadow an unseen danger all around you."

#define N_DESC      " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the north and runs all along the border of the forest for as far as you can see."

#define E_DESC      " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the east and runs all along the border of the forest for as far as you can see."

#define S_DESC      " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the south and runs all along the border of the forest for as far as you can see."

#define W_DESC      " %^RESET%^%^GREEN%^Here, the forest begins to give way to the large cliffs that border vast %^BOLD%^%^CYAN%^ocean %^RESET%^%^GREEN%^off to the west."

#define NE_DESC     " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the northeast and runs all along the border of the forest for as far as you can see."

#define SE_DESC		" %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the southeast and runs all along the border of the forest for as far as you can see."

#define SW_DESC     " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the south and the vast %^BOLD%^%^CYAN%^ocean %^RESET%^%^GREEN%^lies to the west."

#define NW_DESC     " %^RESET%^%^GREEN%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^RESET%^%^GREEN%^comes into view from the north and the vast %^BOLD%^%^CYAN%^ocean %^RESET%^%^GREEN%^lies to the west."

#define MID_DESC    " %^RESET%^%^GREEN%^Here in the %^BOLD%^%^GREEN%^heart %^RESET%^%^GREEN%^of the forest there is nothing, but trees to see for miles all around."

#define N_N         " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the north and runs all along the border of the forest for as far as you can see."

#define N_E         " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the east and runs all along the border of the forest for as far as you can see."

#define N_S         " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BP:D%^%^BLACK%^comes into view from the south and runs all along the border of the forest for as far as you can see."

#define N_W         " %^BOLD%^%^BLACK%^Here, the forest begins to give way to the large cliffs that border vast %^BOLD%^%^CYAN%^ocean %^BOLD%^%^BLACK%^off to the west."

#define N_NE       " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the northeast and runs all along the border of the forest for as far as you can see."

#define N_SE        " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the southeast and runs all along the border of the forest for as far as you can see."

#define N_SW        " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the south and the vast %^BOLD%^%^CYAN%^ocean %^BOLD%^%^BLACK%^lies to the west."

#define N_NW        " %^BOLD%^%^BLACK%^Here, in the thinner region of the forest an enormous %^RESET%^%^ORANGE%^mountain range %^BOLD%^%^BLACK%^comes into view from the north and the vast %^BOLD%^%^CYAN%^ocean %^BOLD%^%^BLACK%^lies to the west."

#define N_MID       " %^BOLD%^%^BLACK%^Here in the %^BOLD%^%^GREEN%^heart %^BOLD%^%^BLACK%^of the forest there is nothing, but trees to see for miles all around."

#define SM_N        "%^RESET%^ORANGE%^The powerful scent of mountain air is carried by a strong breeze from the north."
#define SM_E        "%^RESET%^ORANGE%^The powerful scent of mountain air is carried by a strong breeze from the east."
#define SM_S        "%^RESET%^ORANGE%^The powerful scent of mountain air is carried by a strong breeze from the south."
#define SM_W        "%^RESET%^%^CYAN%^The strong smell of salt water is carried by from the west."
#define SM_NE       "%^RESET%^ORANGE%^The powerful scent of mountain air is carried by a strong breeze from the northeast."
#define SM_SE       "%^RESET%^ORANGE%^The powerful scent of mountain air is carried by a strong breeze from the southeast."
#define SM_SW       "%^RESET%^%^CYAN%^The strong smell of salt water is carried by from the west."
#define SM_NW       "%^RESET%^%^CYAN%^The strong smell of salt water is carried by from the west."
#define SM_MID      "%^BOLD%^%^GREEN%^The scent of redwood trees is all around you."

#define SO_N        "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_E        "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_S        "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_W        "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_NE       "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_SE       "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_SW       "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_NW       "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
#define SO_MID      "%^RESET%^%^BLUE%^You can only hear the sounds of nature."
